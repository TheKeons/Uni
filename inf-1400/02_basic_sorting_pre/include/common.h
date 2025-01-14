#ifndef COMMON_H
#define COMMON_H


// These can be passed as function pointers to our sort function
typedef int (*cmpfunc_t)(void *, int, int);
typedef int (*exchfunc_t)(void *, int, int);

// Compare two values
// Return > 0 if a is larger
// Return 0   if ints are equal
// Return < 0 if a is smaller
int cmp_ints(void *d, int a, int b);


// Swap two ints in arr
int swap_ints(void *arr, int a, int b);

// Generate n ints with order
// 0  - Random order
// -1 - Descending order
// 1  - Ascending order
int *generate_data(int n, int order);

#endif