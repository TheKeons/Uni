#include <stdio.h>

int main(){
    char bokstav;

    printf("Skriv en bokstav: ");
    scanf("%c", &bokstav);

    if (bokstav >= 65 && bokstav <= 90){
        bokstav = bokstav + 32;
        printf("%c\n", bokstav);
    }

    else if (bokstav >= 97 && bokstav <= 122){
        bokstav = bokstav - 32;
        printf("%c\n", bokstav);
    }

    else {
        printf("%c er enten ikke en bokstav eller finnes ikke i ASCII\n", bokstav);
    }
}