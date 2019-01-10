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

double sequence_access(double size){
    int array[(int)size];
    int result;
    int i;
    double t1 = tvgetf();
    for(i=0; i<size; i++){
        result += array[i];
    }
    double t2 = tvgetf();
    return t2 - t1;
}

double random_access(double size){
    int array[(int)size];
    int access_list[(int)size];
    int result;
    int i;
    for(i=0; i<(int)size; i++){
        access_list[i] = rand() % (int)size;
    }
    double t1 = tvgetf();
    for(i=0; i<(int)size; i++){
        result += array[access_list[i]];
    }
    double t2 = tvgetf();
    return t2 - t1;
}