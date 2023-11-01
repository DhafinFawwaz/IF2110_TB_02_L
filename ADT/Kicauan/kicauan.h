#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "../Boolean/boolean.h"
#include "../Akun/akun.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"

typedef struct kicauan
{
    int id;
    Word text;
    int likeCount;
    Word namaPembuat;
    DateTime dateTime;
    // Word tagar;
    // boolean isUtas;
} Kicauan;

extern int banyakKicauan;
extern Kicauan currentKicauan;
extern Kicauan listKicauan[100];

#define IDKICAU(k) (k).id
#define TEXT_KICAU(k) (k).text
#define JUMLAH_LIKE(k) (k).likeCount
#define PEMBUAT(k) (k).namaPembuat
#define WAKTU(k) (k).dateTime
#define TAGAR(k) (k).tagar
#define isUTAS(k) (k).isUtas

void createKicauan();

void printKicauan(Kicauan kicauan);
void printKicauan(Kicauan kicauan);

void KICAU(Word currPengguna);
void KICAU(Word currPengguna);

// void KICAUAN(ListDinKicauan l_kicauan, Word currPengguna);
// void KICAUAN(ListDinKicauan l_kicauan, Word currPengguna);

// boolean isAkunPublicByPengguna(Word pengguna);
// boolean isBerteman(ListDinKicauan l, int id);

// void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan);
// void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan);
// boolean isSama(Word w1, Word w2);

// void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan);
// void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan);


void DebugListKicauan();
void displayKicauan(Kicauan kicauan);

#endif