#include "FlexSimPy.h"

PyMethodDef FlexSimPy::methods[] = {
    {"launch",  launch, METH_KEYWORDS, "Launch a new instance of FlexSim."},
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

PyMODINIT_FUNC
PyInit_FlexSimPy(void)
{
    PyObject* m;

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

PyObject* FlexSimPy::launch(PyObject* self, PyObject* args, PyObject* kwargs)
{
    char* keywords[] = {
        "Async",
        "DllPath",
        nullptr
    };
    int doAsync = true;
    const char* dllPath = "C:\\Program Files\\FlexSim22\\program\\flexsim.dll";
    PyArg_ParseTupleAndKeywords(args, kwargs, "|ps", keywords, &doAsync, &dllPath);
    return nullptr;
}
