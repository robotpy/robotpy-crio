/**
   \file       NiRioStatus.h
   \author     Dave Madden <david.madden@ni.com>
   \date       02/21/2006

   Copyright (c) 2006-2007. National Instruments. All rights reserved.
*/

#ifndef  ___NiRioSrv_NiRioStatus_H___
#define  ___NiRioSrv_NiRioStatus_H___

// typedefs...
typedef tNIRIO_i32 tRioStatusCode;

// Valid RIO ranges: [-63199, -63000], [63000,63199]
const tRioStatusCode kRioStatusOffset = -63000;

/// The operation was successful
const tRioStatusCode kRioStatusSuccess = 0;

// Errors

// -------------------------------------------------------------------------
// FIFO Error messages...
// -------------------------------------------------------------------------

/// DMA to the FPGA target is not supported by the controller associated with the FPGA (e.g. cRIO-9002/4).
const tRioStatusCode kRioStatusDmaOutputNotSupported        = kRioStatusOffset - 1;

// -------------------------------------------------------------------------
// IO Manager
// -------------------------------------------------------------------------

/// <internal>The parameters do not describe a valid address range</internal>
const tRioStatusCode kRIOStatusIOInvalidAddressRange        = kRioStatusOffset - 10;

/// <internal>The buffer supplied for the I/O operation in invalid</internal>
const tRioStatusCode kRIOStatusIOInvalidBuffer              = kRioStatusOffset - 11;

// -------------------------------------------------------------------------
// Device Errors
// -------------------------------------------------------------------------

/// The operation could not complete because another session has reconfigured the device.
///
/// DEPRECATED in 230
const tRioStatusCode kRIOStatusDeviceReconfigured           = kRioStatusOffset - 30;

/// <internal>The operation is not allowed because another session is accessing the device. Close all other sessions and retry.</internal>
const tRioStatusCode kRIOStatusDeviceInvariant              = kRioStatusOffset - 31;

/// <internal>Download is not allowed because another session is accessing the device. Close all other sessions and retry</internal>.
const tRioStatusCode kRIOStatusDeviceInvalidStateTransition = kRioStatusOffset - 32;

/// The operation was prohibited by the device access settings on the remote system.
const tRioStatusCode kRIOStatusAccessDenied                 = kRioStatusOffset - 33;


// -------------------------------------------------------------------------
// Rpc/Network Errors
// -------------------------------------------------------------------------

/// An Rpc connection could not be made to the remote device. The device may be offline, disconnected, or NI-RIO software may be missing or configured incorrectly
const tRioStatusCode kRIOStatusRpcConnectionError           = kRioStatusOffset - 40;

/// The Rpc server had an error. Close any open sessions and reconnect. The current operation cannot complete.
const tRioStatusCode kRIOStatusRpcServerError               = kRioStatusOffset - 41;

/// A fault on the network caused the operation to fail.
const tRioStatusCode kRIOStatusNetworkFault                 = kRioStatusOffset - 42;

/// The current session is invalid. The target may have reset or been
/// rebooted. The current operation cannot complete. Try again.
const tRioStatusCode kRIOStatusRioRpcSessionError           = kRioStatusOffset - 43;

/// The RIO server is not installed or operating on the target. The
/// current operation cannot complete. Try again.
const tRioStatusCode kRIOStatusRioRpcServerMissing          = kRioStatusOffset - 44;

// -------------------------------------------------------------------------
// Session Errors
// -------------------------------------------------------------------------
/// The specified trigger line is already reserved
const tRioStatusCode kRIOStatusTriggerReserved              = kRioStatusOffset - 50;

/// The specified trigger line is not reserved by the current session.
const tRioStatusCode kRIOStatusTriggerNotReserved           = kRioStatusOffset - 51;

/// Trigger lines are not supported or enabled. For PXI chasses, identify the controller and chassis via MAX.
const tRioStatusCode kRIOStatusTriggerNotSupported          = kRioStatusOffset - 52;


// -------------------------------------------------------------------------
// Event Errors
// -------------------------------------------------------------------------

/// <internal>The specified event type is invalid.</internal>
const tRioStatusCode kRIOStatusEventInvalid                 = kRioStatusOffset - 70;

/// The specified RIO event has already been enabled for this session.
const tRioStatusCode kRIOStatusEventEnabled                 = kRioStatusOffset - 71;

/// The specified RIO event has not been enabled for this session.
const tRioStatusCode kRIOStatusEventNotEnabled              = kRioStatusOffset - 72;

///  The specified RIO event did not complete within the specified time limit.
const tRioStatusCode kRIOStatusEventTimedOut                = kRioStatusOffset - 73;

/// <internal>The specified operation on a the specified Rio event is invalid at this time</internal>.
const tRioStatusCode kRIOStatusEventInvalidOperation        = kRioStatusOffset - 74;

// -------------------------------------------------------------------------
// API Errors
// -------------------------------------------------------------------------

/// Allocated buffer is too small
const tRioStatusCode kRIOStatusBufferInvalidSize            = kRioStatusOffset - 80;

/// Caller did not allocate a buffer
const tRioStatusCode kRIOStatusBufferNotAllocated           = kRioStatusOffset - 81;

/// The fifo is reservered in another session
const tRioStatusCode kRIOStatusFifoReserved                 = kRioStatusOffset - 82;

// -------------------------------------------------------------------------
// PAL Replacements
// -------------------------------------------------------------------------

/// A hardware failure has occurred. The operation could not be completed as specified.
const tRioStatusCode kRIOStatusHardwareFault                = kRioStatusOffset - 150;

/// <internal>The resource was already initialized and cannot be initialized again. The operation could not be completed as specified.</internal>
const tRioStatusCode kRIOStatusResourceInitialized          = kRioStatusOffset - 151;

/// <internal>The requested resource was not found </internal>.
const tRioStatusCode kRIOStatusResourceNotFound             = kRioStatusOffset - 152;

// -------------------------------------------------------------------------
// Configuration
// -------------------------------------------------------------------------

/// A reserved word or an invalid alias was specified. RIO aliases may only contain alphanumerics, '-', and '_'.
const tRioStatusCode kRIOStatusInvalidAliasName             = kRioStatusOffset - 180;

/// The supplied alias was not found.
const tRioStatusCode kRIOStatusAliasNotFound                = kRioStatusOffset - 181;

/// An invalid device access setting was specified. RIO device access patterns may only contain alphanumerics, '-', '_', '.', and '*'.
const tRioStatusCode kRIOStatusInvalidDeviceAccess          = kRioStatusOffset - 182;

/// An invalid port was specified. The RIO Server port must be between 0 and 65535, where 0 indicates a dynamically assigned port. Port 3580 is reserved and cannot be used.
const tRioStatusCode kRIOStatusInvalidPort                  = kRioStatusOffset - 183;

// -------------------------------------------------------------------------
// Misc.
// -------------------------------------------------------------------------

/// The first table segment has overflowed, so this session is on
/// another segment. Only returned as a warning. Client should check
/// for leaked sessions or increase the table segment size in their
/// INI file.
const tRioStatusCode kRIOStatusTableSegmentOverflow         = kRioStatusOffset - 186;

/// This platform does not support connections to remote targets.
const tRioStatusCode kRIOStatusRemoteTarget                 = kRioStatusOffset - 187;

/// The operation is no longer supported
const tRioStatusCode kRIOStatusDeprecatedFunction           = kRioStatusOffset - 188;

/// The supplied search pattern isn't understood
const tRioStatusCode kRIOStatusInvalidPattern               = kRioStatusOffset - 189;

/// <internal>The specified device control code is not recognized.</internal>
const tRioStatusCode kRIOStatusBadDeviceControlCode         = kRioStatusOffset - 190;

/// The supplied resource name is not valid. Use MAX to find the proper resource name.
const tRioStatusCode kRIOStatusInvalidResourceName          = kRioStatusOffset - 192;

/// The requested feature is not supported in the current version of the driver software on either the host or the target.
const tRioStatusCode kRIOStatusFeatureNotSupported          = kRioStatusOffset - 193;

/// The version of the target software is incompatible. Upgrade target software to get full functionality. (For use by host interface).
const tRioStatusCode kRIOStatusVersionMismatch              = kRioStatusOffset - 194;

/// A handle for device communication is invalid. The device connection has been lost.
const tRioStatusCode kRIOStatusInvalidHandle                = kRioStatusOffset - 195;

/// An invalid attribute has been specified.
const tRioStatusCode kRIOStatusInvalidAttribute             = kRioStatusOffset - 196;

/// An invalid attribute value has been specified.
const tRioStatusCode kRIOStatusInvalidAttributeValue        = kRioStatusOffset - 197;

/// The system has run out of resource handles. Try closing some sessions.
const tRioStatusCode kRIOStatusOutOfHandles                 = kRioStatusOffset - 198;

/// <internal>The server does not recognize the command</internal>
const tRioStatusCode kRIOStatusInvalidFunction              = kRioStatusOffset - 199;

// -------------------------------------------------------------------------
// APAL translation
// #define nNIAPALS100_tStatus_kOffset    -52000
// -------------------------------------------------------------------------

/// nNIAPALS100_tStatus_kMemoryFull. The specified number of bytes could not be allocated
const tRioStatusCode kRIOStatusMemoryFull                   = -52000;

/// nNIAPALS100_tStatus_kPageLockFailed. The memory could not be page locked
const tRioStatusCode kRIOStatusPageLockFailed               = -52001;

/// nNIAPALS100_tStatus_kSoftwareFault. An unexpected software error occurred.
const tRioStatusCode kRIOStatusSoftwareFault                = -52003;

/// nNIAPALS100_tStatus_kDynamicCastFailed. The dynamic cast operation failed.
const tRioStatusCode kRIOStatusDynamicCastFailed            = -52004;

/// nNIAPALS100_tStatus_kInvalidParameter. The parameter recieved by the function is not valid.
const tRioStatusCode kRIOStatusInvalidParameter             = -52005;

/// nNIAPALS100_tStatus_kOperationTimedOut. The requested operation did not complete in time.
const tRioStatusCode kRIOStatusOperationTimedOut            = -52007;

/// nNIAPALS100_tStatus_kOSFault. An unexpected operationg system error occurred.
const tRioStatusCode kRIOStatusOSFault                      = -52008;

/// nNIAPALS100_tStatus_kResourceMarkedForDelete. The requested resource has been marked for deletion and is rejecting new requests.
const tRioStatusCode kRIOStatusMarkedForDelete              = -52009;

/// nNIAPALS100_tStatus_kResourceNotInitialized. The requested resource must be initializaed before use.
const tRioStatusCode kRIOStatusResourceNotInitialized       = -52010;

/// nNIAPALS100_tStatus_kOperationPending. The operation has begun and will complete asynchronously.
const tRioStatusCode kRIOStatusOperationPending             = -52011;

/// nNIAPALS100_tStatus_kEndOfData. There is no more data available to read or no more space available in which to write.
const tRioStatusCode kRIOStatusEndOfData                    = -52012;

/// nNIAPALS100_tStatus_kObjectNameCollision. The name or handle requested has already been reserved by another client
const tRioStatusCode kRIOStatusObjectNameCollision          = -52013;

/// nNIAPALS100_tStatus_kSyncronizationObjectAbandoned. The synchronization object was abandoned by the previous holder
const tRioStatusCode kRIOStatusSyncObjectAbandoned          = -52014;

/// nNIAPALS100_tStatus_kSyncronizationAcquireFailed. The acquisition of the synchronization object failed
const tRioStatusCode kRIOStatusSyncAcquireFailed            = -52015;

/// nNIAPALS100_tStatus_kThreadAlreadyStarted. The thread was running when you attempted to start it (redundant state change).
const tRioStatusCode kRIOStatusThreadAlreadyStarted         = -52016;

/// nNIAPALS100_tStatus_kInvalidStateTransition. The operation you requested is redundant or invalid when the object is in this state.
const tRioStatusCode kRIOStatusInvalidStateTransition       = -52017;

// -------------------------------------------------------------------------
// Traditional PAL translation
// #define nNIAPALS100_tStatus_kOffset    -50000
// -------------------------------------------------------------------------
/// An attribute whether explicit or implicit is not relevant or is not relevant given the current system state. The operation could not be completed as specified.
const tRioStatusCode kRIOStatusIrrelevantAttribute          = -50001;

/// A selector - usually of an enumerated type - is inappropriate or out of range. The operation could not be completed as specified.
const tRioStatusCode kRIOStatusBadSelector                  = -50003;

/// The specified software component is not available. The component was not loaded.
const tRioStatusCode kRIOStatusComponentNotFound            = -50251;

/// The specified device is not present or is deactivated. The operation could not be completed as specified.
const tRioStatusCode kRIOStatusDeviceNotFound               = -50300;

/// The operation was aborted.
const tRioStatusCode kRIOStatusOperationAborted             = -50405;

// -------------------------------------------------------------------------
// LabVIEW FPGA errors
// -------------------------------------------------------------------------

// Error during download
const tRioStatusCode kFpgaStatusDownloadError               = -61018;

// Device type incorrect
const tRioStatusCode kFpgaStatusDeviceTypeIncorrect         = -61024;

// -------------------------------------------------------------------------
// LabVIEW errors
// -------------------------------------------------------------------------

/// Generic file I/O error.
const tRioStatusCode kRIOStatusFileError                    = -6;

//
// Helper functions
//

inline bool rioStatusIsFatal(const tRioStatusCode status)
{
   return status < 0;
}

inline bool rioStatusIsNotFatal(const tRioStatusCode status)
{
   return status >= 0;
}

#ifdef __cplusplus
template <typename T>
inline T& rioSetStatus(T&                   status,
                       const tRioStatusCode newStatus)
{
   if (status >= 0 && (status == 0 || newStatus < 0)) {
      status = newStatus;
   }
   return status;
}
#endif

#endif // ___NiRioSrv_NiRioStatus_H___
