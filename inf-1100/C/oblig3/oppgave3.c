#include <stdio.h>
#include <string.h>

void flipString(char *string){
    int length = strlen(string);
    int startIndex = 0; 
    int endIndex = length - 1;
    char temp;

    while (startIndex < endIndex){
        temp = string[startIndex]; //Bytter bokstavene ved bruk av temp variabel
        string[startIndex] = string[endIndex];
        string[endIndex] = temp;

        startIndex++; // Flytter startindexen opp og endindexen ned slik at jeg kan bytte de riktige variablene
        endIndex--;
    }
}

int main () {
    char string[20] = "tseb e navyeK";
    flipString(string);
    printf("%s\n", string);

    return 0;
}