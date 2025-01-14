#ifndef SORT_H
#define SORT_H

#include "common.h"

/*
* common sort interface
* left starting index
* right end index
* swap swaps
*/

int sort(void *d, int left, int right, cmpfunc_t cmp, exchfunc_t swap);


#endif
