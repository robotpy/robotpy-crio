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

char *wpi_getLabel(unsigned int addr, int32_t *found = 0);
void wpi_selfTrace();
void wpi_suspendOnAssertEnabled(bool enabled);
void wpi_stackTraceOnAssertEnable(bool enabled);

uint16_t GetFPGAVersion();
uint32_t GetFPGARevision();
uint32_t GetFPGATime();
int32_t GetRIOUserSwitch();
void SetRIOUserLED(uint32_t state);
int32_t GetRIOUserLED();
int32_t ToggleRIOUserLED();
void SetRIO_FPGA_LED(uint32_t state);
int32_t GetRIO_FPGA_LED();
int32_t ToggleRIO_FPGA_LED();
