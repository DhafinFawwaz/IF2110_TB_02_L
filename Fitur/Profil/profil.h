/* File: profil.h */
/* Fitur Profil pengguna yang terdiri dari bio akun, nomor HP, weton, jenis akun, dan foto profil */

#ifndef PROFIL_H
#define PROFIL_H

#include "../Global/global.h"
#include "../Perintah/perintah.h"
#include "../../ADT/Akun/akun.h"
#include "../../ADT/Profile/profile.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"

/* *** DAFTAR PERINTAH FITUR PROFIL *** */
/* I.S. terdapat pengguna yang login */
/* Mengubah profil berdasarkan masukan pengguna */
void ganti_profil();
/* Menampilkan profil pengguna yang diinginkan */
void lihat_profil_other(Word nama);
/* Mengubah jenis akun pengguna */
void atur_jenis_akun();
/* Mengubah foto profil berdasarkan masukan pengguna */
void ubah_foto_profil();

#endif