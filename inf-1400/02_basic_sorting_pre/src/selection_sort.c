#include "sort.h"

int sort(void *d, int left, int right, cmpfunc_t cmp, exchfunc_t swap){
    for (int i = left; i < right; i++){
        int min_i = i;

        for (int k = i +1; k <= right; k++){
            if (cmp(d, k, min_i) < 0){
                min_i = k;
            }
        }
        if (min_i != i){
            swap(d, i, min_i);
        }
    }
    return 0;
}