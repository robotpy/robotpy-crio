/*
 *  LuaRobot.cpp - C++ code to start Lua
 *  FIRSTLua
 *
 *  Copyright (c) 2010 Ross Light
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
#include "WPILib.h"
#include "Python.h"

#define ROBOTPY_BOOT "py/boot.py"

class PyRobot : public RobotBase
{
public:
    PyRobot()
    {
    }
    
    virtual ~PyRobot()
    {
    }
    
protected:
    void writeMessageFile(const char *fname, const char *fmt, va_list args)
    {
    	FILE *errfile;
    	
    	errfile = fopen(fname, "w");
    	vfprintf(errfile, fmt, args);
    	fputs("\n", errfile);
    	fclose(errfile);
    }
    
    void writeMessageFile(const char *fname, const char *fmt, ...)
    {
    	va_list args;
    	
    	va_start(args, fmt);
    	writeMessageFile(fname, fmt, args);
    	va_end(args);
    }
    
    void writeError(const char *errfmt, ...)
    {
    	va_list args;
    	
    	va_start(args, errfmt);
    	writeMessageFile("boot-error.txt", errfmt, args);
    	va_end(args);
    }
    
	virtual void StartCompetition()
    {
        puts("RobotPy 2010.beta1");
    	/* Initialize the Python interpreter.  Required. */
		Py_SetProgramName(L"./RobotPy");
		Py_SetPythonHome(L"/");
		Py_Initialize();
		for (;;)
		{
			puts("starting " ROBOTPY_BOOT);
			if (FILE* f = fopen(ROBOTPY_BOOT, "r"))
			{
				PyRun_SimpleFile(f, ROBOTPY_BOOT);
				fclose(f);
			}
			else
				puts("Could not open " ROBOTPY_BOOT);
	
	    	puts(ROBOTPY_BOOT " ended; waiting 5 seconds before restart");
			Wait(5.0);
		}
		Py_Finalize();
    }
};

START_ROBOT_CLASS(PyRobot);
