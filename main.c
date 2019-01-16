#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "access.h"

#define MAX 31

int compare(const void *arg1, const void *arg2)
{
    if (*(double *) arg1 > *(double *) arg2)
        return 1;
    else if (*(double *) arg1 < *(double *) arg2)
        return -1;
    else
        return 0;
}

double avg_result(double (*func)(unsigned int), unsigned int size)
{
    double result[20];
    int i;
    for (i = 0; i < 20; i++) {
        result[i] = func(size);
    }
    qsort(result, 20, sizeof(double), compare);
    double avg = 0;
    for (i = 5; i < 15; i++) {
        avg += result[i];
    }
    return avg / 10;
}

int main()
{
    double result[MAX][2];
    unsigned int size = 0;
    cpu_init();
    for (int i = 0; i < MAX; i++) {
        size = (unsigned int) pow(2, i);
        result[i][0] = avg_result(sequence_access, size);
        result[i][1] = avg_result(random_access, size);
    }

    FILE *f_seq, *f_ram;
    f_seq = fopen("result_seq.txt", "w");
    f_ram = fopen("result_ram.txt", "w");

    for (int i = 0; i < MAX; i++) {
        fprintf(f_seq, "%u %lf\n", (unsigned int) pow(2, i), result[i][0]);
        fprintf(f_ram, "%u %lf\n", (unsigned int) pow(2, i), result[i][1]);
    }

    fclose(f_seq);
    fclose(f_ram);
    return 0;
}
