// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2010 Peter Johnson
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

%ModuleCode
#include <WPILib/Utility.h>
%End

void wpi_suspendOnAssertEnabled(bool enabled);
void wpi_stackTraceEnable(bool enabled);

UINT16 GetFPGAVersion();
UINT32 GetFPGARevision();
UINT32 GetFPGATime();
INT32 GetRIOUserSwitch();
void SetRIOUserLED(UINT32 state);
INT32 GetRIOUserLED();
INT32 ToggleRIOUserLED();
void SetRIO_FPGA_LED(UINT32 state);
INT32 GetRIO_FPGA_LED();
INT32 ToggleRIO_FPGA_LED();
