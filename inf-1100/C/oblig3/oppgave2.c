#include <stdio.h>
#include <stdbool.h>

bool eksamenCheck(bool *student){
    int counter;
    int i;

    if (student[2] == true || student[5] == true){ // Hvis oblig 3 eller oblig 6 er godkjent
        for (i = 0; i < 6; i++){ // teller godkjente obliger
            if (student[i] == true){
                counter++;
            }
        }

        if (counter >= 4){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main () {
    // Her velger jeg å representere hvilken obligere som er bestått/ikke bestått som en array sotert fra oblig 1 til oblig 6
    // dette gjør at det er lett å finne hviken booleen som tilhører hvilken oblig
    bool student[6] = {true, true, false, true, true, false};
    
    if (eksamenCheck(student)){
        printf("Studenten kan gå opp til eksamen\n");
    } else {
        printf("Studenten kan ikke gå opp til eksamen\n");
    }

    return 0;
}