#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cpu.h"

void cpu_init();
double tvgetf();
double random_access(unsigned int size);
double sequence_access(unsigned int size);