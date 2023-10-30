/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
void listStatik_Create(ListStatik *l){
  int i;

  for (i=0; i<CAPACITY; i++){
    ELMT(*l, i) = MARK;
  }
}


int listStatik_Length(ListStatik l){
  int count = 0;

  while ((ELMT(l,count) != MARK) && (count < CAPACITY)) {
    count++;
  }

  return count;
}

/* *** Selektor INDEKS *** */
IdxType listStatik_getFirstIdx(ListStatik l){
  return 0;
}

IdxType listStatik_getLastIdx(ListStatik l){
  return (listStatik_Length(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean listStatik_isIdxValid(ListStatik l, IdxType i){
  return ((i >= 0) && (i < CAPACITY));
}

boolean listStatik_isIdxEff(ListStatik l, IdxType i){
  return ((i >= 0) && (i < listStatik_Length(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean liststatik_isEmpty(ListStatik l){
  return (listStatik_Length(l) == 0);
}

boolean liststatik_isFull(ListStatik l){
  return (listStatik_Length(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void liststatik_readList(ListStatik *l){
  int i;
  int n;

  scanf("%d", &n);
  while ((n < 0) || (n > CAPACITY)) {
    scanf("%d", &n);
  }

  listStatik_Create(l);

  for (i=0; i<n; i++){
    scanf("%d", &ELMT(*l,i));
  }
}

void liststatik_printList(ListStatik l){
  printf("[");

  if (!liststatik_isEmpty(l)){
    int i;
    for (i=0; i<(listStatik_Length(l)-1); i++){
      printf("%d,", ELMT(l, i));
    }
    printf("%d", ELMT(l, listStatik_Length(l)-1));
  }

  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */

ListStatik liststatik_plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
  int length = listStatik_Length(l1); /* Sama untuk l1 dan l2*/
  int i;
  ListStatik l3;
  listStatik_Create(&l3);

  if (plus == true) {
    for (i=0; i<length; i++){
      ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
    }
  }
  else {
    for (i=0; i<length; i++){
      ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
    }
  }

  return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean liststatik_isListEqual(ListStatik l1, ListStatik l2){
  if (listStatik_Length(l1) != listStatik_Length(l2)) {return false;}
  
  int i;
  for (i=0; i<listStatik_Length(l1); i++){
    if (ELMT(l1,i) != ELMT(l2,i)) {return false;}
  }

  return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int liststatik_indexOf(ListStatik l, ElType val){
  int i;
  for (i=0; i<listStatik_Length(l); i++){
    if (ELMT(l,i) == val) {
      return i;
    }
  }
  return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void liststatik_extremeValues(ListStatik l, ElType *max, ElType *min){
  int i; 

  for (i=0;i<listStatik_Length(l);i++){
    if (i==0){
      *max = ELMT(l,i);
      *min = ELMT(l,i);
    }
    else{
      if (ELMT (l,i) < *min) {
        *min = ELMT(l,i);
      }
      if (ELMT (l,i) > *max) {
        *max = ELMT(l,i);
      }
    }
  }
}

/* ********** MENAMBAH ELEMEN ********** */
void liststatik_insertFirst(ListStatik *l, ElType val){
  liststatik_insertAt(l, val, 0);
}

/* *** Menambahkan elemen pada index tertentu *** */
void liststatik_insertAt(ListStatik *l, ElType val, IdxType idx){
  int i;

  for (i=listStatik_Length(*l); i>idx ; i-- ){
    ELMT(*l,i) = ELMT(*l,i-1);
  }

  ELMT(*l,idx) = val;
}

void liststatik_insertLast(ListStatik *l, ElType val){
  ELMT(*l,listStatik_Length(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void liststatik_deleteFirst(ListStatik *l, ElType *val){
  liststatik_deleteAt(l, val, 0);
}

void liststatik_deleteAt(ListStatik *l, ElType *val, IdxType idx){
  int i;
  *val = ELMT(*l, idx);

  for (i=idx; i<listStatik_getLastIdx(*l); i++){
    ELMT(*l, i) = ELMT(*l, i+1);
  }

  ELMT(*l, listStatik_getLastIdx(*l)) = MARK;

}

void liststatik_deleteLast(ListStatik *l, ElType *val){
  liststatik_deleteAt(l, val, listStatik_Length(*l) - 1);
}

/* ********** SORTING ********** */

void liststatik_swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

boolean liststatik_compare(int x, int y, boolean asc){
  if (asc == true) {
    return (x>y);
  }
  else{
    return (x<y);
  }
}


void liststatik_sortList(ListStatik *l, boolean asc)
  {
  /* Bubble Sort */
  int i,j;
  int n = listStatik_Length(*l);
  boolean swapped;
  for (i=0; i<n; i++) {
    swapped = false;
    for (j=0; j< n-i-1 ; j++) {
      if (liststatik_compare (ELMT(*l,j) , ELMT(*l,j+1), asc)){
        liststatik_swap(&ELMT(*l,j), &ELMT(*l,j+1));
        swapped = true;
      }
    }

    if (swapped == false){
      break;
    }
  }
}


