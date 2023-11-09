/* File: foto.c */
/* ADT Foto untuk foto profil pengguna yang berbentuk matriks persegi 5 x 5 dengan warna dan simbol */

#include <stdio.h>
#include "foto.h"

/* *** PROTOTYPE *** */
/* *** PEMBUATAN DENGAN NILAI DEFAULT *** */
void CreateFotoProfil(Foto *F){
    /* Mengisi foto profil dengan nilai default */
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            Warna(*F, i, j) = 'R';
            Simbol(*F, i, j) = '*';
        }
    }
}

/* *** PENGUBAHAN NILAI *** */
void changeFotoProfil(Foto *F, Word w){
    /* Mengubah foto profil berdasarkan masukan pengguna */
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            Warna(*F, i, j) = w.TabWord[i * 20 + 4 * j];
            Simbol(*F, i, j) = w.TabWord[i * 20 + 4 * j + 2];            
        }
    }
}

/* *** PENAMPILAN NILAI *** */
void displayFotoProfil(Foto F){
    /* Menampilkan foto profil pengguna */
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (Warna(F, i, j) == 'R'){
                print_red(Simbol(F, i, j));
            }
            else if (Warna(F, i, j) == 'G'){
                print_green(Simbol(F, i, j));
            }
            else if (Warna(F, i, j) == 'B'){
                print_blue(Simbol(F, i, j));
            }
        }
        printf("\n");
    }
}