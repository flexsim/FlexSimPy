#include "PyConverter.h"
#include <string>
#include <codecvt>

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
        std::string utf8Str;
        switch (PyUnicode_KIND(obj)) {
            case PyUnicode_2BYTE_KIND:
            {
                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> convert;
                utf8Str = convert.to_bytes((wchar_t*)PyUnicode_2BYTE_DATA(obj));
                break;
            }
            case PyUnicode_1BYTE_KIND: {
                utf8Str = (const char*)PyUnicode_1BYTE_DATA(obj);
                break;
            }
        }

        return utf8Str.c_str();
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
