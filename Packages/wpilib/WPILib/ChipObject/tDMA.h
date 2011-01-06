// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_DMA_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_DMA_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tDMA : public tScopedSystem
{
public:
   tDMA(tRioStatusCode *status);
   ~tDMA();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;

   typedef
   union{
      struct{
         unsigned Pause : 1;
         unsigned Enable_AI0_Low : 1;
         unsigned Enable_AI0_High : 1;
         unsigned Enable_AIAveraged0_Low : 1;
         unsigned Enable_AIAveraged0_High : 1;
         unsigned Enable_AI1_Low : 1;
         unsigned Enable_AI1_High : 1;
         unsigned Enable_AIAveraged1_Low : 1;
         unsigned Enable_AIAveraged1_High : 1;
         unsigned Enable_Accumulator0 : 1;
         unsigned Enable_Accumulator1 : 1;
         unsigned Enable_DI : 1;
         unsigned Enable_AnalogTriggers : 1;
         unsigned Enable_Counters_Low : 1;
         unsigned Enable_Counters_High : 1;
         unsigned Enable_CounterTimers_Low : 1;
         unsigned Enable_CounterTimers_High : 1;
         unsigned Enable_Encoders : 1;
         unsigned Enable_EncoderTimers : 1;
         unsigned ExternalClock : 1;
      };
      struct{
         unsigned value : 20;
      };
   } tConfig;
   typedef
   union{
      struct{
         unsigned ExternalClockSource_Channel : 4;
         unsigned ExternalClockSource_Module : 1;
         unsigned ExternalClockSource_AnalogTrigger : 1;
         unsigned RisingEdge : 1;
         unsigned FallingEdge : 1;
      };
      struct{
         unsigned value : 8;
      };
   } tExternalTriggers;



   typedef enum
   {
      kDMA_RateAddress = 0x815C,
   } tRate_Constants;

   void writeRate(unsigned int value, tRioStatusCode *status);
   unsigned int readRate(tRioStatusCode *status);


   typedef enum
   {
      kDMA_ConfigAddress = 0x8158,
   } tConfig_Constants;

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_Pause(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AI0_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AI0_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AIAveraged0_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AIAveraged0_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AI1_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AI1_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AIAveraged1_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AIAveraged1_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_Accumulator0(bool value, tRioStatusCode *status);
   void writeConfig_Enable_Accumulator1(bool value, tRioStatusCode *status);
   void writeConfig_Enable_DI(bool value, tRioStatusCode *status);
   void writeConfig_Enable_AnalogTriggers(bool value, tRioStatusCode *status);
   void writeConfig_Enable_Counters_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_Counters_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_CounterTimers_Low(bool value, tRioStatusCode *status);
   void writeConfig_Enable_CounterTimers_High(bool value, tRioStatusCode *status);
   void writeConfig_Enable_Encoders(bool value, tRioStatusCode *status);
   void writeConfig_Enable_EncoderTimers(bool value, tRioStatusCode *status);
   void writeConfig_ExternalClock(bool value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   bool readConfig_Pause(tRioStatusCode *status);
   bool readConfig_Enable_AI0_Low(tRioStatusCode *status);
   bool readConfig_Enable_AI0_High(tRioStatusCode *status);
   bool readConfig_Enable_AIAveraged0_Low(tRioStatusCode *status);
   bool readConfig_Enable_AIAveraged0_High(tRioStatusCode *status);
   bool readConfig_Enable_AI1_Low(tRioStatusCode *status);
   bool readConfig_Enable_AI1_High(tRioStatusCode *status);
   bool readConfig_Enable_AIAveraged1_Low(tRioStatusCode *status);
   bool readConfig_Enable_AIAveraged1_High(tRioStatusCode *status);
   bool readConfig_Enable_Accumulator0(tRioStatusCode *status);
   bool readConfig_Enable_Accumulator1(tRioStatusCode *status);
   bool readConfig_Enable_DI(tRioStatusCode *status);
   bool readConfig_Enable_AnalogTriggers(tRioStatusCode *status);
   bool readConfig_Enable_Counters_Low(tRioStatusCode *status);
   bool readConfig_Enable_Counters_High(tRioStatusCode *status);
   bool readConfig_Enable_CounterTimers_Low(tRioStatusCode *status);
   bool readConfig_Enable_CounterTimers_High(tRioStatusCode *status);
   bool readConfig_Enable_Encoders(tRioStatusCode *status);
   bool readConfig_Enable_EncoderTimers(tRioStatusCode *status);
   bool readConfig_ExternalClock(tRioStatusCode *status);


   typedef enum
   {
      kNumExternalTriggersElements = 4,
      kExternalTriggers_ElementSize = 8,
      kExternalTriggers_ElementMask = 0xFF,
      kDMA_ExternalTriggersAddress = 0x8120,
   } tExternalTriggers_Constants;

   void writeExternalTriggers(unsigned char bitfield_index, tExternalTriggers value, tRioStatusCode *status);
   void writeExternalTriggers_ExternalClockSource_Channel(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   void writeExternalTriggers_ExternalClockSource_Module(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   void writeExternalTriggers_ExternalClockSource_AnalogTrigger(unsigned char bitfield_index, bool value, tRioStatusCode *status);
   void writeExternalTriggers_RisingEdge(unsigned char bitfield_index, bool value, tRioStatusCode *status);
   void writeExternalTriggers_FallingEdge(unsigned char bitfield_index, bool value, tRioStatusCode *status);
   tExternalTriggers readExternalTriggers(unsigned char bitfield_index, tRioStatusCode *status);
   unsigned char readExternalTriggers_ExternalClockSource_Channel(unsigned char bitfield_index, tRioStatusCode *status);
   unsigned char readExternalTriggers_ExternalClockSource_Module(unsigned char bitfield_index, tRioStatusCode *status);
   bool readExternalTriggers_ExternalClockSource_AnalogTrigger(unsigned char bitfield_index, tRioStatusCode *status);
   bool readExternalTriggers_RisingEdge(unsigned char bitfield_index, tRioStatusCode *status);
   bool readExternalTriggers_FallingEdge(unsigned char bitfield_index, tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_DMA_h__
