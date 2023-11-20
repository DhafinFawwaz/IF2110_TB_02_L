#include "global.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"

Akun * currentAddrAkun;
// DrafKicauan
GrafTeman currentGrafTeman;

ListDinKicauan globalListKicauan;
ListStatikAkun listAkun; 
int banyakKicauanBerbalasan;
TreeBalasanAddress currentTreeBalasan;

void inisialisasiGlobal(){
    createListDinKicauan(&globalListKicauan,10);
}