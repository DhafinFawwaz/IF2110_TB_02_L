#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "../LinkedListValue/linkedlistvalue.h"

#define VAL_UNDEF NULL;
#define INITIAL_CAP 3;

typedef int Tagar;
typedef Tagar KeyType;
typedef LinkedListValue ElType;

typedef struct map_entry
{
    KeyType key;
    ElType value;
} MapEntry;

typedef struct mapdin
{
    MapEntry* buffer;
    int capacity;
    int nEff;
} MapDin;

#define ELMT_KEY(m,i) m.buffer[i].key
#define ELMT_VALUE(m,i) m.buffer[i].value

void createMapDin();

void expandMapDin();

void shrinkMapDin();

KeyType hash();

void set();

void find();

void rehashing();

#endif


