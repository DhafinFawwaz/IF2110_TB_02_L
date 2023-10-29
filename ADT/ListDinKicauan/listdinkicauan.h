#ifndef LISTDINKICAUAN_H
#define LISTDINKICAUAN_H

#include "boolean.h"
#include "../Kicauan/kicauan.h"

#define INITIAL_CAPACITY 10
#define MIN_IDX 0

typedef Kicauan* AddressKicauan;

typedef struct listdinkicauan
{
    AddressKicauan* contents;
    int nEff;
} ListDinKicauan;


boolean isEmpty(ListDinKicauan l_kicauan);

boolean isIn(int idKicau, ListDinKicauan l_kicauan);

int getLastIdx(ListDinKicauan l_kicauan);

Word getPembuatByIdx(ListDinKicauan l_kicauan, int idx);

Word getPembuatById(ListDinKicauan l_kicauan, int idKicau);

Kicauan getKicauan(ListDinKicauan l_kicauan, int idx);

int getLike(int id_kicauan, ListDinKicauan l_kicauan);

void setLike(int id_kicauan, ListDinKicauan l_kicauan, int jml_like);


#endif