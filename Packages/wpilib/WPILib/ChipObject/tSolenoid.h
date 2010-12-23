// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __nAD9A5591CC64E4DF756D77D1B57A549E_Solenoid_h__
#define __nAD9A5591CC64E4DF756D77D1B57A549E_Solenoid_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace nAD9A5591CC64E4DF756D77D1B57A549E
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
      kSolenoid_DO7_0Address = 0x8410,
   } tDO7_0_Constants;

   void writeDO7_0(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readDO7_0(unsigned char bitfield_index, tRioStatusCode *status);




private:

};

}
}

#endif // __nAD9A5591CC64E4DF756D77D1B57A549E_Solenoid_h__
