/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../Boolean/boolean.h"
#include "charmachine.h"
#include <string.h>

#define NMax 300
#define BLANK ' '
#define NEWLINE '\n'
#define CARRIAGE '\r'

typedef struct word
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

// Mulai baca file
void STARTWORDFILEREADER(char path[]);

// Mulai tulis ke file
void STARTWORDFILEWRITER(char path[]);

// Tulis Word ke file
void WRITEWORD(Word w);

// Tulis int ke file
void WRITEINT(int i);

// Maju 1 baris
void ADVLINE();
void CopyLine();
Word cleanWord(Word w);
Word intToWord(int N);
int wordToInt(Word w);
void setWord(Word* w, char s[]);
boolean compareWord(Word w1, Word w2);
void capCurrentWord(int cap);
void printWord(Word w);
Word stringToWord(const char* str);
char* wordToString(Word w);
char wordToChar(Word w);
Word getWordAfterFirstSpace(Word inputWord);

#endif