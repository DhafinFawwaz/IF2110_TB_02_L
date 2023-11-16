#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "../Boolean/boolean.h"
#include "../Akun/akun.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"

// Struktur Kicauan
typedef struct kicauan
{
    int id;
    Word text;
    int likeCount;
    Akun *akunKicauan;
    DateTime dateTime;
    Word tagar;
    boolean isUtas;
    TreeBalasanAddress balasan;
} Kicauan;

extern int banyakKicauan;
extern Kicauan currentKicauan;

#define IDKICAU(k) (k).id
#define TEXT_KICAU(k) (k).text
#define JUMLAH_LIKE(k) (k).likeCount
#define ADDR_AKUN_KICAUAN(k) (k).akunKicauan
#define WAKTU(k) (k).dateTime
#define TAGAR(k) (k).tagar
#define isUTAS(k) (k).isUtas
// End of Struktur Kicauan

// Struktur List Dinamis Kicauan
typedef Kicauan* AddressKicauan;

typedef struct listdinkicauan
{
    AddressKicauan* contents;
    int nEff;
    int cap;
} ListDinKicauan;

#define ADDR_KICAUAN(l,idx) (l).contents[idx]
#define CONTENTS_LIST_KICAUAN(l) (l).contents
#define NEFF_LIST_KICAUAN(l) (l).nEff
#define CAP_LIST_KICAUAN(l) (l).cap
// End of Struktur List Dinamis Kicauan

// Global Variable
extern ListDinKicauan listKicauan;
// End of Global Variable

// Fungsi dan Prosedur Kicauan
void createKicauan(Kicauan * k, Word text, Word tagar);

void printKicauan(Kicauan kicauan);

void kicau();

void KICAUAN();

void SUKA_KICAUAN(int id_kicau);

void UBAH_KICAUAN(int id_kicau);
// End of Fungsi dan Prosedur Kicauan

// Fungsi dan Prosedur List Dinamis Kicauan
void createListDinKicauan(ListDinKicauan *l, int cap);

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2);

void expandListKicauan(ListDinKicauan *l);

boolean isFullListKicauan(ListDinKicauan l);

void insertKicauan(Kicauan *k);

boolean isListKicauanEmpty();

boolean isInListKicauan(int idKicau);
// End of Fungsi dan Prosedur List Dinamis Kicauan


void DebugListKicauan();
void displayKicauan(Kicauan kicauan);

#endif