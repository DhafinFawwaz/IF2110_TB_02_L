/* File: profil.c */
/* Fitur Profil pengguna yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil */

#include <stdio.h>
#include "profil.h"

void CreateProfil(Profil *P){
    /* Mambuat profil kosong dengan nilai-nilai default */
    setWord(&Bio(*P), "");
    setWord(&NomorHP(*P), "");
    setWord(&Weton(*P), "");
    setWord(&JenisAkun(*P), "Publik");
    CreateFotoProfil(P);
}

void CreateFotoProfil(Profil *P){
    /* Mengisi foto profil dengan nilai default */
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            Foto(*P, i, j).warna = 'R';
            Foto(*P, i, j).simbol = '*';
        }
    }
}

boolean isWetonValid(Word weton){
    /* Memeriksa apakah weton valid */
    // Konversi semua huruf ke huruf kecil
    Word weton_kecil = weton;
    for (int i = 0; i < weton.Length; i++){
        if (weton_kecil.TabWord[i] >= 'A' && weton_kecil.TabWord[i] <= 'Z'){
            weton_kecil.TabWord[i] += ('a' - 'A');
        }
    }
    return (compareWord(weton_kecil, stringToWord("pahing")) ||
            compareWord(weton_kecil, stringToWord("kliwon")) ||
            compareWord(weton_kecil, stringToWord("wage")) ||
            compareWord(weton_kecil, stringToWord("pon")) ||
            compareWord(weton_kecil, stringToWord("legi")));
}

boolean isNomorHPValid(Word nomor_hp){
    /* Memeriksa apakah nomor HP valid */
    for (int i = 0; i < nomor_hp.Length; i++){
        if (!(nomor_hp.TabWord[i] >= '0' && nomor_hp.TabWord[i] <= '9')){
            return false;
        }
    }
    return true;
}

boolean isAkunPrivat(Profil P){
    /* Memeriksa apakah jenis akun privat */
    return (compareWord(JenisAkun(P), stringToWord("Privat")));
}

boolean isAkunPublik(Profil P){
    /* Memeriksa apakah jenis akun publik */
    return (compareWord(JenisAkun(P), stringToWord("Publik")));
}

void changeProfil(Profil *P){
    /* Mengubah profil berdasarkan masukan pengguna */
    displayProfil(*P);
    printf("\n\n");
    changeBio(P);
    printf("\n");
    changeNomorHP(P);
    printf("\n");
    changeWeton(P);
    printf("\nProfil Anda sudah berhasil diperbarui!\n\n");
}

void changeBio(Profil *P){
    /* Mengubah bio berdasarkan masukan pengguna */
    printf("Masukkan Bio Akun:\n");
    readInput();
    if (currentWord.Length > 135){
        printf("\nPanjang bio melebihi batas maksimum. Karakter ke 136 dan seterusnya akan dihapus.\n");
    }
    capCurrentWord(135);
    Bio(*P) = currentWord;
}

void changeNomorHP(Profil *P){
    /* Mengubah nomor HP berdasarkan masukan pengguna */
    printf("Masukkan No HP:\n");
    readInput();
    while (!isNomorHPValid(currentWord)){
        printf("\nNo HP tidak valid. Masukkan lagi yuk!\n");
        printf("\nMasukkan No HP:\n");
        readInput();
    }
    NomorHP(*P) = currentWord;
}

void changeWeton(Profil *P){
    /* Mengubah weton berdasarkan masukan pengguna */
    printf("Masukkan Weton:\n");
    readInput();
    while (!isWetonValid(currentWord)){
        printf("\nWeton anda tidak valid.\n");
        printf("\nMasukkan Weton:\n");
        readInput();
    }
    Weton(*P) = currentWord;
}

void changeJenisAkun(Profil *P){
    /* Mengubah jenis akun pengguna */
    if (isAkunPrivat(*P)){
        printf("\nSaat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        readInput();
        printf("\n");
        if (compareWord(currentWord, stringToWord("YA"))){
            setWord(&JenisAkun(*P), "Publik");
            printf("Akun anda sudah diubah menjadi akun Publik.\n");
        }
    }
    else if (isAkunPublik(*P)){
        printf("\nSaat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        readInput();
        printf("\n");
        if (compareWord(currentWord, stringToWord("YA"))){
            setWord(&JenisAkun(*P), "Privat");
            printf("Akun anda sudah diubah menjadi akun Privat.\n");
        }
    }
}

void changeFotoProfil(Profil *P){
    /* Mengubah foto profil berdasarkan masukan pengguna */
    printf("\nFoto profil Anda saat ini adalah\n");
    displayFotoProfil(*P);
    printf("\nMasukkan foto profil yang baru\n");
    readInput();
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            Foto(*P, i, j).warna = currentWord.TabWord[i * 20 + 4 * j];
            Foto(*P, i, j).simbol = currentWord.TabWord[i * 20 + 4 * j + 2];            
        }
    }
    printf("\nFoto profil anda sudah berhasil diganti!\n\n");
}

void displayProfil(Profil P){
    /* Menampilkan profil pengguna kecuali bagian foto profil */
    printf("\n| Nama: ");
    printWord(currentPengguna);
    printf("\n| Bio Akun: ");
    printWord(Bio(P));
    printf("\n| No HP: ");
    printWord(NomorHP(P));
    printf("\n| Weton: ");
    printWord(Weton(P));
}

void lihatProfil(Profil P, Word username){
    /* Menampilkan profil pengguna dengan username "username" */
    if (isAkunPrivat(P)){ // && belum follow
        printf("Wah, akun Tuan Prim diprivat nih. Ikuti dulu yuk untuk bisa melihat profil Tuan Prim!");
    }
    else {
        printf("\n| Nama: ");
        printWord(username);
        printf("\n| Bio Akun: ");
        printWord(Bio(P));
        printf("\n| No HP: ");
        printWord(NomorHP(P));
        printf("\n| Weton: ");
        printWord(Weton(P));
        printf("\n\nFoto profil akun ");
        printWord(username);
        printf("\n");
        displayFotoProfil(P);
        printf("\n");
    }
}

void displayFotoProfil(Profil P){
    /* Menampilkan foto profil pengguna */
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (Foto(P, i, j).warna == 'R'){
                print_red(Foto(P, i, j).simbol);
            }
            else if (Foto(P, i, j).warna == 'G'){
                print_green(Foto(P, i, j).simbol);
            }
            else if (Foto(P, i, j).warna == 'B'){
                print_blue(Foto(P, i, j).simbol);
            }
        }
        printf("\n");
    }
}