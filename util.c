#include "philo.h"

unsigned long   get_time(void)
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec * 1000 * 1000) + current_time.tv_usec);
}

// unsigned long   