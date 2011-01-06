// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __n2EAA5E59CAF1A8A966853A011B61CC91_Alarm_h__
#define __n2EAA5E59CAF1A8A966853A011B61CC91_Alarm_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace n2EAA5E59CAF1A8A966853A011B61CC91
{

class tAlarm : public tScopedSystem
{
public:
   tAlarm(tRioStatusCode *status);
   ~tAlarm();

   typedef enum
   {
      kNumSystems = 1,
   } tConstants;




   typedef enum
   {
      kAlarm_TriggerTimeAddress = 0x8128,
   } tTriggerTime_Constants;

   void writeTriggerTime(unsigned int value, tRioStatusCode *status);
   unsigned int readTriggerTime(tRioStatusCode *status);


   typedef enum
   {
      kAlarm_EnableAddress = 0x8124,
   } tEnable_Constants;

   void writeEnable(bool value, tRioStatusCode *status);
   bool readEnable(tRioStatusCode *status);




private:

};

}
}

#endif // __n2EAA5E59CAF1A8A966853A011B61CC91_Alarm_h__
