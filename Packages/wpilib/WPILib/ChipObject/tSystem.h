// Base class for generated chip objects
// Copyright (c) National Instruments 2008.  All Rights Reserved.

#ifndef __tSystem_h__
#define __tSystem_h__

#include "NiRio.h"
#include "tDMAChannelDescriptor.h"
#include <vxWorks.h>

namespace nFPGA
{

#define FPGA_INTERRUPT_BASE_ADDRESS 0x8000
#define FPGA_SIGNATURE_REGISTER 0x8108

class tSystem
{
public:
   tSystem(tRioStatusCode *status, bool getLVHandle = false);
   ~tSystem();
   void getFpgaGuid(unsigned *guid_ptr, tRioStatusCode *status);
   void downloadFPGAImage(const char *imageFileName, tRioStatusCode *status);

protected:
   void configDMA(const tDMAChannelDescriptor *descriptors, int numChannels, unsigned int dmaVersion, tRioStatusCode *status);
   static tRioDeviceHandle _DeviceHandle;
   tRioDeviceHandle _LVDeviceHandle;
   static const tDMAChannelDescriptor *_configuredDmaDescriptors;
   static int _numDmaDescriptors;
   bool getFPGAReconfigured()
   {
      return _fpgaReconfigured;
   }

private:
   void abortFPGA(tRioStatusCode *status);
   static int _ReferenceCount;
   static SEM_ID _ReferenceMutex;
   static bool _fpgaReconfigured;
};

}

#endif // __tSystem_h__
