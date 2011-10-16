#include <time.h>
#include <sys/times.h>

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    int ret;
    struct timespec tp;

    if  ( (ret=clock_gettime(CLOCK_REALTIME, &tp))==0)
    {
        tv->tv_sec  = tp.tv_sec;
        tv->tv_usec = (tp.tv_nsec + 500) / 1000;
    }
     return ret;
}

