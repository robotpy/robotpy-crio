%MappedType std::string
{
%TypeHeaderCode
#include <string>
%End

%ConvertFromTypeCode
	if (!sipCpp) {
		Py_INCREF(Py_None);
		return Py_None;
	}
#if PY_MAJOR_VERSION >= 3
	return PyUnicode_FromStringAndSize(sipCpp->data(), sipCpp->size());
#else
    return PyString_FromStringAndSize(sipCpp->data(), sipCpp->size());
#endif

%End

%ConvertToTypeCode
#if PY_MAJOR_VERSION >= 3
	// Allow a Python string whenever a string is expected.
	if (sipIsErr == NULL)
		return PyUnicode_Check(sipPy);
	PyObject* utf8 = PyUnicode_AsUTF8String(sipPy);
	char* buf;
	Py_ssize_t len;
	PyBytes_AsStringAndSize(utf8, &buf, &len);
	*sipCppPtr = new std::string(buf, len);
	Py_DECREF(utf8);
	return sipGetState(sipTransferObj);
#else
    // Allow a Python string whenever a string is expected.
	if (sipIsErr == NULL)
		return PyString_Check(sipPy);
	char* buf;
	Py_ssize_t len;
	PyString_AsStringAndSize(sipPy, &buf, &len);
	*sipCppPtr = new std::string(buf, len);
	return sipGetState(sipTransferObj);
#endif
%End
};
