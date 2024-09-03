#include <stdio.h>

int main(){
    float kilo;
    int meny;
    float new_value;
    char * måleenhet;
    int loop ;
    int i;

    while (1){
        printf("Lets convert some numbers!\nHvor mange kilo vil du konvertere?\n");
        scanf("%f", &kilo);

        printf("Hva ønsker du å konverterer til? 1 for Center, 2 for Newton og 3 for Karat\n");
        scanf("%d", &meny);

        if (meny <= 3 && meny >= 1){
            if (meny == 1){
                new_value = kilo * 0.01;
                måleenhet = "Center";

            }
            else if (meny == 2){
                new_value = kilo * 9.81;
                måleenhet = "Newton";
            }

            else if (meny == 3){
                new_value == kilo * 5000;
                måleenhet = "Karat";
            }

            printf("%.1f kilo tilsvarer %f %s\n", kilo, new_value, måleenhet);
            printf("Ønsker du å kjøre en gang til? 1 for ja alle andre tegn for nei\n");
            scanf("%d", &loop);

            if (loop != 1){
                break;
            }
        }
        else {
            printf("Velg tall fra 1 til 3\n");
        }

    }
}