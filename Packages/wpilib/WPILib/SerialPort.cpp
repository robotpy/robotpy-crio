/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SerialPort.h"

#include "Utility.h"
#include "visa/visa.h"

//static ViStatus _VI_FUNCH ioCompleteHandler (ViSession vi, ViEventType eventType, ViEvent event, ViAddr userHandle);

/**
 * Create an instance of a Serial Port class.
 * 
 * @param baudRate The baud rate to configure the serial port.  The cRIO-9074 supports up to 230400 Baud.
 * @param dataBits The number of data bits per transfer.  Valid values are between 5 and 8 bits.
 * @param parity Select the type of parity checking to use.
 * @param stopBits The number of stop bits to use as defined by the enum StopBits.
 */
SerialPort::SerialPort(UINT32 baudRate, UINT8 dataBits, SerialPort::Parity parity, SerialPort::StopBits stopBits)
	: m_resourceManagerHandle (0)
	, m_portHandle (0)
	, m_consoleModeEnabled (false)
{
	ViStatus status = VI_SUCCESS;
	status = viOpenDefaultRM((ViSession*)&m_resourceManagerHandle);
	wpi_assertCleanStatus(status);

	status = viOpen(m_resourceManagerHandle, "ASRL1::INSTR", VI_NULL, VI_NULL, (ViSession*)&m_portHandle);
	wpi_assertCleanStatus(status);
	if (status != 0)
	{
		m_consoleModeEnabled = true;
		return;
	}

	status = viSetAttribute(m_portHandle, VI_ATTR_ASRL_BAUD, baudRate);
	wpi_assertCleanStatus(status);
	status = viSetAttribute(m_portHandle, VI_ATTR_ASRL_DATA_BITS, dataBits);
	wpi_assertCleanStatus(status);
	status = viSetAttribute(m_portHandle, VI_ATTR_ASRL_PARITY, parity);
	wpi_assertCleanStatus(status);
	status = viSetAttribute(m_portHandle, VI_ATTR_ASRL_STOP_BITS, stopBits);
	wpi_assertCleanStatus(status);

	// Set the default timeout to 5 seconds.
	SetTimeout(5.0f);

	// Don't wait until the buffer is full to transmit.
	SetWriteBufferMode(kFlushOnAccess);

	EnableTermination();

	//viInstallHandler(m_portHandle, VI_EVENT_IO_COMPLETION, ioCompleteHandler, this);
	//viEnableEvent(m_portHandle, VI_EVENT_IO_COMPLETION, VI_HNDLR, VI_NULL);
}

/**
 * Destructor.
 */
SerialPort::~SerialPort()
{
	if (!m_consoleModeEnabled)
	{
		//viUninstallHandler(m_portHandle, VI_EVENT_IO_COMPLETION, ioCompleteHandler, this);
		viClose(m_portHandle);
	}
	viClose(m_resourceManagerHandle);
}

/**
 * Set the type of flow control to enable on this port.
 * 
 * By default, flow control is disabled.
 */
void SerialPort::SetFlowControl(SerialPort::FlowControl flowControl)
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viSetAttribute (m_portHandle, VI_ATTR_ASRL_FLOW_CNTRL, flowControl);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Enable termination and specify the termination character.
 * 
 * Termination is currently only implemented for receive.
 * When the the terminator is recieved, the Read() or Scanf() will return
 *   fewer bytes than requested, stopping after the terminator.
 * 
 * @param terminator The character to use for termination.
 */
void SerialPort::EnableTermination(char terminator)
{
	if (!m_consoleModeEnabled)
	{
		viSetAttribute(m_portHandle, VI_ATTR_TERMCHAR_EN, VI_TRUE); 
		viSetAttribute(m_portHandle, VI_ATTR_TERMCHAR, terminator);
		viSetAttribute(m_portHandle, VI_ATTR_ASRL_END_IN, VI_ASRL_END_TERMCHAR);
	}
}

/**
 * Disable termination behavior.
 */
void SerialPort::DisableTermination()
{
	if (!m_consoleModeEnabled)
	{
		viSetAttribute(m_portHandle, VI_ATTR_TERMCHAR_EN, VI_FALSE); 
		viSetAttribute(m_portHandle, VI_ATTR_ASRL_END_IN, VI_ASRL_END_NONE);
	}
}

/**
 * Get the number of bytes currently available to read from the serial port.
 * 
 * @return The number of bytes available to read.
 */
INT32 SerialPort::GetBytesReceived()
{
	INT32 bytes = 0;
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viGetAttribute(m_portHandle, VI_ATTR_ASRL_AVAIL_NUM, &bytes);
		wpi_assertCleanStatus(status);
	}
	return bytes;
}

/**
 * Output formatted text to the serial port.
 * 
 * @bug All pointer-based parameters seem to return an error.
 * 
 * @param writeFmt A string that defines the format of the output.
 */
void SerialPort::Printf(const char *writeFmt, ...)
{
	if (!m_consoleModeEnabled)
	{
		va_list args;
		va_start (args, writeFmt);
		ViStatus status = viVPrintf(m_portHandle, (ViString)writeFmt, args);
		va_end (args);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Input formatted text from the serial port.
 * 
 * @bug All pointer-based parameters seem to return an error.
 * 
 * @param readFmt A string that defines the format of the input.
 */
void SerialPort::Scanf(const char *readFmt, ...)
{
	if (!m_consoleModeEnabled)
	{
		va_list args;
		va_start (args, readFmt);
		ViStatus status = viVScanf(m_portHandle, (ViString)readFmt, args);
		va_end (args);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Read raw bytes out of the buffer.
 * 
 * @param buffer Pointer to the buffer to store the bytes in.
 * @param count The maximum number of bytes to read.
 * @return The number of bytes actually read into the buffer.
 */ 
UINT32 SerialPort::Read(char *buffer, INT32 count)
{
	UINT32 retCount = 0;
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viBufRead(m_portHandle, (ViPBuf)buffer, count, (ViPUInt32)&retCount);
		switch (status)
		{
		case VI_SUCCESS_TERM_CHAR:
		case VI_SUCCESS_MAX_CNT:
		case VI_ERROR_TMO: // Timeout
			break;
		default:
			wpi_assertCleanStatus(status);
		}
	}
	return retCount;
}

/**
 * Write raw bytes to the buffer.
 * 
 * @param buffer Pointer to the buffer to read the bytes from.
 * @param count The maximum number of bytes to write.
 * @return The number of bytes actually written into the port.
 */ 
UINT32 SerialPort::Write(const char *buffer, INT32 count)
{
	UINT32 retCount = 0;
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viBufWrite(m_portHandle, (ViPBuf)buffer, count, (ViPUInt32)&retCount);
		wpi_assertCleanStatus(status);
	}
	return retCount;
}

/**
 * Configure the timeout of the serial port.
 * 
 * This defines the timeout for transactions with the hardware.
 * It will affect reads and very large writes.
 * 
 * @param timeout The number of seconds to to wait for I/O.
 */
void SerialPort::SetTimeout(float timeout)
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viSetAttribute(m_portHandle, VI_ATTR_TMO_VALUE, (UINT32)(timeout * 1e3));
		wpi_assertCleanStatus(status);
	}
}

/**
 * Specify the size of the input buffer.
 * 
 * Specify the amount of data that can be stored before data
 * from the device is returned to Read or Scanf.  If you want
 * data that is recieved to be returned immediately, set this to 1.
 * 
 * It the buffer is not filled before the read timeout expires, all
 * data that has been received so far will be returned.
 * 
 * @param size The read buffer size.
 */
void SerialPort::SetReadBufferSize(UINT32 size)
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viSetBuf(m_portHandle, VI_READ_BUF, size);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Specify the size of the output buffer.
 * 
 * Specify the amount of data that can be stored before being
 * transmitted to the device.
 * 
 * @param size The write buffer size.
 */
void SerialPort::SetWriteBufferSize(UINT32 size)
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viSetBuf(m_portHandle, VI_WRITE_BUF, size);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Specify the flushing behavior of the output buffer.
 * 
 * When set to kFlushOnAccess, data is synchronously written to the serial port
 *   after each call to either Printf() or Write().
 * 
 * When set to kFlushWhenFull, data will only be written to the serial port when
 *   the buffer is full or when Flush() is called.
 * 
 * @param mode The write buffer mode.
 */
void SerialPort::SetWriteBufferMode(SerialPort::WriteBufferMode mode)
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viSetAttribute(m_portHandle, VI_ATTR_WR_BUF_OPER_MODE, mode);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Force the output buffer to be written to the port.
 * 
 * This is used when SetWriteBufferMode() is set to kFlushWhenFull to force a
 * flush before the buffer is full.
 */
void SerialPort::Flush()
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viFlush(m_portHandle, VI_WRITE_BUF);
		wpi_assertCleanStatus(status);
	}
}

/**
 * Reset the serial port driver to a known state.
 * 
 * Empty the transmit and receive buffers in the device and formatted I/O.
 */
void SerialPort::Reset()
{
	if (!m_consoleModeEnabled)
	{
		ViStatus status = viClear(m_portHandle);
		wpi_assertCleanStatus(status);
	}
}

//void SerialPort::_internalHandler(UINT32 port, UINT32 eventType, UINT32 event)
//{
//}

//ViStatus _VI_FUNCH ioCompleteHandler (ViSession vi, ViEventType eventType, ViEvent event, ViAddr userHandle)
//{
//	((SerialPort*) userHandle)->_internalHandler(vi, eventType, event);
//	return VI_SUCCESS;
//}

