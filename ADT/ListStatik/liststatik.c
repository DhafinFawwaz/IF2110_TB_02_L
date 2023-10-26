/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
void CreateListStatik(ListStatik *l){
  int i;

  for (i=0; i<CAPACITY; i++){
    ELMT(*l, i) = MARK;
  }
}


int listLength(ListStatik l){
  int count = 0;

  while ((ELMT(l,count) != MARK) && (count < CAPACITY)) {
    count++;
  }

  return count;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
  return 0;
}

IdxType getLastIdx(ListStatik l){
  return (listLength(l) - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
  return ((i >= 0) && (i < CAPACITY));
}

boolean isIdxEff(ListStatik l, IdxType i){
  return ((i >= 0) && (i < listLength(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
boolean isEmpty(ListStatik l){
  return (listLength(l) == 0);
}

boolean isFull(ListStatik l){
  return (listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void readList(ListStatik *l){
  int i;
  int n;

  scanf("%d", &n);
  while ((n < 0) || (n > CAPACITY)) {
    scanf("%d", &n);
  }

  CreateListStatik(l);

  for (i=0; i<n; i++){
    scanf("%d", &ELMT(*l,i));
  }
}

void printList(ListStatik l){
  printf("[");

  if (!isEmpty(l)){
    int i;
    for (i=0; i<(listLength(l)-1); i++){
      printf("%d,", ELMT(l, i));
    }
    printf("%d", ELMT(l, listLength(l)-1));
  }

  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
  int length = listLength(l1); /* Sama untuk l1 dan l2*/
  int i;
  ListStatik l3;
  CreateListStatik(&l3);

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
boolean isListEqual(ListStatik l1, ListStatik l2){
  if (listLength(l1) != listLength(l2)) {return false;}
  
  int i;
  for (i=0; i<listLength(l1); i++){
    if (ELMT(l1,i) != ELMT(l2,i)) {return false;}
  }

  return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
  int i;
  for (i=0; i<listLength(l); i++){
    if (ELMT(l,i) == val) {
      return i;
    }
  }
  return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
  int i; 

  for (i=0;i<listLength(l);i++){
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
void insertFirst(ListStatik *l, ElType val){
  insertAt(l, val, 0);
}

/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
  int i;

  for (i=listLength(*l); i>idx ; i-- ){
    ELMT(*l,i) = ELMT(*l,i-1);
  }

  ELMT(*l,idx) = val;
}

void insertLast(ListStatik *l, ElType val){
  ELMT(*l,listLength(*l)) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteFirst(ListStatik *l, ElType *val){
  deleteAt(l, val, 0);
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
  int i;
  *val = ELMT(*l, idx);

  for (i=idx; i<getLastIdx(*l); i++){
    ELMT(*l, i) = ELMT(*l, i+1);
  }

  ELMT(*l, getLastIdx(*l)) = MARK;

}

void deleteLast(ListStatik *l, ElType *val){
  deleteAt(l, val, listLength(*l) - 1);
}

/* ********** SORTING ********** */

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

boolean compare(int x, int y, boolean asc){
  if (asc == true) {
    return (x>y);
  }
  else{
    return (x<y);
  }
}


void sortList(ListStatik *l, boolean asc)
  {
  /* Bubble Sort */
  int i,j;
  int n = listLength(*l);
  boolean swapped;
  for (i=0; i<n; i++) {
    swapped = false;
    for (j=0; j< n-i-1 ; j++) {
      if (compare (ELMT(*l,j) , ELMT(*l,j+1), asc)){
        swap(&ELMT(*l,j), &ELMT(*l,j+1));
        swapped = true;
      }
    }

    if (swapped = false){
      break;
    }
  }
}


