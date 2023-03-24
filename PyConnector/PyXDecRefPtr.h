#pragma once
#include "Python.h"

class PyXDecRefPtr
{
private:
	PyObject* object = nullptr;

public:
	PyXDecRefPtr() = delete;
	PyXDecRefPtr(const PyXDecRefPtr& other) = delete;
	PyXDecRefPtr(PyObject* object) : object(object) {};
	~PyXDecRefPtr() { Py_XDECREF(object); }

	operator PyObject* () { return object; }
	PyObject* operator->() { return object; }
};