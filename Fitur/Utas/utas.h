
#include "../../ADT/listdinUtas/listdinUtas.h"
#include "../Perintah/perintah.h"

extern Word currentUtas;

//Fungsi dan Prosedur UTAS
Utas buatUtas(int IDKicau);
void sambungUtas(int IDUtas, int index);
void hapusUtas(int IDUtas, int index);
void cetakUtas(int IDUtas);

//Fungsi lain
boolean isUtasIsInListKicauan(IDUtas);
Utas getUtasInListKicauan(int IDKicau);
