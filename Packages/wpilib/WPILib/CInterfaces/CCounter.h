#ifndef _C_COUNTER_H
#define _C_COUNTER_H

void StartCounter(UINT32 channel);
void StartCounter(UINT32 slot, UINT32 channel);
INT32 GetCounter(UINT32 channel);
INT32 GetCounter(UINT32 slot, UINT32 channel);
void ResetCounter(UINT32 channel);
void ResetCounter(UINT32 slot, UINT32 channel);
void StopCounter(UINT32 channel);
void StopCounter(UINT32 slot, UINT32 channel);
double GetCounterPeriod(UINT32 channel);
double GetCounterPeriod(UINT32 slot, UINT32 channel);
void DeleteCounter(UINT32 slot, UINT32 channel);
void DeleteCounter(UINT32 channel);

typedef void *CounterObject;

CounterObject CreateCounter(UINT32 channel);
CounterObject CreateCounter(UINT32 slot, UINT32 channel);
void StartCounter(CounterObject o);
INT32 GetCounter(CounterObject o);
void ResetCounter(CounterObject o);
void StopCounter(CounterObject o);
double GetCounterPeriod(CounterObject o);
void DeleteCounter(CounterObject o);


#endif
