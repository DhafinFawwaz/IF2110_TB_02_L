/* File : daftarpermintaan.h */
/* Definisi ADT Daftar Permintaan menggunakan Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef DAFTARPERMINTAAN_H
#define DAFTARPERMINTAAN_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include "../Boolean/boolean.h"
#include "../MesinKata/wordmachine.h"

/* Konstanta untuk mendefinisikan address tak terdefinisi */
#define Nil -1

/* *** DEFINISI TYPE DAFTAR PERMINTAAN *** */
typedef struct {
    int jumlah_teman;
    Word nama_minta;
} permintaan;
typedef int address;   /* indeks tabel */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct {
    permintaan * P;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxAcc;     /* Max permintaan pada daftar */
} DaftarPermintaan;

/* ********* AKSES (Selektor) ********* */
/* Jika p adalah permintaan dan D adalah DaftarPermintaan, maka akses elemen : */
#define JumlahTeman(p) (p).jumlah_teman
#define NamaMinta(p) (p).nama_minta
#define Head(D) (D).HEAD
#define Tail(D) (D).TAIL
#define HeadPermintaan(D) (D).P[(D).HEAD]
#define TailPermintaan(D) (D).P[(D).TAIL]
#define MaxPermintaan(D) (D).MaxAcc
#define Elmt(D,i) (D).P[(i)]

/* ********* Prototype ********* */
/* *** KREATOR *** */
/* Membuat daftar permintaan kosong */
void CreateDaftar(DaftarPermintaan *D, int Max);
/* *** PEMERIKSAAN NILAI *** */
/* Mengirim true jika daftar permintaan kosong */
boolean isDaftarEmpty(DaftarPermintaan D);
/* Mengirim true jika daftar permintaan sudah penuh */
boolean isDaftarFull(DaftarPermintaan D);
/* Mengirimkan banyaknya akun di dalam daftar permintaan */
int panjangDaftar(DaftarPermintaan D);
/* *** PENGUBAHAN NILAI *** */
/* Menambahkan permintaan pada daftar permintaan dengan aturan priority queue, terurut mengecil berdasarkan jumlah teman */
void enqueuePermintaan(DaftarPermintaan *D, permintaan p);
/* Menghapus permintaan teratas pada daftar permintaan */
void dequeuePermintaan(DaftarPermintaan *D, permintaan *p);
/* *** PENAMPILAN NILAI *** */
/* Menampilkan permintaan pertemanan teratas */
void displayTopPermintaan(DaftarPermintaan D);
/* Menampilkan isi daftar permintaan ke layar */
void displayDaftar(DaftarPermintaan D);

#endif