#include <stdio.h>
#include "../Perintah/perintah.h"
#include "kicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/Akun/akun.h"
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

void kicauan(){
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

void sukaKicauan(int id_kicau){
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

void ubahKicauan(int id_kicau){
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
}