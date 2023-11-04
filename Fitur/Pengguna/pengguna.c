#include <stdio.h>
#include <stdlib.h>
#include "pengguna.h"
#include "../../ADT/Akun/akun.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../Perintah/perintah.h"

boolean isLogin = false;
Word currentPengguna;
int effID = 0;

void daftar(){
    /* INPUT USERNAME */
    printf("\nMasukkan nama: \n");
    readInput();

    int tempID = findIdxByName(listAkun, currentWord);
    while (tempID != IDX_UNDEF){
        printf("\nWah, sayang sekali nama tersebut telah diambil.\n");
        printf("Masukkan nama: \n");

        readInput();
        tempID = findIdxByName(listAkun, currentWord);
    }
    effID++;
    CreateAkun(&listAkun.contents[effID]);
    listAkun.contents[effID].username = currentWord;
    

    /* INPUT PASSWORD */
    printf("\nMasukkan kata sandi: \n");
    readInput();
    listAkun.contents[effID].password = currentWord;

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur Burbir");
}
void masuk(){
    if (isLogin == false){
        printf("\nMasukkan nama: \n");
        readInput();
        int tempID = findIdxByName(listAkun, currentWord);
        while (tempID == IDX_UNDEF){
            printf("\nNama tersebut belum terdaftar dalam database BurBir.\n");
            printf("Masukkan nama: \n");

            readInput();
            tempID = findIdxByName(listAkun, currentWord);
        }

        printf("\nMasukkan kata sandi: \n");
        readInput();

        while (compareWord(listAkun.contents[tempID].password, currentWord) == false) {
            printf("\nWah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            printf("\nMasukkan kata sandi: \n");
            readInput();
        }

        printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi Burbir bersama Ande-Ande Lumut!", listAkun.contents[tempID].username.TabWord);
        isLogin = true;
    } else {
        printf("\nAnda sudah masuk. Keluar dulu yuk!");
    }

}


void keluar(){
    if (isLogin == true){
        isLogin = false;
        printf("\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n");
    } else {
        printf("\nAnda belum login!. Masuk terlebih dahulu untuk menikmati layanan BurBir");
        masuk();
    }
}

void tutup_program(){
    printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya!\n");
}

// int main(){
//     List pengguna;
//     listStatikAkun_Create(&pengguna);

// }