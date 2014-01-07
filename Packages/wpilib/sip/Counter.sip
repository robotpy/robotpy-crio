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

class Counter : SensorBase, CounterBase
{
%TypeHeaderCode
#include <WPILib/Counter.h>
%End

public:
	enum Mode {kTwoPulse=0, kSemiperiod=1, kPulseLength=2, kExternalDirection=3};

	Counter();
	explicit Counter(uint32_t channel);
	Counter(uint8_t moduleNumber, uint32_t channel);
	explicit Counter(DigitalSource *source);
	explicit Counter(AnalogTrigger *trigger);
	Counter(EncodingType encodingType, DigitalSource *upSource, DigitalSource *downSource, bool inverted);
	virtual ~Counter();

	void SetUpSource(uint32_t channel);
	void SetUpSource(uint8_t moduleNumber, uint32_t channel);
	void SetUpSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType);
	void SetUpSource(DigitalSource *source);
	void SetUpSourceEdge(bool risingEdge, bool fallingEdge);
	void ClearUpSource();

	void SetDownSource(uint32_t channel);
	void SetDownSource(uint8_t moduleNumber, uint32_t channel);
	void SetDownSource(AnalogTrigger *analogTrigger, AnalogTriggerOutput::Type triggerType);
	void SetDownSource(DigitalSource *source);
	void SetDownSourceEdge(bool risingEdge, bool fallingEdge);
	void ClearDownSource();

	void SetUpDownCounterMode();
	void SetExternalDirectionMode();
	void SetSemiPeriodMode(bool highSemiPeriod);
	void SetPulseLengthMode(float threshold);

	void SetReverseDirection(bool reverseDirection);

	// CounterBase interface
	void Start();
	int32_t Get();
	void Reset();
	void Stop();
	double GetPeriod();
	void SetMaxPeriod(double maxPeriod);
	void SetUpdateWhenEmpty(bool enabled);
	bool GetStopped();
	bool GetDirection();
	void SetSamplesToAverage(int samplesToAverage);
	int GetSamplesToAverage();
    uint32_t GetIndex();
};
