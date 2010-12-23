// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __nAD9A5591CC64E4DF756D77D1B57A549E_Alarm_h__
#define __nAD9A5591CC64E4DF756D77D1B57A549E_Alarm_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace nAD9A5591CC64E4DF756D77D1B57A549E
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
      kAlarm_TriggerTimeAddress = 0x8124,
   } tTriggerTime_Constants;

   void writeTriggerTime(unsigned int value, tRioStatusCode *status);
   unsigned int readTriggerTime(tRioStatusCode *status);


   typedef enum
   {
      kAlarm_EnableAddress = 0x8120,
   } tEnable_Constants;

   void writeEnable(bool value, tRioStatusCode *status);
   bool readEnable(tRioStatusCode *status);




private:

};

}
}

#endif // __nAD9A5591CC64E4DF756D77D1B57A549E_Alarm_h__
