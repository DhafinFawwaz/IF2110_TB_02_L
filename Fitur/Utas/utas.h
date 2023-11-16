
#include "../../ADT/listdinUtas/listdinUtas.h"
#include "../Perintah/perintah.h"

extern Word currentUtas;

//Fungsi dan Prosedur UTAS
void UTAS(int IDKicau);
void SAMBUNG_UTAS(int IDUtas, int index);
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);

//Fungsi lain
boolean isUtasIsInListKicauan(IDUtas);
Utas getUtasInListKicauan(int IDKicau);