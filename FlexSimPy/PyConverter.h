#pragma once
#include "Python.h"
#include "FlexSimDefs.h"

class PyConverter {
public:
    static PyObject* convertToPyObject(const Variant& v);
    static Variant convertToVariant(PyObject* obj);
    static Array convertTupleToArray(PyObject* obj);
};