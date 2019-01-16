#include "access.h"

double sequence_access(unsigned int size)
{
    char array[size];
    int index[size], result, i;
    result = 0;
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
    char array[size];
    int index[size], result, i;
    result = 0;
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