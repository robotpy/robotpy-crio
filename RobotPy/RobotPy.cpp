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
