// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_AI_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_AI_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tAI : public tScopedSystem
{
public:
   tAI(unsigned char sys_index, tRioStatusCode *status);
   ~tAI();

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
         unsigned Channel : 3;
         unsigned Module : 1;
         unsigned Averaged : 1;
      };
      struct{
         unsigned value : 5;
      };
   } tReadSelect;
   typedef
   union{
      struct{
         unsigned ScanSize : 3;
         unsigned ConvertRate : 26;
      };
      struct{
         unsigned value : 29;
      };
   } tConfig;


   typedef enum
   {
      kAI0_ConfigAddress = 0x8414,
      kAI1_ConfigAddress = 0x8400,
   } tConfig_Constants;
   static const unsigned int kConfigAddresses [];

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_ScanSize(unsigned char value, tRioStatusCode *status);
   void writeConfig_ConvertRate(unsigned int value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   unsigned char readConfig_ScanSize(tRioStatusCode *status);
   unsigned int readConfig_ConvertRate(tRioStatusCode *status);


   typedef enum
   {
      kNumScanListElements = 8,
      kScanList_ElementSize = 3,
      kScanList_ElementMask = 0x7,
      kAI0_ScanListAddress = 0x8410,
      kAI1_ScanListAddress = 0x83FC,
   } tScanList_Constants;
   static const unsigned int kScanListAddresses [];

   void writeScanList(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readScanList(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kNumAverageBitsElements = 8,
      kAverageBits_ElementSize = 4,
      kAverageBits_ElementMask = 0xF,
      kAI0_AverageBitsAddress = 0x8408,
      kAI1_AverageBitsAddress = 0x83F4,
   } tAverageBits_Constants;
   static const unsigned int kAverageBitsAddresses [];

   void writeAverageBits(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readAverageBits(unsigned char bitfield_index, tRioStatusCode *status);


   typedef enum
   {
      kAI0_LoopTimingAddress = 0x8404,
      kAI1_LoopTimingAddress = 0x83F0,
   } tLoopTiming_Constants;
   static const unsigned int kLoopTimingAddresses [];

   unsigned int readLoopTiming(tRioStatusCode *status);


   typedef enum
   {
      kNumOversampleBitsElements = 8,
      kOversampleBits_ElementSize = 4,
      kOversampleBits_ElementMask = 0xF,
      kAI0_OversampleBitsAddress = 0x840C,
      kAI1_OversampleBitsAddress = 0x83F8,
   } tOversampleBits_Constants;
   static const unsigned int kOversampleBitsAddresses [];

   void writeOversampleBits(unsigned char bitfield_index, unsigned char value, tRioStatusCode *status);
   unsigned char readOversampleBits(unsigned char bitfield_index, tRioStatusCode *status);



   typedef enum
   {
      kAI_OutputAddress = 0x8418,
   } tOutput_Constants;

   signed int readOutput(tRioStatusCode *status);


   typedef enum
   {
      kAI_ReadSelectAddress = 0x8420,
   } tReadSelect_Constants;

   void writeReadSelect(tReadSelect value, tRioStatusCode *status);
   void writeReadSelect_Channel(unsigned char value, tRioStatusCode *status);
   void writeReadSelect_Module(unsigned char value, tRioStatusCode *status);
   void writeReadSelect_Averaged(bool value, tRioStatusCode *status);
   tReadSelect readReadSelect(tRioStatusCode *status);
   unsigned char readReadSelect_Channel(tRioStatusCode *status);
   unsigned char readReadSelect_Module(tRioStatusCode *status);
   bool readReadSelect_Averaged(tRioStatusCode *status);


   typedef enum
   {
      kAI_LatchOutputAddress = 0x841C,
   } tLatchOutput_Constants;

   void strobeLatchOutput(tRioStatusCode *status);




private:
   unsigned char _SystemIndex;

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_AI_h__
