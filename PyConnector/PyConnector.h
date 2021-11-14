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
#ifdef _DEBUG
#undef _DEBUG
#include "Python.h"
#define _DEBUG
#else
#include "Python.h"
#endif

namespace FlexSim {
class PyConnector {
public:
    ~PyConnector();

private:
    friend class PyCode;
    bool isInitialized = false;
    std::string initializedWithModelDir;
    size_t importedWithResetCount = 0;
    std::map<std::string, PyObject*> importedModules;
    std::set<NodeRef> boundNodes;
    bool initialize();


    void clearModules(); // completely clears all imported modules (i.e. when a new model is opened)
    void reloadModules(); // reloads all modules (e.g. after a reset)
public:
    static PyObject* redirectStdOut(PyObject* self, PyObject* args);
    static PyObject* redirectStdErr(PyObject* self, PyObject* args);
    static PyMethodDef consoleRedirectModuleFuncs[];
    static PyModuleDef consoleRedirectModule;
    PyObject* findProc(const char* moduleName, const char* procName);
};

class PyCode : public CodeSDT {
    PyObject* func = nullptr;
    int resetCount = 0;
    static PyObject* convertToPyObject(const Variant& v);
    static Variant convertToVariant(PyObject* obj);
public:
    static const char* s_classFactory;
    virtual const char* getClassFactory() override { return s_classFactory; }
    PyCode(PyObject* func);
    PyCode() {}
    virtual ~PyCode();
    virtual Variant evaluate(CallPoint* callPoint) override;
    static void bindToNode(TreeNode* x, PyObject* func);
    static PyCode* getCode(TreeNode* x);
    virtual bool isConnected() override { return func != nullptr; }
};

extern PyConnector flexSimPy;

}