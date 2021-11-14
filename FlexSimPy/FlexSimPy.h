#define PY_SSIZE_T_CLEAN
#include "Python.h"

class FlexSimPy {
public:
	static PyObject* launch(PyObject* self, PyObject* args, PyObject* kwargs);
	//PyObject* find(PyObject* self, PyObject* args);
	//static PyObject* s_find(PyObject* self, PyObject* args) { return instance.find(self, args); }

	static PyMethodDef methods[];
	static PyModuleDef flexSimPyModule;
};
extern FlexSimPy flexSimPy;