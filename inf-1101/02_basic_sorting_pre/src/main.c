#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "timer.h"
#include "common.h"
#include "printing.h"

void test_sort(int n, int order)
{
    int *data = generate_data(n, order);
    INFO_PRINT("Sorting %d ints with order %d\n", n, order);

    unsigned long long t = gettime();

    sort(data, 0, n-1, cmp_ints, swap_ints);

    unsigned long long diff = gettime() - t;

    fprintf(stdout, "%d %llu\n", n, diff);
    free(data);
}

int main(int argc, char **argv)
{   
    int n = 2048;
    int order = 0;

    if (argc == 3){
        n = atoi(argv[1]);
        order = atoi(argv[2]);
    }
    for (int i = 0; i < 7; i++){
        test_sort(n, order);
        n *= 1.5;
    }
}
