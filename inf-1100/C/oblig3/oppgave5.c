#include <stdio.h>
#include <string.h>


int main () {
    char *tekst = "Hvor skal det pekes?";
    printf("%s\nFørste: %c\nSiste: %c\n", tekst, tekst[0], tekst[strlen(tekst)-1]);

    return 0;
}

/*  Den orginale koden har mye unødvendig. For det første er det ingen grunn til å bruke dobbel pointer når man kun skal printe ut ting.
    I dette tilfellet er det heller ingen vits å definere pointeren som en egen variabel, jeg valgte heller å definere stringen som en ponter,
    slik som i linje 6, fordi jeg ikke ska endre stringen.
    Det er heller ingen grunn til å prøve å endre på pekeren slik i det orginale programet når man kan finne det man leter ette ved bruk av indexer.
    Når man skal finne det siste elementet av arrayen er det også viktig å ta lengden - 1 fordi indexer starter på 0.
    Jeg valgte også å skrive lengden og print funksjonene på en linje bare fordi.
*/