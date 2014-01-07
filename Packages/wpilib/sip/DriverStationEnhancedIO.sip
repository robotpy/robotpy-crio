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

class DriverStationEnhancedIO : ErrorBase
{
%TypeHeaderCode
#include <WPILib/DriverStationEnhancedIO.h>
%End

public:
	enum tDigitalConfig {kUnknown, kInputFloating, kInputPullUp, kInputPullDown, kOutput, kPWM, kAnalogComparator};
	enum tAccelChannel {kAccelX = 0, kAccelY = 1, kAccelZ = 2};
	enum tPWMPeriodChannels {kPWMChannels1and2, kPWMChannels3and4};

	double GetAcceleration(tAccelChannel channel);
	double GetAnalogIn(uint32_t channel);
	double GetAnalogInRatio(uint32_t channel);
	double GetAnalogOut(uint32_t channel);
	void SetAnalogOut(uint32_t channel, double value);
	bool GetButton(uint32_t channel);
	uint8_t GetButtons();
	void SetLED(uint32_t channel, bool value);
	void SetLEDs(uint8_t value);
	bool GetDigital(uint32_t channel);
	uint16_t GetDigitals();
	void SetDigitalOutput(uint32_t channel, bool value);
	tDigitalConfig GetDigitalConfig(uint32_t channel);
	void SetDigitalConfig(uint32_t channel, tDigitalConfig config);
	double GetPWMPeriod(tPWMPeriodChannels channels);
	void SetPWMPeriod(tPWMPeriodChannels channels, double period);
	bool GetFixedDigitalOutput(uint32_t channel);
	void SetFixedDigitalOutput(uint32_t channel, bool value);
	int16_t GetEncoder(uint32_t encoderNumber);
	void ResetEncoder(uint32_t encoderNumber);
	bool GetEncoderIndexEnable(uint32_t encoderNumber);
	void SetEncoderIndexEnable(uint32_t encoderNumber, bool enable);
	double GetTouchSlider();
	double GetPWMOutput(uint32_t channel);
	void SetPWMOutput(uint32_t channel, double value);
	uint8_t GetFirmwareVersion();

private:
	DriverStationEnhancedIO();
	virtual ~DriverStationEnhancedIO();
};
