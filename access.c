#include "access.h"
double tvgetf(){
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;

    return sec;
}

double sequence_access(int size){
    int array[size];
    int result;
    int i;
    double t1 = tvgetf();
    for(i=0; i<size; i++){
        result += array[i];
    }
    double t2 = tvgetf();
    return t2 - t1;
}

double random_access(int size){
    int array[size];
    int access_list[size];
    int result;
    int i;
    for(i=0; i<(int)size; i++){
        access_list[i] = rand() % size;
    }
    double t1 = tvgetf();
    for(i=0; i<size; i++){
        result += array[access_list[i]];
    }
    double t2 = tvgetf();
    return t2 - t1;
}