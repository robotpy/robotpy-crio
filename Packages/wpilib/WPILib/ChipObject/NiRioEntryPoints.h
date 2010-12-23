/**
   \file       NiRioEntryPoints.h
   \author     Erik Hons <erik.hons@ni.com>
   \date       12/14/2004

   \brief Declarations for RIO services client DLL entry points

   Intended to be called from a C client, or the LabVIEW
   interface.

   Copyright (c) 2004. National Instruments. All rights reserved.
*/

#ifndef  ___NiRioSrv_NiRioEntryPoints_H___
#define  ___NiRioSrv_NiRioEntryPoints_H___

// includes...
#include "NiRioStatus.h"

// typedefs...
typedef tNIRIO_u32 tRioDeviceHandle;


#ifdef __cplusplus
extern "C" {
#endif


// ---------------------------
// Utilities:

// freeString()
//
// Used to free the memory for any string returned from these
// entry-points. Passing NULL is a no-op.
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_freeString(     char* s)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_freeStringFn)(char* s);

// ---------------------------
// Device Discovery:

// NiRioSrv_host_getResourceString
//
// Enumerate RIO resources that match the supplied search pattern on
// the specified host.
//
// host:
//     NULL, ""              : Local host
//     "rio://<host_name>/"  : Remote host
//     "visa://<host_name>/" : Remote host (deprecated)
//
// pattern:
//     NULL, ""              : All devices
//
// index       : 0-based index of string to return (0 refreshes list).
// resource    : on success, set to a new character buffer with the
//             :     requested string
//
// returns     : resource string, or NULL on error
//
// To enumerate resources, repeat this call with idx == 0, 1, 2,
// ... until NULL is returned. Note: idx == 0 performs an internal
// refresh of the list for the specified host+pattern.
//
// Client must freeString() any non-NULL return value.
//
kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_host_getResourceString(const char*     host,
                                               const char*     pattern,
                                               tNIRIO_u32      index,
                                               tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_host_getResourceStringFn)(
                                               const char*     host,
                                               const char*     pattern,
                                               tNIRIO_u32      index,
                                               tRioStatusCode* status);

// ---------------------------
// Device Handles:

// open(): Get a device handle for the specified RIO resource. The
// handle must be released before unloading this
//
// returns: tNIRIO_u32 device handle (0 if error)
//
kNIRIOSRVExportPre tRioDeviceHandle
kNIRIOSRVCCall NiRioSrv_device_open(const char*     resource,
                                    tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef tRioDeviceHandle
(kNIRIOSRVCCall *NiRioSrv_device_openFn)(const char*     resource,
                                         tRioStatusCode* status);

// close(): Release the specified device handle.
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_close(tRioDeviceHandle hClient,
                                     tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_closeFn)(tRioDeviceHandle hClient,
                                          tRioStatusCode*  status);


// ---------------------------
// RIO Device Interface:
//
// This set of functions allow RIO device access using a logical
// handle (obtained using NiRioSrv_getDeviceByResourceString()).
//
// Each device function accepts a handle and provides optional status
// chaining via the status parameter (status may be NULL).
//
// NOTE: All device handles are independant even if they reference the
// same device. i.e.: a caller cannot wait on events using handle A,
// if the events were enabled using handle B.
//

// ---------------------------
// Device Attribute Access:

kNIRIOSRVExportPre tNIRIO_u32
kNIRIOSRVCCall NiRioSrv_device_get32(      tRioDeviceHandle hClient,
                                           tRioDeviceAttribute32 attribute,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef tNIRIO_u32
(kNIRIOSRVCCall *NiRioSrv_device_get32Fn)( tRioDeviceHandle hClient,
                                           tRioDeviceAttribute32 attribute,
                                           tRioStatusCode*  status);

// Added in 230
//
// Client must freeString() any non-NULL return value.
//
kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_device_getString(  tRioDeviceHandle  hClient,
                                           tRioDeviceAttributeStr attribute,
                                           tRioStatusCode*   status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_device_getStringFn)(
                                           tRioDeviceHandle  hClient,
                                           tRioDeviceAttributeStr attribute,
                                           tRioStatusCode*   status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_set32(      tRioDeviceHandle hClient,
                                           tRioDeviceAttribute32 attribute,
                                           tNIRIO_u32       value,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_set32Fn)( tRioDeviceHandle hClient,
                                           tRioDeviceAttribute32 attribute,
                                           tNIRIO_u32       value,
                                           tRioStatusCode*  status);

// Added in 230
//
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_setString(  tRioDeviceHandle  hClient,
                                           tRioDeviceAttributeStr attribute,
                                           const char*       value,
                                           tRioStatusCode*   status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_setStringFn)(
                                           tRioDeviceHandle  hClient,
                                           tRioDeviceAttributeStr attribute,
                                           const char*       value,
                                           tRioStatusCode*   status);

// ---------------------------
// Device Download Control:

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_download(     tRioDeviceHandle handle,
                                             const tNIRIO_u8* bitstream,
                                             tNIRIO_u32       size,
                                             tNIRIO_u32       attribute,
                                             tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_downloadFn)(tRioDeviceHandle handle,
                                             const tNIRIO_u8* bitstream,
                                             tNIRIO_u32       size,
                                             tNIRIO_u32       attribute,
                                             tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_downloadBegin(     tRioDeviceHandle hClient,
                                                  tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_downloadBeginFn)(tRioDeviceHandle hClient,
                                                  tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_downloadEnd(       tRioDeviceHandle hClient,
                                                  tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_downloadEndFn)(  tRioDeviceHandle hClient,
                                                  tRioStatusCode*  status);

// ---------------------------
// Device Driver Configuration (resources):
//
// The driver must be configured to match whatever resources are
// present on the FPGA device so that the RIO driver can provide
// platform independant, thread-safe mechanisms to access them.
//
// Resources are specified "script-style". Each resource is specified,
// one at a time, with a configAddXXX() call. Once specified,
// resources are are then enabled as a group using configSet().
//

// configSet(): All resources "added" since the device handle was
// obtained, or since the last configSet() call, are enabled for use.
//
// attribute: must be 0
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_configSet(     tRioDeviceHandle hClient,
                                              tNIRIO_u32       attribute,
                                              tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_configSetFn)(tRioDeviceHandle hClient,
                                              tNIRIO_u32       attribute,
                                              tRioStatusCode*  status);

// configAddFifoInput(): Add an input fifo device resource.
//
// channel: logical channel for fifo (DMA channel)
//
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_configAddFifoInputEx(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tNIRIO_u32       version,
   tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_configAddFifoInputExFn)(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tNIRIO_u32       version,
   tRioStatusCode*  status);


// configAddFifoOutput(): Add an output fifo device resource.
//
// channel: logical channel for fifo (DMA channel)
//
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_configAddFifoOutputEx(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tNIRIO_u32       version,
   tRioStatusCode*  status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_configAddFifoOutputExFn)(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tNIRIO_u32       version,
   tRioStatusCode*  status);

// ---------------------------
// Fifo Operations:

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoConfig(      tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tNIRIO_u32       fifoDepthInElements,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoConfigFn)( tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tNIRIO_u32       fifoDepthInElements,
                                                tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoStart(       tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoStartFn)(  tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoStop(        tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoStopFn)(   tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoRead(        tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tNIRIO_u32*      buf,
                                                tNIRIO_u32       number,
                                                tNIRIO_u32       timeout,
                                                tNIRIO_u32*      read,
                                                tNIRIO_u32*      remaining,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoReadFn)(   tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tNIRIO_u32*      buf,
                                                tNIRIO_u32       number,
                                                tNIRIO_u32       timeout,
                                                tNIRIO_u32*      read,
                                                tNIRIO_u32*      remaining,
                                                tRioStatusCode*  status);


kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoWrite(       tRioDeviceHandle  hClient,
                                                tNIRIO_u32        channel,
                                                const tNIRIO_u32* buf,
                                                tNIRIO_u32        number,
                                                tNIRIO_u32        timeout,
                                                tNIRIO_u32*       remaining,
                                                tRioStatusCode*   status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoWriteFn)(  tRioDeviceHandle hClient,
                                                tNIRIO_u32       channel,
                                                tNIRIO_u32*      buf,
                                                tNIRIO_u32       number,
                                                tNIRIO_u32       timeout,
                                                tNIRIO_u32*      remaining,
                                                tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_fifoStopAll(     tRioDeviceHandle hClient,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_fifoStopAllFn)(tRioDeviceHandle hClient,
                                                tRioStatusCode*  status);

// ---------------------------
// I/O:

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_readBlock(     tRioDeviceHandle hClient,
                                              tNIRIO_u32       offset,
                                              tNIRIO_u32       repeat,
                                              void*            data,
                                              tNIRIO_u32       attribute,
                                              tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_readBlockFn)(tRioDeviceHandle hClient,
                                              tNIRIO_u32       offset,
                                              tNIRIO_u32       repeat,
                                              void*            data,
                                              tNIRIO_u32       attribute,
                                              tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_writeBlock(     tRioDeviceHandle hClient,
                                               tNIRIO_u32       offset,
                                               tNIRIO_u32       repeat,
                                               const void*      data,
                                               tNIRIO_u32       attribute,
                                               tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_writeBlockFn)(tRioDeviceHandle hClient,
                                               tNIRIO_u32       offset,
                                               tNIRIO_u32       repeat,
                                               const void*      data,
                                               tNIRIO_u32       attribute,
                                               tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_poke64(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u64       value,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_poke64Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u64       value,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_poke32(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u32       value,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_poke32Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u32       value,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_poke16(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u16       value,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_poke16Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tNIRIO_u16       value,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_poke8(     tRioDeviceHandle hClient,
                                          tNIRIO_u32       offset,
                                          tNIRIO_u8        value,
                                          tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_poke8Fn)(tRioDeviceHandle hClient,
                                          tNIRIO_u32       offset,
                                          tNIRIO_u8        value,
                                          tRioStatusCode*  status);

kNIRIOSRVExportPre tNIRIO_u64
kNIRIOSRVCCall NiRioSrv_device_peek64(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef tNIRIO_u64
(kNIRIOSRVCCall *NiRioSrv_device_peek64Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre tNIRIO_u32
kNIRIOSRVCCall NiRioSrv_device_peek32(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef tNIRIO_u32
(kNIRIOSRVCCall *NiRioSrv_device_peek32Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre tNIRIO_u16
kNIRIOSRVCCall NiRioSrv_device_peek16(     tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef tNIRIO_u16
(kNIRIOSRVCCall *NiRioSrv_device_peek16Fn)(tRioDeviceHandle hClient,
                                           tNIRIO_u32       offset,
                                           tRioStatusCode*  status);

kNIRIOSRVExportPre tNIRIO_u8
kNIRIOSRVCCall NiRioSrv_device_peek8(     tRioDeviceHandle hClient,
                                          tNIRIO_u32       offset,
                                          tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef tNIRIO_u8
(kNIRIOSRVCCall *NiRioSrv_device_peek8Fn)(tRioDeviceHandle hClient,
                                          tNIRIO_u32       offset,
                                          tRioStatusCode*  status);

// ---------------------------
// Events (interrupts):

// enableEvent(): Make it possible to wait on the specified event. As
// soon as the event is enabled, it starts counting occurences.
//
// eventID:
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_eventEnable(     tRioDeviceHandle hClient,
                                                tNIRIO_u32       eventID,
                                                tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_eventEnableFn)(tRioDeviceHandle hClient,
                                                tNIRIO_u32       eventID,
                                                tRioStatusCode*  status);

// disableEvent(): Remove all resources required to wait on an
// event. Any threads currently waiting on the event will be woken and
// given an error.
//
// eventID:
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_eventDisable(     tRioDeviceHandle hClient,
                                                 tNIRIO_u32       eventID,
                                                 tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_eventDisableFn)(tRioDeviceHandle hClient,
                                                 tNIRIO_u32       eventID,
                                                 tRioStatusCode*  status);

// waitEvent(): Wait (block the calling thread) until the next event
// occurrs. All occurences since the corresponding enableEvent()
// count, so the thread may not block at all.
//
// eventID:
// timeout: maximum wait time in ms (0xFFFFFFFF for infinite)
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_eventWait(     tRioDeviceHandle hClient,
                                              tNIRIO_u32       eventID,
                                              tNIRIO_u32       timeout,
                                              tRioStatusCode*  status)
kNIRIOSRVExportPost;
typedef void
(kNIRIOSRVCCall *NiRioSrv_device_eventWaitFn)(tRioDeviceHandle hClient,
                                              tNIRIO_u32       eventID,
                                              tNIRIO_u32       timeout,
                                              tRioStatusCode*  status);

// ---------------------------
// IRQs:

kNIRIOSRVExportPre
void kNIRIOSRVCCall
NiRioSrv_device_irqReserve(tRioDeviceHandle hClient,
                           void**           context,
                           tNIRIO_i32*      status)
   kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_irqReserveFn)(tRioDeviceHandle hClient,
                                               void**           context,
                                               tNIRIO_i32*      status);

kNIRIOSRVExportPre
void kNIRIOSRVCCall
NiRioSrv_device_irqUnreserve(tRioDeviceHandle hClient,
                             void**           context,
                             tNIRIO_i32*      status)
   kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_device_irqUnreserveFn)(tRioDeviceHandle hClient,
                                                 void**           context,
                                                 tNIRIO_i32*      status);


kNIRIOSRVExportPre
tNIRIO_u32 kNIRIOSRVCCall
NiRioSrv_device_irqWait(tRioDeviceHandle hClient,
                        void**           context,
                        tNIRIO_u32       irqs,
                        tNIRIO_i32       timeout,
                        tNIRIO_i32*      status)
   kNIRIOSRVExportPost;

typedef tNIRIO_u32
(kNIRIOSRVCCall *NiRioSrv_device_irqWaitFn)(tRioDeviceHandle hClient,
                                            void**           context,
                                            tNIRIO_u32       irqs,
                                            tNIRIO_i32       timeout,
                                            tNIRIO_i32*      status);

// ---------------------------
// Host interface:

//
// NiRioSrv_host_get32
//
// Gets a 32-bit attribute from a host.
//
// host:      host to query, NULL or empty string for local
// attribute: attribute to query
//
kNIRIOSRVExportPre tNIRIO_u32
kNIRIOSRVCCall NiRioSrv_host_get32(     const char*         host,
                                        tRioHostAttribute32 attribute,
                                        tRioStatusCode*     status)
kNIRIOSRVExportPost;

typedef tNIRIO_u32
(kNIRIOSRVCCall *NiRioSrv_host_get32Fn)(const char*         host,
                                        tRioHostAttribute32 attribute,
                                        tRioStatusCode*     status);

//
// NiRioSrv_host_set32
//
// Sets a 32-bit attribute on a host.
//
// host:      host to set, NULL or empty string for local
// attribute: attribute to set
// value:     value to set
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_host_set32(     const char* const   host,
                                        tRioHostAttribute32 attribute,
                                        tNIRIO_u32          value,
                                        tRioStatusCode*     status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_host_set32Fn)(const char* const   host,
                                        tRioHostAttribute32 attribute,
                                        tNIRIO_u32          value,
                                        tRioStatusCode*     status);

//
// NiRioSrv_host_getString
//
// Gets a string attribute from a host.
//
// host:      host to query, NULL or empty string for local
// attribute: attribute to query
//
kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_host_getString( const char*             host,
                                        tRioHostAttributeString attribute,
                                        tRioStatusCode*         status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_host_getStringFn)(const char*             host,
                                            tRioHostAttributeString attribute,
                                            tRioStatusCode*         status);


//
// NiRioSrv_host_setAliases
//
// Sets the aliases to a given list. This list is a semicolon-delimited list of
// alias/resource pairs separated by =. For example:
//
//    local=RIO0;remote=rio://kjohnson9004/RIO0
//
// host: host to configure, NULL or empty string for local
// list: semicolon-delimited list, NULL or empty string to clear
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_host_setAliases(const char*     host,
                                        const char*     list,
                                        tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_host_setAliasesFn)(
                                        const char*     host,
                                        const char*     list,
                                        tRioStatusCode* status);

//
// NiRioSrv_host_setAlias
//
// Sets an alias for a given resource, or deletes aliases. In particular:
//
//    (alias, resource) sets alias to point to resource.
//    (alias, NULL) deletes alias.
//    (NULL, resource) deletes the alias that points to resource.
//    (NULL, NULL) is invalid.
//
// NULL and the empty string can be used interchangeably.
//
// host:     host to configure, NULL or empty string for local
// alias:    alias to set
// resource: resource that should be resolved from this alias
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_host_setAlias(const char*     host,
                                      const char*     alias,
                                      const char*     resource,
                                      tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_host_setAliasFn)(
                                      const char*     host,
                                      const char*     alias,
                                      const char*     resource,
                                      tRioStatusCode* status);

//
// NiRioSrv_host_getAliases
//
// Gets an alias and its resource from a given index.
//
// host      : host to configure, NULL or empty string for local
// index     : index of alias to get, starting at 0
// alias     : set to buffer containing requested string value
// resource  : set to buffer containing requested string value
//
// returns   : zero on error, non-zero on success
//
// Passing index 0 refreshes the internal list.
//
// Client must freeString() both output buffers on non-zero return. Both will
// be NULL on return of 0, so it's safe to unconditionally call freeString().
//
kNIRIOSRVExportPre tNIRIO_u32
kNIRIOSRVCCall NiRioSrv_host_getAliases(const char*     host,
                                        tNIRIO_u32      index,
                                        char**          alias,
                                        char**          resource,
                                        tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef tNIRIO_u32
(kNIRIOSRVCCall *NiRioSrv_host_getAliasesFn)(
                                        const char*     host,
                                        tNIRIO_u32      index,
                                        char**          alias,
                                        char**          resource,
                                        tRioStatusCode* status);

//
// NiRioSrv_host_resolveAlias
//
// Resolves a resource from a given alias, or vice versa.
//
// host      : host to configure, NULL or empty string for local
// alias     : alias to resolve
// reverse   : non-zero to look up an alias from a resource instead
//
// returns   : resolved alias, or NULL on error
//
// Client must freeString() any non-NULL return value.
//
kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_host_resolveAlias(const char*     host,
                                          const char*     alias,
                                          tNIRIO_u32      reverse,
                                          tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_host_resolveAliasFn)(
                                          const char*     host,
                                          const char*     alias,
                                          tNIRIO_u32      reverse,
                                          tRioStatusCode* status);

//
// NiRioSrv_host_setDeviceAccess
//
// Sets the device access list to a given ordered list. This list is a
// semicolon-delimited list of patterns, with each pattern prepended by a
// tRioDeviceAccess. For example:
//
//    +10.0.29.*;-kjohnson
//
// host: host to configure, NULL or empty string for local
// list: semicolon-delimited list, NULL or empty string to clear
//
kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_host_setDeviceAccess(const char*     host,
                                             const char*     list,
                                             tRioStatusCode* status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall *NiRioSrv_host_setDeviceAccessFn)(
                                             const char*     host,
                                             const char*     list,
                                             tRioStatusCode* status);

//
// NiRioSrv_host_getDeviceAccess
//
// Gets a pattern and it's access at a given index in the device access list.
//
// host:    host to configure, NULL or empty string for local
// index:   index of pattern to get, starting at 0
// access:  the device access, output only
//
// returns: pattern sans access prefix, or NULL on error
//
// Passing index 0 refreshes the internal list.
//
// Client must freeString() any non-NULL return value.
//
kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_host_getDeviceAccess(const char*       host,
                                             tNIRIO_u32        index,
                                             tRioDeviceAccess* access,
                                             tRioStatusCode*   status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_host_getDeviceAccessFn)(
                                             const char*       host,
                                             tNIRIO_u32        index,
                                             tRioDeviceAccess* access,
                                             tRioStatusCode*   status);


//
// Entry points used by the RIO IO Control
//


kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_setRecentDevices(const char* host,
                                         const char* list,
                                         tNIRIO_i32* status)
kNIRIOSRVExportPost;

typedef void
(kNIRIOSRVCCall  *NiRioSrv_setRecentDevicesFn)(const char* host,
                                               const char* list,
                                               tNIRIO_i32* status);

kNIRIOSRVExportPre char*
kNIRIOSRVCCall NiRioSrv_getRecentDevices(const char* host,
                                         tNIRIO_u32  index,
                                         tNIRIO_i32* status)
kNIRIOSRVExportPost;

typedef char*
(kNIRIOSRVCCall *NiRioSrv_getRecentDevicesFn)(const char* host,
                                              tNIRIO_u32  index,
                                              tNIRIO_i32* status);

//
// End of entry points used by the RIO IO Control
//

// TODO: Leave for 230 release, kill next release

// DEPRECATED! And DO NOT even dare to remove this comment by mistake
//

kNIRIOSRVExportPre tNIRIO_u32
kNIRIOSRVCCall NiRioSrv_getRsrcString(     tNIRIO_u32      index,
                                           char*           buffer,
                                           tNIRIO_u32      bufferLen,
                                           tNIRIO_u32*     stringLen, // output only
                                           tRioStatusCode* status)
kNIRIOSRVExportPost;

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_configAddFifoInput(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tRioStatusCode*  status)
kNIRIOSRVExportPost;

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_device_configAddFifoOutput(
   tRioDeviceHandle hClient,
   tNIRIO_u32       channel,
   tNIRIO_u32       baseAddress,
   tNIRIO_u32       depthInSamples,
   tRioStatusCode*  status)
kNIRIOSRVExportPost;

kNIRIOSRVExportPre tRioDeviceHandle
kNIRIOSRVCCall NiRioSrv_getDeviceByRsrcString(     const char*     resource,
                                                   tRioStatusCode* status)
kNIRIOSRVExportPost;

kNIRIOSRVExportPre void
kNIRIOSRVCCall NiRioSrv_releaseDevice(     tRioDeviceHandle hClient,
                                           tRioStatusCode*  status)
kNIRIOSRVExportPost;

#ifdef __cplusplus
}
#endif

#endif // ___NiRioSrv_NiRioEntryPoints_H___
