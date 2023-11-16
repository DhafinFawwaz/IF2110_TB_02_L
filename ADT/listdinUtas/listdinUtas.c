
#include "listdinUtas.h"
#include <stdio.h>
#include <stdlib.h>

Utas newNode(isi_utas val){
	Utas p = (NodeUtas*)malloc(sizeof(NodeUtas));
	INFO(p) = val;
	NEXT(p) = NULL;
	return p;
}

void Utas_CreateUtas(Utas *l){
	*l = NULL;
}

boolean Utas_isEmpty(Utas l){
	return (l == NULL);
}

boolean Utas_compareIsi(isi_utas iu1, isi_utas iu2){
	return (compareDateTime(WAKTU(iu1), WAKTU(iu2)) && compareWord(TEXT(iu1), TEXT(iu2)));
}

void Utas_setUtasFromWord(Utas *u, Word w){
	TEXT(*u) = currentWord;
	SetToCurrentDateTime(&WAKTU(*u));
}

isi_utas Utas_getElmt(Utas l, int idx){
	int ctr = 0;
	Utas p = l;
	while (ctr<idx) {
		ctr++;
		p = NEXT(p);
	}

	return INFO(p);
}

void Utas_setElmt(Utas *l, int idx, isi_utas val){
	int ctr = 0;
	Utas p = *l;
	while (ctr<idx) {
		ctr++;
		p = NEXT(p);
	}

	INFO(p) = val;
}

int Utas_indexOf(Utas l, isi_utas val){
	int idx = 0;
	Utas p = l;
	boolean found = false;

	while ((p != NULL) && (!found)){
		if (Utas_compareIsi(INFO(p), INFO(val))) found = true;
		else{
		 	idx++;
		 	p = NEXT(p);
		}
	}
	
	if (found) return idx;
	else return IDX_UNDEF;
}

void Utas_insertFirst(Utas *l, isi_utas val){
	Utas p;
	p = newNode(val);
	if (p != NULL) {
		NEXT(p) = *l;
		*l = p;
	}
}

void Utas_insertLast(Utas *l, isi_utas val){
	if (Utas_isEmpty(*l)) Utas_insertFirst(l, val);
	else {
		Utas p = newNode(val);
		if (p != NULL) {
			Utas last = *l;
			while (NEXT(last) != NULL) {
				last = NEXT(last);
			}
			NEXT(last) = p;
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
				loc = NEXT(loc);
			}
			NEXT(p) = NEXT(loc);
			NEXT(loc) = p;
		}
	}
}

void Utas_deleteFirst(Utas *l, isi_utas *val){
	Utas p = *l;
	*val = INFO(p);
	*l = NEXT(p);
	free(p);
}

void Utas_deleteLast(Utas *l, isi_utas *val){
	Utas p, loc;
	
	p = *l;
	loc = NULL;
	while (NEXT(p) != NULL) {
		loc = p;
		p = NEXT(p);
	}
	// p->next = NULL;
	if (loc == NULL) {
		*l = NULL;
	}
	else {
		NEXT(loc) = NULL;
	}

	*val = INFO(p);
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
			loc = NEXT(loc);
		}
		//ctr = idx-1
		p = NEXT(loc);
		*val = INFO(p);
		NEXT(loc) = NEXT(p);
		free(p);
	}

}

int length(Utas l){
	int ctr = 0;
	Utas p = l;
	while (p != NULL){
		ctr++;
		p = NEXT(p);
	}
	return ctr;
}

Utas Utas_concatUtas(Utas l1, Utas l2) {
	Utas p;
	Utas l3;

	Utas_CreateUtas(&l3);
	p = l1;
	while (p != NULL) {
		Utas_insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	p = l2;
	while (p != NULL) {
		Utas_insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	return l3;
}