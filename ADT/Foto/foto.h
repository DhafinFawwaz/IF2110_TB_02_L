/* File: foto.h */
/* ADT Foto untuk foto profil pengguna yang berbentuk matriks persegi 5 x 5 dengan warna dan simbol */

#ifndef FOTO_H
#define FOTO_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "../Pcolor/pcolor.h"
#include "../MesinKata/wordmachine.h"

#define FOTO_ROW_CAP 5
#define FOTO_COL_CAP 5

/* *** DEFINISI TYPE FOTO *** */
typedef struct foto {
    char warna[FOTO_ROW_CAP][FOTO_COL_CAP];
    char simbol[FOTO_ROW_CAP][FOTO_COL_CAP];
} Foto;

/* ********* AKSES (Selektor) ********* */
/* Jika F adalah Foto, maka akses elemen : */
#define Warna(F, i, j) (F).warna[i][j]
#define Simbol(F, i, j) (F).simbol[i][j]

/* *** PROTOTYPE *** */
/* *** PEMBUATAN DENGAN NILAI DEFAULT *** */
void CreateFotoProfil(Foto *F);
/* Mengisi foto profil dengan nilai default */
/* *** PENGUBAHAN NILAI *** */
void changeFotoProfil(Foto *F, Word w);
/* Mengubah foto profil berdasarkan masukan pengguna */
/* *** PENAMPILAN NILAI *** */
void displayFotoProfil(Foto F);
/* Menampilkan foto profil pengguna */

#endif