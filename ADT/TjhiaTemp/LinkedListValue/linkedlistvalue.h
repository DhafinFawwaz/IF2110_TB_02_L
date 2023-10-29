#ifndef LINKEDLISTVALUE_H
#define LINKEDLISTVALUE_H

#include <stdio.h>
// #include "boolean.h"

// typedef Kicauan* ElType;
typedef struct node* Address;
typedef Address LinkedListValue;

typedef struct node 
{
    // ElType address_kicauan;
    Address next;
} Node;

// #define ADDRESS_KICAUAN(p) (p)->address_kicauan
#define NEXT(p) (p)->next;
// #define TAGAR(p) (((p)->address.kicauan)+ sizeof() + ... )->tagar;

// Address newNode(ElType addresKicauan);

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

#endif