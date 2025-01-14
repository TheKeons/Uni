
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "printing.h"
#include "timer.h"

#define MAX_INT 200


int cmp_ints(void *arr, int a, int b)
{
    return ((int *)arr)[a] - ((int *)arr)[b];
}


int swap_ints(void *arr, int a, int b)
{
    int *_arr = (int *)arr;

    int tmp = _arr[a];
    _arr[a] = _arr[b];
    _arr[b] = tmp;

    return 0;
}


int *generate_data(int n, int order)
{
    int *data = calloc(n, sizeof(int));
    if (data == NULL)
    {
        ERROR_PRINT("Could not allocate data array\n");
        return NULL;
    }

    if (order == 0)
    {
        srand(gettime());
        for (int i = 0; i < n; i++)
        {
            data[i] = rand() % MAX_INT;
        }
    }
    else if (order == -1)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = n - i;
        }
    }
    else if (order == 1)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = i;
        }
    }
    else
    {
        ERROR_PRINT("Could not understand order %d\n", order);
        return NULL;
    }
    return data;
}