/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DigitalOutput.h"
#include "DigitalModule.h"

void DigitalOutput::InitDigitalOutput(UINT32 slot, UINT32 channel)
{
	m_channel = channel;
	m_module = DigitalModule::GetInstance(slot);
	m_module->AllocateDIO(m_channel, false);
}

/**
 * Create an instance of a digital output.
 * Create a digital output given a channel. The default module is used.
 */
DigitalOutput::DigitalOutput(UINT32 channel)
{
	InitDigitalOutput(GetDefaultDigitalModule(), channel);
}

/**
 * Create an instance of a digital output.
 * Create an instance of a digital output given a slot and channel.
 */
DigitalOutput::DigitalOutput(UINT32 slot, UINT32 channel)
{
	InitDigitalOutput(slot, channel);
}

/**
 * Free the resources associated with a digital output.
 */
DigitalOutput::~DigitalOutput()
{
	m_module->FreeDIO(m_channel);
}

/**
 * Set the value of a digital output.
 * Set the value of a digital output to either one (true) or zero (false).
 */
void DigitalOutput::Set(UINT32 value)
{
	m_module->SetDIO(m_channel, value);
}

/**
 * Output a single pulse on the digital output line.
 * Send a single pulse on the digital output line where the pulse diration is specified in seconds.
 * Maximum pulse length is 0.0016 seconds.
 * @param length The pulselength in seconds
 */
void DigitalOutput::Pulse(float length)
{
	m_module->Pulse(m_channel, length);
}

/**
 * Determine if the pulse is still going.
 * Determine if a previously started pulse is still going.
 */
bool DigitalOutput::IsPulsing()
{
	return m_module->IsPulsing(m_channel);
}
