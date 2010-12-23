/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Compressor.h"
#include "DigitalInput.h"
#include "Timer.h"
#include "Utility.h"
#include "WPIStatus.h"

/**
 * Internal task.
 * 
 * Task which checks the compressor pressure switch and operates the relay as necessary
 * depending on the pressure.
 * 
 * Do not call this function directly.
 */
static void compressorChecker(Compressor *c)
{
	while (1)
	{
		if (c->Enabled())
		{
			c->SetRelayValue( c->GetPressureSwitchValue() == 0 ? Relay::kOn : Relay::kOff );
		}
		else
		{
			c->SetRelayValue(Relay::kOff);
		}
		Wait(0.5);
	}
}

/**
 * Initialize the Compressor object.
 * This method is the common initialization code for all the constructors for the Compressor
 * object. It takes the relay channel and pressure switch channel and spawns a task that polls the
 * compressor and sensor.
 * 
 * You MUST start the compressor by calling the Start() method.
 */
void Compressor::InitCompressor(UINT32 pressureSwitchSlot,
		UINT32 pressureSwitchChannel,
		UINT32 compresssorRelaySlot,
		UINT32 compressorRelayChannel)
{
	CheckDigitalModule(pressureSwitchSlot);
	CheckRelayModule(compresssorRelaySlot);
	CheckDigitalChannel(pressureSwitchChannel);
	CheckRelayChannel(compressorRelayChannel);

	m_enabled = false;
	m_pressureSwitch = new DigitalInput(pressureSwitchSlot, pressureSwitchChannel);
	m_relay = new Relay(compresssorRelaySlot, compressorRelayChannel, Relay::kForwardOnly);

	if (!m_task.Start((INT32)this))
	{
		wpi_fatal(CompressorTaskError);
	}
}

/**
 * Compressor constructor.
 * Given a fully specified relay channel and pressure switch channel, initialize the Compressor object.
 * 
 * You MUST start the compressor by calling the Start() method.
 * 
 * @param pressureSwitchSlot The module that the pressure switch is attached to.
 * @param pressureSwitchChannel The GPIO channel that the pressure switch is attached to.
 * @param compresssorRelaySlot The module that the compressor relay is attached to.
 * @param compressorRelayChannel The relay channel that the compressor relay is attached to.
 */
Compressor::Compressor(UINT32 pressureSwitchSlot,
		UINT32 pressureSwitchChannel,
		UINT32 compresssorRelaySlot,
		UINT32 compressorRelayChannel)
	: m_task ("Compressor", (FUNCPTR)compressorChecker)
{
	InitCompressor(pressureSwitchSlot,
		pressureSwitchChannel,
		compresssorRelaySlot,
		compressorRelayChannel);
}

/**
 * Compressor constructor.
 * Given a relay channel and pressure switch channel (both in the default digital module), initialize
 * the Compressor object.
 * 
 * You MUST start the compressor by calling the Start() method.
 * 
 * @param pressureSwitchChannel The GPIO channel that the pressure switch is attached to.
 * @param compressorRelayChannel The relay channel that the compressor relay is attached to.
 */
Compressor::Compressor(UINT32 pressureSwitchChannel, UINT32 compressorRelayChannel)
	: m_task ("Compressor", (FUNCPTR)compressorChecker)
{
	InitCompressor(GetDefaultDigitalModule(),
			pressureSwitchChannel,
			GetDefaultDigitalModule(),
			compressorRelayChannel);
}

/**
 * Delete the Compressor object.
 * Delete the allocated resources for the compressor and kill the compressor task that is polling
 * the pressure switch.
 */
Compressor::~Compressor()
{
	delete m_pressureSwitch;
	delete m_relay;
}

/**
 * Operate the relay for the compressor.
 * Change the value of the relay output that is connected to the compressor motor.
 * This is only intended to be called by the internal polling thread.
 */
void Compressor::SetRelayValue(Relay::Value relayValue)
{
	m_relay->Set(relayValue);
}

/**
 * Get the pressure switch value.
 * Read the pressure switch digital input.
 * 
 * @return The current state of the pressure switch.
 */
UINT32 Compressor::GetPressureSwitchValue()
{
	return m_pressureSwitch->Get();
}

/**
 * Start the compressor.
 * This method will allow the polling loop to actually operate the compressor. The
 * is stopped by default and won't operate until starting it.
 */
void Compressor::Start()
{
	m_enabled = true;
}

/**
 * Stop the compressor.
 * This method will stop the compressor from turning on.
 */
void Compressor::Stop()
{
	m_enabled = false;
}

/**
 * Get the state of the enabled flag.
 * Return the state of the enabled flag for the compressor and pressure switch
 * combination.
 * 
 * @return The state of the compressor thread's enable flag.
 */
bool Compressor::Enabled()
{
	return m_enabled;
}

