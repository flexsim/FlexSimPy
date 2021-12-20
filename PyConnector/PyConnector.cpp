#include "PyConnector.h"
#include "FlexSimDefs.h"
#include "PyConverter.h"
#include <string>

using std::string;

namespace FlexSim {
visible ObjectDataType* createodtderivative(char* classname)
{
	return NULL;
}

visible SimpleDataType* createsdtderivative(char* classname)
{
	return NULL;
}

visible void dllinitialize()
{

}

visible void dllcleanup()
{

}


PyConnector flexSimPy;
const char* PyCode::s_classFactory = "PyCode";
PyMethodDef PyConnector::consoleRedirectModuleFuncs[] = {
    {"redirectStdOut",  redirectStdOut, METH_VARARGS,  "Redirect stdout to FlexSim"},
    {"redirectStdErr",  redirectStdErr, METH_VARARGS,  "Redirect stderr to FlexSim"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
PyModuleDef PyConnector::consoleRedirectModule = {
    PyModuleDef_HEAD_INIT,
    "consoleredirection",   /* name of module */
    nullptr, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    consoleRedirectModuleFuncs
};

PyConnector::~PyConnector()
{
    if (isInitialized)
        Py_Finalize();
}

PyObject* PyConnector::redirectStdOut(PyObject* self, PyObject* args)
{
    const char* string;
    if (!PyArg_ParseTuple(args, "s", &string))
        return nullptr;
    pt(string);
    //pass string onto somewhere
    Py_INCREF(Py_None);
    return Py_None;
}
PyObject* PyConnector::redirectStdErr(PyObject* self, PyObject* args)
{
    const char* string;
    if (!PyArg_ParseTuple(args, "s", &string))
        return nullptr;
    EX("", string, 1);
    //pass string onto somewhere
    Py_INCREF(Py_None);
    return Py_None;
}


PyMODINIT_FUNC PyInit_consoleredirection(void)
{
    return PyModule_Create(&flexSimPy.consoleRedirectModule);
}

bool PyConnector::initialize()
{
    if (isInitialized)
        return true;

    initializedWithModelDir = modeldir();

    string pPath = modeldir() + platform.envPathSep() + pdir() + "python";
    hasFlexSimPyController = platform.getLibrary("FlexSimPy") != nullptr;
    if (hasFlexSimPyController) {
        // If the FlexSimPy module has already been loaded, then 
        isInitialized = true;
        return true;
    }


    platform.setEnv("PYTHONPATH", pPath.c_str());
#if 0
    PyStatus status;

    PyConfig config;
    PyConfig_InitPythonConfig(&config);
    ScopeGuard configGuard([&]() {PyConfig_Clear(&config); });

    /* Set the program name. Implicitly preinitialize Python. */
    //status = PyConfig_SetString(&config, &config.home, nowide::widen(directories.modelDir).c_str());
    //std::string modelDir = modeldir();
    //std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;

    //status = PyConfig_SetString(&config, &config.pythonpath_env, convert.from_bytes(modelDir).c_str());
    //platform.setEnv("__PYVENV_LAUNCHER__", "C:\\Program Files (x86)\\Microsoft Visual Studio\\Shared\\Python37_64\\python.exe");
    //status = PyConfig_SetString(&config, &config.executable, L);
    //if (PyStatus_Exception(status))
       // return false;

#endif

    if (PyImport_AppendInittab("consoleredirection", PyInit_consoleredirection) == -1)
        return false;

#if 0
    status = Py_InitializeFromConfig(&config);
    if (PyStatus_Exception(status))
        return false;
#else
    Py_Initialize();
#endif
    //PyObject* redirectModule = PyModule_Create(&consoleRedirectModule);

    int result = PyRun_SimpleString("\
import consoleredirection\n\
import sys\n\
class StdOutRedirect:\n\
    def write(self, stuff):\n\
        consoleredirection.redirectStdOut(stuff)\n\
class StdErrRedirect:\n\
    def write(self, stuff):\n\
        consoleredirection.redirectStdErr(stuff)\n\
sys.stdout = StdOutRedirect()\n\
sys.stderr = StdErrRedirect()\n");

    isInitialized = true;
    return true;
}

PyObject* PyConnector::findProc(const char* moduleName, const char* procName)
{
    if (!isInitialized) {
        if (!initialize())
            return nullptr;
    }

    bool reInitByExecutive = false;

    if (initializedWithModelDir != modeldir()) {
        clearModules();
    }
    else if (reInitByExecutive) {
        reloadModules();
    }

    if (importedModules.find(moduleName) == importedModules.end()) {
        auto mod = PyImport_ImportModule(moduleName);
        importedModules[moduleName] = mod;
    }

    PyObject* mod = importedModules[moduleName];

    if (mod) {
        PyObject* func = PyObject_GetAttrString(mod, procName);

        if (func && PyCallable_Check(func)) {
            return func;
        }
    }
    return nullptr;
}

extern "C" PY_CONNECTOR_EXPORT
PyObject * FlexSimPy_findProc(const char* moduleName, const char* procName)
{
    return flexSimPy.findProc(moduleName, procName);
}

void PyConnector::clearModules()
{
    for (auto& boundNode : boundNodes) {
        if (boundNode)
            boundNode->dataType = 0;
    }
    for (auto& mod : importedModules)
        Py_XDECREF(mod.second);

    importedModules.clear();
}

void PyConnector::reloadModules()
{
    for (auto& boundNode : boundNodes) {
        if (boundNode)
            boundNode->dataType = 0;
    }
    for (auto& mod : importedModules)
        mod.second = PyImport_ReloadModule(mod.second);
}

PyCode::PyCode(PyObject* func) : func(func)
{
#ifdef FLEXSIM_EXECUTIVE
    resetCount = Executive::instance.resetCount;
#endif
}
PyCode::~PyCode()
{
    Py_XDECREF(func);
}

Variant PyCode::evaluate(CallPoint* callPoint)
{
#ifdef FLEXSIM_EXECUTIVE
    if (resetCount != Executive::instance.resetCount) {
        TreeNode* evalNode = holder->up;
        flexSimPy.reloadModules();
        return evalNode->callMemberFunction(0, callPoint->theinstance, callPoint->theclass, nullptr, nullptr, callPoint->involved, callPoint);
    }
#endif
    int numParams = parqty(callPoint);
    PyObject* tuple = PyTuple_New(numParams);
    for (int i = 1; i <= numParams; i++) {
        PyObject* p = PyConverter::convertToPyObject(_param(i, callPoint));
        PyTuple_SetItem(tuple, (size_t)i - 1, p);
    }
    PyObject* result = PyObject_Call(func, tuple, nullptr);
    if (result) {
        Variant returnVal = PyConverter::convertToVariant(result);
        Py_XDECREF(result);
        return returnVal;
    }
    return Variant();
}


void PyCode::bindToNode(TreeNode* t, PyObject* func)
{
    auto b = t->branch;
    if (!b) {
        llinsertbranch(t);
        b = t->branch;
    }
    PyCode* pyCode = new PyCode(func);
    b->dataType = 0;
    b->addSimpleData(pyCode, 0);
    flexSimPy.boundNodes.insert(b);
}

extern "C" PY_CONNECTOR_EXPORT
void PyCode_bindToNode(TreeNode * t, PyObject * func)
{
    PyCode::bindToNode(t, func);
}


PyCode* PyCode::getCode(TreeNode* t)
{
    TreeNode* branch = t->branch;
    if (!branch)
        return nullptr;

    if (branch->dataType != DATA_SIMPLE)
        return nullptr;

    SimpleDataType* sdt = branch->object<SimpleDataType>();
    if (sdt->getClassFactory() != s_classFactory)
        return nullptr;

    return (PyCode*)sdt;
}
extern "C" PY_CONNECTOR_EXPORT
PyCode * PyCode_getCode(TreeNode * t)
{
    return PyCode::getCode(t);
}
}