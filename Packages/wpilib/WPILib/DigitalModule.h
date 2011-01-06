/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef DIGITAL_MODULE_H_
#define DIGITAL_MODULE_H_

#include "Module.h"
#include "ChipObject.h"

class I2C;

const UINT32 kExpectedLoopTiming = 261;

class DigitalModule: public Module
{
	friend class I2C;

protected:
	explicit DigitalModule(UINT32 slot);
	virtual ~DigitalModule();

public:
	void SetPWM(UINT32 channel, UINT8 value);
	UINT8 GetPWM(UINT32 channel);
	void SetPWMPeriodScale(UINT32 channel, UINT32 squelchMask);
	void SetRelayForward(UINT32 channel, bool on);
	void SetRelayReverse(UINT32 channel, bool on);
	bool GetRelayForward(UINT32 channel);
	UINT8 GetRelayForward(void);
	bool GetRelayReverse(UINT32 channel);
	UINT8 GetRelayReverse(void);
	bool AllocateDIO(UINT32 channel, bool input);
	void FreeDIO(UINT32 channel);
	void SetDIO(UINT32 channel, short value);
	bool GetDIO(UINT32 channel);
	UINT16 GetDIO(void);
	bool GetDIODirection(UINT32 channel);
	UINT16 GetDIODirection(void);
	void Pulse(UINT32 channel, float pulseLength);
	bool IsPulsing(UINT32 channel);
	bool IsPulsing();
	UINT32 AllocateDO_PWM();
	void FreeDO_PWM(UINT32 pwmGenerator);
	void SetDO_PWMRate(float rate);
	void SetDO_PWMDutyCycle(UINT32 pwmGenerator, float dutyCycle);
	void SetDO_PWMOutputChannel(UINT32 pwmGenerator, UINT32 channel);

	I2C* GetI2C(UINT32 address);

	static UINT32 SlotToIndex(UINT32 slot);
	static DigitalModule* GetInstance(UINT32 slot);
	static UINT8 RemapDigitalChannel(UINT32 channel) { return 15 - channel; }; // TODO: Need channel validation
	static UINT8 UnmapDigitalChannel(UINT32 channel) { return 15 - channel; }; // TODO: Need channel validation

private:
	SEM_ID m_relaySemaphore;
	tDIO *m_fpgaDIO;
};

#endif

