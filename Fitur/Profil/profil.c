/* File: profil.c */
/* Fitur Profil pengguna yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil */

#include <stdio.h>
#include "profil.h"

/* *** DAFTAR PERINTAH FITUR PROFIL *** */
/* I.S. terdapat pengguna yang login */
void ganti_profil(){
    /* Mengubah profil berdasarkan masukan pengguna */
    displayProfil(Profil(currentAkun), Username(currentAkun));
    printf("\n\n");
    printf("Masukkan Bio Akun:\n");
    readInput();
    changeBio(&Profil(currentAkun), currentWord);
    printf("\n");
    printf("Masukkan No HP:\n");
    readInput();
    while (!isNomorHPValid(currentWord)){
        printf("\nNo HP tidak valid. Masukkan lagi yuk!\n");
        printf("\nMasukkan No HP:\n");
        readInput();
    }
    changeNomorHP(&Profil(currentAkun), currentWord);
    printf("\n");
    printf("Masukkan Weton:\n");
    readInput();
    while (!isWetonValid(currentWord)){
        printf("\nWeton anda tidak valid.\n");
        printf("\nMasukkan Weton:\n");
        readInput();
    }
    changeWeton(&Profil(currentAkun), currentWord);
    printf("\nProfil Anda sudah berhasil diperbarui!\n\n");
}

void lihat_profil_other(Word nama){
    /* Menampilkan profil pengguna yang diinginkan */
    int othersID = findIdxByName(listAkun, nama);
    if (othersID == IDX_UNDEF){
        printf("\nNama tersebut belum terdaftar dalam database BurBir.\n");
    }
    else{
        if (isAkunPrivat(Profil(currentAkun)) && !isAkunBerteman(currentGrafTeman, currentAkun, CONTENT(listAkun, othersID))){
            printf("Wah, akun Tuan Prim diprivat nih. Ikuti dulu yuk untuk bisa melihat profil Tuan Prim!");
        }
        else{
            printf("\n| Nama: ");
            printWord(nama);
            printf("\n| Bio Akun: ");
            printWord(Bio(Profil(CONTENT(listAkun, othersID))));
            printf("\n| No HP: ");
            printWord(NomorHP(Profil(CONTENT(listAkun, othersID))));
            printf("\n| Weton: ");
            printWord(Weton(Profil(CONTENT(listAkun, othersID))));
            printf("\n\nFoto profil akun ");
            printWord(nama);
            printf("\n");
            displayFotoProfil(Foto(Profil(CONTENT(listAkun, othersID))));
            printf("\n");    
        }
    }
}

void atur_jenis_akun(){
    /* Mengubah jenis akun pengguna */
    if (isAkunPrivat(Profil(currentAkun))){
        printf("\nSaat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        readInput();
        printf("\n");
        if (compareWord(currentWord, stringToWord("YA"))){
            changeJenisAkun(&Profil(currentAkun));
            printf("Akun anda sudah diubah menjadi akun Publik.\n");
        }
    }
    else if (isAkunPublik(Profil(currentAkun))){
        printf("\nSaat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        readInput();
        printf("\n");
        if (compareWord(currentWord, stringToWord("YA"))){
            changeJenisAkun(&Profil(currentAkun));
            printf("Akun anda sudah diubah menjadi akun Privat.\n");
        }
    }
}

void ubah_foto_profil(){
    /* Mengubah foto profil berdasarkan masukan pengguna */
    printf("\nFoto profil Anda saat ini adalah\n");
    displayFotoProfil(Foto(Profil(currentAkun)));
    printf("\nMasukkan foto profil yang baru\n");
    readInput();
    changeFotoProfil(&Foto(Profil(currentAkun)), currentWord);
    printf("\nFoto profil anda sudah berhasil diganti!\n\n");
}