#include "sort.h"

int sort(void *d, int left, int right, cmpfunc_t cmp, exchfunc_t swap){
    int sorted = 0;
    while (!sorted){
        sorted = 1;
        for (int i = left; i < right; i++){
            if (cmp(d, i, i+1) > 0){
                swap(d, i, i+1);
                sorted = 0;
            }
        }
    }
    return 0;
}