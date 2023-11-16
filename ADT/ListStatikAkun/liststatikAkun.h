/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIKAKUN_H
#define LISTSTATIKAKUN_H

#include "../Boolean/boolean.h"
#include "../Akun/akun.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct {
   Akun contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   int Neff;
} ListStatikAkun;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define CONTENT(l, i) (l).contents[(i)]
#define NEFF(l) (l).Neff

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void listStatikAkun_Create(ListStatikAkun *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listStatikAkun_Length(ListStatikAkun l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
int listStatikAkun_getFirstIdx(ListStatikAkun l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int listStatikAkun_getLastIdx(ListStatikAkun l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean listStatikAkun_isIdxValid(ListStatikAkun l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean listStatikAkun_isIdxEff(ListStatikAkun l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean listStatikAkun_isEmpty(ListStatikAkun l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean listStatikAkun_isFull(ListStatikAkun l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

void listStatikAkun_print(ListStatikAkun l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void listStatikAkun_insertFirst(ListStatikAkun *l, Akun val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void listStatikAkun_insertAt(ListStatikAkun *l, Akun val, int idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void listStatikAkun_insertLast(ListStatikAkun *l, Akun val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void listStatikAkun_deleteFirst(ListStatikAkun *l, Akun *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void listStatikAkun_deleteAt(ListStatikAkun *l, Akun *val, int idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void listStatikAkun_deleteLast(ListStatikAkun *l, Akun *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
// return id akun. kalau ga ada, return IDX_UNDEF
int findIdxById(ListStatikAkun l, int id);

int findIdxByName(ListStatikAkun l, Word name);

int findIdxByPassword(ListStatikAkun l, Word password);

#endif