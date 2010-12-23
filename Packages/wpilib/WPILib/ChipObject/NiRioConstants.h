/**
    \file       NiRioConstants.h
    \author     Erik Hons <erik.hons@ni.com>
    \date       12/14/2004

    \brief Public constants for the RIO services

    Copyright (c) 2004. National Instruments. All rights reserved.
*/

#ifndef  ___NiRioSrv_NiRioConstants_H___
#define  ___NiRioSrv_NiRioConstants_H___

//  defines...
//  type declarations (typedefs)...

//
// Basic constants.
//

const tNIRIO_u32 kRioInvalid32        = 0xffffffff;
const tNIRIO_u16 kRioInvalid16        = 0xffff;
const tNIRIO_u8  kRioInvalid8         = 0xff;
const tNIRIO_u32 kRioInvalid          = kRioInvalid32;
const tNIRIO_u32 kRioMaxLen           = 256;
const tNIRIO_u32 kRioInvalidHandle    = 0;

//
// FIFO Constants
//
const tNIRIO_u32 kRioMinFifoVersionWithClearCapability = 1;

//
// Device Access
//

typedef char tRioDeviceAccess;
const tRioDeviceAccess kRioDeviceAccessDeny  = '-';
const tRioDeviceAccess kRioDeviceAccessAllow = '+';

/**
      DeviceUserData registered data structure for non R-series devices that
      utilize RIO technology.
*/

const tNIRIO_u16 kRIODeviceUserDataKey  = 0x4352;  /// 'CR' for CompactRio

typedef struct {
   tNIRIO_u32 identifier;    /// Use kDevDeviceClassRIO.
   tNIRIO_u32 serialNumber;
} tRIODeviceUserData;

//  constants...

// Timeouts
const tNIRIO_u32 kRioTimeoutZero      = 0;
const tNIRIO_u32 kRioTimeoutInfinite  = 0xFFFFFFFFUL;

//
// Device attribute identifiers
//
// NOTE: *** Maintain the enum ordering for client compatibility. (e.g.: the
// RIO attribute ring control in the FPGA plug-in code. ***
//

// 32-bit attributes
// Name                           =  X,   // AddedVersion: Comments
typedef enum {
   kRioInitialized                =  0UL, // 200
   kRioInterfaceNumber            =  1UL, // 200
   kRioProductNumber              =  2UL, // 200
   kRioVendorNumber               =  3UL, // 200
   kRioSerialNumber               =  4UL, // 200
   kRioSignature                  =  5UL, // 200
   kRioResourceType               =  6UL, // 200
   kRioDeviceManager              =  7UL, // 200: Obsolete in 230
   kRioDefaultTimeout             =  8UL, // 200
   kRioLocalFifoRatio             =  9UL, // 200: Obsolete in 230

   // HACK HACK: PCI-SPECIFIC.
   kRioBusNumber                  = 10UL, // 200
   kRioDeviceNumber               = 11UL, // 200
   kRioFunctionNumber             = 12UL, // 200

   kRioRestrictedAccess           = 13UL, // 220: Obsolete in 230
   kRioCurrentVersion             = 14UL, // 220
   kRioOldestCompatibleVersion    = 15UL, // 220
   kRioClientIsBigEndian          = 16UL, // 220: kFalse means little-endian
   kRioFpgaInterruptControlOffset = 17UL, // 220

   kRioNumberMemWindows           = 18UL, // 230

   // ------------- HACK HACK: Keep in sequential order Until IO Manager ---
   // HACK HACK until we have the IO Manager.  DO NOT INCLUDE INTO THE
   // RING CONTROL!!!
   kRioMemBaseBar0                = 19UL, // 230
   kRioMemBaseBar1                = 20UL, // 230
   kRioMemSizeBar0                = 21UL, // 230
   kRioMemSizeBar1                = 22UL, // 230
   // --------------- End HACK HACK ------------------------------------

   kRioSessionState               = 23UL, // 230
   kRioPersonalityLockTimeout     = 24UL, // 230
   kRioAddressSpace               = 25UL, // 230

   kRioChassisNumber              = 27UL, // 230
   kRioSlotNumber                 = 28UL, // 230
   kRioLocalFifoDefaultDepth      = 29UL, // 230

   kRioTriggerBusNumber           = 30UL, // 230
   kRioTriggerReserveLine         = 31UL, // 230
   kRioTriggerUnreserveLine       = 32UL, // 230
   kRioTriggerReservedLines       = 33UL, // 230

   kRioIrqNodeReserve             = 34UL, // 230
   kRioFpgaInterruptEnable        = 35UL, // 230

   kRioIsItOkToDownload           = 36UL, // 230

   kRioFpgaResetOffset            = 37UL, // 230
   kRioFpgaResetWidthInBits       = 38UL, // 230
   kRioFpgaControlOffset          = 39UL, // 230

   kRioResetIfLastSession         = 40UL, // 230
   kRioHasDeviceAccess            = 41UL, // 230

   kRioBusInterfaceType           = 42UL, // 240

   kRioNumberOfDmaChannels        = 43UL, // 300
   kRioFpgaAddressSpaceOffset     = 44UL, // 300
   kRioBitstreamVersion           = 45UL, // 300
   kRioIsInAPciSlot               = 46UL, // 300
   kRioIsRio                      = 47UL, // 300

   kRioIsFpgaProgrammed           = 48UL, // 300 

   kRioFpgaGuid0                  = 49UL, // 300 32-bit values from 
   kRioFpgaGuid1                  = 50UL, // 300    signature register
   kRioFpgaGuid2                  = 51UL, // 300    in the order read
   kRioFpgaGuid3                  = 52UL, // 300 

   kRioFpgaDefaultSignatureOffset = 53UL, // 300 Default Offsets for FPGA
   kRioFpgaDefaultResetOffset     = 54UL, // 300    registers. Supplied by 
   kRioFpgaDefaultResetSize       = 55UL, // 300    the board driver on device
   kRioFpgaDefaultControlOffset   = 56UL, // 300    start.
   kRioFpgaDefaultInterruptOffset = 57UL, // 300 

   kRioIsItOkToTalkToHardware     = 58UL, // 300 
   kRioHasNoFPGASwitch            = 59UL, // 310

   // The P2P-enabled application will have an 8-bit local endpoint resource
   // lookup table.  Within the table, each local endpoint resource number is
   // associated with a globally unique hardware endpoint ID. 
   kRioP2PLocalEndpointResourceBase = 100UL,  // 310
   kRioP2PLocalEndpointResourceMax  = kRioP2PLocalEndpointResourceBase+255,//310

} tRioDeviceAttribute32;

// String attributes
typedef enum {
   kRioProductName                = 0UL,
   kRioWhatFpgaIsDoing            = 1UL,   // 230
   kRioResourceName               = 2UL,   // 230
   kRioCompilationResults         = 3UL,   // 300
   kRioCompatibleIDs              = 4UL,   // 300
} tRioDeviceAttributeStr;

// Host attributes
typedef enum {
   kRioHostCurrentVersion          = 0UL,
   kRioHostOldestCompatibleVersion = 1UL,
   kRioHostRpcServerPort           = 2UL,
   kRioHostRpcTimeout              = 3UL, // NI-RPC timeout (seconds)
   kRioHostDeviceDiscoveryTimeout  = 4UL,
   kRioHostHasDeviceAccess         = 5UL,
   kRioHostRpcSessionTimeout       = 6UL, // RIO session timeout (seconds)
   kRioHostTableSegmentSize        = 7UL, //< Number of entries per segment
                                          //  of the growable session table
   kRioActivePowerSource           = 8UL, // 310
} tRioHostAttribute32;

typedef enum {
   kRioHostAliases       = 0UL,
   kRioHostAlias         = 1UL,
   kRioHostDeviceAccess  = 2UL,
   kRioHostRecentDevices = 3UL,
   kRioHostInputVoltage  = 4UL,  // 310
   kRioHostTemperature   = 5UL,  // 310
} tRioHostAttributeString;

const tNIRIO_u32 kRioDynamicRpcServerPort = 0;

//
// IO Window types
//

typedef enum {
   kRioAddressSpaceInvalid = 0,
   kRioAddressSpaceBusInterface = 1,
   kRioAddressSpaceFpga = 2,
} tRioAddressSpace;

//
// Memory Map Spaces
//

typedef enum {
   kRioMapSpaceInvalid = 0,
   kRioMapSpaceKernel = 1,
   kRioMapSpaceUser = 2,
} tRioMapSpace;

//
// Device block[Read|Write] attributes
//

const tNIRIO_u32 kRioIoAttributeAccessByteWidthMask      = 0x0F;
const tNIRIO_u32 kRioIoAttributeFpgaIncrement            = 0x10;
const tNIRIO_u32 kRioIoAttributeDustMiteNtFlashBitstream = 0x20;

//
// Device download attributes
//

typedef enum {
   kRioDeviceDownloadAttributeDestinationFpga  = 0x1,
   kRioDeviceDownloadAttributeDestinationFlash = 0x2,
} tRioDeviceDownloadAttribute;

//
// Event types
//

typedef enum {
   kRioEventInvalidEvent      = -1,
   kRioEventFirstEvent        = 0,
   kRioEventPciInterrupt      = 0,
   kRioEventRemoval           = 1,
   kRioEventMaxNumberOfEvents = 2, // Add all other events before this one
} tRioEventType;

//
// Session states
//

typedef enum {
   kRioSSNothing        = 1,
   kRioSSExclusive      = 2,
   kRioSSInvariant      = 4,
   kRioSSOverride       = 6,
   kRioSSHardwareAccess = 7,
} tRioSessionState;


/// Device signature information.

// The lower 32 bits are divided by:
// bits 28-31  busType , see nRioBusType
// bits 16-27  TBD
// bits 8-15   bus (0 - 255 ),
// bits 3-7    device number (0-31),
// bits 0-2    function number (0-7)
//
/// RIO Bus types.
typedef enum {
   kRioBusTypePci = 0x00000001,
} tRioBusType;

const tNIRIO_u32 kRioBusTypeShift     = 28;
const tNIRIO_u32 kRioBusTypeMask      = 0xF;   // bus type range: 0 - 15 (4 bits)

/// Signature bus number shift
const tNIRIO_u32 kRioBusNumberShift      = 8;
const tNIRIO_u32 kRioBusNumberMask       = 0xFF;  // range: 0 - 255 (8 bits)

/// Signature device number shift
const tNIRIO_u32 kRioSocketNumberShift   = 3;
const tNIRIO_u32 kRioSocketNumberMask    = 0x1F;  // range: 0 - 31 (5 bits)

/// Signature function number shift
const tNIRIO_u32 kRioFunctionNumberShift = 0;
const tNIRIO_u32 kRioFunctionNumberMask  = 0x7;   // range: 0 - 7 (3 bits)

/// RIO Device categories.
typedef enum {
   kRioDeviceTypeInvalid = 0x00000000UL,   //!< invalid device
   kRioDeviceCRio        = 0x00000001UL,   //!< compactRIO device
   kRioDevicePxi         = 0x00000002UL,   //!< PXI device
   kRioDeviceFW          = 0x00000004UL,   //!< FireWire (1394) device
   kRioDeviceBB          = 0x00000008UL,   //!< BlueBonnet device
   kRioDevicePuma        = 0x00000010UL,   //!< Puma device
   kRioDeviceSync        = 0x73796E63UL,   //!< 'sync' (NI-PAL ID)
   kRioDeviceDaq         = 0x20646171UL,   //!< 'daq ' (NI-PAL ID for new sync)
   kRioDeviceIMAQ        = 0x696D6171UL,   //!< 'imaq' (NI-PAL ID)
} tRioDeviceType;

// RIO bus interface types
typedef enum {
   kRioBusInterfaceTypeInvalid = 0x00000000UL,
   kRioDustMite                = 0x00000001UL,
   kRioDustMiteNt              = 0x00000002UL,
   kRioStc2                    = 0x00000003UL,
   kRioStc3                    = 0x00000004UL,
} tRioBusInterfaceType;


//============================================================================
//  tRioScalarType - Type enums for numbereric data types.
//    IMPORTANT:  The numbereric values of these enums need to match those of the
//    nNIRVIDF100::tFifoDataType enum (which in turn matches the values of the
//    LabVIEW NumberType enum).  Note also that we only support a subset of the
//    LabVIEW NumberType enums.  If this set of supported enums ever grows, we need
//    to be careful to match the appropriate NumberType numbereric value.
//    TODO:  Replace with LabVIEW numbereric type enum.
//============================================================================
typedef enum {
   kRioScalarType_iB = 1UL,
   kRioScalarType_iW = 2UL,
   kRioScalarType_iL = 3UL,
   kRioScalarType_iQ = 4UL,
   kRioScalarType_uB = 5UL,
   kRioScalarType_uW = 6UL,
   kRioScalarType_uL = 7UL,
   kRioScalarType_uQ = 8UL,
} tRioScalarType;


//============================================================================
//  tRioFifoDataType - Defines data type information for an associated data
//  value (which is generally identified via an opaque pointer).  Note that we
//  currently only support scalar data type definitions.  One example of how we
//  use this information is for supporting FIFOs with arbitrary scalar
//    data types.
//       scalarType - The type of the underlying scalar we're representing
//       bitWidth   - The number of active data bits in the scalar value.  For
//          non fixed-point types, this will equal the precision of the datatype
//          (i.e. 8, 16, 32, 64).  For fixed-point datatypes, this will equal
//          the number of bits in the fixed-point number that contain information.
//============================================================================
typedef struct {
   tRioScalarType scalarType;
   tNIRIO_u32     bitWidth;
} tRioFifoDataType;


//  declarations for globally-scoped globals...
//  prototypes...
//  inline methods and function macros...


#endif // ___NiRioSrv_NiRioConstants_H___
