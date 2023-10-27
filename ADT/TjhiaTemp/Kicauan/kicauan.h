#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdio.h>
// #include "boolean.h";
#include "../ListDinKicauan/listdinkicauan.h"
#include "../Akun/akun.h"

typedef struct kicauan
{
    int IDKicau;
    // Word text_kicau;
    int jml_like;
    // Word pembuat;
    // Datetime waktu;
    // Word tagar;
    // boolean isUtas;
} Kicauan;

#define IDKICAU(k) (k).IDKicau
#define TEXT_KICAU(k) (k).text_kicau
#define JUMLAH_LIKE(k) (k).jml_like
#define PEMBUAT(k) (k).pembuat
#define WAKTU(k) (k).waktu
#define TAGAR(k) (k).tagar
#define isUTAS(k) (k).isUtas

void createKicauan();

void printKicauan(Kicauan kicauan);
void printKicauan(Kicauan kicauan){
    printf("| ID = %d\n", IDKICAU(kicauan));
    printf("| ");
    // --> printWord(PEMBUAT(kicauan)); printf("\n");
    printf("| ");
    // --> printDatetime(WAKTU(kicauan)); printf("\n");
    printf("| ");
    // --> printWord(TEXT_KICAU(kicauan)); printf("\n");
    printf("| Disukai : %d", JUMLAH_LIKE(kicauan));
}

void KICAU(Word currPengguna);
void KICAU(Word currPengguna){
    // Word input_kicauan;
    printf("Masukkan kicauan:\n");
    // <--Disini nanti diminta masukan input_kicauan
    printf("\n");
    // # Case 1 : input_kicauan hanya mengandung spasi saja

        // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");

    // # Case 2 : input_kicauan valid, terima maksimal 280 character

    // --> buat kicauan baru, masukin ke list_kicauan (ListDin)

    // Cetak pesan
    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    printKicauan(getKicauan(l_kicauan,getLastIdx(l_kicauan)));
}

void KICAUAN(ListDinKicauan l_kicauan, Word currPengguna);
void KICAUAN(ListDinKicauan l_kicauan, word currPengguna){
    int i;
    if(isEmpty(l_kicauan)){
        printf("Belum ada kicauan nihh\n");
    }else{
        for(i=getLastIdx(l_kicauan); i>=0;i--){
            //if (isBerteman(currPengguna, getPembuatByIdx(l_kicauan,i))){printKicauan(getKicauan(l_kicauan,i))}
        }
    }
}

void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan);
void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan){
    printf("\n");
    if(!isIn(id_kicau,l_kicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau);
    }else if(!isAkunPublicByPengguna(getPembuatById(l_kicauan,id_kicau)) && !isBerteman(currPengguna,getPembuatById(l_kicauan,id_kicau))){
        printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya!")
    }else{
        setLike(id_kicau, l_kicauan, 1+getLike(id_kicau, l_kicauan));
        printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
        printKicauan(getKicauan(l_kicauan,id_kicau));
    }
    printf("\n\n");
}


void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan);
void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan){
    if(!isIn(id_kicau,l_kicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d!", id_kicau);
    }else if(!isSama(currPengguna,getPembuatById(l_kicauan,id_kicau))){ // pre-requisite: boolean isSama(Word w1, Word w2)
        printf("Kicauan dengan ID = %d bukan milikmu!",id_kicau);
    }else{
        // Word input_kicauan;
        printf("Masukkan kicauan baru:\n");
        // <--Disini nanti diminta masukan input_kicauan
        printf("\n");
        // # Case 1 : input_kicauan hanya mengandung spasi saja

            // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");

        // # Case 2 : input_kicauan valid, terima maksimal 280 character

        // --> buat kicauan baru, masukin ke list_kicauan (ListDin)

        // Cetak pesan
        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        printKicauan(getKicauan(l_kicauan,getLastIdx(l_kicauan)));
    } 
}

#endif