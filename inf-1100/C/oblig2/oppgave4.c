#include <stdio.h>
#include <math.h>
#define SQUARE(x) ((x)*(x))

double avstand(int x1, int y1, int x2, int y2);

int main(){
    printf("%f\n", avstand(2, 5, 6, 8));
}

double avstand(int x1, int y1, int x2, int y2){

    double number = sqrt(SQUARE(x1-x2) + SQUARE(y1-y2));
    return number;
}