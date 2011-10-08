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
	*sipCppPtr = new std::string(PyByteArray_AS_STRING(utf8),
		PyByteArray_GET_SIZE(utf8));
	Py_DECREF(utf8);
	return sipGetState(sipTransferObj);
%End
};
