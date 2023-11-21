#include "global.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/Boolean/boolean.h"

boolean isLogin = false;
Akun * globalCurrentAddrAkun;
// DrafKicauan
GrafTeman globalGrafTeman;
boolean isLoginGlobal = false;

ListDinKicauan globalListKicauan;
ListStatikAkun globalListStatikAkun; 
int banyakKicauanBerbalasan;
TreeBalasanAddress globalTreeBalasan;

void inisialisasiGlobal(){
    createListDinKicauan(&globalListKicauan,10);
    listStatikAkun_Create(&globalListStatikAkun);
}
