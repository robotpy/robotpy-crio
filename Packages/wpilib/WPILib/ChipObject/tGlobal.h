// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Global_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Global_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tGlobal : public tScopedSystem
{
public:
   tGlobal(tRioStatusCode *status);
   ~tGlobal();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;




   typedef enum
   {
      kGlobal_VersionAddress = 0x8118,
   } tVersion_Constants;

   unsigned short readVersion(tRioStatusCode *status);


   typedef enum
   {
      kGlobal_FPGA_LEDAddress = 0x811C,
   } tFPGA_LED_Constants;

   void writeFPGA_LED(bool value, tRioStatusCode *status);
   bool readFPGA_LED(tRioStatusCode *status);


   typedef enum
   {
      kGlobal_LocalTimeAddress = 0x8110,
   } tLocalTime_Constants;

   unsigned int readLocalTime(tRioStatusCode *status);


   typedef enum
   {
      kGlobal_RevisionAddress = 0x8114,
   } tRevision_Constants;

   unsigned int readRevision(tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Global_h__
