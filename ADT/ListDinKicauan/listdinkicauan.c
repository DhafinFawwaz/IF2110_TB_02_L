#include <stdio.h>
#include "listdinkicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../ListStatikAkun/liststatikAkun.h"
#include "../Akun/akun.h"

// int banyakKicauan;
// Kicauan currentKicauan;
// Kicauan listKicauan[100]; // sementara array dulu

ListDinKicauan globalListKicauan;

void createKicauan(Kicauan *k, Word text, Word tagar){
    k = (Kicauan*) malloc(sizeof(Kicauan));
    if(k!=NULL){
        IDKICAU(*k) = NEFF_LIST_KICAUAN(globalListKicauan)+1;
        setWord(&TEXT_KICAU(*k),text.TabWord);
        JUMLAH_LIKE(*k) = 0;
        ADDR_AKUN_KICAUAN(*k) = currentAkun;
        SetToCurrentDateTime(&WAKTU(*k));
        setWord(&TAGAR(*k),tagar.TabWord);
    }
}

void printKicauan(Kicauan kicauan){
    printf("| ID = %d\n", IDKICAU(kicauan));
    printf("| ");
    Word pembuat = (*ADDR_AKUN_KICAUAN(kicauan)).username;
    printWord(pembuat);
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
    CONTENTS_LIST_KICAUAN(*l) = (AddressKicauan*) malloc(cap * sizeof(AddressKicauan));
}

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2){
    int i;
    // createListDinKicauan(l2);
    for(i=0;i < NEFF_LIST_KICAUAN(*l1);i++){
        ADDR_KICAUAN(*l2,i) = ADDR_KICAUAN(*l1,i);
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

void insertKicauan(Kicauan *k){
    AddressKicauan p = k;
    if(isFullListKicauan(globalListKicauan)){
        expandListKicauan(&globalListKicauan);
    }
    int idx = NEFF_LIST_KICAUAN(globalListKicauan);
    ADDR_KICAUAN(globalListKicauan,idx) = p;
    NEFF_LIST_KICAUAN(globalListKicauan)++;
}

boolean isListKicauanEmpty(){
    return(NEFF_LIST_KICAUAN(globalListKicauan)==0);
}

boolean isInListKicauan(int idKicau){
    return(idKicau <= NEFF_LIST_KICAUAN(globalListKicauan) && idKicau >= 1);
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