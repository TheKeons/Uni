#include <stdio.h>
#include <string.h>

void flipString(char *string){
    int length = strlen(string);
    int startIndex = 0;
    int endIndex = length - 1;
    char temp;

    while (startIndex < endIndex){
        temp = string[startIndex];
        string[startIndex] = string[endIndex];
        string[endIndex] = temp;

        startIndex++;
        endIndex--;
    }
}

int main () {
    char string[20] = "tseb e navyeK";
    flipString(string);
    printf("%s\n", string);

    return 0;
}