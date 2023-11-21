#include <stdio.h>
#include "../Perintah/perintah.h"
#include "kicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/Akun/akun.h"
#include "../Global/global.h"
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

        if(tagar.Length!=0){
            //Hash map
        }
        Kicauan k;
        createKicauan(&k, globalCurrentAddrAkun,text_kicau, tagar);
        IDKICAU(k) = NEFF_LIST_KICAUAN(globalListDinKicauan)+1;
        insertKicauan(&k, &globalListDinKicauan);
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
        AddressKicauan currentKicauan;
        Word pengguna;
        int idx_akun;
        for(i=NEFF_LIST_KICAUAN(globalListDinKicauan)-1;i>=0;i--){
            currentKicauan = ADDR_KICAUAN(globalListDinKicauan,i);
            if(isAkunBerteman(globalGrafTeman, *ADDR_AKUN_KICAUAN(*currentKicauan), *globalCurrentAddrAkun)){
                printKicauan(*currentKicauan);
                printf("\n");
            }
        }
    }
}

void sukaKicauan(int id_kicau){
    printf("\n");
    AddressKicauan k = (ADDR_KICAUAN(globalListDinKicauan,(id_kicau-1)));
    if(!isInListKicauan(id_kicau, globalListDinKicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau);   
    }else if(!((*ADDR_AKUN_KICAUAN(*k)).isPublic) && !isAkunBerteman(globalGrafTeman,(*ADDR_AKUN_KICAUAN(*k)),*globalCurrentAddrAkun)){
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
    AddressKicauan k = ADDR_KICAUAN(globalListDinKicauan,idxKicauan);
    if(!isInListKicauan(id_kicau, globalListDinKicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d!", id_kicau);
    }else if(!compareWord(Username(*globalCurrentAddrAkun),Username(*ADDR_AKUN_KICAUAN(*ADDR_KICAUAN(globalListDinKicauan,id_kicau-1))))){ // pre-requisite: boolean isSama(Word w1, Word w2)
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
}