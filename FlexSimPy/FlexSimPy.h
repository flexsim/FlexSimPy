#pragma once
#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <thread>

#include "FlexSimApplication.h"
#include "FlexSimDefs.h"

namespace FlexSim {

struct Controller {
    PyObject_HEAD

    static const int LAUNCH_SYNCHRONOUS = 0;
    static const int LAUNCH_ASYNCHRONOUS = 1;
    //static const int LAUNCH_INTERPROCESS = 2; // not implemented
    int concurrencyType = LAUNCH_ASYNCHRONOUS;
    std::thread flexSimThread;
    std::mutex awaitMutex;
    std::condition_variable awaitCondition;
    PyObject* awaitValue = nullptr;
    std::mutex yieldMutex;
    std::condition_variable yieldCondition;
    PyObject* yieldValue = nullptr;

    static PyObject* __new__(PyTypeObject* self, PyObject* args, PyObject* kwargs);
    static int __init__(PyObject* self, PyObject* args, PyObject* kwargs);
    static void deallocate(Controller* self);
    static PyMethodDef methods[];

    treenode findParameter(const char* name, bool isPerformanceMeasure);
    PyObject* appCommand(PyObject* args);
    PyObject* open(PyObject* args);
    PyObject* reset(PyObject* args);
    PyObject* run(PyObject* args);
    PyObject* stop(PyObject* args);
    PyObject* getParameter(PyObject* args);
    PyObject* setParameter(PyObject* args);
    PyObject* getPerformanceMeasure(PyObject* args);
    PyObject* time(PyObject* args);
    PyObject* execString(PyObject* args);
    PyObject* yield(PyObject* args);
    PyObject* await(PyObject* args);

    template <class Callback>
    PyObject* callMethod(PyObject* args, Callback callback) {
        if (concurrencyType == LAUNCH_SYNCHRONOUS)
            return callback(args);
        else {
            PyObject* result = nullptr;
            Py_BEGIN_ALLOW_THREADS
            FlexSimApplication::getPlatform().callMainThreadCallback([args, &result, &callback]() {
                PyGILState_STATE gstate;
                gstate = PyGILState_Ensure();
                result = callback(args);
                PyGILState_Release(gstate);
            }, true);
            Py_END_ALLOW_THREADS
            return result;
        }
    }

    static PyObject* s_appCommand(Controller* self, PyObject* args) 
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->appCommand(args); }); }
    static PyObject* s_open(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->open(args); }); }
    static PyObject* s_reset(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->reset(args); }); }
    static PyObject* s_run(Controller* self, PyObject* args) 
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->run(args); }); }
    static PyObject* s_stop(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->stop(args); }); }
    static PyObject* s_getParameter(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->getParameter(args); }); }
    static PyObject* s_setParameter(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->setParameter(args); }); }
    static PyObject* s_getPerformanceMeasure(Controller* self, PyObject* args) 
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->getPerformanceMeasure(args); }); }
    static PyObject* s_time(Controller* self, PyObject* args) 
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->time(args); }); }
    static PyObject* s_execString(Controller* self, PyObject* args) 
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->execString(args); }); }
    static PyObject* s_yield(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->yield(args); }); }
    static PyObject* s_await(Controller* self, PyObject* args)
        { return self->callMethod(args, [self](PyObject* args) -> PyObject* {return self->await(args); }); }
};


struct PyTreeNode {
    PyObject_HEAD
    NodeRef ref;
    Controller* controller;
    static void deallocate(PyTreeNode* self);
    static PyMethodDef methods[];
};


class FlexSimPy {
private:
    FlexSimApplication* flexSimApp = nullptr;
    Controller* inProcessController = nullptr;
public:
    static FlexSimPy inst;
    ~FlexSimPy();
    
    /// <summary>Check if the flexsim dll has already been loaded</summary>
      /// <remarks>This is called when the FlexSimPy module is initially loaded. If the FlexSimPy module is loaded 
      /// as the result of evaluating a FlexSim node, then the flexsim dll will already have been loaded, so I 
      /// don't want to load it again.</remarks>
    void checkBindToLoadedApp();

    PyObject* launch(PyObject* self, PyObject* args, PyObject* kwargs);
    static PyObject* s_launch(PyObject* self, PyObject* args, PyObject* kwargs) { return inst.launch(self, args, kwargs); }

    PyObject* yield(PyObject* args);
    static PyObject* s_yield(PyObject* self, PyObject* args, PyObject* kwargs) { return inst.yield(args); }
    PyObject* await(PyObject* args);
    static PyObject* s_await(PyObject* self, PyObject* args, PyObject* kwargs) { return inst.await(args); }


	//PyObject* find(PyObject* self, PyObject* args);
	//static PyObject* s_find(PyObject* self, PyObject* args) { return instance.find(self, args); }

	static PyMethodDef methods[];
	static PyModuleDef flexSimPyModule;
    static PyTypeObject Controller_Type;
    static PyTypeObject PyTreeNode_Type;
};
}