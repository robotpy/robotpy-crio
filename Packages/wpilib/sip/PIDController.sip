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

class PIDController : LiveWindowSendable, Controller, ITableListener
{
%TypeHeaderCode
#include <WPILib/PIDController.h>
%End

public:
	PIDController(float p, float i, float d,
					PIDSource *source, PIDOutput *output,
					float period = 0.05) /NewThread/;
	PIDController(float p, float i, float d, float f,
					PIDSource *source, PIDOutput *output,
					float period = 0.05) /NewThread/;
	virtual ~PIDController();
	virtual float Get();
	virtual void SetContinuous(bool continuous = true);
	virtual void SetInputRange(float minimumInput, float maximumInput);
	virtual void SetOutputRange(float mimimumOutput, float maximumOutput);
	virtual void SetPID(float p, float i, float d);
	virtual void SetPID(float p, float i, float d, float f);
	virtual float GetP();
	virtual float GetI();
	virtual float GetD();
	virtual float GetF();
	
	virtual void SetSetpoint(float setpoint);
	virtual float GetSetpoint();

	virtual float GetError();
	
	virtual void SetTolerance(float percent);
	virtual void SetAbsoluteTolerance(float absValue);
	virtual void SetPercentTolerance(float percentValue);
	virtual bool OnTarget();
	
	virtual void Enable();
	virtual void Disable();
	virtual bool IsEnabled();

	virtual void Reset();

	virtual void CalculateCallback(float input, float setpoint,
					float result, float error);

	virtual void InitTable(ITable* table);

private:
	PIDController(const PIDController&);
	
	virtual ITable* GetTable();
	virtual std::string GetSmartDashboardType();
	virtual void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
	virtual void UpdateTable();
	virtual void StartLiveWindowMode();
	virtual void StopLiveWindowMode();
	
protected:
	void Calculate();
};
