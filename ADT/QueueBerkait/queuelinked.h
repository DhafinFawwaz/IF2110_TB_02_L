/* File: queuelinked.h */

#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include "../Boolean/boolean.h"
#include "../MesinKata/wordmachine.h"
#include <stdlib.h>

#define NIL NULL

/* Queue dengan representasi berkait dengan pointer */
typedef struct queuenode* queueAddress;
typedef struct queuenode { 
    char info;
    queueAddress next; 
} QueueNode; 
/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct {
    queueAddress addrHead; /* alamat penghapusan */
    queueAddress addrTail; /* alamat penambahan */
} QueueLinked;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define      HEAD(q) (q).addrHead->info

/* Prototype manajemen memori */
queueAddress queueLinked_newNode(char x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean queueLinked_isEmpty(QueueLinked q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int queueLinked_length(QueueLinked q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void queueLinked_CreateQueue(QueueLinked *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void queueLinked_DisplayQueue(QueueLinked q);
/* Proses : Menuliskan isi Queue */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: e1e2...en */

/*** Primitif Enqueue/Dequeue ***/
void queueLinked_enqueue(QueueLinked *q, char x);
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void queueLinked_dequeue(QueueLinked *q, char *x);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
/* *** Fungsi berkaitan dengan Mesin Kata *** */
/* Mengubah Queue berkait menjadi Word */
Word QueueLinkedToWord(QueueLinked q);
/* Mengubah Word menjadi Queue berkait */
void WordToQueueLinked(Word w, QueueLinked *q);

#endif