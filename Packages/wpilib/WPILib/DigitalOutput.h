/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef DIGITAL_OUTPUT_H_
#define DIGITAL_OUTPUT_H_

#include "SensorBase.h"

class DigitalModule;

/**
 * Class to write to digital outputs.
 * Write values to the digital output channels. Other devices implemented elsewhere will allocate
 * channels automatically so for those devices it shouldn't be done here.
 */
class DigitalOutput : SensorBase
{
public:
	explicit DigitalOutput(UINT32 channel);
	DigitalOutput(UINT32 slot, UINT32 channel);
	~DigitalOutput();
	void Set(UINT32 value);
	void Pulse(float length);
	bool IsPulsing();

private:
	void InitDigitalOutput(UINT32 slot, UINT32 channel);

	UINT32 m_channel;
	DigitalModule *m_module;
};

#endif
