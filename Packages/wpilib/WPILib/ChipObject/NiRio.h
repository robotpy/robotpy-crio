// Copyright (c) National Instruments 2008.  All Rights Reserved.

#ifndef __NiRio_h__
#define __NiRio_h__

#define kNIRIOSRVExportPre   
#define kNIRIOSRVExportPost  
#define kNIRIOSRVCCall  
#define tNIRIO_i64 long
#define tNIRIO_i32 int
#define tNIRIO_i16 short
#define tNIRIO_i8  char
#define tNIRIO_u64 unsigned long
#define tNIRIO_u32 unsigned int
#define tNIRIO_u16 unsigned short
#define tNIRIO_u8  unsigned char
#ifndef __cplusplus
   typedef enum 
   {
      kFalse=0,
      kTrue=1
   } bool;
#else
   #define kTrue true
   #define kFalse false
#endif

#include "NiRioStatus.h"

// Definitions needed from internal header files.
typedef tNIRIO_u32 tRioDeviceHandle;

#endif // __NiRio_h__
