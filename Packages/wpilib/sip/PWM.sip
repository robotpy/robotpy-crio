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

class PWM : SensorBase
{
%TypeHeaderCode
#include <WPILib/PWM.h>
%End

public:
	enum PeriodMultiplier {kPeriodMultiplier_1X = 1, kPeriodMultiplier_2X = 2, kPeriodMultiplier_4X = 4};

	explicit PWM(uint32_t channel);
	PWM(uint8_t moduleNumber, uint32_t channel);
	virtual ~PWM();
	virtual void SetRaw(uint8_t value);
	virtual uint8_t GetRaw();
	void SetPeriodMultiplier(PeriodMultiplier mult);
	void EnableDeadbandElimination(bool eliminateDeadband);
	void SetBounds(int32_t max, int32_t deadbandMax, int32_t center, int32_t deadbandMin, int32_t min);
	void SetBounds(double max, double deadBandMax, double center, double deadbandMin, double min);

protected:
	//virtual void SetPosition(float pos);
	//virtual float GetPosition();
	//virtual void SetSpeed(float speed);
	//virtual float GetSpeed();
};
