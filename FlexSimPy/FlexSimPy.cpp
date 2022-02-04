#include "FlexSimPy.h"
#include "PyPlatform.h"
#include <iostream>
#include "Platform.h"
#include "FlexSimDefs.h"
#include "PyConverter.h"
#include <chrono>
#include <filesystem>

using namespace std::chrono_literals;
using std::string;
using std::cout;
using std::cin;

namespace FlexSim {

 std::string Controller::errorStr;
FlexSimPy FlexSimPy::inst;

PyMethodDef FlexSimPy::methods[] = {
    {"launch",  (PyCFunction)s_launch, METH_VARARGS | METH_KEYWORDS, "Launch a new instance of FlexSim."},
    {"sendToController",  (PyCFunction)s_sendToController, METH_VARARGS, "Send a value to the controller (matched with controller.receive())."},
    {"receiveFromController",  (PyCFunction)s_receiveFromController, METH_VARARGS, "Receive a value from the controller (matched with controller.send())."},
    {nullptr, nullptr, 0, nullptr}
};

PyMethodDef Controller::methods[] = {
    {"open",  (PyCFunction)s_open, METH_VARARGS, "Open a FlexSim model."},
    {"reset",  (PyCFunction)s_reset, METH_VARARGS, "Reset the currently open FlexSim model."},
    {"run",  (PyCFunction)s_run, METH_VARARGS, "Set the currently open FlexSim model to be running."},
    {"runToTime",  (PyCFunction)s_runToTime, METH_VARARGS, "Run to a defined time (blocking until the time is reached)."},
    {"stop",  (PyCFunction)s_stop, METH_VARARGS, "Set the currently open FlexSim model to be running."},
    {"getParameter",  (PyCFunction)s_getParameter, METH_VARARGS, "Get a model parameter."},
    {"setParameter",  (PyCFunction)s_setParameter, METH_VARARGS, "Set a model parameter."},
    {"getPerformanceMeasure",  (PyCFunction)s_getPerformanceMeasure, METH_VARARGS, "Get a model performance measure value."},
    {"time",  (PyCFunction)s_time, METH_VARARGS, "Get the model time."},
    {"evaluate",  (PyCFunction)s_evaluate, METH_VARARGS, "Evaluate a FlexScript node addressed by its path."},
    {"send",  (PyCFunction)s_send, METH_VARARGS, "Send a value to the running model."},
    {"receive",  (PyCFunction)s_receive, METH_VARARGS, "Receive a response or information from the running model (blocking)."},
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

/*
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
*/

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
        bool showGUI = false;
        bool evaluationLicense = false;
        const char* keywords[] = {
            "concurrency",
            "programDir",
            "args",
            "showGUI",
            "evaluationLicense",
            nullptr
        };
        const char* dllDirCStr = "";
        PyArg_ParseTupleAndKeywords(args, kwargs, "|isspp", (char**)keywords, &concurrencyType, &dllDirCStr,
            &userArgs, &showGUI, &evaluationLicense);

        string dllDir(dllDirCStr);
        if (dllDir[0] == 0)
            dllDir = pyPlatform.findFlexSimDir();

        controller->concurrencyType = concurrencyType;

        std::filesystem::path path("C:\\Anthony\\Documents\\Repositories\\Dev\\FlexSim\\program");
        pyPlatform.setDllDirectory(path.generic_string().c_str());
        flexSimApp = &FlexSimApplication::getInstance();

        int flags = 0;
        string prefix = "";
        if (!strstr(userArgs, "maintenance ") && (!showGUI || evaluationLicense))
            prefix.assign("/maintenance ").append(showGUI ? "" : "nogui_").append(evaluationLicense ? "evaluationlicense" : "").append(" ");
        string argStr = prefix + userArgs;
        auto* platform = &FlexSimApplication::getPlatform();
        if (concurrencyType == Controller::LAUNCH_ASYNCHRONOUS) {
            std::mutex mutex;
            bool isInitialized = false;
            std::unique_lock<std::mutex> lock(mutex);
            std::condition_variable condVar;
            controller->flexSimThread = std::thread([this, argStr, &mutex, &isInitialized, &condVar]() {
                std::unique_lock<std::mutex> lock(mutex);
                flexSimApp->initialize(argStr.c_str(), 0, 0);
                isInitialized = true;
                auto& platform = flexSimApp->getPlatform();
                auto& messageQueue = platform.assertThreadMessageQueue(platform.getMainThreadID());
                condVar.notify_all();
                lock.unlock();
                messageQueue.runLoop();
            });
            condVar.wait(lock, [&]() { return isInitialized; });
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


PyObject* FlexSimPy::sendToController(PyObject* self, PyObject* args)
{
    // This method is called from FlexSim's main thread, and is meant to send a value to the controller
    // (you should call controller.receive() to receive the value sent).
    if (inProcessController == nullptr) {
        Py_RETURN_NONE;
    }
    auto controller = inProcessController;

    std::unique_lock lock(controller->receiveMutex);
    PyObject* arg = PyTuple_GetItem(args, 0);
    controller->receiveValues.push(arg);
    controller->receiveCondition.notify_all();
    Py_RETURN_NONE;
}

PyObject* FlexSimPy::receiveFromController(PyObject* self, PyObject* args)
{
    // This method is called from FlexSim's main thread, and is meant to send a value to the controller
    // (you should call controller.receive() to receive the value sent).
    if (inProcessController == nullptr) {
        Py_RETURN_NONE;
    }
    auto controller = inProcessController;

    std::unique_lock lock(controller->sendMutex);
    auto& platform = FlexSimApplication::getPlatform();
    auto& messageQueue = platform.assertThreadMessageQueue(platform.mainThreadID);
    while (controller->sendValues.size() == 0) {
        lock.unlock();
        Py_BEGIN_ALLOW_THREADS
        ThreadMessage message;
        messageQueue.pump();
        Py_END_ALLOW_THREADS
        lock.lock();
    }
    auto value = controller->sendValues.front();
    controller->sendValues.pop();
    return value;
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

Controller::~Controller()
{
    if (concurrencyType == LAUNCH_ASYNCHRONOUS) {
        auto& platform = FlexSimApplication::getPlatform();
        platform.postThreadMessage(platform.mainThreadID, WM_QUIT, 0, 0);
        flexSimThread.join();
    }
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

PyObject* Controller::runToTime(PyObject* args)
{
    double toTime = -1.0;
    PyArg_ParseTuple(args, "d", &toTime);
    TreeNode* events = node("MAIN:/project/exec/events");
 
    while (events->first && events->first->object<FlexSimEvent>()->time < toTime)
        step();
    
    if (events->first)
        node("MAIN:/project/exec/time")->value = toTime;

    if (showingGUI)
        repaintall();
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

PyObject* Controller::evaluate(PyObject* args)
{
    Variant path = PyConverter::convertToVariant(PyTuple_GetItem(args, 0));
    treenode node = Model::find(path.c_str());
    Variant result;
    if (node) {
        int numParams = PyTuple_Size(args);
        std::vector<Variant> params;
        for (int i = 1; i < numParams; i++)
            params.push_back(PyConverter::convertToVariant(PyTuple_GetItem(args, i)));
        result = node->evaluate(VariantParams(params));
    }
    return PyConverter::convertToPyObject(result);
}


PyObject* Controller::send(PyObject* args)
{
    // Controller::send() is called on the controller/python thread (not on FlexSim's thread). However, it 
    // locks the sendMutex, so I know sendValues won't be changed by multiple threads.
    if (concurrencyType == LAUNCH_SYNCHRONOUS) {
        PyErr_SetString(PyExc_RuntimeError, "Calling Controller.send() in synchronous mode not allowed.");
        return nullptr;
    }
    std::unique_lock lock(sendMutex);
    PyObject* value = PyTuple_GetItem(args, 0);
    Py_XINCREF(value);
    sendValues.push(value);

    // below will "kick" the main thread if it's 
    // within receiveFromController() waiting for me to send something
    if (sendValues.size() == 1)
        FlexSimApplication::getPlatform().callMainThreadCallback([]() {}, false);
    Py_RETURN_NONE;
}

PyObject* Controller::receive(PyObject* args)
{
    // Controller::received() is called on the controller/python thread (not on FlexSim's thread). However, it 
    // locks the sendMutex, so I know sendValues won't be changed by multiple threads.
    if (concurrencyType == LAUNCH_SYNCHRONOUS) {
        PyErr_SetString(PyExc_RuntimeError, "Calling Controller.receive() in synchronous mode not allowed.");
        return nullptr;
    }
    std::unique_lock lock(receiveMutex);
    if (receiveValues.size() == 0) {
        Py_BEGIN_ALLOW_THREADS
        receiveCondition.wait(lock, [&]() { return receiveValues.size() > 0; });
        Py_END_ALLOW_THREADS
    }
    PyObject* value = receiveValues.front();
    receiveValues.pop();

    return value;
}

PyMODINIT_FUNC
PyInit_FlexSimPy(void)
{
    FlexSimPy::inst.checkBindToLoadedApp();

    if (PyType_Ready(&FlexSimPy::Controller_Type) < 0)
        return nullptr;

    PyObject* m = PyModule_Create(&FlexSimPy::flexSimPyModule);
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

}