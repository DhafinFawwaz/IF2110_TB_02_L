/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah Utas */

#ifndef listlinier_H
#define listlinier_H

#include "../Boolean/boolean.h"
#include "../DateTime/datetime.h"
#include "../MesinKata/wordmachine.h"

/* Definisi isi_utas */
typedef struct isiUtas {
	DateTime waktu;
	Word text;
} isi_utas;

/* Definisi Utas :  */
typedef struct node_utas* Utas;
typedef struct node_utas {
    isi_utas info_utas;
    Utas next_utas;
} NodeUtas;

#define INFO_UTAS(p) (p)->info_utas
#define NEXT_UTAS(p) (p)->next_utas
#define TEXT_UTAS(p) (p)->info_utas.text
#define WAKTU_UTAS(p) (p)->info_utas.waktu

#define IDX_UNDEF (-1)

//Membuat node Utas baru; NULL jika memory penuh
Utas newNode(isi_utas isiUtas);

//Inisialisasi Utas
void Utas_CreateUtas(Utas *u);
//Cek apakah Utas NULL (kosong) atau bukan
boolean Utas_isEmpty(Utas u);
//Cek apakah isi kedua utas sama, tidak termasuk NEXT_UTAS
boolean Utas_compareUtas(Utas u1, Utas u2);
//Membuat Utas dari Word
void Utas_setUtasFromWord(Utas *u, Word w);

//Manipulasi Utas
void Utas_insertFirst(Utas *u, isi_utas isiUtas);
void Utas_insertLast(Utas *u, isi_utas isiUtas);
void Utas_insertAt(Utas *u, isi_utas isiUtas, int idUtas);
void Utas_deleteFirst(Utas *u, isi_utas *isiUtas);
void Utas_deleteLast(Utas *u, isi_utas *isiUtas);
void Utas_deleteAt(Utas *u, int idUtas, isi_utas *isiUtas);

//Mengeluarkan panjang Utas
int Utas_length(Utas u);

//Mengeluarkan sebagian isi utas untuk keperluan testing
void displayTestUtas(Utas u);

#endif