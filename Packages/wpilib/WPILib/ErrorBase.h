/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef _ERROR_BASE_H
#define _ERROR_BASE_H

#include "Base.h"
#include "ChipObject.h"
#include "Error.h"
#include <semLib.h>
#include <vxWorks.h>

/// Use this macro to set the error.
#define wpi_setError(errorBase, code)   ((errorBase).SetError((code), __FILE__, __LINE__))

/**
 * Base class for most objects.
 * ErrorBase is the base class for most objects since it holds the generated error
 * for that object. In addition, there is a single instance of a global error object
 */
class ErrorBase
{
//TODO: Consider initializing instance variables and cleanup in destructor
public:
	virtual ~ErrorBase();
	virtual Error& GetError();
	virtual const Error& GetError() const;
	virtual void SetError(Error::Code code, const char* filename, UINT32 lineNumber) const;
    virtual void ClearError();
    virtual bool StatusIsFatal() const;
    static Error& GetGlobalError();
protected:
    //  TODO: Get rid of status when rest of the code does not need it
    tRioStatusCode status;
	mutable Error error;
    static SEM_ID globalErrorMutex;
	static Error globalError;
	ErrorBase();
private:
	DISALLOW_COPY_AND_ASSIGN(ErrorBase);
};

#endif
