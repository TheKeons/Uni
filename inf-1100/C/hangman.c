#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* randomWord();

int main() {

    printf("%s\n", randomWord());

}

char* randomWord() {
    char wordList[9][10] = {"apple", "banana", "grape","orange", "lemon","kiwi", "pineapple", "strawberry", "blueberry"};

    srand(time(NULL));

    int length = sizeof(wordList)/sizeof(wordList[0]);
    int random =  rand() % length + 1;
    char* word = wordList[random];

    int i;

    for (i=0; i<=length; i++){
        printf("%s\n", wordList[i]);
    }

    //printf("%s\n", word);

    return word;
}