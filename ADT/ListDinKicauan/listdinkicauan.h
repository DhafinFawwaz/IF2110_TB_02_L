#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
#include "../Boolean/boolean.h"
#include "../Akun/akun.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../Akun/akun.h"
#include "../listKaitUtas/listkaitUtas.h"
#include "../TreeBalasan/treebalasan.h"
// Struktur Kicauan
typedef struct kicauan
{
    int likeCount;
    int id;
    Word text;
    Akun * akunKicauan;
    DateTime dateTime;
    Utas firstUtas;
    TreeBalasanAddress firstBalasan;
    Word tagar;
} Kicauan;

#define IDKICAU(k) (k).id
#define TEXT_KICAU(k) (k).text
#define JUMLAH_LIKE(k) (k).likeCount
#define ADDR_AKUN_KICAUAN(k) (k).akunKicauan
#define WAKTU(k) (k).dateTime
#define TAGAR(k) (k).tagar
// End of Struktur Kicauan

// Struktur List Dinamis Kicauan

typedef struct listdinkicauan
{
    Kicauan* contents;
    int nEff;
    int cap;
} ListDinKicauan;

#define GET_ELMT_KICAUAN(l,idx) (l).contents[idx]
#define CONTENTS_LIST_KICAUAN(l) (l).contents
#define NEFF_LIST_KICAUAN(l) (l).nEff
#define CAP_LIST_KICAUAN(l) (l).cap
// End of Struktur List Dinamis Kicauan

// Fungsi dan Prosedur Kicauan
void createKicauan(Kicauan * k, Word text, Word tagar);

void printKicauan(Kicauan kicauan);
// End of Fungsi dan Prosedur Kicauan

// Fungsi dan Prosedur List Dinamis Kicauan
void createListDinKicauan(ListDinKicauan *l, int cap);

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2);

void expandListKicauan(ListDinKicauan *l);

boolean isFullListKicauan(ListDinKicauan l);

void insertKicauan(Kicauan k, ListDinKicauan * listKicauan);

boolean isListKicauanEmpty(ListDinKicauan listKicauan);

boolean isInListKicauan(int idKicau, ListDinKicauan listKicauan);
// End of Fungsi dan Prosedur List Dinamis Kicauan


// void DebugListKicauan();

Kicauan getKicauanById(ListDinKicauan listKicauan, int id);

#endif