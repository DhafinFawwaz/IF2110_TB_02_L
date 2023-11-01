
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val){
	Address p = (Node*)malloc(sizeof(Node));
	INFO(p) = val;
	NEXT(p) = NULL;
	return p;
}

void CreateList(List *l){
	*l = NULL;
}

boolean isEmpty(List l){
	return (l == NULL);
}

ElType getElmt(List l, int idx){
	int ctr = 0;
	Address p = l;
	while (ctr<idx) {
		ctr++;
		p = NEXT(p);
	}

	return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
	int ctr = 0;
	Address p = *l;
	while (ctr<idx) {
		ctr++;
		p = NEXT(p);
	}

	INFO(p) = val;
}

int indexOf(List l, ElType val){
	int idx = 0;
	Address p = l;
	boolean found = false;

	while ((p != NULL) && (!found)){
		if (INFO(p) == val) found = true;
		else{
			idx++;
			p = NEXT(p);
		}
	}
	
	if (found) return idx;
	else return IDX_UNDEF;
}

void insertFirst(List *l, ElType val){
	Address p;
	p = newNode(val);
	if (p != NULL) {
		NEXT(p) = *l;
		*l = p;
	}
}

void insertLast(List *l, ElType val){
	if (isEmpty(*l)) insertFirst(l, val);
	else {
		Address p = newNode(val);
		if (p != NULL) {
			Address last = *l;
			while (NEXT(last) != NULL) {
				last = NEXT(last);
			}
			NEXT(last) = p;
		}
	}
}

void insertAt(List *l, ElType val, int idx){
	if (idx == 0) insertFirst(l, val);
	else{
		Address p = newNode(val);
		if (p != NULL){
			int ctr = 0;
			Address loc = *l;
			while (ctr<(idx-1)){
				ctr++;
				loc = NEXT(loc);
			}
			NEXT(p) = NEXT(loc);
			NEXT(loc) = p;
		}
	}
}

void deleteFirst(List *l, ElType *val){
	Address p = *l;
	*val = INFO(p);
	*l = NEXT(p);
	free(p);
}

void deleteLast(List *l, ElType *val){
	Address p, loc;
	
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

void deleteAt(List *l, int idx, ElType *val){
	int ctr;
	Address p, loc;
	
	if (idx == 0){
		deleteFirst(l,val);
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

void displayList(List l) {

	printf("[");

	Address p = l;
	if (!isEmpty(p)){
		while (NEXT(p) != NULL) {
			printf("%d,", INFO(p));
			p = NEXT(p);
		}

		printf("%d", INFO(p));
	}

	printf("]");

}

int length(List l){
	int ctr = 0;
	Address p = l;
	while (p != NULL){
		ctr++;
		p = NEXT(p);
	}
	return ctr;
}

List concat(List l1, List l2) {
	Address p;
	List l3;

	CreateList(&l3);
	p = l1;
	while (p != NULL) {
		insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	p = l2;
	while (p != NULL) {
		insertLast(&l3, INFO(p));
		p = NEXT(p);
	}

	return l3;
}
