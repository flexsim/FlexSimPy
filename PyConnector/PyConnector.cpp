#include "PyConnector.h"
#include "FlexSimDefs.h"
#include "PyConverter.h"
#include "PyXDecRefPtr.h"
#include <string>
#include <codecvt>

using std::string;

namespace FlexSim {
fsvisible ObjectDataType* createodtderivative(char* classname)
{
	return NULL;
}

fsvisible SimpleDataType* createsdtderivative(char* classname)
{
	return NULL;
}

fsvisible void dllinitialize()
{

}

fsvisible void dllcleanup()
{

}


PyConnector pyConnector;
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
    if (isInitialized && !hasFlexSimPyController)
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
    return PyModule_Create(&pyConnector.consoleRedirectModule);
}

bool PyConnector::initialize()
{
#ifdef _MSC_VER
    bool isWindows = true;
#else
    bool isWindows = false;
#endif
    if (isInitialized)
        return true;

    initializedWithModelDir = modeldir();


    hasFlexSimPyController = platform.getModuleHandle(isWindows ? "FlexSimPy.pyd" : "FlexSimPy.so") != nullptr;
    if (hasFlexSimPyController) {
        // If the FlexSimPy module has already been loaded, then 
        isInitialized = true;
        return true;
    }

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


    updatePythonPathEnv();
    int x = Py_IgnoreEnvironmentFlag;
    pd(x);
    
#endif
    //PyObject* redirectModule = PyModule_Create(&consoleRedirectModule);

    int result = PyRun_SimpleString("\
import consoleredirection\n\
import sys\n\
class StdOutRedirect:\n\
    def write(self, stuff):\n\
        consoleredirection.redirectStdOut(stuff)\n\
    def flush(self):\n\
        pass\n\
class StdErrRedirect:\n\
    def write(self, stuff):\n\
        consoleredirection.redirectStdErr(stuff)\n\
    def flush(self):\n\
        pass\n\
sys.stdout = StdOutRedirect()\n\
sys.stderr = StdErrRedirect()\n");

    isInitialized = Py_IsInitialized();
    return isInitialized;
}

void PyConnector::updatePythonPathEnv()
{
    //string pPath = ".";
   // pPath.append(platform.envPathSep()).append(modeldir());
    //pPath.pop_back();
    //pPath.append(platform.envPathSep()).append(pdir()).append("python"); 
   // std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
    //std::wstring utf16NativeString = convert.from_bytes(pPath);
    //PySys_SetPath(utf16NativeString.c_str());

    PyObject* path = PySys_GetObject("path");
    if (path) {
        int length = PyList_GET_SIZE(path);
        string mDir = modeldir();
        if (!sysPathModel) {
            sysPathModel = PyUnicode_FromKindAndData(PyUnicode_1BYTE_KIND, mDir.c_str(), mDir.length());
            PyList_Insert(path, 0, sysPathModel);
        }
        else {
            Py_DECREF(sysPathModel);
            sysPathModel = PyUnicode_FromKindAndData(PyUnicode_1BYTE_KIND, mDir.c_str(), mDir.length());
            PyList_SetItem(path, 0, sysPathModel);
        }
    }

}

PyObject* PyConnector::findProc(const char* moduleName, const char* procName)
{
    if (!isInitialized) {
        if (!initialize())
            return nullptr;
    }

    auto found = importedModules.find(moduleName);
    PyObject* mod = nullptr;
    PyGILState_STATE state;
    if (pyConnector.hasFlexSimPyController)
        state = PyGILState_Ensure();
    if (found == importedModules.end()) {
        mod = PyImport_ImportModule(moduleName);
        if (mod) {
            importedModules[moduleName] = mod;
        }
        else {
            printLastPyError();
        }
    }
    else mod = found->second;

    PyObject* func = nullptr;
    if (mod) {
       func  = PyObject_GetAttrString(mod, procName);

        if (func && !PyCallable_Check(func)) {
            func = nullptr;
        }
    }
    if (pyConnector.hasFlexSimPyController)
        PyGILState_Release(state);
    return func;
}

extern "C" PY_CONNECTOR_EXPORT
PyObject * findProc(const char* moduleName, const char* procName)
{
    return pyConnector.findProc(moduleName, procName);
}


void PyConnector::printLastPyError()
{
    PyObject* pType, * pValue, * pTraceback;
    PyErr_Fetch(&pType, &pValue, &pTraceback);
    PyObject* str = pValue ? PyObject_Str(pValue) : nullptr;

    if (str != nullptr) {
        Variant val = PyConverter::convertToVariant(str);
        mpt(val.c_str()); mpr();
        Py_DECREF(str);
    }
    else {
        mpt("Unknown Python Error"); mpr();
    }
    PyErr_Restore(pType, pValue, pTraceback);
    PyErr_Clear();
}

int PyConnector::onBuildFlexScript()
{

    if (initializedWithModelDir != modeldir()) {
        clearModules();
        updatePythonPathEnv();
        initializedWithModelDir = modeldir();
    }
    else {
        reloadModules();
    }
    return 1;
}

extern "C" PY_CONNECTOR_EXPORT
int onBuildFlexScript()
{
    return pyConnector.onBuildFlexScript();
}


void PyConnector::clearModules()
{
    for (auto& mod : importedModules)
        Py_XDECREF(mod.second);

    importedModules.clear();
}

void PyConnector::reloadModules()
{
    for (auto& mod : importedModules) {
        if (mod.second) {
            auto newModule = PyImport_ReloadModule(mod.second);
            if (newModule) {
                mod.second = newModule;
            }
            else {
                printLastPyError();
            }
        }
        if (!mod.second)
            importedModules.erase(mod.first);
    }
}

PyCode::PyCode(PyObject* func) : func(func)
{
}
PyCode::~PyCode()
{
    Py_XDECREF(func);
}

Variant PyCode::evaluate(CallPoint* callPoint)
{
    int numParams = (int)parqty(callPoint);
    PyGILState_STATE state;
    if (pyConnector.hasFlexSimPyController)
        state = PyGILState_Ensure();

    PyObject* tuple = PyTuple_New(numParams);

    for (int i = 1; i <= numParams; i++) {
        PyObject* p = PyConverter::convertToPyObject(_param(i, callPoint));
        PyTuple_SetItem(tuple, (size_t)i - 1, p);
    }
    PyObject* result = PyObject_Call(func, tuple, nullptr);
    Variant returnVal;
    if (result) {
        returnVal = PyConverter::convertToVariant(result);
    }
    else {
        PyConnector::printLastPyError();
    }
    if (pyConnector.hasFlexSimPyController) {
        // releasing the GIL handles tuple/result memory
        PyGILState_Release(state);
    } else {
        // Otherwise it needs to be handled here
        Py_XDECREF(result);
        Py_XDECREF(tuple);
    }

    return returnVal;
}


CodeSDT* PyCode::bindToNode(TreeNode* t, PyObject* func)
{
    auto b = t->branch;
    if (!b) {
        llinsertbranch(t);
        b = t->branch;
    }
    PyCode* pyCode = new PyCode(func);
    b->dataType = 0;
    b->addSimpleData(pyCode, 0);
    return pyCode;
}

extern "C" PY_CONNECTOR_EXPORT
CodeSDT* bindToNode(TreeNode * t, PyObject * func)
{
    return PyCode::bindToNode(t, func);
}

}