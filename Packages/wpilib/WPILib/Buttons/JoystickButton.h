/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef __JOYSTICK_BUTTON_H__
#define __JOYSTICK_BUTTON_H__

#include "Joystick.h"
#include "Buttons/Button.h"

class JoystickButton : public Button
{
public:
	JoystickButton(Joystick *joystick, int buttonNumber);
	virtual ~JoystickButton() {}

	virtual bool Get();

private:
	Joystick *m_joystick;
	int m_buttonNumber;
};

#endif
