#include "FlexSimPy.h"
#include "PyPlatform.h"
#include <iostream>
#include "Platform.h"
#include "FlexSimDefs.h"
#include "PyConverter.h"

using std::string;
using std::cout;
using std::cin;

namespace FlexSim {

void (*flexsimfree)(void*);

FlexSimPy FlexSimPy::inst;

PyMethodDef FlexSimPy::methods[] = {
    {"launch",  (PyCFunction)s_launch, METH_VARARGS | METH_KEYWORDS, "Launch a new instance of FlexSim."},
    {"appCommand",  (PyCFunction)s_appCommand, METH_VARARGS | METH_KEYWORDS, "Call a FlexSim application command."},
    {nullptr, nullptr, 0, nullptr}
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

void FlexSimPy::checkBindToLoadedApp()
{
    DllModule mod = pyPlatform.getModuleHandle("FlexSim");
    if (mod) {
        flexSimApp = &FlexSimApplication::getInstance();
    }
}

PyObject* FlexSimPy::launch(PyObject* self, PyObject* args, PyObject* kwargs)
{
    if (flexSimApp != nullptr)
        Py_RETURN_NONE;

    DllModule mod = pyPlatform.getModuleHandle("FlexSim");

    if (!mod) {
        const char* keywords[] = {
            "Concurrency",
            "Dir",
            "Arguments",
            nullptr
        };
        const char* userArgs = "";
        PyArg_ParseTupleAndKeywords(args, kwargs, "|iss", (char**)keywords, &concurrencyType, &dllDir, &userArgs);

        pyPlatform.setDllDirectory(dllDir);
        flexSimApp = &FlexSimApplication::getInstance();

        int flags = 0;
        string prefix = "";
        if (!strstr(userArgs, "maintenance "))
            prefix = "/maintenance nogui ";
        string argStr = prefix + userArgs;
        if (concurrencyType == LAUNCH_ASYNCHRONOUS) {

            flexSimThread = std::thread([this, argStr]() {
                flexSimApp->initialize(argStr.c_str(), 0, FlexSimApplication::INIT_FLAG_RUN_MESSAGE_LOOP);
             });
            bindAsync();
        }
        else {
            flexSimApp->initialize(argStr.c_str(), 0, 0);
            bindSync();
        }
    }
    else {
        flexSimApp = &FlexSimApplication::getInstance();
    }

    Py_RETURN_NONE;
}

Variant FlexSimPy::appCommand_sync(PyObject* args)
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
    return result;
}

PyObject* FlexSimPy::appCommand_sync(PyObject* self, PyObject* args, PyObject* kwargs)
{
    return PyConverter::convertToPyObject(appCommand_sync(args));
}

PyObject* FlexSimPy::appCommand_async(PyObject* self, PyObject* args, PyObject* kwargs)
{
    //const char* keywords[] = {
    //    "Async",
    //    nullptr
    //};
    //bool doAsync = false;
    //PyArg_ParseTupleAndKeywords(args, kwargs, "|p", (char**)keywords, &doAsync);
    Variant result;
    FlexSimApplication::getPlatform().callMainThreadCallback([this, args, &result]() {
        result = appCommand_sync(args);
    }, true);
    
    return PyConverter::convertToPyObject(result);
}


PyMODINIT_FUNC
PyInit_FlexSimPy(void)
{
    PyObject* m;

    FlexSimPy::inst.checkBindToLoadedApp();
    m = PyModule_Create(&FlexSimPy::flexSimPyModule);
    if (m == nullptr)
        return nullptr;

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