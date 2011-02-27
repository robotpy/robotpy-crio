/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "DigitalModule.h"
#include "I2C.h"
#include "PWM.h"
#include "Resource.h"
#include "Synchronized.h"
#include "Utility.h"
#include "WPIStatus.h"
#include <math.h>

static Resource *DIOChannels = NULL;
static Resource *DO_PWMGenerators[tDIO::kNumSystems] = {NULL};

/**
 * Get an instance of an Digital Module.
 * Singleton digital module creation where a module is allocated on the first use
 * and the same module is returned on subsequent uses.
 */
DigitalModule* DigitalModule::GetInstance(UINT32 slot)
{
	if (CheckDigitalModule(slot))
	{
		if (m_modules[slot] == NULL)
		{
			m_modules[slot] = new DigitalModule(slot);
		}
		return (DigitalModule*)m_modules[slot];
	}
	return NULL;
}

UINT32 DigitalModule::SlotToIndex(UINT32 slot)
{
	const UINT32 mapping[] = {0,0,0,0,0,1,0,0};
	return mapping[slot - 1];
}

/**
 * Create a new instance of an digital module.
 * Create an instance of the digital module object. Initialize all the parameters
 * to reasonable values on start.
 * Setting a global value on an digital module can be done only once unless subsequent
 * values are set the previously set value.
 * Digital modules are a singleton, so the constructor is never called outside of this class.
 */
DigitalModule::DigitalModule(UINT32 slot)
	: Module(slot)
	, m_fpgaDIO (NULL)
{
	Resource::CreateResourceObject(&DIOChannels, tDIO::kNumSystems * kDigitalChannels);
	Resource::CreateResourceObject(&DO_PWMGenerators[SlotToIndex(m_slot)], tDIO::kNumDO_PWMDutyCycleElements);
	m_fpgaDIO = new tDIO(SlotToIndex(m_slot), &status);

	// Make sure that the 9403 IONode has had a chance to initialize before continuing.
	while(m_fpgaDIO->readLoopTiming(&status) == 0) taskDelay(1);
	if (m_fpgaDIO->readLoopTiming(&status) != kExpectedLoopTiming)
	{
		wpi_fatal(LoopTimingError);
		printf("DIO LoopTiming: %d, expecting: %d\n", m_fpgaDIO->readLoopTiming(&status), kExpectedLoopTiming);
	}
	m_fpgaDIO->writePWMConfig_Period(PWM::kDefaultPwmPeriod, &status);
	m_fpgaDIO->writePWMConfig_MinHigh(PWM::kDefaultMinPwmHigh, &status);

	// Ensure that PWM output values are set to OFF
	for (UINT32 pwm_index = 1; pwm_index <= kPwmChannels; pwm_index++)
	{
		SetPWM(pwm_index, PWM::kPwmDisabled);
		SetPWMPeriodScale(pwm_index, 3); // Set all to 4x by default.
	}

	// Turn off all relay outputs.
	m_fpgaDIO->writeSlowValue_RelayFwd(0, &status);
	m_fpgaDIO->writeSlowValue_RelayRev(0, &status);

	// Create a semaphore to protect changes to the relay values
	m_relaySemaphore = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);

	AddToSingletonList();
}

DigitalModule::~DigitalModule()
{
	semDelete(m_relaySemaphore);
	m_relaySemaphore = NULL;
	delete m_fpgaDIO;
	m_modules[m_slot] = NULL;
}

/**
 * Set a PWM channel to the desired value. The values range from 0 to 255 and the period is controlled
 * by the PWM Period and MinHigh registers.
 * 
 * @param channel The PWM channel to set.
 * @param value The PWM value to set.
 */
void DigitalModule::SetPWM(UINT32 channel, UINT8 value)
{
	CheckPWMChannel(channel);
	m_fpgaDIO->writePWMValue(channel - 1, value, &status);
}

/**
 * Get a value from a PWM channel. The values range from 0 to 255.
 * 
 * @param channel The PWM channel to read from.
 * @return The raw PWM value.
 */
UINT8 DigitalModule::GetPWM(UINT32 channel)
{
	CheckPWMChannel(channel);
	return m_fpgaDIO->readPWMValue(channel - 1, &status);
}

/**
 * Set how how often the PWM signal is squelched, thus scaling the period.
 * 
 * @param channel The PWM channel to configure.
 * @param squelchMask The 2-bit mask of outputs to squelch.
 */
void DigitalModule::SetPWMPeriodScale(UINT32 channel, UINT32 squelchMask)
{
	CheckPWMChannel(channel);
	m_fpgaDIO->writePWMPeriodScale(channel - 1, squelchMask, &status);
}

/**
 * Set the state of a relay.
 * Set the state of a relay output to be forward. Relays have two outputs and each is
 * independently set to 0v or 12v.
 */
void DigitalModule::SetRelayForward(UINT32 channel, bool on)
{
	status = 0;
	CheckRelayChannel(channel);
	{
		Synchronized sync(m_relaySemaphore);
		UINT8 forwardRelays = m_fpgaDIO->readSlowValue_RelayFwd(&status);
		if (on)
			forwardRelays |= 1 << (channel - 1);
		else
			forwardRelays &= ~(1 << (channel - 1));
		m_fpgaDIO->writeSlowValue_RelayFwd(forwardRelays, &status);
	}
	wpi_assertCleanStatus(status);
}

/**
 * Set the state of a relay.
 * Set the state of a relay output to be reverse. Relays have two outputs and each is
 * independently set to 0v or 12v.
 */
void DigitalModule::SetRelayReverse(UINT32 channel, bool on)
{
	status = 0;
	CheckRelayChannel(channel);
	{
		Synchronized sync(m_relaySemaphore);
		UINT8 reverseRelays = m_fpgaDIO->readSlowValue_RelayRev(&status);
		if (on)
			reverseRelays |= 1 << (channel - 1);
		else
			reverseRelays &= ~(1 << (channel - 1));
		m_fpgaDIO->writeSlowValue_RelayRev(reverseRelays, &status);
	}
	wpi_assertCleanStatus(status);
}

/**
 * Get the current state of the forward relay channel
 */
bool DigitalModule::GetRelayForward(UINT32 channel)
{
	status = 0;
	UINT8 forwardRelays = m_fpgaDIO->readSlowValue_RelayFwd(&status);
	return (forwardRelays & (1 << (channel - 1))) != 0;
}

/**
 * Get the current state of all of the forward relay channels on this module.
 */
UINT8 DigitalModule::GetRelayForward(void)
{
	status = 0;
	return m_fpgaDIO->readSlowValue_RelayFwd(&status);
}

/**
 * Get the current state of the reverse relay channel
 */
bool DigitalModule::GetRelayReverse(UINT32 channel)
{
	status = 0;
	UINT8 reverseRelays = m_fpgaDIO->readSlowValue_RelayRev(&status);
	return (reverseRelays & (1 << (channel - 1))) != 0;
	
}

/**
 * Get the current state of all of the reverse relay channels on this module.
 */
UINT8 DigitalModule::GetRelayReverse(void)
{
	status = 0;
	return m_fpgaDIO->readSlowValue_RelayRev(&status);	
}


/**
 * Allocate Digital I/O channels.
 * Allocate channels so that they are not accidently reused. Also the direction is set at the
 * time of the allocation.
 */
bool DigitalModule::AllocateDIO(UINT32 channel, bool input)
{
	status = 0;
	DIOChannels->Allocate(kDigitalChannels * SlotToIndex(m_slot) + channel - 1);
	UINT32 outputEnable = m_fpgaDIO->readOutputEnable(&status);
	UINT32 bitToSet = 1 << (RemapDigitalChannel(channel - 1));
	UINT32 outputEnableValue;
	if (input)
	{
		outputEnableValue = outputEnable & (~ bitToSet ); // clear the bit for read
	}
	else
	{
		outputEnableValue = outputEnable | bitToSet; // set the bit for write
	}
	m_fpgaDIO->writeOutputEnable(outputEnableValue, &status);
	wpi_assertCleanStatus(status);
	return true;
}

/**
 * Free the resource associated with a digital I/O channel.
 */
void DigitalModule::FreeDIO(UINT32 channel)
{
	DIOChannels->Free(kDigitalChannels * SlotToIndex(m_slot) + channel - 1);
}

/**
 * Write a digital I/O bit to the FPGA.
 * Set a single value on a digital I/O channel.
 */
void DigitalModule::SetDIO(UINT32 channel, short value)
{
	status = 0;
	if (value != 0 && value != 1)
	{
		wpi_fatal(NonBinaryDigitalValue);
		if (value != 0)
			value = 1;
	}
	UINT16 currentDIO = m_fpgaDIO->readDO(&status);
	if(value == 0)
	{
		currentDIO = currentDIO & ~(1 << RemapDigitalChannel(channel - 1));
	}
	else if (value == 1)
	{
		currentDIO = currentDIO | (1 << RemapDigitalChannel(channel - 1));
	} 
	m_fpgaDIO->writeDO(currentDIO, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Read a digital I/O bit from the FPGA.
 * Get a single value from a digital I/O channel.
 */
bool DigitalModule::GetDIO(UINT32 channel)
{
	status = 0;
	UINT32 currentDIO = m_fpgaDIO->readDI(&status);
	
	//Shift 00000001 over channel-1 places.
	//AND it against the currentDIO
	//if it == 0, then return false
	//else return true
	wpi_assertCleanStatus(status);
	return ((currentDIO >> RemapDigitalChannel(channel - 1)) & 1) != 0;
}

/**
 * Read the state of all the Digital I/O lines from the FPGA
 * These are not remapped to logical order.  They are still in hardware order.
 */
UINT16 DigitalModule::GetDIO(void)
{
	status = 0;
	return m_fpgaDIO->readDI(&status);
}

/**
 * Read the direction of a the Digital I/O lines
 * A 1 bit means output and a 0 bit means input.
 */
bool DigitalModule::GetDIODirection(UINT32 channel)
{
	status = 0;
	UINT32 currentOutputEnable = m_fpgaDIO->readOutputEnable(&status);
	
	//Shift 00000001 over channel-1 places.
	//AND it against the currentOutputEnable
	//if it == 0, then return false
	//else return true
	wpi_assertCleanStatus(status);
	return ((currentOutputEnable >> RemapDigitalChannel(channel - 1)) & 1) != 0;
}

/**
 * Read the direction of all the Digital I/O lines from the FPGA
 * A 1 bit means output and a 0 bit means input.
 * These are not remapped to logical order.  They are still in hardware order.
 */
UINT16 DigitalModule::GetDIODirection(void)
{
	status = 0;
	return m_fpgaDIO->readOutputEnable(&status);
}

/**
 * Generate a single pulse.
 * Write a pulse to the specified digital output channel. There can only be a single pulse going at any time.
 */
void DigitalModule::Pulse(UINT32 channel, float pulseLength)
{
	UINT16 mask = 1 << RemapDigitalChannel(channel - 1);
	m_fpgaDIO->writePulseLength((UINT8)(1.0e9 * pulseLength / (m_fpgaDIO->readLoopTiming(&status) * 25)), &status);
	m_fpgaDIO->writePulse(mask, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Check a DIO line to see if it is currently generating a pulse.
 */
bool DigitalModule::IsPulsing(UINT32 channel)
{
	UINT16 mask = 1 << RemapDigitalChannel(channel - 1);
	UINT16 pulseRegister = m_fpgaDIO->readPulse(&status);
	wpi_assertCleanStatus(status);
	return (pulseRegister & mask) != 0;
}

/**
 * Check if any DIO line is currently generating a pulse.
 */
bool DigitalModule::IsPulsing()
{
	UINT16 pulseRegister = m_fpgaDIO->readPulse(&status);
	wpi_assertCleanStatus(status);
	return pulseRegister != 0;
}

/**
 * Allocate a DO PWM Generator.
 * Allocate PWM generators so that they are not accidently reused.
 */
UINT32 DigitalModule::AllocateDO_PWM()
{
	return DO_PWMGenerators[SlotToIndex(m_slot)]->Allocate();
}

/**
 * Free the resource associated with a DO PWM generator.
 */
void DigitalModule::FreeDO_PWM(UINT32 pwmGenerator)
{
	if (pwmGenerator == ~0ul) return;
	DO_PWMGenerators[SlotToIndex(m_slot)]->Free(pwmGenerator);
}

/**
 * Change the frequency of the DO PWM generator.
 * 
 * The valid range is from 0.6 Hz to 19 kHz.  The frequency resolution is logarithmic.
 * 
 * @param rate The frequency to output all digital output PWM signals on this module.
 */
void DigitalModule::SetDO_PWMRate(float rate)
{
	// Currently rounding in the log rate domain... heavy weight toward picking a higher freq.
	// TODO: Round in the linear rate domain.
	UINT8 pwmPeriodPower = (UINT8)(log(1.0 / (m_fpgaDIO->readLoopTiming(&status) * 0.25E-6 * rate))/log(2.0) + 0.5);
	m_fpgaDIO->writeDO_PWMConfig_PeriodPower(pwmPeriodPower, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Configure which DO channel the PWM siganl is output on
 * @param pwmGenerator The generator index reserved by AllocateDO_PWM()
 * @param channel The Digital Output channel to output on
 */
void DigitalModule::SetDO_PWMOutputChannel(UINT32 pwmGenerator, UINT32 channel)
{
	if (pwmGenerator == ~0ul) return;
	switch(pwmGenerator)
	{
	case 0:
		m_fpgaDIO->writeDO_PWMConfig_OutputSelect_0(RemapDigitalChannel(channel - 1), &status);
		break;
	case 1:
		m_fpgaDIO->writeDO_PWMConfig_OutputSelect_1(RemapDigitalChannel(channel - 1), &status);
		break;
	case 2:
		m_fpgaDIO->writeDO_PWMConfig_OutputSelect_2(RemapDigitalChannel(channel - 1), &status);
		break;
	case 3:
		m_fpgaDIO->writeDO_PWMConfig_OutputSelect_3(RemapDigitalChannel(channel - 1), &status);
		break;
	}
	wpi_assertCleanStatus(status);
}

/**
 * Configure the duty-cycle of the PWM generator
 * @param pwmGenerator The generator index reserved by AllocateDO_PWM()
 * @param dutyCycle The percent duty cycle to output [0..1].
 */
void DigitalModule::SetDO_PWMDutyCycle(UINT32 pwmGenerator, float dutyCycle)
{
	if (pwmGenerator == ~0ul) return;
	if (dutyCycle > 1.0) dutyCycle = 1.0;
	if (dutyCycle < 0.0) dutyCycle = 0.0;
	float rawDutyCycle = 256.0 * dutyCycle;
	if (rawDutyCycle > 255.5) rawDutyCycle = 255.5;
	UINT8 pwmPeriodPower = m_fpgaDIO->readDO_PWMConfig_PeriodPower(&status);
	if (pwmPeriodPower < 4)
	{
		// The resolution of the duty cycle drops close to the highest frequencies.
		rawDutyCycle = rawDutyCycle / pow(2.0, 4 - pwmPeriodPower);
	}
	m_fpgaDIO->writeDO_PWMDutyCycle(pwmGenerator, (UINT8)rawDutyCycle, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Return a pointer to an I2C object for this digital module
 * The caller is responsible for deleting the pointer.
 */
I2C* DigitalModule::GetI2C(UINT32 address)
{
	return new I2C(this, address);
}


