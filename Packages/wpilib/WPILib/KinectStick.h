/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __KINECT_STICK_H__
#define __KINECT_STICK_H__

#include "ErrorBase.h"
#include "GenericHID.h"

class KinectStick : public GenericHID, public ErrorBase
{
public:
	explicit KinectStick(int id);
	virtual float GetX(JoystickHand hand = kRightHand);
	virtual float GetY(JoystickHand hand = kRightHand);
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	virtual float GetRawAxis(UINT32 axis);

	virtual bool GetTrigger(JoystickHand hand = kRightHand);
	virtual bool GetTop(JoystickHand hand = kRightHand);
	virtual bool GetBumper(JoystickHand hand = kRightHand);
	virtual bool GetRawButton(UINT32 button);

private:
	void GetData();
	float ConvertRawToFloat(INT8 charValue);

	typedef union
	{
		struct
		{
			UINT8 size;
			UINT8 id;
			struct
			{
				unsigned char axis[6];
				unsigned short buttons;
			} rawSticks[2];
		} formatted;
		char data[18];
	} KinectStickData;

	int m_id;
	static UINT32 _recentPacketNumber;
	static KinectStickData _sticks;
};

#endif

