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
#include <string.h>
#include <sysLib.h>
#include <usrLib.h>
#include <taskLib.h>
#include <taskHookLib.h>
#include <moduleLib.h>
#include <unldLib.h>
#include <semLib.h>
#include <ioLib.h>
#include <loadLib.h>
#include <symLib.h>
#include <sysSymTbl.h>
#include <errno.h>
#include <vector>
#include "pyconfig.h"
#include "NetworkCommunication/FRCComm.h"
#include "NetworkCommunication/symModuleLink.h"
#include "NetworkCommunication/UsageReporting.h"

static INT32 pythonTaskId;
SEM_ID pythonTaskEnded;
std::vector<MODULE_ID> pythonLoadedModules;
SEM_ID pythonLoadedModulesMutex;

static void
RobotTask_DeleteHook(WIND_TCB *pTcb)
{
    if (pythonTaskId == -1)
        return;
    if (((INT32)pTcb) != pythonTaskId)
        return;
    semGive(pythonTaskEnded);
}

static void
RobotModule_CreateHook(MODULE_ID moduleId)
{
    char *name = moduleNameGet(moduleId);
    if (strcmp(strrchr(name, '.'), ".pyd") != 0)
        return;
    //printf("Created module '%s'\n", name);
    semTake(pythonLoadedModulesMutex, WAIT_FOREVER);
    pythonLoadedModules.push_back(moduleId);
    semGive(pythonLoadedModulesMutex);
}

static void
RobotTask()
{
    int count = 0;
    puts("starting RobotPy");
    for (;;)
    {
        int fd = open("/c/ni-rt/system/RobotPy.out", O_RDONLY, 0644);
        MODULE_ID handle = loadModule(fd, LOAD_GLOBAL_SYMBOLS);
        close(fd);
        if (handle == NULL)
        {
            printf("Could not load RobotPy.out: %s\n", strerror(errno));
            return;
        }
        FUNCPTR robotpy_func;
        SYM_TYPE type;
        if (symFindByName(sysSymTbl, "RobotPy_Run", (char **)&robotpy_func,
                          &type) != OK)
        {
            printf("Could not find RobotPy_Run(): %s\n", strerror(errno));
            return;
        }

        pythonTaskId = taskSpawn("FRC_RobotPy", 100, VX_FP_TASK,
                                 THREAD_STACK_SIZE, robotpy_func,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        // wait here until FRC_RobotPy task dies
        semTake(pythonTaskEnded, WAIT_FOREVER);
        puts("RobotPy terminated, restarting");

        ++count;
        if (count > 100)
        {
            puts("Too many restarts, terminating");
            return;
        }

        // reload/restart
        semTake(pythonLoadedModulesMutex, WAIT_FOREVER);
        for (std::vector<MODULE_ID>::iterator i = pythonLoadedModules.begin(),
             end = pythonLoadedModules.end(); i != end; ++i)
        {
            if (unldByModuleId(*i, 0) != OK)
            {
                printf("Could not unload '%s': %s\n", moduleNameGet(*i),
                       strerror(errno));
            }
        }
        pythonLoadedModules.clear();
        semGive(pythonLoadedModulesMutex);
        if (unldByModuleId(handle, 0) != OK)
        {
            printf("Could not unload RobotPy.out: %s\n", strerror(errno));
            return;
        }
    }
}

INT32 robotTaskId = -1;

extern "C" INT32
FRC_UserProgram_StartupLibraryInit()
{
    puts("starting FRC_UserProgram");

    pythonTaskId = -1;
    pythonTaskEnded = semBCreate(SEM_Q_FIFO, SEM_EMPTY);
    pythonLoadedModulesMutex = semBCreate(SEM_Q_PRIORITY, SEM_FULL);
    taskHookInit();
    taskDeleteHookAdd((FUNCPTR)RobotTask_DeleteHook);
    moduleCreateHookAdd((FUNCPTR)RobotModule_CreateHook);

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

    // Let the FMS know we're running Python.
    FRC_NetworkCommunication_nUsageReporting_report(
        nUsageReporting::kResourceType_Language,
        nUsageReporting::kLanguage_Python, 0, 0);

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
        taskDeleteHookDelete((FUNCPTR)RobotTask_DeleteHook);
        moduleCreateHookDelete((FUNCPTR)RobotModule_CreateHook);
        if (robotTaskId != -1)
        {
            taskDelete(robotTaskId);
            robotTaskId = -1;
        }
    }
};

static RobotTaskDeleter g_robotTaskDeleter;

