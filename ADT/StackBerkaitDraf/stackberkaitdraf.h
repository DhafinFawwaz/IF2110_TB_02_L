#ifndef STACKBerkaitDraf_H
#define STACKBerkaitDraf_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../StackDin/stackdin.h"


#define NIL NULL

typedef struct DrafKicauan
{
    int id;
    Word text;
    Word nama;
    DateTime dateTime;
} DrafKicauan;

void CreateDraftKicauan(DrafKicauan *drafkicauan);

typedef struct nodedraf* AddressDraf;
typedef struct nodedraf {
    DrafKicauan drafkicauan;
    AddressDraf next;
} NodeDraf;

#define     NEXT_DRAF(p) (p)->next
#define     INFO_DRAF(p) (p)->drafkicauan

typedef struct stackBerkaitDraf {
    AddressDraf addrTopDraf;
} StackBerkaitDraf;

/* Selektor */
#define ADDR_TOP_DRAF(s) (s).addrTopDraf
#define      TOP_DRAF(s) (s).addrTopDraf->drafkicauan 


// Membuat node baru untuk DrafKicauan dan mengembalikan alamatnya
AddressDraf newNodeStackBerkaitDraf(DrafKicauan x);

// Memeriksa apakah StackBerkaitDraf kosong atau tidak
boolean isEmptyStackBerkaitDraf(StackBerkaitDraf s);

// Mengembalikan panjang StackBerkaitDraf (jumlah elemen dalam stack)
int lengthStackBerkaitDraf(StackBerkaitDraf s);

// Membuat StackBerkaitDraf baru dan menginisialisasi nilainya
void createStackBerkaitDraf(StackBerkaitDraf *s);

// Menampilkan isi StackBerkaitDraf ke layar
void displayStackBerkaitDraf(StackBerkaitDraf *s);

// Menambahkan DrafKicauan ke dalam StackBerkaitDraf
void pushStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan x);

// Menghapus elemen paling atas dari StackBerkaitDraf dan mengembalikan nilainya melalui parameter x
void popStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan *x);

void DebugListDraftKicauan();

#endif