#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cpu.h"

enum error_type { TOO_FEW_ARGS, WRONG_ARGS, READ_ERROR };

long cpu_hz;

void runtime_error_message(int type)
{
    switch (type) {
    case WRONG_ARGS:
        printf("Wrong arguments, please check the following help\n");
        break;
    case TOO_FEW_ARGS:
        printf("Too few arguments, please check the following help\n");
        break;
    case READ_ERROR:
        printf("Check file IO and fgets...\n");
        goto exit_program;
    default:
        printf("Unknown error\n");
    }
exit_program:
    exit(1);
}


long read_cpu_freq()
{
    FILE *cpu_file =
        fopen("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq", "r");
    if (!cpu_file) {  // error cant read cpuinfo
        runtime_error_message(READ_ERROR);
        return -1;
    }

    char info_line[20] = {0};
    if (fgets(info_line, 20, cpu_file) == NULL) {
        runtime_error_message(READ_ERROR);
        fclose(cpu_file);
        return -1;
    }
    fclose(cpu_file);
    return atol(info_line) * 1000;
}


void cpu_init()
{
    cpu_hz = read_cpu_freq();
}

double tvgetf()
{
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;
    sec /= 1e9;
    sec += ts.tv_sec;
    return sec * cpu_hz;
}