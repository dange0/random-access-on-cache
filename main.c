#include <stdio.h>
#include <stdlib.h>
#include "access.h"
#define MAX 10000


int main(){
    double result[MAX][2];
    for(int i = 0; i < MAX; i++){
        result[i][0] = sequence_access(i);
        result[i][1] = random_access(i);
    }
    
    int f_seq, f_ram;
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