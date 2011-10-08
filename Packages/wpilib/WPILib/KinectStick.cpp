/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "KinectStick.h"

#include "DriverStation.h"
#include "Joystick.h"
#include "NetworkCommunication/FRCComm.h"
#include "Utility.h"
#include "WPIErrors.h"

UINT32 KinectStick::_recentPacketNumber = 0;
KinectStick::KinectStickData KinectStick::_sticks;

#define kJoystickBundleID kFRC_NetworkCommunication_DynamicType_Kinect_Joystick
#define kTriggerMask 1
#define kTopMask 2

/**
 * Kinect joystick constructor
 * @param id value is either 1 or 2 for the left or right joystick decoded from
 * gestures interpreted by the Kinect server on the Driver Station computer.
 */
KinectStick::KinectStick(int id)
{
	if (id != 1 && id != 2)
	{
		wpi_setWPIErrorWithContext(ParameterOutOfRange, "KinectStick ID must be 1 or 2");
		return;
	}
	m_id = id;
}

/**
 * Get the X joystick value
 * This is not supported in the default gestures and always returns 0
 */
float KinectStick::GetX(JoystickHand hand)
{
	return GetRawAxis(Joystick::kDefaultXAxis);
}

/**
 * Get the joystick Y value
 * @param hand
 * @returns The floating point representation of the Y value
 */
float KinectStick::GetY(JoystickHand hand)
{
	return GetRawAxis(Joystick::kDefaultYAxis);
}

/**
 * Get the Z joystick value
 * This is not supported in the default gestures and always returns 0
 */
float KinectStick::GetZ()
{
	return GetRawAxis(Joystick::kDefaultZAxis);
}

/**
 * Get the Twist joystick value
 * This is not supported in the default gestures and always returns 0
 */
float KinectStick::GetTwist()
{
	return GetRawAxis(Joystick::kDefaultTwistAxis);
}

/**
 * Get the Throttle joystick value
 * This is not supported in the default gestures and always returns 0
 */
float KinectStick::GetThrottle()
{
	return GetRawAxis(Joystick::kDefaultThrottleAxis);
}

/**
 * Get the joystick axis value by axis number
 * This is only supported for X in the default gestures and all others always returns 0
 */
float KinectStick::GetRawAxis(UINT32 axis)
{
	if (StatusIsFatal()) return 0.0;

	GetData();
	float value = ConvertRawToFloat(_sticks.formatted.rawSticks[m_id - 1].axis[axis-1]);
	return value;
}

/**
 * Get the trigger value for the joystick
 * @param hand
 * @returns true if the triger is pressed
 */
bool KinectStick::GetTrigger(JoystickHand hand)
{
	return GetRawButton(kTriggerMask);
}

/**
 * Get the top button value for the joystick
 * @param hand
 * @returns true if the top button is pressed
 */
bool KinectStick::GetTop(JoystickHand hand)
{
	return GetRawButton(kTopMask);
}

bool KinectStick::GetBumper(JoystickHand hand)
{
	// TODO: Should this even be in GenericHID?  Is 4 an appropriate mask value (button 3)?
	return GetRawButton(4);
}

bool KinectStick::GetRawButton(UINT32 button)
{
	if (StatusIsFatal()) return false;

	GetData();
	return (_sticks.formatted.rawSticks[m_id - 1].buttons & (1 << button)) != 0;
}

/**
 * Get dynamic data from the driver station buffer
 */
void KinectStick::GetData()
{
	UINT32 packetNumber = DriverStation::GetInstance()->GetPacketNumber();
	if (_recentPacketNumber != packetNumber)
	{
		_recentPacketNumber = packetNumber;
		int retVal = getDynamicControlData(kJoystickBundleID, _sticks.data, sizeof(_sticks.data), 5);
		if (retVal == 0)
		{
			wpi_assert(_sticks.formatted.size == sizeof(_sticks.data) - 1);
		}
	}
}

/**
 * Convert an 8 bit joystick value to a floating point (-1,1) value
 * @param value The 8 bit raw joystick value returned from the driver station
 */
float KinectStick::ConvertRawToFloat(INT8 value)
{
	float result;

	if (value < 0)
		result = ((float) value) / 128.0;
	else
		result = ((float) value) / 127.0;

	wpi_assert(result <= 1.0 && result >= -1.0);

	if (result > 1.0)
		result = 1.0;
	else if (result < -1.0)
		result = -1.0;

	return result;
}
