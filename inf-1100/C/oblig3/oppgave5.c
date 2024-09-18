#include <stdio.h>
#include <string.h>


int main () {
    char *tekst = "Hvor skal det pekes?";
    printf("%s\nFørste: %c\nSiste: %c\n", tekst, tekst[0], tekst[strlen(tekst)-1]);

    return 0;
}