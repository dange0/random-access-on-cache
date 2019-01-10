#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "access.h"

#define MAX 20


int main(){
    double result[MAX][2];
    int size = 0;
    for(int i = 0; i < MAX; i++){
        size = (int)pow(2,i);
        result[i][0] = sequence_access(size);
        result[i][1] = random_access(size);
    }
    
    int f_seq, f_ram;
    f_seq = fopen("result_seq.txt","w");
    f_ram = fopen("result_ram.txt","w");
    
    for(int i = 0; i < MAX; i++){
        fprintf(f_seq, "2^%d %lf\n", i, result[i][0]);
        fprintf(f_ram, "2^%d %lf\n", i, result[i][1]);
    }
    
    fclose(f_seq);
    fclose(f_ram);
    return 0;
}
