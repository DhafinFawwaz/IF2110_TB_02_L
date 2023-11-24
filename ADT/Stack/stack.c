/* File: stack.c */
/* *** Deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama *** */

#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void stack_CreateEmpty(Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean stack_IsEmpty(Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == Nil);
}

boolean stack_IsFull(Stack S){
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return (Top(S) == MaxEl - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void stack_Push(Stack * S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void stack_Pop(Stack * S, infotype* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S)--;
}

void stack_displayStack(Stack S){
/* Menampilkan semua elemen Stack S */
    if (stack_IsEmpty(S)){
        printf("[]\n");
    } 
    else{
        printf("[");
        for (int i = 0; i <= Top(S); i++){
            printf("%d", S.T[i]);
            if (i < Top(S)) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}