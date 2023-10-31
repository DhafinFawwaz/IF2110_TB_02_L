#include "perintah.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include <stdio.h>

void readInput() {
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
