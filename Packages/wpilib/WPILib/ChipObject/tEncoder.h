// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Encoder_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Encoder_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tEncoder : public tScopedSystem
{
public:
   tEncoder(unsigned char sys_index, tRioStatusCode *status);
   ~tEncoder();

   inline unsigned char getSystemIndex()
   {
      return _SystemIndex;
   }

   typedef enum
   {
      kNumSystems = 4,
   } tConstants;

   typedef
   union{
      struct{
         unsigned Direction : 1;
         signed Value : 31;
      };
      struct{
         unsigned value : 32;
      };
   } tOutput;
   typedef
   union{
      struct{
         unsigned ASource_Channel : 4;
         unsigned ASource_Module : 1;
         unsigned ASource_AnalogTrigger : 1;
         unsigned BSource_Channel : 4;
         unsigned BSource_Module : 1;
         unsigned BSource_AnalogTrigger : 1;
         unsigned IndexSource_Channel : 4;
         unsigned IndexSource_Module : 1;
         unsigned IndexSource_AnalogTrigger : 1;
         unsigned IndexActiveHigh : 1;
         unsigned Reverse : 1;
         unsigned Enable : 1;
      };
      struct{
         unsigned value : 21;
      };
   } tConfig;
   typedef
   union{
      struct{
         unsigned Period : 23;
         signed Count : 8;
         unsigned Stalled : 1;
      };
      struct{
         unsigned value : 32;
      };
   } tTimerOutput;
   typedef
   union{
      struct{
         unsigned StallPeriod : 24;
         unsigned AverageSize : 7;
         unsigned UpdateWhenEmpty : 1;
      };
      struct{
         unsigned value : 32;
      };
   } tTimerConfig;


   typedef enum
   {
      kEncoder0_OutputAddress = 0x81E0,
      kEncoder1_OutputAddress = 0x81CC,
      kEncoder2_OutputAddress = 0x81B8,
      kEncoder3_OutputAddress = 0x81A4,
   } tOutput_Constants;
   static const unsigned int kOutputAddresses [];

   tOutput readOutput(tRioStatusCode *status);
   bool readOutput_Direction(tRioStatusCode *status);
   signed int readOutput_Value(tRioStatusCode *status);


   typedef enum
   {
      kEncoder0_ConfigAddress = 0x81E8,
      kEncoder1_ConfigAddress = 0x81D4,
      kEncoder2_ConfigAddress = 0x81C0,
      kEncoder3_ConfigAddress = 0x81AC,
   } tConfig_Constants;
   static const unsigned int kConfigAddresses [];

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_ASource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_ASource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_ASource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_BSource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_BSource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_BSource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_IndexSource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_IndexSource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_IndexSource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_IndexActiveHigh(bool value, tRioStatusCode *status);
   void writeConfig_Reverse(bool value, tRioStatusCode *status);
   void writeConfig_Enable(bool value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   unsigned char readConfig_ASource_Channel(tRioStatusCode *status);
   unsigned char readConfig_ASource_Module(tRioStatusCode *status);
   bool readConfig_ASource_AnalogTrigger(tRioStatusCode *status);
   unsigned char readConfig_BSource_Channel(tRioStatusCode *status);
   unsigned char readConfig_BSource_Module(tRioStatusCode *status);
   bool readConfig_BSource_AnalogTrigger(tRioStatusCode *status);
   unsigned char readConfig_IndexSource_Channel(tRioStatusCode *status);
   unsigned char readConfig_IndexSource_Module(tRioStatusCode *status);
   bool readConfig_IndexSource_AnalogTrigger(tRioStatusCode *status);
   bool readConfig_IndexActiveHigh(tRioStatusCode *status);
   bool readConfig_Reverse(tRioStatusCode *status);
   bool readConfig_Enable(tRioStatusCode *status);


   typedef enum
   {
      kEncoder0_ResetAddress = 0x81E4,
      kEncoder1_ResetAddress = 0x81D0,
      kEncoder2_ResetAddress = 0x81BC,
      kEncoder3_ResetAddress = 0x81A8,
   } tReset_Constants;
   static const unsigned int kResetAddresses [];

   void strobeReset(tRioStatusCode *status);


   typedef enum
   {
      kTimerOutput_Period_FixedPointIntegerShift = 1,
      kEncoder0_TimerOutputAddress = 0x81D8,
      kEncoder1_TimerOutputAddress = 0x81C4,
      kEncoder2_TimerOutputAddress = 0x81B0,
      kEncoder3_TimerOutputAddress = 0x819C,
   } tTimerOutput_Constants;
   static const unsigned int kTimerOutputAddresses [];

   tTimerOutput readTimerOutput(tRioStatusCode *status);
   unsigned int readTimerOutput_Period(tRioStatusCode *status);
   signed char readTimerOutput_Count(tRioStatusCode *status);
   bool readTimerOutput_Stalled(tRioStatusCode *status);


   typedef enum
   {
      kTimerConfig_StallPeriod_FixedPointIntegerShift = 1,
      kEncoder0_TimerConfigAddress = 0x81DC,
      kEncoder1_TimerConfigAddress = 0x81C8,
      kEncoder2_TimerConfigAddress = 0x81B4,
      kEncoder3_TimerConfigAddress = 0x81A0,
   } tTimerConfig_Constants;
   static const unsigned int kTimerConfigAddresses [];

   void writeTimerConfig(tTimerConfig value, tRioStatusCode *status);
   void writeTimerConfig_StallPeriod(unsigned int value, tRioStatusCode *status);
   void writeTimerConfig_AverageSize(unsigned char value, tRioStatusCode *status);
   void writeTimerConfig_UpdateWhenEmpty(bool value, tRioStatusCode *status);
   tTimerConfig readTimerConfig(tRioStatusCode *status);
   unsigned int readTimerConfig_StallPeriod(tRioStatusCode *status);
   unsigned char readTimerConfig_AverageSize(tRioStatusCode *status);
   bool readTimerConfig_UpdateWhenEmpty(tRioStatusCode *status);





private:
   unsigned char _SystemIndex;

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Encoder_h__
