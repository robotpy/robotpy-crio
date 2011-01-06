// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_SPI_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_SPI_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tSPI : public tScopedSystem
{
public:
   tSPI(tRioStatusCode *status);
   ~tSPI();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;

   typedef
   union{
      struct{
         unsigned ReceivedDataOverflow : 1;
         unsigned Idle : 1;
      };
      struct{
         unsigned value : 2;
      };
   } tStatus;
   typedef
   union{
      struct{
         unsigned BusBitWidth : 8;
         unsigned ClockHalfPeriodDelay : 8;
         unsigned MSBfirst : 1;
         unsigned DataOnFalling : 1;
         unsigned LatchFirst : 1;
         unsigned LatchLast : 1;
         unsigned FramePolarity : 1;
         unsigned WriteOnly : 1;
         unsigned ClockPolarity : 1;
      };
      struct{
         unsigned value : 23;
      };
   } tConfig;
   typedef
   union{
      struct{
         unsigned SCLK_Channel : 4;
         unsigned SCLK_Module : 1;
         unsigned MOSI_Channel : 4;
         unsigned MOSI_Module : 1;
         unsigned MISO_Channel : 4;
         unsigned MISO_Module : 1;
         unsigned SS_Channel : 4;
         unsigned SS_Module : 1;
      };
      struct{
         unsigned value : 20;
      };
   } tChannels;



   typedef enum
   {
      kSPI_StatusAddress = 0x812C,
   } tStatus_Constants;

   tStatus readStatus(tRioStatusCode *status);
   bool readStatus_ReceivedDataOverflow(tRioStatusCode *status);
   bool readStatus_Idle(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ReadReceivedDataAddress = 0x813C,
   } tReadReceivedData_Constants;

   void strobeReadReceivedData(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ConfigAddress = 0x8154,
   } tConfig_Constants;

   void writeConfig(tConfig value, tRioStatusCode *status);
   void writeConfig_BusBitWidth(unsigned char value, tRioStatusCode *status);
   void writeConfig_ClockHalfPeriodDelay(unsigned char value, tRioStatusCode *status);
   void writeConfig_MSBfirst(bool value, tRioStatusCode *status);
   void writeConfig_DataOnFalling(bool value, tRioStatusCode *status);
   void writeConfig_LatchFirst(bool value, tRioStatusCode *status);
   void writeConfig_LatchLast(bool value, tRioStatusCode *status);
   void writeConfig_FramePolarity(bool value, tRioStatusCode *status);
   void writeConfig_WriteOnly(bool value, tRioStatusCode *status);
   void writeConfig_ClockPolarity(bool value, tRioStatusCode *status);
   tConfig readConfig(tRioStatusCode *status);
   unsigned char readConfig_BusBitWidth(tRioStatusCode *status);
   unsigned char readConfig_ClockHalfPeriodDelay(tRioStatusCode *status);
   bool readConfig_MSBfirst(tRioStatusCode *status);
   bool readConfig_DataOnFalling(tRioStatusCode *status);
   bool readConfig_LatchFirst(tRioStatusCode *status);
   bool readConfig_LatchLast(tRioStatusCode *status);
   bool readConfig_FramePolarity(tRioStatusCode *status);
   bool readConfig_WriteOnly(tRioStatusCode *status);
   bool readConfig_ClockPolarity(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ResetAddress = 0x814C,
   } tReset_Constants;

   void strobeReset(tRioStatusCode *status);


   typedef enum
   {
      kSPI_DataToLoadAddress = 0x8144,
   } tDataToLoad_Constants;

   void writeDataToLoad(unsigned int value, tRioStatusCode *status);
   unsigned int readDataToLoad(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ReceivedDataAddress = 0x8138,
   } tReceivedData_Constants;

   unsigned int readReceivedData(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ChannelsAddress = 0x8150,
   } tChannels_Constants;

   void writeChannels(tChannels value, tRioStatusCode *status);
   void writeChannels_SCLK_Channel(unsigned char value, tRioStatusCode *status);
   void writeChannels_SCLK_Module(unsigned char value, tRioStatusCode *status);
   void writeChannels_MOSI_Channel(unsigned char value, tRioStatusCode *status);
   void writeChannels_MOSI_Module(unsigned char value, tRioStatusCode *status);
   void writeChannels_MISO_Channel(unsigned char value, tRioStatusCode *status);
   void writeChannels_MISO_Module(unsigned char value, tRioStatusCode *status);
   void writeChannels_SS_Channel(unsigned char value, tRioStatusCode *status);
   void writeChannels_SS_Module(unsigned char value, tRioStatusCode *status);
   tChannels readChannels(tRioStatusCode *status);
   unsigned char readChannels_SCLK_Channel(tRioStatusCode *status);
   unsigned char readChannels_SCLK_Module(tRioStatusCode *status);
   unsigned char readChannels_MOSI_Channel(tRioStatusCode *status);
   unsigned char readChannels_MOSI_Module(tRioStatusCode *status);
   unsigned char readChannels_MISO_Channel(tRioStatusCode *status);
   unsigned char readChannels_MISO_Module(tRioStatusCode *status);
   unsigned char readChannels_SS_Channel(tRioStatusCode *status);
   unsigned char readChannels_SS_Module(tRioStatusCode *status);


   typedef enum
   {
      kSPI_LoadAddress = 0x8148,
   } tLoad_Constants;

   void strobeLoad(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ReceivedElementsAddress = 0x8134,
   } tReceivedElements_Constants;

   unsigned short readReceivedElements(tRioStatusCode *status);


   typedef enum
   {
      kSPI_ClearReceivedDataAddress = 0x8130,
   } tClearReceivedData_Constants;

   void strobeClearReceivedData(tRioStatusCode *status);


   typedef enum
   {
      kSPI_AvailableToLoadAddress = 0x8140,
   } tAvailableToLoad_Constants;

   unsigned short readAvailableToLoad(tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_SPI_h__
