// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_DIO_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_DIO_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tDIO : public tScopedSystem
{
public:
   tDIO(unsigned char sys_index, tRioStatusCode *status);
   ~tDIO();

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
         unsigned Period : 16;
         unsigned MinHigh : 16;
      };
      struct{
         unsigned value : 32;
      };
   } tPWMConfig;
   typedef
   union{
      struct{
         unsigned Transaction : 1;
         unsigned Done : 1;
         unsigned Aborted : 1;
         unsigned DataReceivedHigh : 24;
      };
      struct{
         unsigned value : 27;
      };
   } tI2CStatus;
   typedef
   union{
      struct{
         unsigned RelayFwd : 8;
         unsigned RelayRev : 8;
         unsigned I2CHeader : 4;
      };
      struct{
         unsigned value : 20;
      };
   } tSlowValue;
   typedef
   union{
      struct{
         unsigned PeriodPower : 4;
         unsigned OutputSelect_0 : 4;
         unsigned OutputSelect_1 : 4;
         unsigned OutputSelect_2 : 4;
         unsigned OutputSelect_3 : 4;
      };
      struct{
         unsigned value : 20;
      };
   } tDO_PWMConfig;
   typedef
   union{
      struct{
         unsigned Address : 8;
         unsigned BytesToRead : 3;
         unsigned BytesToWrite : 3;
         unsigned DataToSendHigh : 16;
         unsigned BitwiseHandshake : 1;
      };
      struct{
         unsigned value : 31;
      };
   } tI2CConfig;


   typedef enum
   {
      kDIO0_DOAddress = 0x8360,
      kDIO1_DOAddress = 0x82F4,
   } tDO_Constants;
   static const unsigned int kDOAddresses [];

   void writeDO(unsigned short value, tRioStatusCode *status);
   unsigned short readDO(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CDataToSendAddress = 0x8328,
      kDIO1_I2CDataToSendAddress = 0x82BC,
   } tI2CDataToSend_Constants;
   static const unsigned int kI2CDataToSendAddresses [];

   void writeI2CDataToSend(unsigned int value, tRioStatusCode *status);
   unsigned int readI2CDataToSend(tRioStatusCode *status);


   typedef enum
   {
      kNumFilterSelectElements = 16,
      kFilterSelect_ElementSize = 2,
      kFilterSelect_ElementMask = 0x3,
      kDIO0_FilterSelectAddress = 0x8300,
      kDIO1_FilterSelectAddress = 0x8294,
   } tFilterSelect_Constants;
   static const unsigned int kFilterSelectAddresses [];

   void writeFilterSelect(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readFilterSelect(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kNumFilterPeriodElements = 3,
      kFilterPeriod_ElementSize = 8,
      kFilterPeriod_ElementMask = 0xFF,
      kDIO0_FilterPeriodAddress = 0x8304,
      kDIO1_FilterPeriodAddress = 0x8298,
   } tFilterPeriod_Constants;
   static const unsigned int kFilterPeriodAddresses [];

   void writeFilterPeriod(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readFilterPeriod(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kDIO0_OutputEnableAddress = 0x8358,
      kDIO1_OutputEnableAddress = 0x82EC,
   } tOutputEnable_Constants;
   static const unsigned int kOutputEnableAddresses [];

   void writeOutputEnable(unsigned short value, tRioStatusCode *status);
   unsigned short readOutputEnable(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_DIAddress = 0x835C,
      kDIO1_DIAddress = 0x82F0,
   } tDI_Constants;
   static const unsigned int kDIAddresses [];

   unsigned short readDI(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CDataReceivedAddress = 0x831C,
      kDIO1_I2CDataReceivedAddress = 0x82B0,
   } tI2CDataReceived_Constants;
   static const unsigned int kI2CDataReceivedAddresses [];

   unsigned int readI2CDataReceived(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CStatusAddress = 0x8318,
      kDIO1_I2CStatusAddress = 0x82AC,
   } tI2CStatus_Constants;
   static const unsigned int kI2CStatusAddresses [];

   tI2CStatus readI2CStatus(tRioStatusCode *status);
   unsigned char readI2CStatus_Transaction(tRioStatusCode *status);
   bool readI2CStatus_Done(tRioStatusCode *status);
   bool readI2CStatus_Aborted(tRioStatusCode *status);
   unsigned int readI2CStatus_DataReceivedHigh(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_SlowValueAddress = 0x8314,
      kDIO1_SlowValueAddress = 0x82A8,
   } tSlowValue_Constants;
   static const unsigned int kSlowValueAddresses [];

   void writeSlowValue(tSlowValue value, tRioStatusCode *status);
   void writeSlowValue_RelayFwd(unsigned char value, tRioStatusCode *status);
   void writeSlowValue_RelayRev(unsigned char value, tRioStatusCode *status);
   void writeSlowValue_I2CHeader(unsigned char value, tRioStatusCode *status);
   tSlowValue readSlowValue(tRioStatusCode *status);
   unsigned char readSlowValue_RelayFwd(tRioStatusCode *status);
   unsigned char readSlowValue_RelayRev(tRioStatusCode *status);
   unsigned char readSlowValue_I2CHeader(tRioStatusCode *status);


   typedef enum
   {
      kNumPWMPeriodScaleElements = 10,
      kPWMPeriodScale_ElementSize = 2,
      kPWMPeriodScale_ElementMask = 0x3,
      kDIO0_PWMPeriodScaleAddress = 0x832C,
      kDIO1_PWMPeriodScaleAddress = 0x82C0,
   } tPWMPeriodScale_Constants;
   static const unsigned int kPWMPeriodScaleAddresses [];

   void writePWMPeriodScale(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readPWMPeriodScale(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kDIO0_PulseAddress = 0x830C,
      kDIO1_PulseAddress = 0x82A0,
   } tPulse_Constants;
   static const unsigned int kPulseAddresses [];

   void writePulse(unsigned short value, tRioStatusCode *status);
   unsigned short readPulse(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CStartAddress = 0x8320,
      kDIO1_I2CStartAddress = 0x82B4,
   } tI2CStart_Constants;
   static const unsigned int kI2CStartAddresses [];

   void strobeI2CStart(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_BFLAddress = 0x8310,
      kDIO1_BFLAddress = 0x82A4,
   } tBFL_Constants;
   static const unsigned int kBFLAddresses [];

   void writeBFL(bool value, tRioStatusCode *status);
   bool readBFL(tRioStatusCode *status);


   typedef enum
   {
      kNumDO_PWMDutyCycleElements = 4,
      kDO_PWMDutyCycle_ElementSize = 8,
      kDO_PWMDutyCycle_ElementMask = 0xFF,
      kDIO0_DO_PWMDutyCycleAddress = 0x82FC,
      kDIO1_DO_PWMDutyCycleAddress = 0x8290,
   } tDO_PWMDutyCycle_Constants;
   static const unsigned int kDO_PWMDutyCycleAddresses [];

   void writeDO_PWMDutyCycle(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readDO_PWMDutyCycle(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kDIO0_PulseLengthAddress = 0x8308,
      kDIO1_PulseLengthAddress = 0x829C,
   } tPulseLength_Constants;
   static const unsigned int kPulseLengthAddresses [];

   void writePulseLength(unsigned char value, tRioStatusCode *status);
   unsigned char readPulseLength(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_DO_PWMConfigAddress = 0x82F8,
      kDIO1_DO_PWMConfigAddress = 0x828C,
   } tDO_PWMConfig_Constants;
   static const unsigned int kDO_PWMConfigAddresses [];

   void writeDO_PWMConfig(tDO_PWMConfig value, tRioStatusCode *status);
   void writeDO_PWMConfig_PeriodPower(unsigned char value, tRioStatusCode *status);
   void writeDO_PWMConfig_OutputSelect_0(unsigned char value, tRioStatusCode *status);
   void writeDO_PWMConfig_OutputSelect_1(unsigned char value, tRioStatusCode *status);
   void writeDO_PWMConfig_OutputSelect_2(unsigned char value, tRioStatusCode *status);
   void writeDO_PWMConfig_OutputSelect_3(unsigned char value, tRioStatusCode *status);
   tDO_PWMConfig readDO_PWMConfig(tRioStatusCode *status);
   unsigned char readDO_PWMConfig_PeriodPower(tRioStatusCode *status);
   unsigned char readDO_PWMConfig_OutputSelect_0(tRioStatusCode *status);
   unsigned char readDO_PWMConfig_OutputSelect_1(tRioStatusCode *status);
   unsigned char readDO_PWMConfig_OutputSelect_2(tRioStatusCode *status);
   unsigned char readDO_PWMConfig_OutputSelect_3(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CConfigAddress = 0x8324,
      kDIO1_I2CConfigAddress = 0x82B8,
   } tI2CConfig_Constants;
   static const unsigned int kI2CConfigAddresses [];

   void writeI2CConfig(tI2CConfig value, tRioStatusCode *status);
   void writeI2CConfig_Address(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_BytesToRead(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_BytesToWrite(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_DataToSendHigh(unsigned short value, tRioStatusCode *status);
   void writeI2CConfig_BitwiseHandshake(bool value, tRioStatusCode *status);
   tI2CConfig readI2CConfig(tRioStatusCode *status);
   unsigned char readI2CConfig_Address(tRioStatusCode *status);
   unsigned char readI2CConfig_BytesToRead(tRioStatusCode *status);
   unsigned char readI2CConfig_BytesToWrite(tRioStatusCode *status);
   unsigned short readI2CConfig_DataToSendHigh(tRioStatusCode *status);
   bool readI2CConfig_BitwiseHandshake(tRioStatusCode *status);



   typedef enum
   {
      kDIO_LoopTimingAddress = 0x8368,
   } tLoopTiming_Constants;

   unsigned short readLoopTiming(tRioStatusCode *status);


   typedef enum
   {
      kDIO_PWMConfigAddress = 0x8364,
   } tPWMConfig_Constants;

   void writePWMConfig(tPWMConfig value, tRioStatusCode *status);
   void writePWMConfig_Period(unsigned short value, tRioStatusCode *status);
   void writePWMConfig_MinHigh(unsigned short value, tRioStatusCode *status);
   tPWMConfig readPWMConfig(tRioStatusCode *status);
   unsigned short readPWMConfig_Period(tRioStatusCode *status);
   unsigned short readPWMConfig_MinHigh(tRioStatusCode *status);



   typedef enum
   {
      kNumPWMValueRegisters = 10,
      kDIO0_PWMValue0Address = 0x8354,
      kDIO0_PWMValue1Address = 0x8350,
      kDIO0_PWMValue2Address = 0x834C,
      kDIO0_PWMValue3Address = 0x8348,
      kDIO0_PWMValue4Address = 0x8344,
      kDIO0_PWMValue5Address = 0x8340,
      kDIO0_PWMValue6Address = 0x833C,
      kDIO0_PWMValue7Address = 0x8338,
      kDIO0_PWMValue8Address = 0x8334,
      kDIO0_PWMValue9Address = 0x8330,
      kDIO1_PWMValue0Address = 0x82E8,
      kDIO1_PWMValue1Address = 0x82E4,
      kDIO1_PWMValue2Address = 0x82E0,
      kDIO1_PWMValue3Address = 0x82DC,
      kDIO1_PWMValue4Address = 0x82D8,
      kDIO1_PWMValue5Address = 0x82D4,
      kDIO1_PWMValue6Address = 0x82D0,
      kDIO1_PWMValue7Address = 0x82CC,
      kDIO1_PWMValue8Address = 0x82C8,
      kDIO1_PWMValue9Address = 0x82C4,
   } tPWMValue_Constants;
   static const unsigned int kPWMValueAddresses [];

   void writePWMValue(unsigned char reg_index, unsigned char value, tRioStatusCode *status);
   unsigned char readPWMValue(unsigned char reg_index, tRioStatusCode *status);



private:
   unsigned char _SystemIndex;

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_DIO_h__
