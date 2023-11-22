#include <stdio.h>
#include "listdinkicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../ListStatikAkun/liststatikAkun.h"
#include "../Akun/akun.h"
#include <stdlib.h>

void createKicauan(Kicauan *k, Word text){
    IDKICAU(*k) = -1;
    setWord(&(TEXT_KICAU(*k)),text.TabWord);
    JUMLAH_LIKE(*k) = 0;
    SetToCurrentDateTime(&WAKTU(*k));

    k->firstBalasan = NULL;
    k->firstUtas = NULL;
}

void printKicauan(Kicauan kicauan){
    printf("| ID = %d\n", IDKICAU(kicauan));
    printf("| ");
    printWord(ADDR_AKUN_KICAUAN(kicauan)->username);
    printf("\n");
    printf("| ");
    DisplayDateTime(WAKTU(kicauan));
    printf("\n");
    printf("| ");
    printWord(TEXT_KICAU(kicauan));
    printf("\n");
    printf("| Disukai : %d", JUMLAH_LIKE(kicauan));
}

void createListDinKicauan(ListDinKicauan *l, int cap){
    NEFF_LIST_KICAUAN(*l) = 0;
    CAP_LIST_KICAUAN(*l) = cap;
    CONTENTS_LIST_KICAUAN(*l) = (Kicauan*) malloc(cap * sizeof(Kicauan));
}

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2){
    int i;
    // createListDinKicauan(l2);
    for(i=0;i < NEFF_LIST_KICAUAN(*l1);i++){
        GET_ELMT_KICAUAN(*l2,i) = GET_ELMT_KICAUAN(*l1,i);
    }
    NEFF_LIST_KICAUAN(*l2) = NEFF_LIST_KICAUAN(*l1);
    CAP_LIST_KICAUAN(*l2) = CAP_LIST_KICAUAN(*l1);
}

void expandListKicauan(ListDinKicauan *l){
    int new_cap = 2 * CAP_LIST_KICAUAN(*l);
    ListDinKicauan lNew;
    createListDinKicauan(&lNew, new_cap);
    copyContentListKicauan(l, &lNew);
    *l = lNew;
}

boolean isFullListKicauan(ListDinKicauan l){
    return(NEFF_LIST_KICAUAN(l) == CAP_LIST_KICAUAN(l));
}

void insertKicauan(Kicauan k, ListDinKicauan * listKicauan){
    if(isFullListKicauan(*listKicauan)){
        expandListKicauan(listKicauan);
    }
    int idx = NEFF_LIST_KICAUAN(*listKicauan);
    GET_ELMT_KICAUAN((*listKicauan),idx) = k;
    NEFF_LIST_KICAUAN(*listKicauan)++;
}

boolean isListKicauanEmpty(ListDinKicauan listKicauan){
    return(NEFF_LIST_KICAUAN(listKicauan)==0);
}

boolean isInListKicauan(int idKicau, ListDinKicauan listKicauan){
    return(idKicau <= NEFF_LIST_KICAUAN(listKicauan) && idKicau >= 1);
}

Kicauan getKicauanById(ListDinKicauan listKicauan, int id){
    return GET_ELMT_KICAUAN(listKicauan, id-1);
}


// void DebugListKicauan(){
//     printf("======== [Debug listKicauan] ========\n");
//     int i;
//     for(i=0;i<banyakKicauan;i++){
//         printf("[Kicauan ke-%d]\n",i+1);
//         // displayKicauan(listKicauan[i]);
//         printf("\n");
//     }
//     printf("======== [Debug listKicauan End] ========\n");
// }