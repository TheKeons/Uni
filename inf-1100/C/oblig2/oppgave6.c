#include <stdio.h>
#include <string.h>

int tversumm(char tall[], int len);

int main(){
    // siden strings er arrays av char velger jeg å skrive tallet som string sånn at jeg kan splitte detloope gjennom 
    char tall[] = "57396"; 
    int len = strlen(tall);
    printf("Tversummen av %s er %d\n", tall, tversumm(tall, len));

}

int tversumm(char tall[], int len){
    int i;
    int tverrsummen = 0;
    char ny_tall[10];
    int ny_len;
    for (i = 0; i < len; i++){
        tverrsummen = tverrsummen + (tall[i] - '0'); // gjør hver char om til int og legger de sammen
    }
    sprintf(ny_tall, "%d", tverrsummen); // omgjør tversummen til string
    ny_len = strlen(ny_tall);

    // hvis tallet er større en 10 så kan jeg enda finne en tversum
    // derfor kan jeg kaller jeg funksjonen på nytt
    if (ny_len > 1){
        tversumm(ny_tall, ny_len);
    } 
    else {
        return tverrsummen;
    }
}