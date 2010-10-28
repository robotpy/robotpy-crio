
#ifndef CANJAGUAR_H
#define CANJAGUAR_H

#include "SpeedController.h"
#include "PIDOutput.h"
#include <vxWorks.h>

/**
 * Luminary Micro Jaguar Speed Control
 */
class CANJaguar : public SpeedController, public PIDOutput
{
public:
	typedef enum {kPercentVoltage, kSpeed, kPosition, kCurrent} ControlMode;
	typedef enum {kCurrentFault = 1, kTemperatureFault = 2, kBusVoltageFault = 4} Faults;
	typedef enum {kForwardLimit = 1, kReverseLimit = 2} Limits;

	explicit CANJaguar(UINT8 deviceNumber, ControlMode controlMode = kPercentVoltage);
	virtual ~CANJaguar();

	// SpeedController interface
	float Get();
	void Set(float value);

	// PIDOutput interface
	void PIDWrite(float output);

	// Other Accessors
	float GetBusVoltage();
	float GetOutputVoltage();
	float GetOutputCurrent();
	float GetTemperature();
	double GetPosition();
	double GetSpeed();
	bool GetForwardLimitOK();
	bool GetReverseLimitOK();
	UINT16 GetFaults();
	bool GetPowerCycled();
	UINT32 GetFirmwareVersion();
protected:
	void sendMessage(UINT32 messageID, const UINT8 *data, UINT8 dataSize);
	void receiveMessage(UINT32 *messageID, UINT8 *data, UINT8 *dataSize, float timeout = 0.1);
	UINT8 m_deviceNumber;
	ControlMode m_controlMode;

private:
	void InitJaguar();
};
#endif

