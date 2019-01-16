#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cpu.h"

enum error_type { TOO_FEW_ARGS, WRONG_ARGS, READ_ERROR };

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
    help_message();
exit_program:
    exit(1);
}

void help_message()
{
    printf("Usage ./test_poly [Options] [argument]\n");
    printf("Available options: \n");
    printf(
        "\tdefault: run every instances of unrolling number and split "
        "number\n");
    printf("\t         and show the best CPE found on the system\n");
    printf("\t         also look for the processor model name and max freq\n");
    printf("\tplot: plot comparison graph for every argument listed\n");
    printf("\t      issue- shall we set maximum argument number?\n");
    printf("\tcompare: evaluate CPE for different argument,\n");
    printf("\t            and look for the best one\n");
    printf("\thelp: show this help message again\n\n");
    printf("\tSAMPLE: ./test_poly compare 1,1 2,2 3,3\n");
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