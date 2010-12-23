/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef _ERROR_H
#define _ERROR_H

#include "Base.h"
#include "ChipObject/NiRio.h"
#include <string>
#include <vxWorks.h>

//  Forward declarations
class ErrorBase;

/**
 * Error object represents a library error.
 */
class Error
{
public:
    typedef tRioStatusCode Code;

	Error();
	~Error();
	Code GetCode() const;
	const char *GetMessage() const;
	const char *GetFilename() const;
	UINT32 GetLineNumber() const;
    const ErrorBase* GetOriginatingObject() const;
	void Clear();
	void Set(Code code, const char* filename, UINT32 lineNumber, const ErrorBase* originatingObject);

private:
	Code m_code;
	std::string m_message;
    std::string m_filename;
	UINT32 m_lineNumber;
    const ErrorBase* m_originatingObject;
//TODO: Consider putting this back
//	DISALLOW_COPY_AND_ASSIGN(Error);
};

#endif

