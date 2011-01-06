// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Accumulator_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Accumulator_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tAccumulator : public tScopedSystem
{
public:
   tAccumulator(unsigned char sys_index, tRioStatusCode *status);
   ~tAccumulator();

   inline unsigned char getSystemIndex()
   {
      return _SystemIndex;
   }

   typedef enum
   {
      kNumSystems = 2,
   } tConstants;

   typedef
   union{
      struct{
         signed long long Value;
         unsigned Count : 32;
      };
      struct{
         unsigned value : 32;
         unsigned value2 : 32;
         unsigned value3 : 32;
      };
   } tOutput;


   typedef enum
   {
      kAccumulator0_OutputAddress = 0x83E4,
      kAccumulator1_OutputAddress = 0x83D4,
   } tOutput_Constants;
   static const unsigned int kOutputAddresses [];

   tOutput readOutput(tRioStatusCode *status);
   signed long long readOutput_Value(tRioStatusCode *status);
   unsigned int readOutput_Count(tRioStatusCode *status);


   typedef enum
   {
      kAccumulator0_CenterAddress = 0x83EC,
      kAccumulator1_CenterAddress = 0x83DC,
   } tCenter_Constants;
   static const unsigned int kCenterAddresses [];

   void writeCenter(signed int value, tRioStatusCode *status);
   signed int readCenter(tRioStatusCode *status);


   typedef enum
   {
      kAccumulator0_ResetAddress = 0x83E8,
      kAccumulator1_ResetAddress = 0x83D8,
   } tReset_Constants;
   static const unsigned int kResetAddresses [];

   void strobeReset(tRioStatusCode *status);


   typedef enum
   {
      kAccumulator0_DeadbandAddress = 0x83E0,
      kAccumulator1_DeadbandAddress = 0x83D0,
   } tDeadband_Constants;
   static const unsigned int kDeadbandAddresses [];

   void writeDeadband(signed int value, tRioStatusCode *status);
   signed int readDeadband(tRioStatusCode *status);





private:
   unsigned char _SystemIndex;

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Accumulator_h__
