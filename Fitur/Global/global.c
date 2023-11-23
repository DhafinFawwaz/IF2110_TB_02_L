#include "global.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/Boolean/boolean.h"

boolean globalIsRunning = true;
boolean isLogin = false;
Akun * globalCurrentAddrAkun;
// DrafKicauan
GrafTeman globalGrafTeman;
boolean isLoginGlobal = false;

ListDinKicauan globalListDinKicauan;
ListStatikAkun globalListStatikAkun; 
int banyakKicauanBerbalasan;
int globalBanyakKicauanBerutas;
TreeBalasanAddress globalTreeBalasan;
int globalLastTreeBalasanId = 0;

int globalBanyakPenggunaBerDraf = 0;

void inisialisasiGlobal(){
    createListDinKicauan(&globalListDinKicauan,10);
    listStatikAkun_Create(&globalListStatikAkun);
    CreateAkun(globalCurrentAddrAkun);
}
