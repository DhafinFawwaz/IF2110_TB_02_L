#include <stdio.h>
#include <stdlib.h>
#include "pengguna.h"
#include "../../ADT/Akun/akun.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../Perintah/perintah.h"
#include "../Global/global.h"


void daftar(){
    /* INPUT USERNAME */
    printf("\nMasukkan nama: \n");
    readInput();

    int tempID = findIdxByName(globalListStatikAkun, currentWord);
    while (tempID != IDX_UNDEF){
        printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
        printf("Masukkan nama: \n");

        readInput();
        tempID = findIdxByName(globalListStatikAkun, currentWord);
    }

    int effID = globalListStatikAkun.Neff;
    CreateAkun(&globalListStatikAkun.contents[effID]);
    globalListStatikAkun.contents[effID].username = currentWord;
    globalListStatikAkun.Neff++;
    

    /* INPUT PASSWORD */
    printf("\nMasukkan kata sandi: \n");
    readInput();
    globalListStatikAkun.contents[effID].password = currentWord;

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur Burbir\n");
}
void masuk(){
    if (isLogin == false){
        printf("\nMasukkan nama: \n");
        readInput();
        int tempID = findIdxByName(globalListStatikAkun, currentWord);
        while (tempID == IDX_UNDEF){
            printf("\nNama tersebut belum terdaftar dalam database BurBir.\n");
            printf("Masukkan nama: \n");

            readInput();
            tempID = findIdxByName(globalListStatikAkun, currentWord);
        }

        printf("\nMasukkan kata sandi: \n");
        readInput();

        while (compareWord(globalListStatikAkun.contents[tempID].password, currentWord) == false) {
            printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("\nMasukkan kata sandi: \n");
            readInput();
        }

        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi Burbir bersama Ande-Ande Lumut!\n\n", globalListStatikAkun.contents[tempID].username.TabWord);
        isLogin = true;
    } else {
        printf("\nAnda sudah masuk. Keluar dulu yuk!\n");
    }
}

void keluar(){
    if (isLogin == true){
        isLogin = false;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    } else {
        printf("\nAnda belum login!. Masuk terlebih dahulu untuk menikmati layanan BurBir\n");
        masuk();
    }
}

void tutup_program(){
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya!\n");
}