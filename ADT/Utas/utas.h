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
	Word text_utas;
} isi_utas;

/* Definisi Utas :  */
typedef isi_utas ElType;
typedef struct node* Utas;
typedef struct node {
    ElType info;
    Utas next_utas;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next_utas

Utas newNode(ElType isiUtas);

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

void Utas_CreateUtas(Utas *u);
boolean Utas_isEmpty(Utas u);
ElType Utas_getElmt(Utas u, int idUtas);
void Utas_setElmt(Utas *u, int idUtas, ElType isiUtas);
int Utas_indexOf(Utas u, ElType isiUtas);

void Utas_insertFirst(Utas *u, ElType isiUtas);
void Utas_insertLast(Utas *u, ElType isiUtas);
void Utas_insertAt(Utas *u, ElType isiUtas, int idUtas);
void Utas_deleteFirst(Utas *u, ElType *isiUtas);
void Utas_deleteLast(Utas *u, ElType *isiUtas);
void Utas_deleteAt(Utas *u, int idUtas, ElType *isiUtas);

void Utas_displayUtas(Utas u);
int length(Utas u);

Utas Utas_concatUtas(Utas u1, Utas u2) ;

/*Todo: */
boolean Utas_isiUtasEQ(ElType isi_utas1, ElType isi_utas2); /*Kalau Utas_indexOf diperlukan*/




#endif