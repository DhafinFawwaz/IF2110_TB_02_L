/* File: wordmachine.c */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK || currentChar == NEWLINE || currentChar == CARRIAGE) {
        ADV();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    currentWord.Length = 0;
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == NEWLINE || currentChar == CARRIAGE) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    if(currentChar == MARK || currentChar == NEWLINE || currentChar == CARRIAGE){
        EndWord = true;
    } else {
        CopyWord();
        if(currentChar == MARK || currentChar == NEWLINE || currentChar == CARRIAGE){
            EndWord = true;
        } else {
            IgnoreBlanks();
        }
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

{
    int i;
    i = 0;
    while((currentChar != MARK) && (currentChar != BLANK) && (currentChar != NEWLINE) && (currentChar != CARRIAGE)){
        // printf("%c", currentChar);
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax){
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

void ADVLINE()
{
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    } else {
        CopyLine();
        IgnoreBlanks();
    }
}
void CopyLine()
/* Mengakuisisi kalimat 1 barus, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK atau currentChar = NEWLINE atau currentChar = CARRIAGE;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

{
    int i;
    i = 0;
    while((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != CARRIAGE)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax){
        currentWord.Length = NMax;
    } else {
        currentWord.Length = i;
    }
}

Word cleanWord(Word w){
    int i = 0;
    for(i = w.Length; i < NMax; i++){
        w.TabWord[i] = '\0';
    }
    return w;
}

int wordToInt(Word w){
    int negativeMultiplier = 1;
    if(w.TabWord[0] == '-'){
        negativeMultiplier = -1;
    }
    int i = 0, result = 0;
    for(i = 0; i < w.Length; i++){
        result = result * 10 + (w.TabWord[i] - '0');
    }

    return result * negativeMultiplier;
}
