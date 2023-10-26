#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "boolean.h"

void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType*) malloc(capacity*sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    // printf("X");
    NEFF(*l) = 0;
    // printf("Y");
    CAPACITY(*l) = 0;
    // printf("Z");
}

int listLength(ListDin l){
    return (NEFF(l));
}

IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
    return (listLength(l)-1);
}

boolean isIdxValid(ListDin l, IdxType i){
    return (i>=IDX_MIN && i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
    return (i>=IDX_MIN && i < NEFF(l));
}

boolean isEmpty(ListDin l){
    return (listLength(l)==0);
}

boolean isFull(ListDin l){
    return (listLength(l)==CAPACITY(l));
}

void readList(ListDin *l){
    int N;
    IdxType i;
    do {
        scanf("%d", &N);
    } while(N<0 || N>CAPACITY(*l));
    if(N!=0){
        for(i=0;i<N;i++){
            scanf("%d", &ELMT(*l,i));
        }
    }
    NEFF(*l) = N;
}

void printList(ListDin l){
    IdxType i;
    printf("[");
    if(listLength(l)>0){
        for(i = getFirstIdx(l);i<listLength(l);i++){
            printf("%d", ELMT(l,i));
            if(i+1<listLength(l)){
                printf(",");
            }
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    IdxType i;
    if(plus){
        for(i = IDX_MIN; i<listLength(l1);i++){
            ELMT(l1,i) += ELMT(l2,i);
        }
    } else {
        for(i = IDX_MIN; i<listLength(l1);i++){
            ELMT(l1,i) -= ELMT(l2,i);
        }
    }
    return l1;
//     IdxType i;
//     ListDin l3;
//    CreateListDin(&l3, CAPACITY(l1));
//    NEFF(l3) = NEFF(l1);
//    if (plus){
//       for(i=0;i<listLength(l1);i++){
//          ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
//       }
//    } else{
//       for(i=0;i<listLength(l1);i++){
//          ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
//       }
//    }
//    return l3;
}

boolean isListEqual(ListDin l1, ListDin l2){
    IdxType i;
    if(listLength(l1)!=listLength(l2)){
        return false;
    }
    for(i=IDX_MIN;i<listLength(l1);i++){
        if(ELMT(l1,i)!=ELMT(l2,i)){
            return false;
        }
    }
    return true; 
}

IdxType indexOf(ListDin l, ElType val){
    IdxType i;
    if(isEmpty(l)){
        return IDX_UNDEF;
    }
    for(i=IDX_MIN;i<listLength(l);i++){
        if(ELMT(l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
    IdxType i;
    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));
    for(i=IDX_MIN;i<listLength(l);i++){
        if(ELMT(l,i)>*max){
            *max = ELMT(l,i);
        }
        if(ELMT(l,i)<*min){
            *min = ELMT(l,i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    ListDin temp;
    temp = lIn;
    printf("Address Copy BUFFER lIn:%p\n", BUFFER(lIn));
    printf("Address Copy BUFFER temp:%p\n", BUFFER(temp));
    printf("Address Copy lIn:%p\n", &lIn);
    printf("Address Copy temp:%p\n", &temp);
    
    dealocateList(lOut);
    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
    BUFFER(*lOut) = (ElType*) realloc(BUFFER(temp), CAPACITY(*lOut)*sizeof(ElType));
    printf("Address Copy BUFFER lOut:%p\n", BUFFER(*lOut));
    printf("Address Copy lOut:%p\n", lOut);
//    int i;
// //    printf("A");
// //    printList(*lOut);
//    dealocateList(lOut);
// //    printf("B");
//    CreateListDin(lOut, CAPACITY(lIn));
// //    printf("C");
//    NEFF(*lOut) = NEFF(lIn);
// //    printf("D");
//    for (i=0;i<listLength(lIn);i++){
//         // printf("%d",i);
//       ELMT(*lOut,i) = ELMT(lIn,i);
//    }
// //    printf("E");
}

ElType sumList(ListDin l){
    ElType sum;
    IdxType i;
    sum = 0;
    for(i=IDX_MIN;i<listLength(l);i++){
        sum += ELMT(l,i);
    }
    return sum;
}

int countVal(ListDin l, ElType val){
    int count;
    IdxType i;
    count = 0;
    for(i=IDX_MIN;i<listLength(l);i++){
        if(val==ELMT(l,i)){
            count += 1;
        }
    }
    return count;
}

void sort(ListDin *l, boolean asc){
    IdxType i;
    ElType temp;
    boolean isSorted = false;
    if(asc){
        while(!isSorted){
            isSorted = true;
            for(i=IDX_MIN;i<listLength(*l)-1;i++){
                if(ELMT(*l,i)>ELMT(*l,i+1)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,i+1);
                    ELMT(*l,i+1) = temp;
                    isSorted = false;
                }
            }
        }
    } else {
        while(!isSorted){
            isSorted = true;
            for(i=IDX_MIN;i<listLength(*l)-1;i++){
                if(ELMT(*l,i)<ELMT(*l,i+1)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,i+1);
                    ELMT(*l,i+1) = temp;
                    isSorted = false;
                }
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l) += 1;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
}

void expandList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)+num)*sizeof(ElType));
    CAPACITY(*l) += num;
}

void shrinkList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)-num)*sizeof(ElType));
    CAPACITY(*l) -= num;
}

void compressList(ListDin *l){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), NEFF(*l)*sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}

int main(){
    ListDin l1,l2;
    printf("Address lIn:%p\n", &l1);
    printf("Address lOut:%p\n", &l2);

    CreateListDin(&l1, 10);
    CreateListDin(&l2, 10);
 
    readList(&l1);
   
    printList(l1);
    printf("%p\n", BUFFER(l1));
    printf("%p\n", BUFFER(l2));
    copyList(l1, &l2);
    printList(l1);
    printf("\n");
    printList(l2);
    printf("\n");
    printf("%p\n", BUFFER(l1));
    printf("%p\n", BUFFER(l2));
    ELMT(l2,1) = 999;
    printf("%d\n", ELMT(l1,1));
    printf("%d\n", ELMT(l2,1));
    printf("%d\n", NEFF(l1));
    printf("%d\n", NEFF(l2));
    printf("%d\n", CAPACITY(l1));
    printf("%d\n", CAPACITY(l2));
    printf("%d\n", sumList(l1));
    sort(&l1, true);
    printList(l1);
    sort(&l1, false);
    printList(l1);
    printf("%u\n", isListEqual(l1,l2));
    // printf("DEALO");
    // dealocateList(&l1);
    printList(l1);
    printf("%d\n", NEFF(l1));
    printf("%d\n", CAPACITY(l1));

    printList(l1);
    printList(l2);
    l2=plusMinusList(l1, l2, false);
    printList(l2);
    printList(l1);
    printf("Address lIn:%p\n", &l1);
    printf("Address lOut:%p\n", &l2);
}