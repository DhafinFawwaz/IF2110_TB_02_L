#include <stdio.h>
#include "kicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "grafteman.h"
#include "../ListStatikAkun/liststatikAkun.h"

// int banyakKicauan;
// Kicauan currentKicauan;
// Kicauan listKicauan[100]; // sementara array dulu

ListDinKicauan listKicauan;

void createKicauan(Kicauan *k, Word text, Word tagar){
    k = (Kicauan*) malloc(sizeof(Kicauan));
    if(k!=NULL){
        IDKICAU(*k) = NEFF_LIST_KICAUAN(listKicauan)+1;
        setWord(&TEXT_KICAU(*k),text.TabWord);
        JUMLAH_LIKE(*k) = 0;
        ADDR_AKUN_KICAUAN(*k) = currentAkun;
        SetToCurrentDateTime(&WAKTU(*k));
        setWord(&TAGAR(*k),tagar.TabWord);
        isUTAS(*k) = false;
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

// INI NANTI DIPINDAH KE FOLDER FITUR
#include "../Perintah/perintah.h"
// BELUM BERES : TINGGAL HASHING KL ADA TAGAR
void kicau(){
    Word text_kicau, tagar;
    // Word input_kicauan;
    printf("Masukkan kicauan:\n");
    readInput();
    capCurrentWord(280);
    setWord(&text_kicau, currentWord.TabWord);

    printf("\n");

    if(text_kicau.Length == 0){
        printf("Kicauan tidak boleh kosong!");
    }
    else{
        printf("Masukkan tagar:\n");
        readInput();
        setWord(&tagar, currentWord.TabWord);

        printf("\n");

        if(tagar.Length!=0){
            //Hash map
        }
        Kicauan k;
        createKicauan(&k, text_kicau, tagar);
        insertKicauan(&k);
        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        printKicauan(k);
        printf("\n");
        printf("\n");
    }
}
// END OF INI NANTI DIPINDAH KE FOLDER FITUR

void KICAUAN(){
    int i;
    if(isListKicauanEmpty()){
        printf("Masih belum ada kicauan\n");
    }else{
        AddressKicauan currentKicauan;
        Word pengguna;
        int idx_akun;
        for(i=NEFF_LIST_KICAUAN(listKicauan)-1;i>=0;i--){
            currentKicauan = ADDR_KICAUAN(listKicauan,i);
            if(isAkunBerteman(currentGrafTeman, *ADDR_AKUN_KICAUAN(*currentKicauan), *currentAkun)){
                printKicauan(*currentKicauan);
                printf("\n");
            }
        }
    }
}


// BELUM BERES : PERLU isBerteman dan isAkunPublik dengan parameter nama pembuat
void SUKA_KICAUAN(int id_kicau){
    printf("\n");
    AddressKicauan k = (ADDR_KICAUAN(listKicauan,(id_kicau-1)));
    if(!isInListKicauan(id_kicau)){
        printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau);   
    }else if(!((*ADDR_AKUN_KICAUAN(*k)).isPublic) && !isAkunBerteman(currentGrafTeman,(*ADDR_AKUN_KICAUAN(*k)),*currentAkun)){
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Berteman dengan akun itu dulu ya!");
    }else{
        JUMLAH_LIKE(*k)++;
        printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
        printKicauan(*k);
    }
    printf("\n\n");
}

void UBAH_KICAUAN(int id_kicau){
    int idxKicauan = id_kicau-1;
    AddressKicauan k = ADDR_KICAUAN(listKicauan,idxKicauan);
    if(!isInListKicauan(id_kicau)){
        printf("Tidak ditemukan kicauan dengan ID = %d!", id_kicau);
    }else if(!compareWord(Username(*currentAkun),Username(*ADDR_AKUN_KICAUAN(*ADDR_KICAUAN(listKicauan,id_kicau-1))))){ // pre-requisite: boolean isSama(Word w1, Word w2)
        printf("Kicauan dengan ID = %d bukan milikmu!",id_kicau);
    }else{
        Word new_textKicauan;
        printf("Masukkan kicauan baru:\n");
        readInput();
        capCurrentWord(280);
        setWord(&new_textKicauan, currentWord.TabWord);

        printf("\n");
        if(new_textKicauan.Length == 0){
            printf("Kicauan tidak boleh kosong!");
        }else{
            setWord(&TEXT_KICAU(*k),new_textKicauan.TabWord);
            // Cetak pesan
            printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
            printKicauan(*k);
    } 
}

void createListDinKicauan(ListDinKicauan *l, int cap){
    NEFF_LIST_KICAUAN(*l) = 0;
    CAP_LIST_KICAUAN(*l) = cap;
    CONTENTS_LIST_KICAUAN(*l) = (AddressKicauan*) malloc(cap * sizeof(AddressKicauan));
}

void copyContentListKicauan(ListDinKicauan *l1, ListDinKicauan *l2){
    int i;
    createListDinKicauan(l2);
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
    if(isFullListKicauan(listDinKicauan)){
        expandListKicauan(&listDinKicauan);
    }
    int idx = NEFF_LIST_KICAUAN(listDinKicauan);
    ADDR_KICAUAN(listDinKicauan,idx) = p;
    NEFF_LIST_KICAUAN(listDinKicauan)++;
}

boolean isListKicauanEmpty(){
    return(NEFF_LIST_KICAUAN(listDinKicauan)==0);
}

boolean isInListKicauan(int idKicau){
    return(idKicau <= NEFF_LIST_KICAUAN(listDinKicauan) && idKicau >= 1);
}

void DebugListKicauan(){
    printf("======== [Debug listKicauan] ========\n");
    int i;
    for(i=0;i<banyakKicauan;i++){
        printf("[Kicauan ke-%d]\n",i+1);
        displayKicauan(listKicauan[i]);
        printf("\n");
    }
    printf("======== [Debug listKicauan End] ========\n");
}
void displayKicauan(Kicauan kicauan){
    printf("id: %d\n", IDKICAU(kicauan));
    printf("text: %s\n", TEXT_KICAU(kicauan).TabWord);
    printf("like: %d\n", JUMLAH_LIKE(kicauan));
    printf("nama: %s\n", PEMBUAT(kicauan).TabWord);
    printf("dateTime: ");
    DisplayDateTime(WAKTU(kicauan));
}