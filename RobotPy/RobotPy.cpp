/*
 *  PyRobot.cpp - C++ code to start Python
 *
 *  Copyright (c) 2010 Ross Light, Peter Johnson
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include "Python.h"
#include <sysLib.h>
#include <usrLib.h>
#include <taskLib.h>
#include <moduleLib.h>
#include <unldLib.h>
#include "NetworkCommunication/FRCComm.h"
#include "NetworkCommunication/symModuleLink.h"
#include "RobotPy.h"

#define ROBOTPY_BOOT "/c/py/boot.py"

extern "C" INT32
RobotPy_Run()
{
    puts("RobotPy " ROBOTPY_VERSION);

    /* Initialize the Python interpreter.  Required. */
    //Py_VerboseFlag = 2;
    Py_SetProgramName(L"./RobotPy");
    Py_SetPythonHome(L"/c/");
    Py_Initialize();
    PyEval_InitThreads();
    puts("starting " ROBOTPY_BOOT);
    if (FILE* f = fopen(ROBOTPY_BOOT, "r"))
    {
	PyObject *m = PyImport_AddModule("__main__");
	if (m == NULL)
	    goto hang;
	PyObject *d = PyModule_GetDict(m);
	if (PyDict_GetItemString(d, "__file__") == NULL) {
	    PyObject *fn;
	    fn = PyUnicode_DecodeFSDefault(ROBOTPY_BOOT);
	    if (fn == NULL)
		goto hang;
	    if (PyDict_SetItemString(d, "__file__", fn) < 0) {
		Py_DECREF(fn);
		goto hang;
	    }
	    if (PyDict_SetItemString(d, "__cached__", Py_None) < 0)
		goto hang;
	    Py_DECREF(fn);
	}
        PyObject *v = PyRun_File(f, ROBOTPY_BOOT, Py_file_input, d, d);
	fclose(f);
	if (v == NULL && PyErr_Occurred() && PyErr_ExceptionMatches(PyExc_SystemRestart))
	{
	    puts(ROBOTPY_BOOT " signaled restart");
	    Py_Finalize();
	    return 0; // will force restart at outer layer
	}
	Py_DECREF(v);
    }
    else
	puts("Could not open " ROBOTPY_BOOT);

hang:
    puts(ROBOTPY_BOOT " ended; terminating program");
    for (;;)
	sleep(5);
}

