// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_tScopedSystem_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_tScopedSystem_h__

#include "ExpectedFPGASignature.h"
#include "tSystem.h"
#include <stdio.h>

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{
   class tScopedSystem : public tSystem
   {
   public:
      tScopedSystem(tRioStatusCode *status, bool getLVHandle = false);
      ~tScopedSystem();

   protected:
      bool getHandleOpened()
      {
         return _handleOpened;
      }
   private:
      static bool _handleOpened;
   };

   template<typename ttGlobal>
   inline void printFPGAVersion(ttGlobal &global)
   {
		tRioStatusCode cleanStatus=0;
		unsigned hardwareGuid[4];
		global.getFpgaGuid(hardwareGuid, &cleanStatus);
		const unsigned *softwareGuid = g_ExpectedFPGASignature;
	    printf("FPGA Hardware GUID: 0x");
	    for(int i=0; i<4; i++)
	    {
	        printf("%08X", hardwareGuid[i]);
	    }
	    printf("\n");
	    printf("FPGA Software GUID: 0x");
	    for(int i=0; i<4; i++)
	    {
	       printf("%08X", softwareGuid[i]);
	    }
	    printf("\n");
		UINT16 fpgaHardwareVersion = global.readVersion(&cleanStatus);
		UINT16 fpgaSoftwareVersion = g_ExpectedFPGAVersion;
		printf("FPGA Hardware Version: %d\n", fpgaHardwareVersion);
		printf("FPGA Software Version: %d\n", fpgaSoftwareVersion);
		UINT32 fpgaHardwareRevision = global.readRevision(&cleanStatus);
		UINT32 fpgaSoftwareRevision = g_ExpectedFPGARevision;
		printf("FPGA Hardware Revision: %d.%d.%d\n", (fpgaHardwareRevision >> 20) & 0xFFF, (fpgaHardwareRevision >> 12) & 0xFF, fpgaHardwareRevision & 0xFFF);
		printf("FPGA Software Revision: %d.%d.%d\n", (fpgaSoftwareRevision >> 20) & 0xFFF, (fpgaSoftwareRevision >> 12) & 0xFF, fpgaSoftwareRevision & 0xFFF);
   }
}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_tScopedSystem_h__
