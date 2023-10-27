//KEKNYA GAJADI DIPAKE DEH
#ifndef LISTDINMAP_H
#define LISTDINMAP_H

#include<stdio.h>
// #include"boolean.h"
// #include"../Map/map.h"

#define INITIAL_CAP 3;

typedef MapEntry Eltype;

typedef struct listdinmap
{
    MapEntry* contents;
    int capacity;
    int nEff;
} ListDinMap;


#endif