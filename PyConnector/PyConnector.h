#pragma once

#ifdef _WINDOWS
#define PY_CONNECTOR_EXPORT __declspec(dllexport)
#else
#define PY_CONNECTOR_EXPORT
#endif

#include "BasicClasses.h"
#include "CodeSDT.h"
#include <string>
#include <map>
#include <set>
#include "Python.h"

namespace FlexSim {
class PyConnector {
public:
    ~PyConnector();

private:
    friend class PyCode;
    bool isInitialized = false;
    std::string initializedWithModelDir;
    PyObject* sysPathModel = nullptr;
    std::map<std::string, PyObject*> importedModules;

    bool hasFlexSimPyController = false;
    bool initialize();
    void updatePythonPathEnv();


    void clearModules(); // completely clears all imported modules (i.e. when a new model is opened)
    void reloadModules(); // reloads all modules (e.g. after a reset)
public:
    static PyObject* redirectStdOut(PyObject* self, PyObject* args);
    static PyObject* redirectStdErr(PyObject* self, PyObject* args);
    static PyMethodDef consoleRedirectModuleFuncs[];
    static PyModuleDef consoleRedirectModule;
    PyObject* findProc(const char* moduleName, const char* procName);
    void printLastPyError();
    int onBuildFlexScript();
};

class PyCode : public CodeSDT {
    PyObject* func = nullptr;
public:
    static const char* s_classFactory;
    virtual const char* getClassFactory() override { return s_classFactory; }
    PyCode(PyObject* func);
    PyCode() {}
    virtual ~PyCode();
    virtual Variant evaluate(CallPoint* callPoint) override;
    static CodeSDT* bindToNode(TreeNode* x, PyObject* func);
    virtual bool isConnected() override { return func != nullptr; }
};

extern PyConnector pyConnector;

}