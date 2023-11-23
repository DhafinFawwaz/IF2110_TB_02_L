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
    boolean jenis_akun;
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
/* Mambuat profil kosong dengan nilai-nilai default */
void CreateProfil(Profile *P);
/* *** PEMERIKSAAN NILAI *** */
/* Memeriksa apakah weton valid */
boolean isWetonValid(Word weton);
/* Memeriksa apakah nomor HP valid */
boolean isNomorHPValid(Word nomor_hp);
/* Memeriksa apakah jenis akun privat */
boolean isAkunPrivat(Profile P);
/* Memeriksa apakah jenis akun publik */
boolean isAkunPublik(Profile P);
/* *** PENGUBAHAN NILAI *** */
/* Mengubah bio berdasarkan masukan pengguna */
void changeBio(Profile *P, Word w);
/* Mengubah nomor HP berdasarkan masukan pengguna */
void changeNomorHP(Profile *P, Word w);
/* Mengubah weton berdasarkan masukan pengguna */
void changeWeton(Profile *P, Word w);
/* Mengubah jenis akun pengguna */
void changeJenisAkun(Profile *P);
/* *** PENAMPILAN NILAI *** */
/* Menampilkan profil pengguna kecuali bagian foto profil */
void displayProfil(Profile P, Word username);
/* Menampilkan profil pengguna dengan username "username" */
void lihatProfil(Profile P, Word username);

#endif