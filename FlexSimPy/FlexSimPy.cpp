#include "FlexSimPy.h"
#include "PyPlatform.h"
#include <iostream>
#include "Platform.h"
#include "FlexSimDefs.h"
#include "PyConverter.h"
#include <chrono>

using namespace std::chrono_literals;
using std::string;
using std::cout;
using std::cin;

namespace FlexSim {

 std::string Controller::errorStr;
FlexSimPy FlexSimPy::inst;

PyMethodDef FlexSimPy::methods[] = {
    {"launch",  (PyCFunction)s_launch, METH_VARARGS | METH_KEYWORDS, "Launch a new instance of FlexSim."},
    {nullptr, nullptr, 0, nullptr}
};


PyMethodDef Controller::methods[] = {
    {"appCommand",  (PyCFunction)s_appCommand, METH_VARARGS, "Call a FlexSim application command."},
    {"open",  (PyCFunction)s_open, METH_VARARGS, "Open a FlexSim model."},
    {"reset",  (PyCFunction)s_reset, METH_VARARGS, "Reset the currently open FlexSim model."},
    {"run",  (PyCFunction)s_run, METH_VARARGS, "Set the currently open FlexSim model to be running."},
    {"stop",  (PyCFunction)s_stop, METH_VARARGS, "Set the currently open FlexSim model to be running."},
    {"getParameter",  (PyCFunction)s_getParameter, METH_VARARGS, "Get a model parameter."},
    {"setParameter",  (PyCFunction)s_setParameter, METH_VARARGS, "Set a model parameter."},
    {"getPerformanceMeasure",  (PyCFunction)s_getPerformanceMeasure, METH_VARARGS, "Get a model performance measure value."},
    {"time",  (PyCFunction)s_time, METH_VARARGS, "Get the model time."},
    {"execString",  (PyCFunction)s_execString, METH_VARARGS, "Execute a flexscript string."},
    {"yield",  (PyCFunction)s_yield, METH_VARARGS, "Yield a decision or action to the running model."},
    {"await",  (PyCFunction)s_await, METH_VARARGS, "Await a response or information from the running model."},
    {nullptr, nullptr, 0, nullptr}
};


PyTypeObject FlexSimPy::Controller_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "FlexSimPy.Controller",
    .tp_basicsize = sizeof(Controller),
    .tp_dealloc = (destructor)&Controller::deallocate,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Object to control a launched instance of FlexSim",
    .tp_methods = Controller::methods,
    .tp_init = &Controller::__init__,
    .tp_new = &Controller::__new__,
  //  .tp_repr = (reprfunc)myobj_repr,
};

PyTypeObject FlexSimPy::PyTreeNode_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "FlexSimPy.TreeNode",
    .tp_basicsize = sizeof(PyTreeNode),
    .tp_dealloc = (destructor)&PyTreeNode::deallocate,
  //  .tp_repr = (reprfunc)myobj_repr,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Python object holding a reference to a node in FlexSim's tree",
    //.tp_new = PyType_GenericNew,
};

PyDoc_STRVAR(fsPyDoc, "A module for launching and controlling FlexSim.");

PyModuleDef FlexSimPy::flexSimPyModule = {
    PyModuleDef_HEAD_INIT,
    "FlexSimPy",   /* name of module */
    fsPyDoc, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    methods
};

FlexSimPy::~FlexSimPy()
{
    if (inProcessController)
        Py_DECREF(inProcessController);
}

void FlexSimPy::checkBindToLoadedApp()
{
    DllModule mod = pyPlatform.getModuleHandle("FlexSim");
    if (mod) {
        flexSimApp = &FlexSimApplication::getInstance();
    }
}

PyObject* FlexSimPy::launch(PyObject* self, PyObject* args, PyObject* kwargs)
{

    if (inProcessController != nullptr) {
        PyErr_SetString(PyExc_RuntimeError, "You cannot launch multiple in-process FlexSim controllers");
        return nullptr;
    }
    if (!flexSimApp) {
        const char* userArgs = "";
        int concurrencyType = Controller::LAUNCH_ASYNCHRONOUS;
        Controller* controller = PyObject_New(Controller, &Controller_Type);
        //PyObject_Init((PyObject*)controller, &Controller_Type);
        inProcessController = controller;
        Controller::__init__((PyObject*)controller, nullptr, nullptr);
        Py_INCREF(inProcessController);
        Py_INCREF(inProcessController);
        int showGUI = false;
        int checkLicense = true;
        const char* keywords[] = {
            "concurrency",
            "dir",
            "args",
            "showGUI",
            "checkLicense",
            nullptr
        };
        PyArg_ParseTupleAndKeywords(args, kwargs, "|isspp", (char**)keywords, &concurrencyType, &dllDir, 
            &userArgs, &showGUI, &checkLicense);
        controller->concurrencyType = concurrencyType;

        pyPlatform.setDllDirectory(dllDir);
        flexSimApp = &FlexSimApplication::getInstance();

        int flags = 0;
        string prefix = "";
        if (!strstr(userArgs, "maintenance ") && (!showGUI || !checkLicense))
            prefix.assign("/maintenance ").append(showGUI ? "" : "nogui_").append(checkLicense ? "" : "skiplicensecheck").append(" ");
        string argStr = prefix + userArgs;
        auto* platform = &FlexSimApplication::getPlatform();
        if (concurrencyType == Controller::LAUNCH_ASYNCHRONOUS) {

            controller->flexSimThread = std::thread([this, argStr]() {
                flexSimApp->initialize(argStr.c_str(), 0, FlexSimApplication::INIT_FLAG_RUN_MESSAGE_LOOP);
                });
            platform->lockMainThread();// this will block until the main flexsim thread is finished loading and starts processing messages
            platform->unlockMainThread();
        }
        else {
            flexSimApp->initialize(argStr.c_str(), 0, 0);
        }
        return (PyObject*)controller;
    }
    else {
        PyErr_SetString(PyExc_RuntimeError, "Cannot launch FlexSim from a nested call");
        return nullptr;
    }

    Py_RETURN_NONE;
}

PyObject* FlexSimPy::yield(PyObject* args)
{
    if (!inProcessController) {
        return nullptr;
    }

    std::unique_lock lock(inProcessController->awaitMutex);
    inProcessController->awaitValue = PyTuple_GetItem(args, 0);
    inProcessController->awaitCondition.notify_one();
}

PyObject* FlexSimPy::await(PyObject* args)
{
    if (!inProcessController) {
        return nullptr;
    }
    std::unique_lock lock(inProcessController->awaitMutex);
    inProcessController->awaitCondition.wait(lock);
    return inProcessController->yieldValue;
}

PyObject* Controller::__new__(PyTypeObject* type, PyObject* args, PyObject* kwargs)
{
    return (PyObject*)PyObject_New(Controller, type);
}

int Controller::__init__(PyObject* self, PyObject* args, PyObject* kwargs)
{ 
    new (self) Controller; 
    return 0;
}

void Controller::deallocate(Controller* self)
{
    self->~Controller();
    PyObject_Free(self);
}

treenode Controller::findParameter(const char* name, bool isPerformanceMeasure)
{
    const char* path = isPerformanceMeasure ? "MODEL:/Tools/PerformanceMeasureTables" : "MODEL:/Tools/ParameterTables";
    treenode x = model()->find(path);
    if (x) {
        const char* varPath = isPerformanceMeasure ? ">variables/performanceMeasures" : ">variables/parameters";
        for (int i = 1; i <= x->subnodes.length; i++) {
            treenode table = x->subnodes[i]->find(varPath);
            if (table) {
                for (int j = 1; j <= table->subnodes.length; j++) {
                    treenode row = table->subnodes[j];
                    if (strcmp(row->first->value.c_str(), name) == 0)
                        return row->subnodes[2];
                }
            }
        }
    }
    return nullptr;
}

PyObject* Controller::appCommand(PyObject* args)
{
    Variant result;
    Array a = PyConverter::convertTupleToArray(args);
    switch (a.length) {
    case 0: break;
    case 1: result = applicationcommand(a[1].c_str()); break;
    case 2: result = applicationcommand(a[1].c_str(), a[2]); break;
    case 3: result = applicationcommand(a[1].c_str(), a[2], a[3]); break;
    case 4: result = applicationcommand(a[1].c_str(), a[2], a[3], a[4]); break;
    case 5: result = applicationcommand(a[1].c_str(), a[2], a[3], a[4], a[5]); break;
    case 6: result = applicationcommand(a[1].c_str(), a[2], a[3], a[4], a[5], a[6]); break;
    case 7: result = applicationcommand(a[1].c_str(), a[2], a[3], a[4], a[5], a[6], a[7]); break;
    case 8: result = applicationcommand(a[1].c_str(), a[2], a[3], a[4], a[5], a[6], a[7], a[8]); break;
    }
    return PyConverter::convertToPyObject(result);
}


PyObject* Controller::open(PyObject* args)
{
    Array a = PyConverter::convertTupleToArray(args);
    if (a.length > 0)
        applicationcommand("openmodel", a[1]);
    Py_RETURN_NONE;
}

PyObject* Controller::reset(PyObject* args)
{
    applicationcommand("reset");
    Py_RETURN_NONE;
}

PyObject* Controller::run(PyObject* args)
{
    double runSpeed = -1.0;
    PyArg_ParseTuple(args, "d", &runSpeed);
    if (runSpeed > 0.0) {
        set(node("MAIN:/project/exec/step"), runSpeed);
    }
    applicationcommand("run");
    Py_RETURN_NONE;
}

PyObject* Controller::stop(PyObject* args)
{
    applicationcommand("stop");
    Py_RETURN_NONE;
}

PyObject* Controller::getParameter(PyObject* args)
{
    Array a = PyConverter::convertTupleToArray(args);
    if (a.length < 1) {
        PyErr_SetString(PyExc_RuntimeError, "No parameters passed to Controller.getParameter()");
        return nullptr;
    }
    treenode x = findParameter(a[1].c_str(), false);
    if (x) {
        switch (a.length) {
        case 1: default: return PyConverter::convertToPyObject(x->value);
        case 2: return PyConverter::convertToPyObject(x->evaluate(a[2]));
        case 3: return PyConverter::convertToPyObject(x->evaluate(a[2], a[3]));
        case 4: return PyConverter::convertToPyObject(x->evaluate(a[2], a[3], a[4]));
        case 5: return PyConverter::convertToPyObject(x->evaluate(a[2], a[3], a[4], a[5]));
        }
    }
    else {
        errorStr = string("Parameter \'") + a[1].c_str() + "\' not found";
        PyErr_SetString(PyExc_RuntimeError, errorStr.c_str());
        return nullptr;
    }

    return nullptr;
}
PyObject* Controller::setParameter(PyObject* args)
{
    Array a = PyConverter::convertTupleToArray(args);
    if (a.length < 2) {
        PyErr_SetString(PyExc_RuntimeError, "Not enough parameters passed to Controller.setParameter()");
        return nullptr;
    }
    treenode x = findParameter(a[1].c_str(), false);
    if (x) {
        x->value = a[2];

        Py_RETURN_NONE;
    }
    else {
        errorStr = string("Parameter \'") + a[1].c_str() + "\' not found";
        PyErr_SetString(PyExc_RuntimeError, errorStr.c_str());
        return nullptr;
    }
}

PyObject* Controller::getPerformanceMeasure(PyObject* args)
{
    Array a = PyConverter::convertTupleToArray(args);
    if (a.length < 1) {
        PyErr_SetString(PyExc_RuntimeError, "No parameters passed to Controller.getPerformanceMeasure()");
        return nullptr;
    }
    treenode x = findParameter(a[1].c_str(), true);
    if (x) {
        auto val = x->evaluate();
        return PyConverter::convertToPyObject(val);
    }
    else {
        errorStr = string("Performance measure \'") + a[1].c_str() + "\' not found";
        PyErr_SetString(PyExc_RuntimeError, "Performance measure not found");
        return nullptr;
    }
}

PyObject* Controller::time(PyObject* args)
{
    return PyFloat_FromDouble(FlexSim::time());
}

PyObject* Controller::execString(PyObject* args)
{
    Variant str = PyConverter::convertToVariant(PyTuple_GetItem(args, 0));
    Variant result = executestring(str.c_str());
    return PyConverter::convertToPyObject(result);
}


PyObject* Controller::yield(PyObject* args)
{
    if (concurrencyType == LAUNCH_SYNCHRONOUS) {
        PyErr_SetString(PyExc_RuntimeError, "Calling Controller.yield() in synchronous mode not allowed.");
        return nullptr;
    }
    std::unique_lock lock(yieldMutex);
    yieldValue = PyTuple_GetItem(args, 0);
    yieldCondition.notify_one();
    return nullptr;
}

PyObject* Controller::await(PyObject* args)
{
    Py_BEGIN_ALLOW_THREADS;
    std::unique_lock lock(awaitMutex);
    awaitCondition.wait(lock);

    Py_END_ALLOW_THREADS
    return awaitValue;
}

PyMODINIT_FUNC
PyInit_FlexSimPy(void)
{
    PyObject* m;

    FlexSimPy::inst.checkBindToLoadedApp();

    if (PyType_Ready(&FlexSimPy::Controller_Type) < 0)
        return nullptr;

    m = PyModule_Create(&FlexSimPy::flexSimPyModule);
    if (m == nullptr)
        return nullptr;

    auto* cType = &FlexSimPy::Controller_Type;
    Py_INCREF(cType);
    if (PyModule_AddObject(m, "Controller", (PyObject*)cType) < 0) {
        Py_DECREF(cType);
        Py_DECREF(m);
        return nullptr;
    }
    //SpamError = PyErr_NewException("spam.error", nullptr, nullptr);
    //Py_XINCREF(SpamError);
    //if (PyModule_AddObject(m, "error", SpamError) < 0) {
    //    Py_XDECREF(SpamError);
    //    Py_CLEAR(SpamError);
    //    Py_DECREF(m);
    //    return nullptr;
    //}

    return m;
}
void PyTreeNode::deallocate(PyTreeNode* self)
{

}
}