/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "ErrorBase.h"
#include "Synchronized.h"

SEM_ID ErrorBase::globalErrorMutex = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
Error ErrorBase::globalError;
/**
 * @brief Initialize the instance status to 0 for now.
 */
ErrorBase::ErrorBase():
	status(0)
{}

ErrorBase::~ErrorBase()
{}

/**
 * @brief Retrieve the current error.
 * Get the current error information associated with this sensor.
 */
Error& ErrorBase::GetError()
{	return error;  }

const Error& ErrorBase::GetError() const
{	return error;  }

/**
 * @brief Clear the current error information associated with this sensor.
 */
void ErrorBase::ClearError()
{	error.Clear();  }

/**
 * @brief Set the current error information associated with this sensor.
 * 
 * @param code The error code
 * @param filename Filename of the error source
 * @param lineNumber Line number of the error source
 */
void ErrorBase::SetError(Error::Code code, const char* filename, UINT32 lineNumber) const
{
    //  If there was an error
    if (code != 0) {
        //  Set the current error information for this object.
        error.Set(code, filename, lineNumber, this);
        // Update the global error if there is not one already set.
        CRITICAL_REGION(globalErrorMutex);
        if (globalError.GetCode() == 0) {
            globalError = error;
        }
        END_REGION
    }
}

/**
@brief Check if the current error code represents a fatal error.
  
@return true if the current error is fatal.
*/
bool ErrorBase::StatusIsFatal() const {
    return error.GetCode() < 0;
}


/**
  * Retrieve the current global error.    
*/
Error& ErrorBase::GetGlobalError() {
    CRITICAL_REGION(globalErrorMutex);
    return globalError;
    END_REGION
}

