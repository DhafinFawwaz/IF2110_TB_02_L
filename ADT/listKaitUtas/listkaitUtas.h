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

Utas newNode(isi_utas isiUtas);

#define IDX_UNDEF (-1)

void Utas_CreateUtas(Utas *u);
boolean Utas_isEmpty(Utas u);
boolean Utas_compareUtas(Utas u1, Utas u2); 
void Utas_setUtasFromWord(Utas *u, Word w);
isi_utas Utas_getElmt(Utas u, int idUtas);
void Utas_setElmt(Utas *u, int idUtas, isi_utas isiUtas);

void Utas_insertFirst(Utas *u, isi_utas isiUtas);
void Utas_insertLast(Utas *u, isi_utas isiUtas);
void Utas_insertAt(Utas *u, isi_utas isiUtas, int idUtas);
void Utas_deleteFirst(Utas *u, isi_utas *isiUtas);
void Utas_deleteLast(Utas *u, isi_utas *isiUtas);
void Utas_deleteAt(Utas *u, int idUtas, isi_utas *isiUtas);

int length(Utas u);

Utas Utas_concatUtas(Utas u1, Utas u2) ;
void displayTestUtas(Utas u);

#endif