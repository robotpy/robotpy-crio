// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __nAD9A5591CC64E4DF756D77D1B57A549E_DIO_h__
#define __nAD9A5591CC64E4DF756D77D1B57A549E_DIO_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace nAD9A5591CC64E4DF756D77D1B57A549E
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
         unsigned Address : 8;
         unsigned BytesToRead : 3;
         unsigned BytesToWrite : 3;
         unsigned DataToSendHigh : 16;
      };
      struct{
         unsigned value : 30;
      };
   } tI2CConfig;


   typedef enum
   {
      kDIO0_DOAddress = 0x834C,
      kDIO1_DOAddress = 0x82E8,
   } tDO_Constants;
   static const unsigned int kDOAddresses [];

   void writeDO(unsigned short value, tRioStatusCode *status);
   unsigned short readDO(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CDataToSendAddress = 0x8314,
      kDIO1_I2CDataToSendAddress = 0x82B0,
   } tI2CDataToSend_Constants;
   static const unsigned int kI2CDataToSendAddresses [];

   void writeI2CDataToSend(unsigned int value, tRioStatusCode *status);
   unsigned int readI2CDataToSend(tRioStatusCode *status);


   typedef enum
   {
      kNumFilterSelectElements = 16,
      kFilterSelect_ElementSize = 2,
      kFilterSelect_ElementMask = 0x3,
      kDIO0_FilterSelectAddress = 0x82EC,
      kDIO1_FilterSelectAddress = 0x8288,
   } tFilterSelect_Constants;
   static const unsigned int kFilterSelectAddresses [];

   void writeFilterSelect(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readFilterSelect(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kNumFilterPeriodElements = 3,
      kFilterPeriod_ElementSize = 8,
      kFilterPeriod_ElementMask = 0xFF,
      kDIO0_FilterPeriodAddress = 0x82F0,
      kDIO1_FilterPeriodAddress = 0x828C,
   } tFilterPeriod_Constants;
   static const unsigned int kFilterPeriodAddresses [];

   void writeFilterPeriod(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readFilterPeriod(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kDIO0_OutputEnableAddress = 0x8344,
      kDIO1_OutputEnableAddress = 0x82E0,
   } tOutputEnable_Constants;
   static const unsigned int kOutputEnableAddresses [];

   void writeOutputEnable(unsigned short value, tRioStatusCode *status);
   unsigned short readOutputEnable(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_DIAddress = 0x8348,
      kDIO1_DIAddress = 0x82E4,
   } tDI_Constants;
   static const unsigned int kDIAddresses [];

   unsigned short readDI(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CDataReceivedAddress = 0x8308,
      kDIO1_I2CDataReceivedAddress = 0x82A4,
   } tI2CDataReceived_Constants;
   static const unsigned int kI2CDataReceivedAddresses [];

   unsigned int readI2CDataReceived(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CStatusAddress = 0x8304,
      kDIO1_I2CStatusAddress = 0x82A0,
   } tI2CStatus_Constants;
   static const unsigned int kI2CStatusAddresses [];

   tI2CStatus readI2CStatus(tRioStatusCode *status);
   unsigned char readI2CStatus_Transaction(tRioStatusCode *status);
   bool readI2CStatus_Done(tRioStatusCode *status);
   bool readI2CStatus_Aborted(tRioStatusCode *status);
   unsigned int readI2CStatus_DataReceivedHigh(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_SlowValueAddress = 0x8300,
      kDIO1_SlowValueAddress = 0x829C,
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
      kDIO0_PWMPeriodScaleAddress = 0x8318,
      kDIO1_PWMPeriodScaleAddress = 0x82B4,
   } tPWMPeriodScale_Constants;
   static const unsigned int kPWMPeriodScaleAddresses [];

   void writePWMPeriodScale(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readPWMPeriodScale(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kDIO0_PulseAddress = 0x82F8,
      kDIO1_PulseAddress = 0x8294,
   } tPulse_Constants;
   static const unsigned int kPulseAddresses [];

   void writePulse(unsigned short value, tRioStatusCode *status);
   unsigned short readPulse(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CStartAddress = 0x830C,
      kDIO1_I2CStartAddress = 0x82A8,
   } tI2CStart_Constants;
   static const unsigned int kI2CStartAddresses [];

   void strobeI2CStart(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_BFLAddress = 0x82FC,
      kDIO1_BFLAddress = 0x8298,
   } tBFL_Constants;
   static const unsigned int kBFLAddresses [];

   void writeBFL(bool value, tRioStatusCode *status);
   bool readBFL(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_PulseLengthAddress = 0x82F4,
      kDIO1_PulseLengthAddress = 0x8290,
   } tPulseLength_Constants;
   static const unsigned int kPulseLengthAddresses [];

   void writePulseLength(unsigned char value, tRioStatusCode *status);
   unsigned char readPulseLength(tRioStatusCode *status);


   typedef enum
   {
      kDIO0_I2CConfigAddress = 0x8310,
      kDIO1_I2CConfigAddress = 0x82AC,
   } tI2CConfig_Constants;
   static const unsigned int kI2CConfigAddresses [];

   void writeI2CConfig(tI2CConfig value, tRioStatusCode *status);
   void writeI2CConfig_Address(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_BytesToRead(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_BytesToWrite(unsigned char value, tRioStatusCode *status);
   void writeI2CConfig_DataToSendHigh(unsigned short value, tRioStatusCode *status);
   tI2CConfig readI2CConfig(tRioStatusCode *status);
   unsigned char readI2CConfig_Address(tRioStatusCode *status);
   unsigned char readI2CConfig_BytesToRead(tRioStatusCode *status);
   unsigned char readI2CConfig_BytesToWrite(tRioStatusCode *status);
   unsigned short readI2CConfig_DataToSendHigh(tRioStatusCode *status);



   typedef enum
   {
      kDIO_LoopTimingAddress = 0x8354,
   } tLoopTiming_Constants;

   unsigned short readLoopTiming(tRioStatusCode *status);


   typedef enum
   {
      kDIO_PWMConfigAddress = 0x8350,
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
      kDIO0_PWMValue0Address = 0x8340,
      kDIO0_PWMValue1Address = 0x833C,
      kDIO0_PWMValue2Address = 0x8338,
      kDIO0_PWMValue3Address = 0x8334,
      kDIO0_PWMValue4Address = 0x8330,
      kDIO0_PWMValue5Address = 0x832C,
      kDIO0_PWMValue6Address = 0x8328,
      kDIO0_PWMValue7Address = 0x8324,
      kDIO0_PWMValue8Address = 0x8320,
      kDIO0_PWMValue9Address = 0x831C,
      kDIO1_PWMValue0Address = 0x82DC,
      kDIO1_PWMValue1Address = 0x82D8,
      kDIO1_PWMValue2Address = 0x82D4,
      kDIO1_PWMValue3Address = 0x82D0,
      kDIO1_PWMValue4Address = 0x82CC,
      kDIO1_PWMValue5Address = 0x82C8,
      kDIO1_PWMValue6Address = 0x82C4,
      kDIO1_PWMValue7Address = 0x82C0,
      kDIO1_PWMValue8Address = 0x82BC,
      kDIO1_PWMValue9Address = 0x82B8,
   } tPWMValue_Constants;
   static const unsigned int kPWMValueAddresses [];

   void writePWMValue(unsigned char reg_index, unsigned char value, tRioStatusCode *status);
   unsigned char readPWMValue(unsigned char reg_index, tRioStatusCode *status);



private:
   unsigned char _SystemIndex;

};

}
}

#endif // __nAD9A5591CC64E4DF756D77D1B57A549E_DIO_h__
