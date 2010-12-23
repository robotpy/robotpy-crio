/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "CPWM.h"
#include "../PWM.h"
#include "CWrappers.h"
#include "../DigitalModule.h"

static bool PWMsInitialized = false;
static PWM *PWMs[SensorBase::kDigitalModules][SensorBase::kPwmChannels];

/**
 * Alloate a PWM based object
 *
 * Allocate an instance of a PWM based object. This code is shared between the subclasses
 * of PWM and is not usually created as a standalone object.
 *
 * @param module The slot the digital module is plugged into that corresponds to this serial port
 * @param channel The PWM channel for this PWM object
 * @param createObject The function callback in the subclass object that actually creates an instance
 * of the appropriate class.
 */
PWM *AllocatePWM(UINT32 module, UINT32 channel, SensorCreator createObject)
{
	if (!PWMsInitialized)
	{
		for (unsigned i = 0; i < SensorBase::kDigitalModules; i++)
			for (unsigned j = 0; j < SensorBase::kPwmChannels; j++)
				PWMs[i][j] = NULL;
		PWMsInitialized = true;
	}
	if (!SensorBase::CheckPWMModule(module) || !SensorBase::CheckPWMChannel(channel))
		return NULL;
	PWM *pwm = PWMs[DigitalModule::SlotToIndex(module)][channel - 1];
	if (pwm == NULL)
	{
		pwm = (PWM *) createObject(module, channel);
		PWMs[DigitalModule::SlotToIndex(module)][channel - 1] = pwm;
	}
	return pwm;
}

/**
 * Alloate a PWM based object
 *
 * Allocate an instance of a PWM based object. This code is shared between the subclasses
 * of PWM and is not usually created as a standalone object.
 *
 * @param channel The PWM channel for this PWM object
 * @param createObject The function callback in the subclass object that actually creates an instance
 * of the appropriate class.
 */
PWM *AllocatePWM(UINT32 channel, SensorCreator createObject)
{
	return AllocatePWM(SensorBase::GetDefaultDigitalModule(), channel, createObject);
}

/**
 * Delete a PWM
 * Delete a PWM and free up all the associated resources for this object.
 *
 * @param slot The slot the digital module is plugged into that corresponds to this serial port
 * @param channel The PWM channel for this PWM object
 */
void DeletePWM(UINT32 slot, UINT32 channel)
{
	if (SensorBase::CheckPWMModule(slot) && SensorBase::CheckPWMChannel(channel))
	{
		PWMs[DigitalModule::SlotToIndex(slot)][channel - 1] = NULL;
	}
}

/**
 * Delete a PWM
 * Delete a PWM and free up all the associated resources for this object.
 *
 * @param channel The PWM channel for this PWM object
 */
void DeletePWM(UINT32 channel)
{
	DeletePWM(SensorBase::GetDefaultDigitalModule(), channel);
}
