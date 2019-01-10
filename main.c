#include <stdio.h>
#include <stdlib.h>
#include "access.h"
#define MAX 100


int main(){
    
    for(int i; i<MAX; i++){
        sequence_access(i);
        random_access(i);
        
    }
    
}