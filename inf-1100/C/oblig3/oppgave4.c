#include <stdio.h>

float gjennomsnitt(int heltall[], int length){
    int highIndex;
    int lowIndex;
    int i;
    float gjennomsnitt;

    lowIndex = 1;
    highIndex = 1;
    for (i = 0; i < length; i++){
        if (heltall[i] < heltall[lowIndex]){
            lowIndex = i;
        }
        if (heltall[i] > heltall[highIndex]){
            highIndex = i;
        }
    }
    heltall[lowIndex] = 0; //null gir ikke utslag på gjennomsnittet
    heltall[highIndex] = 0; // og derfor slipper jeg å fjerne de fra arrayen

    for (i = 0; i < length; i++){
        
        gjennomsnitt = gjennomsnitt + heltall[i];
    }

    gjennomsnitt = gjennomsnitt/(length - 2); // minus to fordi jeg vil ikke vil at største og minte element skal gi utslag på gjennomsnittet

    return gjennomsnitt;
}

int main() {
    int heltall[] = {3, 5, 2, 8, 1};
    int length = sizeof(heltall)/sizeof(heltall[0]);
    printf("%f\n", gjennomsnitt(heltall, length));
    return 0;
}