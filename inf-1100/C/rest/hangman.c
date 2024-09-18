#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

const char* randomWord() {
    const char *wordList[] = {
        "elephant", "tiger", "giraffe", "penguin", "dolphin",  // Animals
        "pineapple", "strawberry", "blueberry", "watermelon", "mango",  // Fruits
        "notebook", "backpack", "keyboard", "telephone", "microscope",  // Objects
        "turquoise", "magenta", "scarlet", "indigo", "amber"  // Colors
    };
    int length = sizeof(wordList)/sizeof(wordList[0]);
    int random =  rand() % length;
    return wordList[random];
}

int main() {
    system("clear");
    srand(time(NULL));
    const char* word = randomWord();
    char placeholder[20];
    int length = strlen(word);
    int i;
    int j;
    char guess;
    int lives = 3;


    for (i = 0; i < length; i++){
        placeholder[i] = '#';
    }
    placeholder[length] = '\0';

    while (1){
        printf("%s\nMake a guess\n", placeholder);
        scanf(" %c", &guess);

        while (getchar() != '\n'); 

        if (!isalpha(guess)){
            printf("Invalid input try again\n");
            continue;
        }
        guess = tolower(guess);


        if (strchr(placeholder, '#') != NULL){
            if (strchr(word, guess) != NULL){
                for (j = 0; j < length; j++){
                    if (word[j] == guess){
                        placeholder[j] = guess;
                    }
                }
            } else {
                lives = lives - 1;
                if (lives > 0){
                    printf("Wrong guess. You have %d lives left\n", lives);
                    sleep(2);
                } else {
                    printf("You lost :(\nThe word was %s\n", word);
                    break;
                }
            }
            if (strchr(placeholder, '#') == NULL) {
                printf("Congrats you. Won the word was %s\n", word);
                break;
        }
        system("clear"); 
        }
    }
}

