/* File: profile.h */
/* ADT Profile yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil dari pengguna */

#ifndef PROFILE_H
#define PROFILE_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "../Foto/foto.h"
#include "../Boolean/boolean.h"
#include "../MesinKata/wordmachine.h"

/* *** DEFINISI TYPE PROFILE *** */
typedef struct profile {
    Word bio;
    Word nomor_hp;
    Word weton;
    Word jenis_akun;
    Foto foto;
} Profile;

/* ********* AKSES (Selektor) ********* */
/* Jika P adalah Profile, maka akses elemen : */
#define Bio(P) (P).bio
#define NomorHP(P) (P).nomor_hp
#define Weton(P) (P).weton
#define JenisAkun(P) (P).jenis_akun
#define Foto(P) (P).foto

/* *** PROTOTYPE *** */
/* *** PEMBUATAN DENGAN NILAI DEFAULT *** */
void CreateProfil(Profile *P);
/* Mambuat profil kosong dengan nilai-nilai default */
/* *** PEMERIKSAAN NILAI *** */
boolean isWetonValid(Word weton);
/* Memeriksa apakah weton valid */
boolean isNomorHPValid(Word nomor_hp);
/* Memeriksa apakah nomor HP valid */
boolean isAkunPrivat(Profile P);
/* Memeriksa apakah jenis akun privat */
boolean isAkunPublik(Profile P);
/* Memeriksa apakah jenis akun publik */
/* *** PENGUBAHAN NILAI *** */
void changeBio(Profile *P, Word w);
/* Mengubah bio berdasarkan masukan pengguna */
void changeNomorHP(Profile *P, Word w);
/* Mengubah nomor HP berdasarkan masukan pengguna */
void changeWeton(Profile *P, Word w);
/* Mengubah weton berdasarkan masukan pengguna */
void changeJenisAkun(Profile *P);
/* Mengubah jenis akun pengguna */
/* *** PENAMPILAN NILAI *** */
void displayProfil(Profile P, Word username);
/* Menampilkan profil pengguna kecuali bagian foto profil */
void lihatProfil(Profile P, Word username);
/* Menampilkan profil pengguna dengan username "username" */

#endif