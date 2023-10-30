/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "liststatikakun.h"
#include "../MesinKata/wordmachine.h"
#include <stdio.h>

ListStatikAkun listAkun; // Global 

/* ********** KONSTRUKTOR ********** */
void listStatikAkun_Create(ListStatikAkun *l){
    NEFF(*l) = 0;
}


int listStatikAkun_Length(ListStatikAkun l){
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
int listStatikAkun_getFirstIdx(ListStatikAkun l){
    return IDX_MIN;
}

int listStatikAkun_getLastIdx(ListStatikAkun l){
    return (NEFF(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean listStatikAkun_isIdxValid(ListStatikAkun l, int i){
    return ((i >= IDX_MIN) && (i < CAPACITY));
}

boolean listStatikAkun_isIdxEff(ListStatikAkun l, int i){
    return ((i >= IDX_MIN) && (i < NEFF(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean listStatikAkun_isEmpty(ListStatikAkun l){
    return (NEFF(l) == 0);
}

boolean listStatikAkun_isFull(ListStatikAkun l){
    return (NEFF(l) == CAPACITY-1);
}

void listStatikAkun_print(ListStatikAkun l){
    printf("[");

    if (!listStatikAkun_isEmpty(l)){
        int i;
        for (i = 0; i < (NEFF(l)); i++){
            DisplayAkun(CONTENT(l, i));
        }
    }
    printf("]");
}

/* ********** MENAMBAH ELEMEN ********** */
void listStatikAkun_insertFirst(ListStatikAkun *l, Akun val){
    listStatikAkun_insertAt(l, val, 0);
    NEFF(*l)++;
}

/* *** Menambahkan elemen pada index tertentu *** */
void listStatikAkun_insertAt(ListStatikAkun *l, Akun val, int idx){
    int i;

    for (i = listStatikAkun_Length(*l); i>idx ; i-- ){
        CONTENT(*l,i) = CONTENT(*l,i-1);
    }

    CONTENT(*l,idx) = val;
    NEFF(*l)++;
}

void listStatikAkun_insertLast(ListStatikAkun *l, Akun val){
    CONTENT(*l,listStatikAkun_Length(*l)) = val;
    NEFF(*l)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void listStatikAkun_deleteFirst(ListStatikAkun *l, Akun *val){
    listStatikAkun_deleteAt(l, val, 0);
    NEFF(*l)--;
}

void listStatikAkun_deleteAt(ListStatikAkun *l, Akun *val, int idx){
    int i;
    *val = CONTENT(*l, idx);

    for (i=idx; i<listStatikAkun_getLastIdx(*l); i++){
        CONTENT(*l, i) = CONTENT(*l, i+1);
    }

    NEFF(*l)--;
}

void listStatikAkun_deleteLast(ListStatikAkun *l, Akun *val){
    listStatikAkun_deleteAt(l, val, listStatikAkun_Length(*l) - 1);
    NEFF(*l)--;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
// Mencari akun dengan id. kalau ga ada, return IDX_UNDEF
int findIdxById(ListStatikAkun l, int id){
    int i = 0;
    while (i < listStatikAkun_Length(l)){
        if (CONTENT(l,i).id == id) {
            return i;
        }
        else
            i++;
    }
    return IDX_UNDEF;
}
int findIdxByName(ListStatikAkun l, Word name){
    int i = 0;
    while (i < listStatikAkun_Length(l)){
        if (compareWord(CONTENT(l,i).profil.nama, name)) {
            return i;
        }
        else
            i++;
    }
    return IDX_UNDEF;
}

void findIdxByPassword(ListStatikAkun l, Word password){
    int i = 0;
    while (i < listStatikAkun_Length(l)){
        if (compareWord(CONTENT(l,i).password, password)) {
            return i;
        }
        else
            i++;
    }
    return IDX_UNDEF;
}


void debugAkun(Akun akun){
    printf("nama: %s\n", akun.profil.nama.TabWord);
    printf("password: %s\n", akun.password.TabWord);
    printf("bio: %s\n", akun.profil.bio.TabWord);
    printf("noHp: %s\n", akun.profil.noHp.TabWord);
    printf("weton: %s\n", akun.profil.weton.TabWord);
    printf("isPublic: %s\n", jenisAkunToWord(akun.isPublic).TabWord);
    displayFoto(akun.profil.foto);
}
void DebugListAkun(){
    printf("======== [Debug listAkun] ========\n");
    printf("banyakAkun: %d\n", NEFF(listAkun));
    int i = 0;
    for(i = 0; i < NEFF(listAkun); i++){
        printf("[Akun ke-%d]\n", i);
        debugAkun(CONTENT(listAkun, i));
    }
    printf("======== [Debug listAkun End] ========\n");
}
