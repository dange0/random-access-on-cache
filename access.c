#include "access.h"

double tvgetf()
{
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;

    return sec * 1e9;
}

double sequence_access(unsigned int size)
{
    int array[size], index[size], result, i;
    for (i = 0; i < size; i++) {
        index[i] = i;
    }

    double t1 = tvgetf();
    for (i = 0; i < size; i++) {
        result += array[index[i]];
    }
    double t2 = tvgetf();
    return (t2 - t1) / size;
}

double random_access(unsigned int size)
{
    int array[size], index[size], result, i;
    for (i = 0; i < (int) size; i++) {
        index[i] = rand() % size;
    }
    double t1 = tvgetf();
    for (i = 0; i < size; i++) {
        result += array[index[i]];
    }
    double t2 = tvgetf();
    return (t2 - t1) / size;
}