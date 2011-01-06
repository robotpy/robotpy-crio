// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Solenoid_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Solenoid_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tSolenoid : public tScopedSystem
{
public:
   tSolenoid(tRioStatusCode *status);
   ~tSolenoid();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;




   typedef enum
   {
      kNumDO7_0Elements = 2,
      kDO7_0_ElementSize = 8,
      kDO7_0_ElementMask = 0xFF,
      kSolenoid_DO7_0Address = 0x8424,
   } tDO7_0_Constants;

   void writeDO7_0(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readDO7_0(unsigned char bitfield_index, tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Solenoid_h__
