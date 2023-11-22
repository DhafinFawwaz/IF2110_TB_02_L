/* File: permintaan.h */
/* Fitur Permintaan Pertemanan */

#ifndef PERMINTAAN_H
#define PERMINTAAN_H

#include "../Global/global.h"
#include "../Perintah/perintah.h"
#include "../../ADT/Akun/akun.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/DaftarPermintaan/daftarpermintaan.h"

/* *** DAFTAR PERINTAH FITUR PERMINTAAN PERTEMANAN *** */
/* I.S. terdapat pengguna yang login */
/* Mengirim permintaan pertemanan ke suatu pengguna */
void tambah_teman();
/* Melihat daftar permintaan pertemanan pengguna */
void daftar_permintaan();
/* Menentukan apakah ingin menyetujui suatu permintaan pertemanan atau tidak */
void setujui_pertemanan();

#endif