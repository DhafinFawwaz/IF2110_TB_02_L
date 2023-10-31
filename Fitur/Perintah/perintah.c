#include "perintah.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include <stdio.h>

void readWord() {
    int temp;
    scanf("%d", &temp);
    int i;
    START();
    IgnoreBlanks();

    currentWord.Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    currentWord.Length = i;

    currentWord.TabWord[i] = '\0';
}


// I.S currentWord sembarang
// F.S currentWord berisi kata yang dibaca dari input
void readLine(){
    START();
    ADVLINE();
}