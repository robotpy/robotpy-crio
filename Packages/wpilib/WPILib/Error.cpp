/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Error.h"

Error::Error() :
    m_code(0), 
    m_lineNumber(0),
    m_originatingObject(NULL)
{}

Error::~Error()
{}

Error::Code Error::GetCode() const
{	return m_code;  }

const char * Error::GetMessage() const
{	return m_message.c_str();  }


const char * Error::GetFilename() const
{	return m_filename.c_str();  }

UINT32 Error::GetLineNumber() const
{	return m_lineNumber;  }

const ErrorBase* Error::GetOriginatingObject() const
{	return m_originatingObject;  }

void Error::Set(Code code, const char* filename, UINT32 lineNumber, const ErrorBase* originatingObject)
{
	m_code = code;
    //TODO: Get the message from the "to be generated error, message" pair table.
    //m_message = message;
    m_filename = filename;
	m_lineNumber = lineNumber;
    m_originatingObject = originatingObject;
}

void Error::Clear()
{
	m_code = 0;
	m_message = "";
    m_filename = "";
	m_lineNumber = 0;
    m_originatingObject = NULL;
}

