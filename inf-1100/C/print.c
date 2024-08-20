#include <stdio.h>

int main(){
    int num;

    printf("giv number\n");
    scanf("%d", &num);

    printf( "%d i hexadesimal er : %x\n", num, num);
    printf( "%d i ASCII er : %c\n", num), num;

    return 0;
}
