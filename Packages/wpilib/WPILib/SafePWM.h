/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef _SAFE_PWM_
#define _SAFE_PWM_

#include "MotorSafety.h"
#include "MotorSafetyHelper.h"
#include "PWM.h"

/**
 * A safe version of the PWM class.
 * It is safe because it implements the MotorSafety interface that provides timeouts
 * in the event that the motor value is not updated before the expiration time.
 * This delegates the actual work to a MotorSafetyHelper object that is used for all
 * objects that implement MotorSafety.
 */
class SafePWM: public PWM, public MotorSafety {
public:
	explicit SafePWM(UINT32 channel);
	SafePWM(UINT32 slot, UINT32 channel);
	
	void SetExpiration(float timeout);
	float GetExpiration();
	bool IsAlive();
	void StopMotor();
	bool IsSafetyEnabled();
	void SetSafetyEnabled(bool enabled);

	virtual void SetSpeed(float speed);
private:
	void InitSafePWM();
	MotorSafetyHelper *m_safetyHelper;
};

#endif
