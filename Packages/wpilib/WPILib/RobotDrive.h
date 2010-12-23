/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTDRIVE_H_
#define ROBOTDRIVE_H_

#include "Base.h"
#include <stdlib.h>
#include <vxWorks.h>

class SpeedController;
class GenericHID;

/**
 * Utility class for handling Robot drive based on a definition of the motor configuration.
 * The robot drive class handles basic driving for a robot. Currently, 2 and 4 motor standard
 * drive trains are supported. In the future other drive types like swerve and meccanum might
 * be implemented. Motor channel numbers are passed supplied on creation of the class. Those are
 * used for either the Drive function (intended for hand created drive code, such as autonomous)
 * or with the Tank/Arcade functions intended to be used for Operator Control driving.
 */
class RobotDrive
{
public:
	typedef enum
	{
		kFrontLeftMotor = 0,
		kFrontRightMotor = 1,
		kRearLeftMotor = 2,
		kRearRightMotor = 3
	} MotorType;

	RobotDrive(UINT32 leftMotorChannel, UINT32 rightMotorChannel, float sensitivity = 0.5);
	RobotDrive(UINT32 frontLeftMotorChannel, UINT32 rearLeftMotorChannel,
				UINT32 frontRightMotorChannel, UINT32 rearRightMotorChannel, float sensitivity = 0.5);
	RobotDrive(SpeedController *leftMotor, SpeedController *rightMotor, float sensitivity = 0.5);
	RobotDrive(SpeedController &leftMotor, SpeedController &rightMotor, float sensitivity = 0.5);
	RobotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
				SpeedController *frontRightMotor, SpeedController *rearRightMotor,
				float sensitivity = 0.5);
	RobotDrive(SpeedController &frontLeftMotor, SpeedController &rearLeftMotor,
				SpeedController &frontRightMotor, SpeedController &rearRightMotor,
				float sensitivity = 0.5);
	virtual ~RobotDrive();

	void Drive(float speed, float curve);
	void TankDrive(GenericHID *leftStick, GenericHID *rightStick);
	void TankDrive(GenericHID &leftStick, GenericHID &rightStick);
	void TankDrive(GenericHID *leftStick, UINT32 leftAxis, GenericHID *rightStick, UINT32 rightAxis);
	void TankDrive(GenericHID &leftStick, UINT32 leftAxis, GenericHID &rightStick, UINT32 rightAxis);
	void TankDrive(float leftValue, float rightValue);
	void ArcadeDrive(GenericHID *stick, bool squaredInputs = true);
	void ArcadeDrive(GenericHID &stick, bool squaredInputs = true);
	void ArcadeDrive(GenericHID *moveStick, UINT32 moveChannel, GenericHID *rotateStick, UINT32 rotateChannel, bool squaredInputs = true);
	void ArcadeDrive(GenericHID &moveStick, UINT32 moveChannel, GenericHID &rotateStick, UINT32 rotateChannel, bool squaredInputs = true);
	void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs = true);
	void MecanumDrive_Cartesian(float x, float y, float rotation, float gyroAngle = 0.0);
	void MecanumDrive_Polar(float magnitude, float direction, float rotation);
	void HolonomicDrive(float magnitude, float direction, float rotation);
	void SetLeftRightMotorSpeeds(float leftSpeed, float rightSpeed);
	void SetInvertedMotor(MotorType motor, bool isInverted);

private:
	float Limit(float num);
	void Normalize(double *wheelSpeeds);
	void RotateVector(double &x, double &y, double angle);

	static const INT32 kMaxNumberOfMotors = 4;

	INT32 m_invertedMotors[kMaxNumberOfMotors];
	float m_sensitivity;
	bool m_deleteSpeedControllers;
	SpeedController *m_frontLeftMotor;
	SpeedController *m_frontRightMotor;
	SpeedController *m_rearLeftMotor;
	SpeedController *m_rearRightMotor;
	DISALLOW_COPY_AND_ASSIGN(RobotDrive);
};

#endif

