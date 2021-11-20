#pragma once
#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <thread>

#include "FlexSimApplication.h"
#include "FlexSimDefs.h"

namespace FlexSim {

extern void (*flexsimfree)(void*);

class FlexSimPy {
private:
    FlexSimApplication* flexSimApp = nullptr;
    std::thread flexSimThread;
public:
    static FlexSimPy inst;
    void checkBindToLoadedApp();
    static PyObject* s_launch(PyObject* self, PyObject* args, PyObject* kwargs) { return inst.launch(self, args, kwargs); }
    static PyObject* s_appCommand(PyObject* self, PyObject* args, PyObject* kwargs) { return (inst.*inst.appCommand)(self, args, kwargs); }
    //(app->*__initialize_ptr)(cmdLine, nCmdShow, flags);

    static const int LAUNCH_SYNCHRONOUS = 0;
    static const int LAUNCH_ASYNCHRONOUS = 1;
    //static const int LAUNCH_INTERPROCESS = 2; // not implemented
    int concurrencyType = LAUNCH_SYNCHRONOUS;

    using PyMemberFunction = PyObject * (FlexSimPy::*)(PyObject*, PyObject*);
    using PyMemberFunctionKwargs = PyObject * (FlexSimPy::*)(PyObject*, PyObject*, PyObject*);
    PyObject* launch(PyObject* self, PyObject* args, PyObject* kwargs);

    Variant appCommand_sync(PyObject* args);
    PyObject* appCommand_sync(PyObject* self, PyObject* args, PyObject* kwargs);
    PyObject* appCommand_async(PyObject* self, PyObject* args, PyObject* kwargs);
    PyMemberFunctionKwargs appCommand;

    void bindAsync() { appCommand = &FlexSimPy::appCommand_async; }
    void bindSync() { appCommand = &FlexSimPy::appCommand_sync; }


	//PyObject* find(PyObject* self, PyObject* args);
	//static PyObject* s_find(PyObject* self, PyObject* args) { return instance.find(self, args); }

	static PyMethodDef methods[];
	static PyModuleDef flexSimPyModule;
};
}