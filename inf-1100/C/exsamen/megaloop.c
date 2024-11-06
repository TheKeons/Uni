#include <stdio.h>
#include <time.h>

int main(){

    //clock_t begin = clock();

    for (int i = 0; i<=10000000; i++){
        printf("%d\n", i);
    }
    //clock_t end = clock();
    //double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    //printf("%f", time_spent);
}

