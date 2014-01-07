// This file is part of the RobotPy wpilib package.
//
// Copyright (c) 2013 Peter Johnson
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

class HiTechnicColorSensor : SensorBase
{
%TypeHeaderCode
#include <WPILib/HiTechnicColorSensor.h>
%End

public:
	enum tColorMode {kActive = 0, kPassive = 1, kRaw = 3};
	struct RGB {
		uint16_t red;
		uint16_t blue;
		uint16_t green;
	};
	explicit HiTechnicColorSensor(uint8_t moduleNumber);
	virtual ~HiTechnicColorSensor();
	uint8_t GetColor();
	uint8_t GetRed();
	uint8_t GetGreen();
	uint8_t GetBlue();
	RGB GetRGB();
	uint16_t GetRawRed();
	uint16_t GetRawGreen();
	uint16_t GetRawBlue();
	RGB GetRawRGB();
	void SetMode(tColorMode mode);
};
