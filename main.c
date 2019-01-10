#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "access.h"

#define MAX 40


int main(){
    double result[MAX][2];
    double size = 0;
    for(int i = 0; i < MAX; i++){
        size = pow(2,i);
        result[i][0] = sequence_access(size);
        result[i][1] = random_access(size);
    }
    
    int f_seq, f_ram;
    f_seq = fopen("result_seq.txt","w");
    f_ram = fopen("result_ram.txt","w");
    
    for(int i = 0; i < MAX; i++){
        fprintf(f_seq, "%lf %lf\n", pow(2,i), result[i][0]);
        fprintf(f_ram, "%lf %lf\n", pow(2,i), result[i][1]);
    }
    
    fclose(f_seq);
    fclose(f_ram);
    return 0;
}
