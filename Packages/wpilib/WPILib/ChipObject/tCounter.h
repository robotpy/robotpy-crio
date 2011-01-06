// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Counter_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Counter_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tCounter : public tScopedSystem
{
public:
   tCounter(unsigned char sys_index, tRioStatusCode *status);
   ~tCounter();

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
         unsigned UpSource_Channel : 4;
         unsigned UpSource_Module : 1;
         unsigned UpSource_AnalogTrigger : 1;
         unsigned DownSource_Channel : 4;
         unsigned DownSource_Module : 1;
         unsigned DownSource_AnalogTrigger : 1;
         unsigned IndexSource_Channel : 4;
         unsigned IndexSource_Module : 1;
         unsigned IndexSource_AnalogTrigger : 1;
         unsigned IndexActiveHigh : 1;
         unsigned UpRisingEdge : 1;
         unsigned UpFallingEdge : 1;
         unsigned DownRisingEdge : 1;
         unsigned DownFallingEdge : 1;
         unsigned Mode : 2;
         unsigned PulseLengthThreshold : 6;
         unsigned Enable : 1;
      };
      struct{
         unsigned value : 32;
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
      kCounter0_OutputAddress = 0x8280,
      kCounter1_OutputAddress = 0x826C,
      kCounter2_OutputAddress = 0x8258,
      kCounter3_OutputAddress = 0x8244,
      kCounter4_OutputAddress = 0x8230,
      kCounter5_OutputAddress = 0x821C,
      kCounter6_OutputAddress = 0x8208,
      kCounter7_OutputAddress = 0x81F4,
   } tOutput_Constants;
   static const unsigned int kOutputAddresses [];

   tOutput readOutput(tRioStatusCode *status);
   bool readOutput_Direction(tRioStatusCode *status);
   signed int readOutput_Value(tRioStatusCode *status);


   typedef enum
   {
      kConfig_PulseLengthThreshold_FixedPointIntegerShift = 8,
      kCounter0_ConfigAddress = 0x8288,
      kCounter1_ConfigAddress = 0x8274,
      kCounter2_ConfigAddress = 0x8260,
      kCounter3_ConfigAddress = 0x824C,
      kCounter4_ConfigAddress = 0x8238,
      kCounter5_ConfigAddress = 0x8224,
      kCounter6_ConfigAddress = 0x8210,
      kCounter7_ConfigAddress = 0x81FC,
   } tConfig_Constants;
   static const unsigned int kConfigAddresses [];

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_UpSource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_UpSource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_UpSource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_DownSource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_DownSource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_DownSource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_IndexSource_Channel(unsigned char value, tRioStatusCode *status);
   void writeConfig_IndexSource_Module(unsigned char value, tRioStatusCode *status);
   void writeConfig_IndexSource_AnalogTrigger(bool value, tRioStatusCode *status);
   void writeConfig_IndexActiveHigh(bool value, tRioStatusCode *status);
   void writeConfig_UpRisingEdge(bool value, tRioStatusCode *status);
   void writeConfig_UpFallingEdge(bool value, tRioStatusCode *status);
   void writeConfig_DownRisingEdge(bool value, tRioStatusCode *status);
   void writeConfig_DownFallingEdge(bool value, tRioStatusCode *status);
   void writeConfig_Mode(unsigned char value, tRioStatusCode *status);
   void writeConfig_PulseLengthThreshold(unsigned short value, tRioStatusCode *status);
   void writeConfig_Enable(bool value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   unsigned char readConfig_UpSource_Channel(tRioStatusCode *status);
   unsigned char readConfig_UpSource_Module(tRioStatusCode *status);
   bool readConfig_UpSource_AnalogTrigger(tRioStatusCode *status);
   unsigned char readConfig_DownSource_Channel(tRioStatusCode *status);
   unsigned char readConfig_DownSource_Module(tRioStatusCode *status);
   bool readConfig_DownSource_AnalogTrigger(tRioStatusCode *status);
   unsigned char readConfig_IndexSource_Channel(tRioStatusCode *status);
   unsigned char readConfig_IndexSource_Module(tRioStatusCode *status);
   bool readConfig_IndexSource_AnalogTrigger(tRioStatusCode *status);
   bool readConfig_IndexActiveHigh(tRioStatusCode *status);
   bool readConfig_UpRisingEdge(tRioStatusCode *status);
   bool readConfig_UpFallingEdge(tRioStatusCode *status);
   bool readConfig_DownRisingEdge(tRioStatusCode *status);
   bool readConfig_DownFallingEdge(tRioStatusCode *status);
   unsigned char readConfig_Mode(tRioStatusCode *status);
   unsigned short readConfig_PulseLengthThreshold(tRioStatusCode *status);
   bool readConfig_Enable(tRioStatusCode *status);


   typedef enum
   {
      kCounter0_ResetAddress = 0x8284,
      kCounter1_ResetAddress = 0x8270,
      kCounter2_ResetAddress = 0x825C,
      kCounter3_ResetAddress = 0x8248,
      kCounter4_ResetAddress = 0x8234,
      kCounter5_ResetAddress = 0x8220,
      kCounter6_ResetAddress = 0x820C,
      kCounter7_ResetAddress = 0x81F8,
   } tReset_Constants;
   static const unsigned int kResetAddresses [];

   void strobeReset(tRioStatusCode *status);


   typedef enum
   {
      kTimerOutput_Period_FixedPointIntegerShift = 1,
      kCounter0_TimerOutputAddress = 0x8278,
      kCounter1_TimerOutputAddress = 0x8264,
      kCounter2_TimerOutputAddress = 0x8250,
      kCounter3_TimerOutputAddress = 0x823C,
      kCounter4_TimerOutputAddress = 0x8228,
      kCounter5_TimerOutputAddress = 0x8214,
      kCounter6_TimerOutputAddress = 0x8200,
      kCounter7_TimerOutputAddress = 0x81EC,
   } tTimerOutput_Constants;
   static const unsigned int kTimerOutputAddresses [];

   tTimerOutput readTimerOutput(tRioStatusCode *status);
   unsigned int readTimerOutput_Period(tRioStatusCode *status);
   signed char readTimerOutput_Count(tRioStatusCode *status);
   bool readTimerOutput_Stalled(tRioStatusCode *status);


   typedef enum
   {
      kTimerConfig_StallPeriod_FixedPointIntegerShift = 1,
      kCounter0_TimerConfigAddress = 0x827C,
      kCounter1_TimerConfigAddress = 0x8268,
      kCounter2_TimerConfigAddress = 0x8254,
      kCounter3_TimerConfigAddress = 0x8240,
      kCounter4_TimerConfigAddress = 0x822C,
      kCounter5_TimerConfigAddress = 0x8218,
      kCounter6_TimerConfigAddress = 0x8204,
      kCounter7_TimerConfigAddress = 0x81F0,
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

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Counter_h__
