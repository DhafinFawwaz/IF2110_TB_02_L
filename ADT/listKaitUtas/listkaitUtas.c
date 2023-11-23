
#include "listkaitUtas.h"
#include <stdio.h>
#include <stdlib.h>

Utas newNode(isi_utas val){
	Utas p = (NodeUtas*)malloc(sizeof(NodeUtas));
	INFO_UTAS(p) = val;
	NEXT_UTAS(p) = NULL;
	return p;
}

void Utas_CreateUtas(Utas *l){
	*l = NULL;
}

boolean Utas_isEmpty(Utas l){
	return (l == NULL);
}

boolean Utas_compareUtas(Utas u1, Utas u2){
	return (compareDateTime(WAKTU_UTAS(u1), WAKTU_UTAS(u2)) && compareWord(TEXT_UTAS(u1), TEXT_UTAS(u2)));
}

void Utas_setUtasFromWord(Utas *u, Word w){
	Utas p = (NodeUtas*)malloc(sizeof(NodeUtas));
	TEXT_UTAS(p) = w;
	NEXT_UTAS(p) = NULL;
	SetToCurrentDateTime(&WAKTU_UTAS(p));
	*u = p;
}

isi_utas Utas_getElmt(Utas l, int idx){
	int ctr = 0;
	Utas p = l;
	while (ctr<idx) {
		ctr++;
		p = NEXT_UTAS(p);
	}

	return INFO_UTAS(p);
}

void Utas_setElmt(Utas *l, int idx, isi_utas val){
	int ctr = 0;
	Utas p = *l;
	while (ctr<idx) {
		ctr++;
		p = NEXT_UTAS(p);
	}

	INFO_UTAS(p) = val;
}

void Utas_insertFirst(Utas *l, isi_utas val){
	Utas p;
	p = newNode(val);
	if (p != NULL) {
		NEXT_UTAS(p) = *l;
		*l = p;
	}
}

void Utas_insertLast(Utas *l, isi_utas val){
	if (Utas_isEmpty(*l)) Utas_insertFirst(l, val);
	else {
		Utas p = newNode(val);
		if (p != NULL) {
			Utas last = *l;
			while (NEXT_UTAS(last) != NULL) {
				last = NEXT_UTAS(last);
			}
			NEXT_UTAS(last) = p;
		}
	}
}

void Utas_insertAt(Utas *l, isi_utas val, int idx){
	if (idx == 0) Utas_insertFirst(l, val);
	else{
		Utas p = newNode(val);
		if (p != NULL){
			int ctr = 0;
			Utas loc = *l;
			while (ctr<(idx-1)){
				ctr++;
				loc = NEXT_UTAS(loc);
			}
			NEXT_UTAS(p) = NEXT_UTAS(loc);
			NEXT_UTAS(loc) = p;
		}
	}
}

void Utas_deleteFirst(Utas *l, isi_utas *val){
	Utas p = *l;
	*val = INFO_UTAS(p);
	*l = NEXT_UTAS(p);
	free(p);
}

void Utas_deleteLast(Utas *l, isi_utas *val){
	Utas p, loc;
	
	p = *l;
	loc = NULL;
	while (NEXT_UTAS(p) != NULL) {
		loc = p;
		p = NEXT_UTAS(p);
	}
	// p->next = NULL;
	if (loc == NULL) {
		*l = NULL;
	}
	else {
		NEXT_UTAS(loc) = NULL;
	}

	*val = INFO_UTAS(p);
	free(p);
}

void Utas_deleteAt(Utas *l, int idx, isi_utas *val){
	int ctr;
	Utas p, loc;
	
	if (idx == 0){
		Utas_deleteFirst(l,val);
	}
	else{
		ctr = 0;
		loc = *l;
		while (ctr < (idx-1)) {
			ctr++;
			loc = NEXT_UTAS(loc);
		}
		//ctr = idx-1
		p = NEXT_UTAS(loc);
		*val = INFO_UTAS(p);
		NEXT_UTAS(loc) = NEXT_UTAS(p);
		free(p);
	}

}

int Utas_length(Utas l){
	int ctr = 0;
	Utas p = l;
	while (p != NULL){
		ctr++;
		p = NEXT_UTAS(p);
	}
	return ctr;
}

Utas Utas_concatUtas(Utas l1, Utas l2) {
	Utas p;
	Utas l3;

	Utas_CreateUtas(&l3);
	p = l1;
	while (p != NULL) {
		Utas_insertLast(&l3, INFO_UTAS(p));
		p = NEXT_UTAS(p);
	}

	p = l2;
	while (p != NULL) {
		Utas_insertLast(&l3, INFO_UTAS(p));
		p = NEXT_UTAS(p);
	}

	return l3;
}

void displayTestUtas(Utas u){
	Utas p;

	printf("[");

	if (!Utas_isEmpty(u)){
		p = u;
		while (NEXT_UTAS(p) != NULL){
			printWord(TEXT_UTAS(p));
			//DisplayDateTime(WAKTU_UTAS(p));
			printf(", ");
			p = NEXT_UTAS(p);
		}
		printWord(TEXT_UTAS(p));
	}

	printf("]");
}