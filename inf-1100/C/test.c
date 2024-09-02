#include <stdio.h>

int t;

int main(){
    
    //int t; // This variable is global
    {
        int t = 2;
        printf("%d\n", t); // A
        {
        printf("%d\n", t); // B
        t = 3;
        }
        printf("%d\n", t); // C
    }
    {
    printf("%d\n", t); // D
    }
}