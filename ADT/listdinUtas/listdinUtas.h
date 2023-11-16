/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah Utas */

#ifndef listlinier_H
#define listlinier_H

#include "../Boolean/boolean.h"
#include "../DateTime/datetime.h"
#include "../MesinKata/wordmachine.h"
#include "../ListDinKicauan/listdinkicauan.h"

/* Definisi isi_utas */
typedef struct isiUtas {
	DateTime waktu;
	Word text;
} isi_utas;

/* Definisi Utas :  */
typedef struct node_utas* Utas;
typedef struct node_utas {
    isi_utas info;
    Utas next_utas;
} NodeUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next_utas
#define TEXT(p) (p)->info.text
#define WAKTU(p) (p)->info.waktu

Utas newNode(ElType isiUtas);

#define IDX_UNDEF (-1)

void Utas_CreateUtas(Utas *u);
boolean Utas_isEmpty(Utas u);
boolean Utas_compareIsi(ElType iu1, ElType iu2); 
void Utas_setUtasFromWord(Utas *u, Word w);
ElType Utas_getElmt(Utas u, int idUtas);
void Utas_setElmt(Utas *u, int idUtas, ElType isiUtas);
int Utas_indexOf(Utas u, ElType isiUtas);

void Utas_insertFirst(Utas *u, ElType isiUtas);
void Utas_insertLast(Utas *u, ElType isiUtas);
void Utas_insertAt(Utas *u, ElType isiUtas, int idUtas);
void Utas_deleteFirst(Utas *u, ElType *isiUtas);
void Utas_deleteLast(Utas *u, ElType *isiUtas);
void Utas_deleteAt(Utas *u, int idUtas, ElType *isiUtas);

int length(Utas u);

Utas Utas_concatUtas(Utas u1, Utas u2) ;

#endif