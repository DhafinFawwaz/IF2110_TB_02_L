/* File: stacklinked.c */


#include "../StackDin/stackdin.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNodeStackDin(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NULL jika alokasi gagal */   
{
    Address new = malloc(sizeof(Node));
    if (new != NIL) {
        INFO(new) = x;
        NEXT(new) = NIL;
    }
    return new;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyStackDin(StackDin s)
/* Mengirim true jika Stack kosong: TOP(s) = NIL */
{
    return ADDR_TOP(s) == NIL;
}

int lengthStackDin(StackDin s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    if(isEmptyStackDin(s)){
        return 0;
    } else {
        Address p = ADDR_TOP(s);
        int len = 0;
        while (p != NIL){
            p = NEXT(p);
            len++;
        }
        return len;
    }
}

void CreateStackDin(StackDin *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = NIL;
}

void DisplayStackDin(StackDin s)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    Address p = ADDR_TOP(s);
    while (p != NIL) {
        printf("%d", INFO(p)); 
        p = NEXT(p);
        if (p != NIL) {
            printf(",");
        } 
    }
}

void pushStackDin(StackDin *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = newNodeStackDin(x);
    if(p!= NIL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void popStackDin(StackDin *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NIL;
    free(p);
}