// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __nAD9A5591CC64E4DF756D77D1B57A549E_Watchdog_h__
#define __nAD9A5591CC64E4DF756D77D1B57A549E_Watchdog_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace nAD9A5591CC64E4DF756D77D1B57A549E
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
      kWatchdog_StatusAddress = 0x8434,
   } tStatus_Constants;

   tStatus readStatus(tRioStatusCode *status);
   bool readStatus_SystemActive(tRioStatusCode *status);
   bool readStatus_Alive(tRioStatusCode *status);
   unsigned short readStatus_SysDisableCount(tRioStatusCode *status);
   unsigned short readStatus_DisableCount(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_FeedAddress = 0x8430,
   } tFeed_Constants;

   void strobeFeed(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_KillAddress = 0x842C,
   } tKill_Constants;

   void strobeKill(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_ImmortalAddress = 0x8420,
   } tImmortal_Constants;

   void writeImmortal(bool value, tRioStatusCode *status);
   bool readImmortal(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_ExpirationAddress = 0x8424,
   } tExpiration_Constants;

   void writeExpiration(unsigned int value, tRioStatusCode *status);
   unsigned int readExpiration(tRioStatusCode *status);


   typedef enum
   {
      kWatchdog_TimerAddress = 0x8428,
   } tTimer_Constants;

   unsigned int readTimer(tRioStatusCode *status);




private:

};

}
}

#endif // __nAD9A5591CC64E4DF756D77D1B57A549E_Watchdog_h__
