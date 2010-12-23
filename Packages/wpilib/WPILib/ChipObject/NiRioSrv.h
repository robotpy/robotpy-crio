/**
   \file       NiRioSrv.h
   \author     Dave Madden <david.madden@ni.com>
   \date       01/12/2005

   Main include for clients.

   Copyright (c) 2004, 2005. National Instruments. All rights reserved.
*/


#ifndef  ___NiRioSrv_H___
#define  ___NiRioSrv_H___

// Client Platform Definitions
//
// Client's must supply the following platform specific definition for
// the include headers.
//
// kNIRIOSRVExportPre  : DLL import modifier (before function declation)
// kNIRIOSRVExportPost : DLL import modifier (after function declation)
//
// kNIRIOSRVCCall      : C calling convention modifier
//
// tNIRIO_i64     : Signed 64-bit integer
// tNIRIO_i32     : Signed 32-bit integer
// tNIRIO_i16     : Signed 16-bit integer
// tNIRIO_i8      : Signed  8-bit integer
// tNIRIO_u64     : Unsigned 64-bit integer
// tNIRIO_u32     : Unsigned 32-bit integer
// tNIRIO_u16     : Unsigned 16-bit integer
// tNIRIO_u8      : Unsigned  8-bit integer
//
// An example for PAL:
//
// #define kNIRIOSRVExportPre  nNISS100_kImportPre
// #define kNIRIOSRVExportPost nNISS100_kImportPost
// #define kNIRIOSRVCCall nNISS100_kCCall
// #define tNIRIO_i64 i64Native
// #define tNIRIO_i32 i32
// #define tNIRIO_i16 i16
// #define tNIRIO_i8  i8
// #define tNIRIO_u64 u64Native
// #define tNIRIO_u32 u32
// #define tNIRIO_u16 u16
// #define tNIRIO_u8  u8
//
#if !defined(kNIRIOSRVNoDefaultTypeDefinitions)
//
// An example for atomicPAL:
//
#if defined(___niapal_quarks_platform_h___)
#if !defined(kNIRIOSRVExportPre)
#define kNIRIOSRVExportPre  nNIAPALS100_kImportPre
#endif
#if !defined(kNIRIOSRVExportPost)
#define kNIRIOSRVExportPost nNIAPALS100_kImportPost
#endif
#define kNIRIOSRVCCall nNIAPALS100_kCCall
#define tNIRIO_i64 int64_t
#define tNIRIO_i32 int32_t
#define tNIRIO_i16 int16_t
#define tNIRIO_i8  int8_t
#define tNIRIO_u64 uint64_t
#define tNIRIO_u32 uint32_t
#define tNIRIO_u16 uint16_t
#define tNIRIO_u8  uint8_t
#endif
//
// Sanity checks...
//
#if    !defined(kNIRIOSRVExportPre) \
    || !defined(kNIRIOSRVExportPost) \
    || !defined(kNIRIOSRVCCall) \
    || !defined(tNIRIO_i32) \
    || !defined(tNIRIO_u64) \
    || !defined(tNIRIO_u32) \
    || !defined(tNIRIO_u16) \
    || !defined(tNIRIO_u8)
//
// One or more platform type defines are missing, break the build with
// a helpful error.
//
#error "You must define the client platform types. See NiRioSrv.h"
//
// Note: Only the used type defines are checked. If new exports use
// new types defines, they will be added to this list.
//
#endif

#endif // kNIRIOSRVNoDefaultTypeDefinitions

//  includes...

#ifndef  ___NiRioSrv_NiRioConstants_H___
#include "NiRioConstants.h"
#endif

#ifndef  ___NiRioSrv_NiRioEntryPoints_H___
#include "NiRioEntryPoints.h"
#endif

#ifndef  ___NiRioSrv_NiRioStatus_H___
#include "NiRioStatus.h"
#endif

// Provided for backwards compatability.
#ifndef  ___NiRioSrv_NiRioConstantsDeprecated_H___
#include "NiRioConstantsDeprecated.h"
#endif

// Provided for backwards compatability.
#ifndef  ___NiRioSrv_NiRioStatusDeprecated_H___
#include "NiRioStatusDeprecated.h"
#endif

//  defines...


//  type declarations (typedefs)...


//  constants...


//  declarations for globally-scoped globals...


//  prototypes...


//  inline methods and function macros...


#endif // ___NiRioSrv_H___


