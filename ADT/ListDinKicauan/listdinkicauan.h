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

// Membuat Kicauan dengan text kicauan
void createKicauan(Kicauan * k, Word text);

// Menampilkan informasi mengenai Kicauan
void printKicauan(Kicauan kicauan);

// End of Fungsi dan Prosedur Kicauan

// Fungsi dan Prosedur List Dinamis Kicauan

// Membuat List Dinamis Kicauan Kosong dengan kapasitas sebesar cap
void createListDinKicauan(ListDinKicauan *l, int cap);

// Menyalin isi List l1 pada l2
void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2);

// Memperbesar ukuran kapasitas list sebanyak 2x lipat kapasitas sebelumnya
void expandListKicauan(ListDinKicauan *l);

// Mengembalikan true jika List l penuh
boolean isFullListKicauan(ListDinKicauan l);

// Memasukkan Kicauan k pada indeks efektif terakhir List
void insertKicauan(Kicauan k, ListDinKicauan * listKicauan);

// Mengembalikan true jika List kosong
boolean isListKicauanEmpty(ListDinKicauan listKicauan);

// Mengembalikan true jika Kicauan dengan idKicau ada pada List
boolean isInListKicauan(int idKicau, ListDinKicauan listKicauan);

// Mengembalikan Kicauan dengan id yang diinginkan pada List
Kicauan getKicauanById(ListDinKicauan listKicauan, int id);

// End of Fungsi dan Prosedur List Dinamis Kicauan


#endif