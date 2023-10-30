/* File: akun.h */

#ifndef AKUN_H
#define AKUN_H

#include "boolean.h"
#include "../Profile/profile.h"
#include "../MesinKata/wordmachine.h"
#include "../StackDin/stackdin.h"
#include "../PrioQueue/prioqueue.h"

#define IDMax 20
typedef struct akun
{
    int id;
    Profile profil;
    Word nama;
    Word password;
    StackDin* list_daftar_kicauan;
    PrioQueue list_permintaan_pertemanan;
    boolean isPublic;
} Akun;

/* ********* AKSES (Selektor) ********* */
/* Jika A adalah Akun, maka akses elemen : */
#define Username(A) (A).username
#define Password(A) (A).password

extern Akun currentAkun; // Global variable
void CreateAkun(Akun* akun);
void DisplayAkun(Akun akun);
void DebugListAkun();

boolean jenisAkunToBoolean(Word w);
Word jenisAkunToWord(boolean b);


#endif