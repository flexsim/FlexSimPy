#pragma once
#include "Python.h"

class PyXDecRefPtr
{
private:
	PyObject* object = nullptr;

public:
	PyXDecRefPtr() = delete;
	PyXDecRefPtr(const PyXDecRefPtr& other) = delete;
	explicit PyXDecRefPtr(PyObject* object) : object(object) {}

	~PyXDecRefPtr() { Py_XDECREF(object); }

	PyObject* release() noexcept
	{
		PyObject* tmp = object;
		object = nullptr;
		return tmp;
	}

	PyObject* get() const noexcept { return object; }

	operator PyObject*() const { return object; }
	PyObject* operator->() const { return object; }
};