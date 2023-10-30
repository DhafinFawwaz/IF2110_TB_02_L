#include "perintah.h"

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}


// I.S currentWord sembarang
// F.S currentWord berisi kata yang dibaca dari input
void readLine(){
    START();
    ADVLINE();
}