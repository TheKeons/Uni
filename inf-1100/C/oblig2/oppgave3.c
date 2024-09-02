#include <stdio.h>

void sjekk_tall(int start, int slutt, int faktor);

int main(){
    sjekk_tall(1, 10, 5);
}

void sjekk_tall(int start, int slutt, int faktor){
    int i;
    


    for (i = start; i <= slutt; i++){
        if (i % 2 > 0){
            if (i % faktor == 0){
                printf("%d er ikke partall og %d er en faktor\n", i, faktor);
            }
            else if (i % faktor > 0){
                printf("%d er ikke partall og %d er ikke en faktor\n", i, faktor);
            }
            
        }
        else if (i % 2 == 0){
            if (i % faktor == 0){
                printf("%d er et partall og %d er en faktor\n", i, faktor);
            }
            else if (i % faktor > 0){
                printf("%d er et partall og %d er ikke en faktor\n", i, faktor);
            }
       }
    }
}
