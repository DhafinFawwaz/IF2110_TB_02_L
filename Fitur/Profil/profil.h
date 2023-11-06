/* File: profil.h */
/* Fitur Profil pengguna yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil */

#ifndef PROFIL_H
#define PROFIL_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "pcolor/pcolor.h"
#include "../Perintah/perintah.h"
#include "../Pengguna/pengguna.h"
#include "../../ADT/Boolean/boolean.h"
#include "../../ADT/MesinKata/wordmachine.h"

/* *** DEFINISI TYPE FOTO *** */
typedef struct foto {
    char warna;
    char simbol;
} Foto;

/* *** DEFINISI TYPE PROFIL *** */
typedef struct profil {
    Word bio;
    Word nomor_hp;
    Word weton;
    Word jenis_akun;
    Foto foto[5][5];
} Profil;

/* ********* AKSES (Selektor) ********* */
/* Jika P adalah Profil, maka akses elemen : */
#define Bio(P) (P).bio
#define NomorHP(P) (P).nomor_hp
#define Weton(P) (P).weton
#define JenisAkun(P) (P).jenis_akun
#define Foto(P, i, j) (P).foto[i][j]

/* *** PROTOTYPE *** */
/* I.S. terdapat pengguna yang login */
/* *** PEMBUATAN DENGAN NILAI DEFAULT *** */
void CreateProfil(Profil *P);
/* Mambuat profil kosong dengan nilai-nilai default */
void CreateFotoProfil(Profil *P);
/* Mengisi foto profil dengan nilai default */
/* *** PEMERIKSAAN NILAI *** */
boolean isWetonValid(Word weton);
/* Memeriksa apakah weton valid */
boolean isNomorHPValid(Word nomor_hp);
/* Memeriksa apakah nomor HP valid */
boolean isAkunPrivat(Profil P);
/* Memeriksa apakah jenis akun privat */
boolean isAkunPublik(Profil P);
/* Memeriksa apakah jenis akun publik */
/* *** PENGUBAHAN NILAI *** */
void changeProfil(Profil *P);
/* Mengubah profil berdasarkan masukan pengguna */
void changeBio(Profil *P);
/* Mengubah bio berdasarkan masukan pengguna */
void changeNomorHP(Profil *P);
/* Mengubah nomor HP berdasarkan masukan pengguna */
void changeWeton(Profil *P);
/* Mengubah weton berdasarkan masukan pengguna */
void changeJenisAkun(Profil *P);
/* Mengubah jenis akun pengguna */
void changeFotoProfil(Profil *P);
/* Mengubah foto profil berdasarkan masukan pengguna */
/* *** PENAMPILAN NILAI *** */
void displayProfil(Profil P);
/* Menampilkan profil pengguna kecuali bagian foto profil */
void lihatProfil(Profil P, Word username);
/* Menampilkan profil pengguna dengan username "username" */
void displayFotoProfil(Profil P);
/* Menampilkan foto profil pengguna */

#endif