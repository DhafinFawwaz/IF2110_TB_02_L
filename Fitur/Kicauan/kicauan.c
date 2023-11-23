#include <stdio.h>
#include "../Perintah/perintah.h"
#include "kicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/Akun/akun.h"
#include "../Global/global.h"
#include "../../ADT/MapDin/mapdin.h"

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
        printf("Kicauan tidak boleh kosong!\n");
    }
    else{
        printf("Masukkan tagar:\n");
        readInput();
        setWord(&tagar, currentWord.TabWord);

        printf("\n");

        
        Kicauan k;
        createKicauan(&k,text_kicau);
        setWord(&TAGAR(k),tagar.TabWord);

        // HASH MAP
        if(TAGAR(k).Length!=0){
            if(isFullMapDin(globalMapTagarKicauan)){
                rehashing(&globalMapTagarKicauan);
            }
            insertMapDin(&globalMapTagarKicauan,&k);
        }

        IDKICAU(k) = NEFF_LIST_KICAUAN(globalListDinKicauan)+1;
        ADDR_AKUN_KICAUAN(k) = globalCurrentAddrAkun;
        insertKicauan(k, &globalListDinKicauan);
        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        printKicauan(k);
        printf("\n");
        printf("\n");
    }
}

void kicauan(){
    int i;
    if(isListKicauanEmpty(globalListDinKicauan)){
        printf("Masih belum ada kicauan\n");
    }else{
        int lastIDX = NEFF_LIST_KICAUAN(globalListDinKicauan)-1;
        for(i=lastIDX;i>=0;i--){
            Akun* A1 = (globalListDinKicauan.contents[i]).akunKicauan;
            Akun A2 = *globalCurrentAddrAkun;
            if(isAkunBerteman(globalGrafTeman, *A1, A2)){
                printKicauan(globalListDinKicauan.contents[i]);
                printf("\n\n");
            }
        }
    }
}

void sukaKicauan(int id_kicau){
    printf("\n");
    Kicauan* k = &(GET_ELMT_KICAUAN(globalListDinKicauan,(id_kicau-1)));
    if(!isInListKicauan(id_kicau, globalListDinKicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau); 
    }else if(!JenisAkun(Profil(*ADDR_AKUN_KICAUAN(*k))) && !isAkunBerteman(globalGrafTeman,(*ADDR_AKUN_KICAUAN(*k)),*globalCurrentAddrAkun)){
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Berteman dengan akun itu dulu ya!");
    }else{
        JUMLAH_LIKE(*k)++;
        printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
        printKicauan(*k);
    }
    printf("\n\n");
}

void ubahKicauan(int id_kicau){
    int idxKicauan = id_kicau-1;
    Kicauan* k = &GET_ELMT_KICAUAN(globalListDinKicauan,idxKicauan);
    if(!isInListKicauan(id_kicau, globalListDinKicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d!\n\n", id_kicau);
    }else if(!compareWord(Username(*globalCurrentAddrAkun),Username(*ADDR_AKUN_KICAUAN(GET_ELMT_KICAUAN(globalListDinKicauan,id_kicau-1))))){ // pre-requisite: boolean isSama(Word w1, Word w2)
        printf("Kicauan dengan ID = %d bukan milikmu!\n\n",id_kicau);
    }else{
        printf("Masukkan kicauan baru:\n");
        readInput();
        capCurrentWord(280);
        printf("\n");
        if(currentWord.Length == 0){
            printf("Kicauan tidak boleh kosong!\n\n");
        }else{
            setWord(&TEXT_KICAU(*k),currentWord.TabWord);
            // Cetak pesan
            printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
            printKicauan(*k);
            printf("\n\n");
        }
    } 
}