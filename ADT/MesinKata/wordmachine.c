/* File: wordmachine.c */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

/* State Mesin Word */
Word currentWord;
boolean EndWord;

void IgnorePossibleNewLine(){
    if(currentChar == CARRIAGE){
        // printf("|r|");
        ADV();
    }
    if(currentChar == NEWLINE){
        // printf("|n|");
        ADV();
    }
}

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK) {
        ADV();
    }
    IgnorePossibleNewLine();
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
        IgnorePossibleNewLine();
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
    if(currentChar == MARK){
        EndWord = true;
    } else {
        CopyWord();
        if(currentChar == MARK){
            EndWord = true;
        } else if(currentChar == NEWLINE || currentChar == CARRIAGE) {
            IgnorePossibleNewLine();
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
    if(currentChar == MARK){
        EndWord = true;
    } else {
        CopyLine();
        if(currentChar == MARK){
            EndWord = true;
        } else if(currentChar == NEWLINE || currentChar == CARRIAGE) {
            IgnorePossibleNewLine();
        }
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

// Mengembalikan currentWord yang memastikan setelah currentWord.Length itu empty string semua
Word cleanWord(Word w){
    int i = 0;
    for(i = w.Length; i < NMax; i++){
        w.TabWord[i] = '\0';
    }
    return w;
}

// convert word ke integer, termasuk jika negatif
int wordToInt(Word w){
    if(w.TabWord[0] == '-'){
        int i = 1, result = 0;
        for(i = 1; i < w.Length; i++){
            result = result * 10 + (w.TabWord[i] - '0');
        }
        return -result;
    }
    int i = 0, result = 0;
    for(i = 0; i < w.Length; i++){
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result;
}

// Set stringnya word menjadi s
void setWord(Word* w, char s[]){
    int i = 0;
    while(s[i] != '\0'){
        (*w).TabWord[i] = s[i];
        i++;
    }
    (*w).Length = i;
}

// Cek apakah stringnya w1 sama dengan w2
boolean compareWord(Word w1, Word w2){
    if(w1.Length != w2.Length) return false;
    else{
        int i = 0;
        while(i < w1.Length){
            if(w1.TabWord[i] != w2.TabWord[i]) return false;
            i++;
        }
        return true;
    }
}

// Untuk mengslice current word dari 0 sampai cap. Dipakai misalnya bio max 135 huruf, password max 20 huruf
void capCurrentWord(int cap){
    int i = cap;
    for(i = cap; i < currentWord.Length; i++){
        currentWord.TabWord[i] = '\0';
    }
    currentWord.Length = cap;
}

void printWord(Word w){
    for (int i = 0; i < w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
}
