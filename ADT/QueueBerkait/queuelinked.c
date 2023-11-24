/* File: queuelinked.c */

#include <stdio.h>
#include "queuelinked.h"

/* Prototype manajemen memori */
queueAddress queueLinked_newNode(char x){
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
    queueAddress new = (queueAddress) malloc (sizeof(QueueNode));
    if (new != NIL){
        INFO(new) = x;
        NEXT(new) = NIL;
    }
    return new;
}

boolean queueLinked_isEmpty(QueueLinked q){
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}

int queueLinked_length(QueueLinked q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    if (queueLinked_isEmpty(q)){
        return 0;
    }
    else{
        queueAddress p = ADDR_HEAD(q);
        int count = 1;
        while (p != ADDR_TAIL(q)){
            count++;
            p = NEXT(p);
        }
        return count;
    }
}

/*** Kreator ***/
void queueLinked_CreateQueue(QueueLinked *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void queueLinked_DisplayQueue(QueueLinked q){
/* Proses : Menuliskan isi Queue */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: e1e2...en */
    if (queueLinked_isEmpty(q)){
        printf("");
    } 
    else{
        queueAddress p = ADDR_HEAD(q);
        while (p != ADDR_TAIL(q)){
            printf("%c", INFO(p));
            p = NEXT(p);
        }
        printf("%c", INFO(p));
    }
}

/*** Primitif Enqueue/Dequeue ***/
void queueLinked_enqueue(QueueLinked *q, char x){
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
    queueAddress p;
    p = queueLinked_newNode(x);
    if (p != NIL){
        if (queueLinked_isEmpty(*q)){
            ADDR_HEAD(*q) = p;
        }
        else{
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void queueLinked_dequeue(QueueLinked *q, char *x){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    queueAddress p;
    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NIL){
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}