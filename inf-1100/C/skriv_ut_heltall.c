#include <stdio.h>
#define STOPP 0

int main(){

    int teller;
    int start;

    printf("Skriv inn et heltall: ");
    scanf("%d", &start); // scanf henter input fra terminal. OBS! printer ikke ut

    for (teller = start; teller >= STOPP; teller--) // setter først teller lik start variabelen, sjekker da om teller er mindre enn
                                                    // stopp (her 0). til slutt teller - 1
        printf("%d\n", teller);
    
    return 0;
}