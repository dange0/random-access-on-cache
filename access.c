#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include "fcyc.h"
#include "access.h"
#include "lran2.h"


double get_seq_result(unsigned int size){
    int index_list[size], i;
    for(i=0; i<size; i++){
        index_list[i] = i;
    }
    struct Para_struct seq_para;
    seq_para.size = size;
    seq_para.index = index_list;
    
    return fcyc(access,&seq_para);
}



double get_rand_result(unsigned int size){
    int index_list[size], i;
    for(i=0; i<size; i++){
        index_list[i] = rand() % size;
    }
    struct Para_struct rand_para;
    rand_para.size = size;
    rand_para.index = index_list;
    
    return fcyc(access,&rand_para);
}

void access(struct Para_struct para){
    int size = para.size;
    int *index = para.index;
    int result = 0;
    int array[size];
    for(int i=0; i<size; i++){
        result += array[index[i]];
    }
}