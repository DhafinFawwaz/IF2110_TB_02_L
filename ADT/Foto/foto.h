#ifndef FOTOPROFILE_H
#define FOTOPROFILE_H

#include "pixel.h"

/* Ukuran maksimum baris dan kolom */
#define FOTO_ROW_CAP 5
#define FOTO_COL_CAP 5

typedef int IdxType; /* Index baris, kolom */

typedef struct foto
{
    Pixel buffer[FOTO_ROW_CAP][FOTO_COL_CAP];
} Foto;

void CreateFoto(Foto* foto);
void setPixel(Foto* foto, IdxType row, IdxType col, Pixel pixel);
void setColor(Foto* foto, IdxType row, IdxType col, char c);
void setVal(Foto* foto, IdxType row, IdxType col, char val);
void displayFoto(Foto foto);
void printPixel(Pixel p);
#endif