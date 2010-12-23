/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DigitalModule.h"
#include "DigitalOutput.h"
#include "CDigitalOutput.h"

static DigitalOutput* digitalOutputs[SensorBase::kDigitalModules][SensorBase::kDigitalChannels];
static bool initialized = false;

/**
 * Allocate the DigitalOuput.
 * Allocates the resources associated with this DigitalOutput including the channel/slot reservation
 * and the underlying DigitalOutput object.
 *
 * @param slot The slot this digital module is plugged into
 * @param channel The channel being used for this digital output
 */
static DigitalOutput * AllocateDigitalOutput(UINT32 slot, UINT32 channel)
{
	if (!initialized)
	{
		for (unsigned i = 0; i < SensorBase::kDigitalModules; i++)
			for (unsigned j = 0; j < SensorBase::kDigitalChannels; j++)
				digitalOutputs[i][j] = NULL;
		initialized = true;
	}
	if (SensorBase::CheckDigitalModule(slot) && SensorBase::CheckDigitalChannel(channel))
	{
		unsigned slotOffset = DigitalModule::SlotToIndex(slot);
		if (digitalOutputs[slotOffset][channel - 1] == NULL)
		{
			digitalOutputs[slotOffset][channel - 1] = new DigitalOutput(slot, channel);
		}
		return digitalOutputs[slotOffset][channel - 1];
	}
	return NULL;
}

/**
 * Set the value of a digital output.
 * Set the value of a digital output to either one (true) or zero (false).
 *
 * @param slot The slot this digital module is plugged into
 * @param channel The channel being used for this digital output
 * @param value The 0/1 value set to the port.
 */
void SetDigitalOutput(UINT32 slot, UINT32 channel, UINT32 value)
{
	DigitalOutput *digOut = AllocateDigitalOutput(slot, channel);
	if (digOut)
		digOut->Set(value);
}

/**
 * Set the value of a digital output.
 * Set the value of a digital output to either one (true) or zero (false).
 *
 * @param channel The channel being used for this digital output
 * @param value The 0/1 value set to the port.
 */
void SetDigitalOutput(UINT32 channel, UINT32 value)
{
	SetDigitalOutput(SensorBase::GetDefaultDigitalModule(), channel, value);
}

/**
 * Free the resources associated with this digital output.
 * The underlying DigitalOutput object and the resouces for the channel and slot are
 * freed so they can be reused.
 *
 * @param slot The slot this digital module is plugged into
 * @param channel The channel being used for this digital output
 */
void DeleteDigitalOutput(UINT32 slot, UINT32 channel)
{
	if (SensorBase::CheckDigitalModule(slot) && SensorBase::CheckDigitalChannel(channel))
	{
		unsigned slotOffset = DigitalModule::SlotToIndex(slot);
		delete digitalOutputs[slotOffset][channel - 1];
		digitalOutputs[slotOffset][channel - 1] = NULL;
	}
}

/**
 * Free the resources associated with this digital output.
 * The underlying DigitalOutput object and the resouces for the channel and slot are
 * freed so they can be reused.
 *
 * @param channel The channel being used for this digital output
 */
void DeleteDigitalOutput(UINT32 channel)
{
	DeleteDigitalOutput(SensorBase::GetDefaultDigitalModule(), channel);
}

/*******************************************************************************
 * Alternative interface to digital output
*******************************************************************************/
DigitalOutputObject CreateDigitalOutput(UINT32 module, UINT32 channel)
{
	return (DigitalOutputObject) new DigitalOutput(module, channel); 
}

DigitalOutputObject CreateDigitalOutput(UINT32 channel)
{
	return (DigitalOutputObject) new DigitalOutput(channel); 
}

void SetDigitalOutput(DigitalOutputObject o, bool val)
{
	((DigitalOutput *) o)->Set(val);
}

void DeleteDigitalOutput(DigitalOutputObject o)
{
	delete (DigitalOutput *) o;
}


