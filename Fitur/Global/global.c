#include "global.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/Boolean/boolean.h"

boolean isLogin = false;
Akun * globalCurrentAddrAkun;
// DrafKicauan
GrafTeman currentGrafTeman;
boolean isLoginGlobal = false;

ListDinKicauan globalListKicauan;
ListStatikAkun listAkun; 
int banyakKicauanBerbalasan;
TreeBalasanAddress currentTreeBalasan;

void inisialisasiGlobal(){
    createListDinKicauan(&globalListKicauan,10);
    listStatikAkun_Create(&listAkun);
}
