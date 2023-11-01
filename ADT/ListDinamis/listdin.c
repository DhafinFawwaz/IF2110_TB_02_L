#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "../Boolean/boolean.h"

void listdin_CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType*) malloc(capacity*sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void listdin_dealocateList(ListDin *l){
    free(BUFFER(*l));
    // printf("X");
    NEFF(*l) = 0;
    // printf("Y");
    CAPACITY(*l) = 0;
    // printf("Z");
}

int listdin_listLength(ListDin l){
    return (NEFF(l));
}

IdxType listdin_getFirstIdx(ListDin l){
    return IDX_MIN;
}

IdxType listdin_getLastIdx(ListDin l){
    return (listdin_listLength(l)-1);
}

boolean listdin_isIdxValid(ListDin l, IdxType i){
    return (i>=IDX_MIN && i < CAPACITY(l));
}

boolean listdin_isIdxEff(ListDin l, IdxType i){
    return (i>=IDX_MIN && i < NEFF(l));
}

boolean listdin_isEmpty(ListDin l){
    return (listdin_listLength(l)==0);
}

boolean listdin_isFull(ListDin l){
    return (listdin_listLength(l)==CAPACITY(l));
}

void listdin_readList(ListDin *l){
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

void listdin_printList(ListDin l){
    IdxType i;
    printf("[");
    if(listdin_listLength(l)>0){
        for(i = listdin_getFirstIdx(l);i<listdin_listLength(l);i++){
            printf("%d", ELMT(l,i));
            if(i+1<listdin_listLength(l)){
                printf(",");
            }
        }
    }
    printf("]");
}

ListDin listdin_plusMinusList(ListDin l1, ListDin l2, boolean plus){
    IdxType i;
    if(plus){
        for(i = IDX_MIN; i<listdin_listLength(l1);i++){
            ELMT(l1,i) += ELMT(l2,i);
        }
    } else {
        for(i = IDX_MIN; i<listdin_listLength(l1);i++){
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

boolean listdin_isListEqual(ListDin l1, ListDin l2){
    IdxType i;
    if(listdin_listLength(l1)!=listdin_listLength(l2)){
        return false;
    }
    for(i=IDX_MIN;i<listdin_listLength(l1);i++){
        if(ELMT(l1,i)!=ELMT(l2,i)){
            return false;
        }
    }
    return true; 
}

IdxType listdin_indexOf(ListDin l, ElType val){
    IdxType i;
    if(listdin_isEmpty(l)){
        return IDX_UNDEF;
    }
    for(i=IDX_MIN;i<listdin_listLength(l);i++){
        if(ELMT(l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void listdin_extremeValues(ListDin l, ElType *max, ElType *min){
    IdxType i;
    *max = ELMT(l, listdin_getFirstIdx(l));
    *min = ELMT(l, listdin_getFirstIdx(l));
    for(i=IDX_MIN;i<listdin_listLength(l);i++){
        if(ELMT(l,i)>*max){
            *max = ELMT(l,i);
        }
        if(ELMT(l,i)<*min){
            *min = ELMT(l,i);
        }
    }
}

void listdin_copyList(ListDin lIn, ListDin *lOut){
    ListDin temp;
    temp = lIn;
    printf("Address Copy BUFFER lIn:%p\n", BUFFER(lIn));
    printf("Address Copy BUFFER temp:%p\n", BUFFER(temp));
    printf("Address Copy lIn:%p\n", &lIn);
    printf("Address Copy temp:%p\n", &temp);
    
    listdin_dealocateList(lOut);
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
//         // printf("%d",i);void 
//       ELMT(*lOut,i) = ELMT(lIn,i);
//    }
// //    printf("E");
}

ElType listdin_sumList(ListDin l){
    ElType sum;
    IdxType i;
    sum = 0;
    for(i=IDX_MIN;i<listdin_listLength(l);i++){
        sum += ELMT(l,i);
    }
    return sum;
}

int listdin_countVal(ListDin l, ElType val){
    int count;
    IdxType i;
    count = 0;
    for(i=IDX_MIN;i<listdin_listLength(l);i++){
        if(val==ELMT(l,i)){
            count += 1;
        }
    }
    return count;
}

void listdin_sort(ListDin *l, boolean asc){
    IdxType i;
    ElType temp;
    boolean isSorted = false;
    if(asc){
        while(!isSorted){
            isSorted = true;
            for(i=IDX_MIN;i<listdin_listLength(*l)-1;i++){
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
            for(i=IDX_MIN;i<listdin_listLength(*l)-1;i++){
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

void listdin_insertLast(ListDin *l, ElType val){
    ELMT(*l, listdin_listLength(*l)) = val;
    NEFF(*l) += 1;
}

void listdin_deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, listdin_getLastIdx(*l));
    NEFF(*l) -= 1;
}

void listdin_expandList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)+num)*sizeof(ElType));
    CAPACITY(*l) += num;
}

void listdin_shrinkList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l)-num)*sizeof(ElType));
    CAPACITY(*l) -= num;
}

void listdin_compressList(ListDin *l){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), NEFF(*l)*sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}
