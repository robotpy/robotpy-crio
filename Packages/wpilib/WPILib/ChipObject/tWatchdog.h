// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Watchdog_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Watchdog_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tWatchdog : public tScopedSystem
{
public:
   tWatchdog(tRioStatusCode *status);
   ~tWatchdog();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;

   typedef
   union{
      struct{
         unsigned SystemActive : 1;
         unsigned Alive : 1;
         unsigned SysDisableCount : 15;
         unsigned DisableCount : 15;
      };
      struct{
         unsigned value : 32;
      };
   } tStatus;



   typedef enum
   {
      kWatchdog_StatusAddress = 0x8448,
   } tStatus_Constants;

   tStatus readStatus(tRioStatusCode *status);
   bool readStatus_SystemActive(tRioStatusCode *status);
   bool readStatus_Alive(tRioStatusCode *status);
   unsigned short readStatus_SysDisableCount(tRioStatusCode *status);
   unsigned short readStatus_DisableCount(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_FeedAddress = 0x8444,
   } tFeed_Constants;

   void strobeFeed(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_KillAddress = 0x8440,
   } tKill_Constants;

   void strobeKill(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_ImmortalAddress = 0x8434,
   } tImmortal_Constants;

   void writeImmortal(bool value, tRioStatusCode *status);
   bool readImmortal(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_ExpirationAddress = 0x8438,
   } tExpiration_Constants;

   void writeExpiration(unsigned int value, tRioStatusCode *status);
   unsigned int readExpiration(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_TimerAddress = 0x843C,
   } tTimer_Constants;

   unsigned int readTimer(tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Watchdog_h__
