/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "MotorSafetyHelper.h"
#include "Timer.h"
#include "stdio.h"

/**
 * The constructor for a MotorSafetyHelper object.
 * The helper object is constructed for every object that wants to implement the Motor
 * Safety protocol. The helper object has the code to actually do the timing and call the
 * motors Stop() method when the timeout expires. The motor object is expected to call the
 * Feed() method whenever the motors value is updated.
 * @param safeObject a pointer to the motor object implementing MotorSafety. This is used
 * to call the Stop() method on the motor.
 */
MotorSafetyHelper::MotorSafetyHelper(MotorSafety *safeObject)
{
	m_safeObject = safeObject;
	m_enabled = false;
	m_expiration = DEFAULT_SAFETY_EXPIRATION;
	m_stopTime = Timer::GetFPGATimestamp();
	m_nextHelper = m_headHelper;
	m_headHelper = this;
}

MotorSafetyHelper *MotorSafetyHelper::m_headHelper = 0;

/*
 * Feed the motor safety object.
 * Resets the timer on this object that is used to do the timeouts.
 */
void MotorSafetyHelper::Feed()
{
	m_stopTime = Timer::GetFPGATimestamp() + m_expiration;
}

/*
 * Set the expiration time for the corresponding motor safety object.
 * @param expirationTime The timeout value in seconds.
 */
void MotorSafetyHelper::SetExpiration(float expirationTime)
{
	m_expiration = expirationTime;
}

/**
 * Retrieve the timeout value for the corresponding motor safety object.
 * @returns the timeout value in seconds.
 */
float MotorSafetyHelper::GetExpiration()
{
	return m_expiration;
}

/**
 * Determine if the motor is still operating or has timed out.
 * @returns a true value if the motor is still operating normally and hasn't timed out.
 */
bool MotorSafetyHelper::IsAlive()
{
	return !m_enabled || m_stopTime > Timer::GetFPGATimestamp();
}

/**
 * Check if this motor has exceeded its timeout.
 * This method is called periodically to determine if this motor has exceeded its timeout
 * value. If it has, the stop method is called, and the motor is shut down until its value is
 * updated again.
 */
void MotorSafetyHelper::Check()
{
	if (!m_enabled) return;
	if (m_stopTime < Timer::GetFPGATimestamp())
	{
		// TODO: Produce an error for the driver station in the case of a timeout.
		m_safeObject->StopMotor();
	}
}

/**
 * Enable/disable motor safety for this device
 * Turn on and off the motor safety option for this PWM object.
 * @param enabled True if motor safety is enforced for this object
 */
void MotorSafetyHelper::SetSafetyEnabled(bool enabled)
{
	m_enabled = enabled;
}

/**
 * Return the state of the motor safety enabled flag
 * Return if the motor safety is currently enabled for this devicce.
 * @returns True if motor safety is enforced for this device
 */
bool MotorSafetyHelper::IsSafetyEnabled()
{
	return m_enabled;
}

/**
 * Check the motors to see if any have timed out.
 * This static  method is called periodically to poll all the motors and stop any that have
 * timed out.
 */
//TODO: these should be synchronized with the setting methods in case it's called from a different thread
void MotorSafetyHelper::CheckMotors()
{
	for (MotorSafetyHelper *msh = m_headHelper; msh != NULL; msh = msh->m_nextHelper)
	{
		msh->Check();
	}
}
