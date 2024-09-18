#include <stdio.h>
#include <string.h>


int main () {
    char *tekst = "Hvor skal det pekes?";
    printf("%s\n", tekst);
    printf("%c\n", tekst[0]);
    int lengde = strlen(tekst);  
    printf("%c\n", tekst[lengde-1]); 

    return 0;
}