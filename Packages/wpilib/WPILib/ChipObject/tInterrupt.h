// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Interrupt_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Interrupt_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tInterrupt : public tScopedSystem
{
public:
   tInterrupt(unsigned char sys_index, tRioStatusCode *status);
   ~tInterrupt();

   inline unsigned char getSystemIndex()
   {
      return _SystemIndex;
   }

   typedef enum
   {
      kNumSystems = 8,
   } tConstants;

   typedef
   union{
      struct{
         unsigned Source_Channel : 4;
         unsigned Source_Module : 1;
         unsigned Source_AnalogTrigger : 1;
         unsigned RisingEdge : 1;
         unsigned FallingEdge : 1;
         unsigned WaitForAck : 1;
      };
      struct{
         unsigned value : 9;
      };
   } tConfig;


   typedef enum
   {
      kInterrupt0_TimeStampAddress = 0x8198,
      kInterrupt1_TimeStampAddress = 0x8190,
      kInterrupt2_TimeStampAddress = 0x8188,
      kInterrupt3_TimeStampAddress = 0x8180,
      kInterrupt4_TimeStampAddress = 0x8178,
      kInterrupt5_TimeStampAddress = 0x8170,
      kInterrupt6_TimeStampAddress = 0x8168,
      kInterrupt7_TimeStampAddress = 0x8160,
   } tTimeStamp_Constants;
   static const unsigned int kTimeStampAddresses [];

   unsigned int readTimeStamp(tRioStatusCode *status);


   typedef enum
   {
      kInterrupt0_ConfigAddress = 0x810C,
      kInterrupt1_ConfigAddress = 0x8194,
      kInterrupt2_ConfigAddress = 0x818C,
      kInterrupt3_ConfigAddress = 0x8184,
      kInterrupt4_ConfigAddress = 0x817C,
      kInterrupt5_ConfigAddress = 0x8174,
      kInterrupt6_ConfigAddress = 0x816C,
      kInterrupt7_ConfigAddress = 0x8164,
   } tConfig_Constants;
   static const unsigned int kConfigAddresses [];

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_Source_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_Source_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_Source_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_RisingEdge(bool value, tRioStatusCode *status);
   void writeConfig_FallingEdge(bool value, tRioStatusCode *status);
   void writeConfig_WaitForAck(bool value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   unsigned char readConfig_Source_Channel(tRioStatusCode *status);
   unsigned char readConfig_Source_Module(tRioStatusCode *status);
   bool readConfig_Source_AnalogTrigger(tRioStatusCode *status);
   bool readConfig_RisingEdge(tRioStatusCode *status);
   bool readConfig_FallingEdge(tRioStatusCode *status);
   bool readConfig_WaitForAck(tRioStatusCode *status);





private:
   unsigned char _SystemIndex;

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Interrupt_h__
