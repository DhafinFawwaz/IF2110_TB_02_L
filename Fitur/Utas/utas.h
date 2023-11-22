
#include "../../ADT/listKaitUtas/listkaitUtas.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../Perintah/perintah.h"

#define UtasInKicau(id) (globalListDinKicauan.contents[id-1]).firstUtas

extern Word currentUtas;

//Fungsi dan Prosedur UTAS
void buatUtas(int IDKicau);
void sambungUtas(int IDUtas, int index);
void hapusUtas(int IDUtas, int index);
void cetakUtas(int IDUtas);

//Fungsi lain
boolean isUtasIsInListKicauan(IDUtas);
Utas getUtasInListKicauan(int IDKicau);
