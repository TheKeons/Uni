#include <stdio.h>

void byttTall(int *a, int *b){
    int placeholderA = *a;
    *a = *b;
    *b = placeholderA;
}

int main () {
    int a = 5;
    int b = 2;
    printf("Tallene før bytte a = %d og b = %d\n", a, b);
    byttTall(&a, &b); //insted of sending the values it sends the adress and therefore it changes a and b instead of changing the local variables
    printf("Tallene etter bytte a = %d og b = %d\n", a, b);

    return 0;
}