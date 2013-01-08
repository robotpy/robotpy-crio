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

class PIDSubsystem : Subsystem, PIDOutput, PIDSource
{
%TypeHeaderCode
#include <WPILib/Commands/PIDSubsystem.h>
%End

public:
	PIDSubsystem(const char *name, double p, double i, double d);
	PIDSubsystem(const char *name, double p, double i, double d, double f);
	PIDSubsystem(const char *name, double p, double i, double d, double f, double period);
	PIDSubsystem(double p, double i, double d);
	PIDSubsystem(double p, double i, double d, double f);
	PIDSubsystem(double p, double i, double d, double f, double period);
	virtual ~PIDSubsystem();
	
	void Enable();
	void Disable();

	// PIDOutput interface
	virtual void PIDWrite(float output);

	// PIDSource interface
	virtual double PIDGet();
	void SetSetpoint(double setpoint);
	void SetSetpointRelative(double deltaSetpoint);
	void SetInputRange(float minimumInput, float maximumInput);
	double GetSetpoint();
	double GetPosition();

	virtual void SetAbsoluteTolerance(float absValue);
	virtual void SetPercentTolerance(float percent);
	virtual bool OnTarget();
	
protected:
	PIDController *GetPIDController();

	virtual double ReturnPIDInput() = 0;
	virtual void UsePIDOutput(double output) = 0;

public:
	virtual void InitTable(ITable* table);
	virtual std::string GetSmartDashboardType();
};
