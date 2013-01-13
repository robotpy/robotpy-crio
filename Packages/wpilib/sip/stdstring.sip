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
	return PyUnicode_FromStringAndSize(sipCpp->data(), sipCpp->size());
%End

%ConvertToTypeCode
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
%End
};
