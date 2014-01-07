// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2011 Peter Johnson
// 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

%ModuleHeaderCode
#include <WPILib/NetworkCommunication/FRCComm.h>
%End

void getFPGAHardwareVersion(uint16_t *fpgaVersion /Out/, uint32_t *fpgaRevision /Out/);
//int getCommonControlData(FRCCommonControlData *data /Out/, int wait_ms);
//int getRecentCommonControlData(FRCCommonControlData *commonData /Out/, int wait_ms);
int getRecentStatusData(uint8_t *batteryInt /Out/, uint8_t *batteryDec /Out/, uint8_t *dsDigitalOut /Out/, int wait_ms);
//int getDynamicControlData(uint8_t type, char *dynamicData, int32_t maxLength, int wait_ms);
int setStatusData(float battery, uint8_t dsDigitalOut, uint8_t updateNumber,
		const char *userDataHigh, int userDataHighLength,
		const char *userDataLow, int userDataLowLength, int wait_ms);
int setErrorData(const char *errors, int errorsLength, int wait_ms);
int setUserDsLcdData(const char *userDsLcdData, int userDsLcdDataLength, int wait_ms);
int overrideIOConfig(const char *ioConfig, int wait_ms);

void setNewDataSem(SEM_ID);
void setResyncSem(SEM_ID);
void signalResyncActionDone();

// this uint32_t is really a LVRefNum
void setNewDataOccurRef(uint32_t refnum);
void setResyncOccurRef(uint32_t refnum);

//void FRC_NetworkCommunication_getVersionString(char *version /Out/);
void FRC_NetworkCommunication_observeUserProgramStarting();
void FRC_NetworkCommunication_observeUserProgramDisabled();
void FRC_NetworkCommunication_observeUserProgramAutonomous();
void FRC_NetworkCommunication_observeUserProgramTeleop();
void FRC_NetworkCommunication_observeUserProgramTest();
