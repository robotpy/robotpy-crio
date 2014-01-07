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
#include <WPILib/NetworkCommunication/LoadOut.h>
%End

enum { kMaxModuleNumber = 2 };

namespace nLoadOut
{
    enum tModuleType {
        kModuleType_Unknown = 0x00,
        kModuleType_Analog = 0x01,
        kModuleType_Digital = 0x02,
        kModuleType_Solenoid = 0x03,
    };
    bool getModulePresence(nLoadOut::tModuleType moduleType, uint8_t moduleNumber);
    enum tTargetClass {
        kTargetClass_Unknown = 0x00,
        kTargetClass_FRC1 = 0x10,
        kTargetClass_FRC2 = 0x20,
        kTargetClass_FRC2_Analog = 0x21,
        kTargetClass_FRC2_Digital = 0x22,
        kTargetClass_FRC2_Solenoid = 0x23,
        kTargetClass_FamilyMask = 0xF0,
        kTargetClass_ModuleMask = 0x0F,
    };
    nLoadOut::tTargetClass getTargetClass();
};

uint32_t FRC_NetworkCommunication_nLoadOut_getModulePresence(uint32_t moduleType, uint8_t moduleNumber);
uint32_t FRC_NetworkCommunication_nLoadOut_getTargetClass();
