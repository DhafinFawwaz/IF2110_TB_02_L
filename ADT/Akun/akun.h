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

void CreateAkun(Akun* akun);
void DisplayAkun(Akun akun);
void DebugListAkun();

boolean jenisAkunToBoolean(Word w);
Word jenisAkunToWord(boolean b);


#endif