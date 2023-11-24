#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <math.h>
#include "../Boolean/boolean.h"
#include "../ListDinKicauan/listdinkicauan.h"

#define VAL_UNDEF NULL;
#define INITIAL_CAP 3;
typedef struct nodeValMap* AddressNodeMap;

typedef struct nodeValMap 
{
    Kicauan kicauan;
    AddressNodeMap next;
} NodeValMap;

#define INFO_VAL_MAP(p) (p)->kicauan
#define NEXT_VAL_MAP(p) (p)->next

typedef struct map_entry
{
    int mapKey;
    Word tagar;
    AddressNodeMap value;
} MapEntry;


typedef struct mapdin
{
    MapEntry* buffer;
    int capacity;
    int nEff;
} MapDin;

#define BUFFER_MAP(m) (m).buffer
#define ELMT_MAP_KEY(m,i) (m).buffer[i].mapKey
#define ELMT_MAP_VALUE(m,i) (m).buffer[i].value
#define ELMT_MAP_TAGAR(m,i) (m).buffer[i].tagar
#define CAP_MAPDIN(m) (m).capacity
#define NEFF_MAPDIN(m) (m).nEff

AddressNodeMap newNodeValMap(Kicauan k);

void insertFirstListValue(AddressNodeMap * l, Kicauan k);

void createMapDin(MapDin * m, int cap);

void expandMapDin(MapDin * m);

int hash(Word tagW, int capMap);

// MapDin pasti tidak kosong
void insertMapDin(MapDin * m, Kicauan k);

// MapDin pasti tiak kosong
int findInsertIdx(MapDin m, Word tag, int key);

void rehashing(MapDin * m);

boolean isFullMapDin(MapDin m);

#endif


