#include "PyConverter.h"


PyObject* PyConverter::convertToPyObject(const Variant& v)
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

Variant PyConverter::convertToVariant(PyObject* obj)
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

Array PyConverter::convertTupleToArray(PyObject* obj)
{
    if (!PyTuple_Check(obj))
        return Array();

    Array result;
    int num = PyTuple_Size(obj);
    for (int i = 0; i < num; i++) {
        result.push(convertToVariant(PyTuple_GetItem(obj, i)));
    }
    return result;
}
