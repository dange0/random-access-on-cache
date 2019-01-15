#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "access.h"

#define MAX 30


int main(){
    double result[MAX][2];
    unsigned int size = 0;
    for(int i = 0; i < MAX; i++){
        size = (unsigned int)pow(2,i);
        result[i][0] = get_seq_result(size);
        result[i][1] = get_rand_result(size);
    }
    
    FILE *f_seq, *f_ram;
    f_seq = fopen("result_seq.txt","w");
    f_ram = fopen("result_ram.txt","w");
    
    for(int i = 0; i < MAX; i++){
        fprintf(f_seq, "%d %lf\n", i, result[i][0]);
        fprintf(f_ram, "%d %lf\n", i, result[i][1]);
    }
    
    fclose(f_seq);
    fclose(f_ram);
    return 0;
}
