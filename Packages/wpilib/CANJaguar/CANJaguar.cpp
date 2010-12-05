
#include "CANJaguar.h"
#define tNIRIO_i32 int
#include "ChipObject/NiRioStatus.h"
#include "JaguarCANDriver.h"
#define FIRST_FIRMWARE_VERSION
#include "can_proto.h"
#undef FIRST_FIRMWARE_VERSION
#include "Utility.h"

#define swap16(x) ( (((x)>>8) &0x00FF) \
                  | (((x)<<8) &0xFF00) )
#define swap32(x) ( (((x)>>24)&0x000000FF) \
                  | (((x)>>8) &0x0000FF00) \
                  | (((x)<<8) &0x00FF0000) \
                  | (((x)<<24)&0xFF000000) )

#define kFullMessageIDMask (CAN_MSGID_API_M | CAN_MSGID_MFR_M | CAN_MSGID_DTYPE_M)

/**
 * Common initialization code called by all constructors.
 */
void CANJaguar::InitJaguar()
{
	if (m_deviceNumber < 1 || m_deviceNumber > 63)
	{
		// Error
	}
	UINT32 fwVer = GetFirmwareVersion();
	if (fwVer >= 3330 || fwVer < 85)
	{
		wpi_assertCleanStatus(kRIOStatusVersionMismatch);
		return;
	}
	switch (m_controlMode)
	{
	case kPercentVoltage:
		sendMessage(LM_API_VOLT_T_EN | m_deviceNumber, NULL, 0);
		break;
	default:
		return;
	}
}

/**
 * Constructor
 * 
 * @param deviceNumber The the address of the Jaguar on the CAN bus.
 */
CANJaguar::CANJaguar(UINT8 deviceNumber, ControlMode controlMode)
	: m_deviceNumber (deviceNumber)
	, m_controlMode (controlMode)
{
	InitJaguar();
}

CANJaguar::~CANJaguar()
{
}

/**
 * Set the output set-point value.  
 * 
 * In PercentVoltage Mode, the input is in the range -1.0 to 1.0
 * 
 * @param outputValue The set-point to sent to the motor controller.
 */
void CANJaguar::Set(float outputValue)
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	switch(m_controlMode)
	{
	case kPercentVoltage:
		messageID = LM_API_VOLT_T_SET | m_deviceNumber;
		INT16 value = (INT16)(outputValue * 32767.0);
		*((INT16*)dataBuffer) = swap16(value);
		dataSize = sizeof(INT16);
		break;
	default:
		return;
	}
	sendMessage(messageID, dataBuffer, dataSize);
}

/**
 * Get the recently set outputValue setpoint.
 * 
 * In PercentVoltage Mode, the outputValue is in the range -1.0 to 1.0
 * 
 * @return The most recently set outputValue setpoint.
 */
float CANJaguar::Get()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	switch(m_controlMode)
	{
	case kPercentVoltage:
		messageID = LM_API_VOLT_SET | m_deviceNumber;
		// Sending set with no data is a request for the last set
		sendMessage(messageID, NULL, 0);
		receiveMessage(&messageID, dataBuffer, &dataSize);
		if (dataSize == sizeof(INT16))
		{
			INT16 replyValue = *((INT16*)dataBuffer);
			return swap16(replyValue) / 32767.0;
		}
		else
		{
			// TODO: Error
			return 0.0;
		}
		break;
	default:
		return 0.0;
	}
}

/**
 * Write out the PID value as seen in the PIDOutput base object.
 * 
 * @param output Write out the percentage voltage value as was computed by the PIDController
 */
void CANJaguar::PIDWrite(float output)
{
	if (m_controlMode == kPercentVoltage)
	{
		Set(output);
	}
	else
	{
		// TODO: Error
	}
}

/**
 * Send a message on the CAN bus through the CAN driver in FRC_NetworkCommunication
 * 
 * Trusted messages require a 2-byte token at the beginning of the data payload.
 * If the message being sent is trusted, make space for the token.
 * 
 * @param messageID The messageID to be used on the CAN bus
 * @param data The up to 8 bytes of data to be sent with the message
 * @param dataSize Specify how much of the data in "data" to send
 */
void CANJaguar::sendMessage(UINT32 messageID, const UINT8 *data, UINT8 dataSize)
{
	static const UINT32 kTrustedMessages[] = {
			LM_API_VOLT_T_EN, LM_API_VOLT_T_SET, LM_API_SPD_T_EN, LM_API_SPD_T_SET,
			LM_API_POS_T_EN, LM_API_POS_T_SET, LM_API_ICTRL_T_EN, LM_API_ICTRL_T_SET};
	INT32 status=0;

	for (UINT8 i=0; i<(sizeof(kTrustedMessages)/sizeof(kTrustedMessages[0])); i++)
	{
		if ((kFullMessageIDMask & messageID) == kTrustedMessages[i])
		{
			UINT8 dataBuffer[8];
			dataBuffer[0] = 0;
			dataBuffer[1] = 0;
			// Make sure the data will still fit after adjusting for the token.
			if (dataSize > 6)
			{
				// TODO: Error
				return;
			}
			for (UINT8 j=0; j < dataSize; j++)
			{
				dataBuffer[j + 2] = data[j];
			}
			FRC_NetworkCommunication_JaguarCANDriver_sendMessage(messageID, dataBuffer, dataSize + 2, &status);
			wpi_assertCleanStatus(status);
			return;
		}
	}
	FRC_NetworkCommunication_JaguarCANDriver_sendMessage(messageID, data, dataSize, &status);
	wpi_assertCleanStatus(status);
}

/**
 * Receive a message from the CAN bus through the CAN driver in FRC_NetworkCommunication
 * 
 * @param messageID The messageID to read from the CAN bus
 * @param data The up to 8 bytes of data that was received with the message
 * @param dataSize Indicates how much data was received
 * @param timeout Specify how long to wait for a message (in seconds)
 */
void CANJaguar::receiveMessage(UINT32 *messageID, UINT8 *data, UINT8 *dataSize, float timeout)
{
	INT32 status = 0;
	FRC_NetworkCommunication_JaguarCANDriver_receiveMessage(messageID, data, dataSize,
			(UINT32)(timeout * 1000), &status);
	wpi_assertCleanStatus(status);
}

/**
 * Get the voltage at the battery input terminals of the Jaguar.
 * 
 * @return The bus voltage in Volts.
 */
float CANJaguar::GetBusVoltage()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_VOLTBUS | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT16))
	{
		return swap16(*((INT16*)dataBuffer)) / 256.0;
	}
	return 0.0;
}

/**
 * Get the voltage being output from the motor terminals of the Jaguar.
 * 
 * @return The output voltage in Volts.
 */
float CANJaguar::GetOutputVoltage()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;
	float busVoltage;

	// Read the bus voltage first so we can return units of volts
	messageID = LM_API_STATUS_VOLTBUS | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT16))
	{
		busVoltage = swap16(*((INT16*)dataBuffer)) / 256.0;

		// Then read the volt out which is in percentage of bus voltage units.
		messageID = LM_API_STATUS_VOLTOUT | m_deviceNumber;
		sendMessage(messageID, NULL, 0);
		receiveMessage(&messageID, dataBuffer, &dataSize);
		if (dataSize == sizeof(INT16))
		{
			return busVoltage * (INT16)swap16(*((INT16*)dataBuffer)) / 32767.0;
		}
	}
	return 0.0;
}

/**
 * Get the current through the motor terminals of the Jaguar.
 * 
 * @return The output current in Amps.
 */
float CANJaguar::GetOutputCurrent()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_CURRENT | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT16))
	{
		return swap16(*((INT16*)dataBuffer)) / 256.0;
	}
	return 0.0;
}

/**
 * Get the internal temperature of the Jaguar.
 * 
 * @return The temperature of the Jaguar in degrees Celsius.
 */
float CANJaguar::GetTemperature()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_TEMP | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT16))
	{
		return swap16(*((INT16*)dataBuffer)) / 256.0;
	}
	return 0.0;
}

/**
 * Get the position of the encoder or potentiometer.
 * 
 * @return The position of the motor based on the configured feedback.
 */
double CANJaguar::GetPosition()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_POS | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT32))
	{
		return swap32(*((INT32*)dataBuffer)) / 65536.0;
	}
	return 0.0;
}

/**
 * Get the speed of the encoder.
 * 
 * @return The speed of the motor in RPM based on the configured feedback.
 */
double CANJaguar::GetSpeed()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_SPD | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(INT32))
	{
		return swap32(*((INT32*)dataBuffer)) / 65536.0;
	}
	return 0.0;
}

/**
 * Get the status of the forward limit switch.
 * 
 * @return The motor is allowed to turn in the forward direction when true.
 */
bool CANJaguar::GetForwardLimitOK()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_LIMIT | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(UINT8))
	{
		return (*((UINT8*)dataBuffer) & kForwardLimit) != 0;
	}
	return 0;
}

/**
 * Get the status of the reverse limit switch.
 * 
 * @return The motor is allowed to turn in the reverse direction when true.
 */
bool CANJaguar::GetReverseLimitOK()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_LIMIT | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(UINT8))
	{
		return (*((UINT8*)dataBuffer) & kReverseLimit) != 0;
	}
	return 0;
}

/**
 * Get the status of any faults the Jaguar has detected.
 * 
 * @return A bit-mask of faults defined by the "Faults" enum.
 */
UINT16 CANJaguar::GetFaults()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_FAULT | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(UINT16))
	{
		return swap16(*((UINT16*)dataBuffer));
	}
	return 0;
}

/**
 * Check if the Jaguar's power has been cycled since this was last called.
 * 
 * This should return true the first time called after a Jaguar power up,
 * and false after that.
 * 
 * @return The Jaguar was power cycled since the last call to this function.
 */
bool CANJaguar::GetPowerCycled()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = LM_API_STATUS_POWER | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(UINT8))
	{
		bool powerCycled = *((UINT8*)dataBuffer) != 0;

		// Clear the power cycled bit now that we've accessed it
		dataBuffer[0] = 1;
		sendMessage(messageID, dataBuffer, sizeof(UINT8));

		return powerCycled;
	}
	return 0;
}

UINT32 CANJaguar::GetFirmwareVersion()
{
	UINT32 messageID;
	UINT8 dataBuffer[8];
	UINT8 dataSize;

	messageID = CAN_MSGID_API_FIRMVER | m_deviceNumber;
	sendMessage(messageID, NULL, 0);
	receiveMessage(&messageID, dataBuffer, &dataSize);
	if (dataSize == sizeof(UINT32))
	{
		return *((UINT32*)dataBuffer);
	}
	return 0;
}

