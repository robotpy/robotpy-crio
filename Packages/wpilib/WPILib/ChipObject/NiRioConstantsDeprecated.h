/** 
   \file       NiRioConstantsDeprecated.h
   \author     Dave Madden <david.madden@ni.com>
   \date       01/06/2008

   Declaration of _NiRioConstantsDeprecated class.

   Note that the attributes and typedefs listed below have been deprecated.
   This file is in place for backwards compatiblity, and may be removed
   without warning.

   Copyright (c) 2008. National Instruments. All rights reserved.
*/


#ifndef  ___NiRioSrv_NiRioConstantsDeprecated_H___
#define  ___NiRioSrv_NiRioConstantsDeprecated_H___


//  includes...


//  defines...

const tNIRIO_u16  kRioDevUserDataKay   = kRIODeviceUserDataKey; 

typedef  tRIODeviceUserData         tRIODevUserData;

// Using #define instead of const int32_t since build tools report an error
// with the backwards compatibility.
#define  kRioInterfaceNum           kRioInterfaceNumber
#define  kRioProductNum             kRioProductNumber
#define  kRioVendorNum              kRioVendorNumber
#define  kRioSerialNum              kRioSerialNumber
#define  kRioRsrcType               kRioResourceType
#define  kRioDeviceMgr              kRioDeviceManager
#define  kRioBusNum                 kRioBusNumber
#define  kRioDeviceNum              kRioDeviceNumber
#define  kRioFuncNum                kRioFunctionNumber
#define  kRioNumMemWindows          kRioNumberMemWindows
#define  kRioChassisNum             kRioChassisNumber
#define  kRioSlotNum                kRioSlotNumber
#define  kRioTriggerBusNum          kRioTriggerBusNumber

typedef  tRioDeviceAttribute32      tRioDeviceAttr32;
typedef  tRioDeviceAttributeStr     tRioDeviceAttrStr;

#define  kRioEventPCIInterrupt      kRioEventPciInterrupt

const tNIRIO_u32  kRioBusNumShift      =  kRioBusNumberShift;
const tNIRIO_u32  kRioBusNumMask       =  kRioBusNumberMask;
                                                             
const tNIRIO_u32  kRioSocketNumShift   =  kRioSocketNumberShift;
const tNIRIO_u32  kRioSocketNumMask    =  kRioSocketNumberMask;
                                                             
const tNIRIO_u32  kRioFunctionNumShift =  kRioFunctionNumberShift;
const tNIRIO_u32  kRioFunctionNumMask  =  kRioFunctionNumberMask; 

#define  kRioDustMiteNT             kRioDustMiteNt
#define  kRioSTC2                   kRioStc2
#define  kRioSTC3                   kRioStc3


#endif // ___NiRioSrv_NiRioConstantsDeprecated_H___
