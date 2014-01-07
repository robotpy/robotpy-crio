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

class RobotDrive : MotorSafety, ErrorBase
{
%TypeHeaderCode
#include <WPILib/RobotDrive.h>
%End

public:
	enum MotorType
	{
		kFrontLeftMotor = 0,
		kFrontRightMotor = 1,
		kRearLeftMotor = 2,
		kRearRightMotor = 3
	};

	RobotDrive(uint32_t leftMotorChannel, uint32_t rightMotorChannel);
	RobotDrive(uint32_t frontLeftMotorChannel, uint32_t rearLeftMotorChannel,
				uint32_t frontRightMotorChannel, uint32_t rearRightMotorChannel);
	RobotDrive(SpeedController *leftMotor, SpeedController *rightMotor);
	RobotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
				SpeedController *frontRightMotor, SpeedController *rearRightMotor);
	virtual ~RobotDrive();

	void Drive(float outputMagnitude, float curve);
	void TankDrive(GenericHID *leftStick, GenericHID *rightStick, bool squaredInputs = true);
	void TankDrive(GenericHID *leftStick, uint32_t leftAxis, GenericHID *rightStick, uint32_t rightAxis, bool squaredInputs = true);
	void TankDrive(float leftValue, float rightValue, bool squaredInputs = true);
	void ArcadeDrive(GenericHID *stick, bool squaredInputs = true);
	void ArcadeDrive(GenericHID *moveStick, uint32_t moveChannel, GenericHID *rotateStick, uint32_t rotateChannel, bool squaredInputs = true);
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs = true);
	void MecanumDrive_Cartesian(float x, float y, float rotation, float gyroAngle = 0.0);
	void MecanumDrive_Polar(float magnitude, float direction, float rotation);
	void HolonomicDrive(float magnitude, float direction, float rotation);
	virtual void SetLeftRightMotorOutputs(float leftOutput, float rightOutput);
	void SetInvertedMotor(MotorType motor, bool isInverted);
	void SetSensitivity(float sensitivity);
	void SetMaxOutput(double maxOutput);

	void SetExpiration(float timeout);
	float GetExpiration();
	bool IsAlive();
	void StopMotor();
	bool IsSafetyEnabled();
	void SetSafetyEnabled(bool enabled);
	const char* GetDescription() [void (char *)];
%MethodCode
	char result[100];
	result[0] = '\0';
	sipSelfWasArg ? sipCpp->RobotDrive::GetDescription(result) : sipCpp->GetDescription(result);
	sipRes = result;
%End

protected:
	void InitRobotDrive();
	float Limit(float num);
	//void Normalize(double *wheelSpeeds);
	void RotateVector(double &x /In,Out/, double &y /In,Out/, double angle);

private:
	RobotDrive(const RobotDrive&);
};
