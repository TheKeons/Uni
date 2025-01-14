#include "sort.h"

int sort(void *d, int left, int right, cmpfunc_t cmp, exchfunc_t swap)
{
    for (int i = 1; i <= right; i++)
    {
        for (int k = i; k > left; k--)
        {
            if (cmp(d, k, k-1) < 0)
            {
                swap(d, k, k-1);
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
