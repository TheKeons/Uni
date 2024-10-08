#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAKS 30

typedef struct person {
    char *navn;
    int alder;
}person_t;

typedef struct medlemmer {
    person_t personer[MAKS];
    int antall;
}medlemmer_t;

void write_files(medlemmer_t *medlemer, FILE *txt, FILE *bin){

    txt = fopen("medlemer.txt", "w");
    bin = fopen("medlemer.bin", "wb");



    for (int i = 0; i < medlemer->antall; i++){
        fprintf(txt, "%s %d\n", medlemer->personer[i].navn, medlemer->personer[i].alder);
        
    }
    fwrite(medlemer, sizeof(medlemmer_t), 1, bin);

    fclose(bin);
    fclose(txt);
}

void read_files(medlemmer_t *medlemer, FILE *txt, FILE *bin){
    // Reads and prints the contents of the txt file
    txt = fopen("medlemer.txt", "r");
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), txt)) {
        printf("%s", buffer);
    }
    fclose(txt);

    // Gets the stucture written in the bin file and prints out the array
    bin = fopen("medlemer.bin", "rb");
    medlemmer_t buffer_bin;
    fread(&buffer_bin, sizeof(medlemmer_t), 1, bin);
    fclose(bin);

    printf("\nBinary File; \n");
    for (int i = 0; i < buffer_bin.antall; i++){
        printf("%s %d\n", buffer_bin.personer[i].navn, buffer_bin.personer[i].alder);
    }
}

void make_people(medlemmer_t *medlemer, int nr){
    char* names[30] = {
        "Aaron","Ben","Charles","Daniel","Ethan","Felix",
        "Gabriel","Henry","Isaac","Jack","Kevin","Liam","Michael","Nathan",
        "Oliver","Peter","Quentin","Ryan","Samuel","Thomas","Ulysses","Victor",
        "William","Xavier","Yusuf","Zachary","Adam","Brandon","David","Jason"
    };

    person_t *person = (person_t*)malloc(sizeof(person_t));
    medlemer->antall = 0;
    for (int i = 0; i < nr; i++){
        
        person->navn = names[rand() % 30];
        person->alder = rand() % 100;

        medlemer->personer[i] = *person;
        medlemer->antall = medlemer->antall + 1;
    }
}

int main() {
    srand(time(NULL));
    int random_nr_guys = random() % MAKS;

    if (random_nr_guys == 0){
        random_nr_guys = random_nr_guys + 1;
    }

    medlemmer_t medlemsliste;
    FILE *txt;
    FILE *bin;
    

    make_people(&medlemsliste, random_nr_guys);
    write_files(&medlemsliste, txt, bin);
    read_files(&medlemsliste, txt, bin);

    return 0;
}

