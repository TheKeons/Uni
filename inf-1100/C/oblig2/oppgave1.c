#include <stdio.h>

void triangle(char tegn, int antall_linjer);

int main(){
    triangle('*', 10);
}

void triangle(char tegn, int antall_linjer){
    int i;
    int j;

    for (i = 0; i <= antall_linjer; i++){
        for (j = 0; j <= i; j++){
            printf("%c", tegn);
        }
        printf("\n");
    }
}