#include "FlexSimPy.h"
#include "FlexSimDefs.h"
#include "PyConnector.h"
#include <vector>
//#include "FileUtils.h"
#include <codecvt>

#include "ScopeGuard.h"
//#include "CallPoint.h"


namespace FlexSim {

FlexSimPy flexSimPy;
const char* PyCode::s_classFactory = "PyCode";
PyMethodDef FlexSimPy::consoleRedirectModuleFuncs[] = {
    {"redirectStdOut",  redirectStdOut, METH_VARARGS,  "Redirect stdout to FlexSim"},
    {"redirectStdErr",  redirectStdErr, METH_VARARGS,  "Redirect stderr to FlexSim"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
PyModuleDef FlexSimPy::consoleRedirectModule = {
    PyModuleDef_HEAD_INIT,
    "consoleredirection",   /* name of module */
    nullptr, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    consoleRedirectModuleFuncs
};

FlexSimPy::~FlexSimPy()
{
    if (isInitialized)
        Py_Finalize();
}

PyObject* FlexSimPy::redirectStdOut(PyObject* self, PyObject* args)
{
    const char* string;
    if (!PyArg_ParseTuple(args, "s", &string))
        return nullptr;
    pt(string);
    //pass string onto somewhere
    Py_INCREF(Py_None);
    return Py_None;
}
PyObject* FlexSimPy::redirectStdErr(PyObject* self, PyObject* args)
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

bool FlexSimPy::initialize()
{
    if (isInitialized)
        return true;

    string pPath = modeldir() + platform.envPathSep() + pdir() + "python";

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

    initializedWithModelDir = modeldir();
    isInitialized = true;
#ifdef FLEXSIM_EXECUTIVE
    importedWithResetCount = Executive::instance.resetCount;
#endif
    return true;
}

PyObject* FlexSimPy::findProc(const char* moduleName, const char* procName)
{
    if (!isInitialized) {
        if (!initialize())
            return nullptr;
    }

    bool reInitByExecutive = false;
#ifdef FLEXSIM_EXECUTIVE
    reInitByExecutive = importedWithResetCount != Executive::instance.resetCount;
    importedWithResetCount = Executive::instance.resetCount;
#endif

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

void FlexSimPy::clearModules()
{
    for (auto& boundNode : boundNodes) {
        if (boundNode)
            boundNode->dataType = 0;
    }
    for (auto& mod : importedModules)
        Py_XDECREF(mod.second);

    importedModules.clear();
}

void FlexSimPy::reloadModules()
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
        PyObject* p = convertToPyObject(_param(i, callPoint));
        PyTuple_SetItem(tuple, (size_t)i - 1, p);
    }
    PyObject* result = PyObject_Call(func, tuple, nullptr);
    if (result) {
        Variant returnVal = convertToVariant(result);
        Py_XDECREF(result);
        return returnVal;
    }
    return Variant();
}

PyObject* PyCode::convertToPyObject(const Variant& v)
{
    switch (v.type) {
        case VariantType::String:
            return PyUnicode_FromString(v.c_str());
            break;
        case VariantType::Number:
            return PyFloat_FromDouble((double)v);
        case VariantType::Array: {
            Array a = v;
            int len = a.length;
            PyObject* list = PyList_New(len);
            for (int i = 1; i <= len; i++) {
                PyObject* obj = convertToPyObject(a[i]);
                PyList_SetItem(list, i - 1, obj);
            }
            return list;
            break;
        }
        case VariantType::Map: {
            Map m = v;
            PyObject* dict = PyDict_New();
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                PyObject* key = convertToPyObject(iter.key);
                PyObject* value = convertToPyObject(iter.value);
                PyDict_SetItem(dict, key, value);
            }
            return dict;
        }
        default: {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    return Py_None;
}

Variant PyCode::convertToVariant(PyObject* obj)
{
    Variant result;
    if (PyUnicode_Check(obj)) {
        PyObject* src = obj;
        size_t size = PyUnicode_GET_LENGTH(obj); 
        int type = PyUnicode_KIND(obj);
        if (type != PyUnicode_1BYTE_KIND) {
            src = PyUnicode_AsUTF8String(obj);
        }
        const unsigned char* srcBytes = (const unsigned char*)PyUnicode_DATA(src);
        std::vector<unsigned char> destBytes;
        destBytes.resize(4 * size + 1);
        unsigned char* dest = destBytes.data();
        size_t lengthRead = 0;
        while (lengthRead < size) {
            int codePointLength = 1;
            unsigned char leadChar = *srcBytes;
            if ((leadChar & ~0x7f) != 0) {
                if (leadChar <= 0xc0)
                    codePointLength = 2;
                else if (leadChar <= 0xd0)
                    codePointLength = 3;
                else
                    codePointLength = 4;
            }
            for (int i = 0; i < codePointLength; i++)
                *dest++ = *srcBytes++;
            lengthRead += codePointLength;
        }
        *dest = 0;
        if (src != obj)
            Py_XDECREF(src);

        return (char*)destBytes.data();
    }
    else if (PyFloat_Check(obj)) {
        return PyFloat_AsDouble(obj);
    }
    else if (PyLong_Check(obj)) {
        return (double)PyLong_AsLong(obj);
    }
    else if (PyBool_Check(obj)) {
        return (double)(int)(obj == Py_True);
    }
    else if (PyList_Check(obj)) {
        Array result;
        size_t length = PyList_GET_SIZE(obj);
        for (size_t i = 0; i < length; i++) {
            PyObject* element = PyList_GetItem(obj, i);
            result.push(convertToVariant(element));
        }
    }
    else if (PyTuple_Check(obj)) {
        Array result;
        size_t length = PyTuple_GET_SIZE(obj);
        for (size_t i = 0; i < length; i++) {
            PyObject* element = PyTuple_GetItem(obj, i);
            result.push(convertToVariant(element));
        }
        return result;
    }
    else if (PyDict_Check(obj)) {
        Map result;
        PyObject* key = nullptr, * value = nullptr;
        Py_ssize_t pos = 0;
        while (PyDict_Next(obj, &pos, &key, &value)) {
            result[convertToVariant(key)] = convertToVariant(value);
        }
        return result;
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
void PyCode_bindToNode(TreeNode* t, PyObject* func)
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