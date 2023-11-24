/* File: akun.h */

#ifndef AKUN_H
#define AKUN_H

#include "../Boolean/boolean.h"
#include "../Profile/profile.h"
#include "../MesinKata/wordmachine.h"
#include "../StackBerkaitDraf/stackberkaitdraf.h"
#include "../DaftarPermintaan/daftarpermintaan.h"
#include "../StackBerkaitDraf/stackberkaitdraf.h"

#define IDMax 20
typedef struct akun
{
    int id;
    Profile profil;
    Word username;
    Word password;
    DaftarPermintaan daftar_permintaan_pertemanan;
    StackBerkaitDraf draf_kicauan;
} Akun;

/* ********* AKSES (Selektor) ********* */
/* Jika A adalah Akun, maka akses elemen : */
#define Username(A) (A).username
#define Password(A) (A).password
#define Profil(A) (A).profil
#define DaftarPermintaan(A) (A).daftar_permintaan_pertemanan

// Membuat atau menginisialisasi Akun baru
void CreateAkun(Akun* akun);

// Menampilkan informasi Akun ke layar
void DisplayAkun(Akun akun);

// Menampilkan informasi debug dari daftar Akun
void DebugListAkun();

// Mengonversi tipe data Word ke boolean, Word berisi informasi jenis Akun
boolean jenisAkunToBoolean(Word w);

// Mengonversi boolean ke tipe data Word, boolean merepresentasikan jenis Akun
Word jenisAkunToWord(boolean b);

#endif