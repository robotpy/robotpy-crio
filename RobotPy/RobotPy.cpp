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

#define ROBOTPY_BOOT "/c/py/boot.py"

static void
RobotTask()
{
	/* Initialize the Python interpreter.  Required. */
	//Py_VerboseFlag = 2;
	Py_SetProgramName(L"./RobotPy");
	Py_SetPythonHome(L"/c/");
	PyEval_InitThreads();
	Py_Initialize();
	puts("starting " ROBOTPY_BOOT);
	if (FILE* f = fopen(ROBOTPY_BOOT, "r"))
	{
		PyRun_SimpleFile(f, ROBOTPY_BOOT);
		fclose(f);
	}
	else
		puts("Could not open " ROBOTPY_BOOT);

	puts(ROBOTPY_BOOT " ended; terminating program");
	Py_Finalize();
}

INT32 robotTaskId = -1;

extern "C" INT32
FRC_UserProgram_StartupLibraryInit()
{
	puts("RobotPy 2011.beta1");
	// Check for startup code already running
	INT32 oldId = taskNameToId("FRC_RobotTask");
	if (oldId != ERROR)
	{
		// Find the startup code module.
		char moduleName[256];
		moduleNameFindBySymbolName("FRC_UserProgram_StartupLibraryInit", moduleName);
		MODULE_ID startupModId = moduleFindByName(moduleName);
		if (startupModId != NULL)
		{
			// Remove the startup code.
			unldByModuleId(startupModId, 0);
			printf("!!!   Error: Default code was still running... It was unloaded for you... Please try again.\n");
			return 0;
		}
		// This case should no longer get hit.
		printf("!!!   Error: Other robot code is still running... Unload it and then try again.\n");
		return 0;
	}

	// Let the framework know that we are starting a new user program so the Driver Station can disable.
	FRC_NetworkCommunication_observeUserProgramStarting();

	// Start robot task
	// This is done to ensure that the C++ robot task is spawned with the floating point
	// context save parameter.
	robotTaskId = taskSpawn("FRC_RobotTask", 100, VX_FP_TASK, THREAD_STACK_SIZE,
				(FUNCPTR)RobotTask, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	if (robotTaskId == ERROR)
		printf("error starting robot task: %s\n", strerror(errno));

	return 0;
}

class RobotTaskDeleter
{
public:
	RobotTaskDeleter() {}
	~RobotTaskDeleter() {
		if (robotTaskId != -1)
		{
			taskDelete(robotTaskId);
			robotTaskId = -1;
		}
	}
};

static RobotTaskDeleter g_robotTaskDeleter;

