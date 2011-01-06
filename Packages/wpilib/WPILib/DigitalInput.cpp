/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DigitalInput.h"
#include "DigitalModule.h"
#include "Resource.h"
#include "Utility.h"
#include "WPIStatus.h"

// TODO: This is not a good place for this...
Resource *interruptsResource = NULL;

/**
 * Create an instance of a DigitalInput.
 * Creates a digital input given a slot and channel. Common creation routine
 * for all constructors.
 */
void DigitalInput::InitDigitalInput(UINT32 slot, UINT32 channel)
{
	Resource::CreateResourceObject(&interruptsResource, 8);
	CheckDigitalChannel(channel);
	CheckDigitalModule(slot);
	m_channel = channel;
	m_module = DigitalModule::GetInstance(slot);
	m_module->AllocateDIO(channel, true);
}

/**
 * Create an instance of a Digital Input class.
 * Creates a digital input given a channel and uses the default module.
 */
DigitalInput::DigitalInput(UINT32 channel)
{
	InitDigitalInput(GetDefaultDigitalModule(), channel);
}

/**
 * Create an instance of a Digital Input class.
 * Creates a digital input given an channel and module.
 */
DigitalInput::DigitalInput(UINT32 slot, UINT32 channel)
{
	InitDigitalInput(slot, channel);
}

/**
 * Free resources associated with the Digital Input class.
 */
DigitalInput::~DigitalInput()
{
	if (m_manager != NULL)
	{
		delete m_manager;
		delete m_interrupt;
		interruptsResource->Free(m_interruptIndex);
	}
	m_module->FreeDIO(m_channel);
}

/*
 * Get the value from a digital input channel.
 * Retrieve the value of a single digital input channel from the FPGA.
 */
UINT32 DigitalInput::Get()
{
	return m_module->GetDIO(m_channel);
}

/**
 * @return The GPIO channel number that this object represents.
 */
UINT32 DigitalInput::GetChannel()
{
	return m_channel;
}

/**
 * @return The value to be written to the channel field of a routing mux.
 */
UINT32 DigitalInput::GetChannelForRouting()
{
	return DigitalModule::RemapDigitalChannel(GetChannel() - 1);
}

/**
 * @return The value to be written to the module field of a routing mux.
 */
UINT32 DigitalInput::GetModuleForRouting()
{
	return DigitalModule::SlotToIndex(m_module->GetSlot());
}

/**
 * @return The value to be written to the analog trigger field of a routing mux.
 */
bool DigitalInput::GetAnalogTriggerForRouting()
{
	return false;
}

/**
 * Request interrupts asynchronously on this digital input.
 * @param handler The address of the interrupt handler function of type tInterruptHandler that
 * will be called whenever there is an interrupt on the digitial input port.
 * Request interrupts in synchronus mode where the user program interrupt handler will be
 * called when an interrupt occurs.
 * The default is interrupt on rising edges only.
 */
void DigitalInput::RequestInterrupts(tInterruptHandler handler, void *param)
{
	m_interruptIndex = interruptsResource->Allocate();
//TODO: check for error on allocation

	// Creates a manager too
	AllocateInterrupts(false);

	m_interrupt->writeConfig_WaitForAck(false, &status);
	m_interrupt->writeConfig_Source_AnalogTrigger(GetAnalogTriggerForRouting(), &status);
	m_interrupt->writeConfig_Source_Channel(GetChannelForRouting(), &status);
	m_interrupt->writeConfig_Source_Module(GetModuleForRouting(), &status);
	SetUpSourceEdge(true, false);

	m_manager->registerHandler(handler, param, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Request interrupts synchronously on this digital input.
 * Request interrupts in synchronus mode where the user program will have to explicitly
 * wait for the interrupt to occur.
 * The default is interrupt on rising edges only.
 */
void DigitalInput::RequestInterrupts()
{
	m_interruptIndex = interruptsResource->Allocate();
//TODO: check for errors

	AllocateInterrupts(true);

	m_interrupt->writeConfig_Source_AnalogTrigger(GetAnalogTriggerForRouting(), &status);
	m_interrupt->writeConfig_Source_Channel(GetChannelForRouting(), &status);
	m_interrupt->writeConfig_Source_Module(GetModuleForRouting(), &status);
	SetUpSourceEdge(true, false);
	wpi_assertCleanStatus(status);
}

void DigitalInput::SetUpSourceEdge(bool risingEdge, bool fallingEdge)
{
	wpi_assert(m_interrupt != NULL);
	if (m_interrupt != NULL)
	{
		m_interrupt->writeConfig_RisingEdge(risingEdge, &status);
		m_interrupt->writeConfig_FallingEdge(fallingEdge, &status);
	}
	wpi_assertCleanStatus(status);
}

