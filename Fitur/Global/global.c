#include "global.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/Boolean/boolean.h"

boolean globalIsRunning = true;
boolean isLogin = false;

Akun * globalCurrentAddrAkun;
GrafTeman globalGrafTeman;
ListDinKicauan globalListDinKicauan;
ListStatikAkun globalListStatikAkun; 

int globalBanyakKicauanBerbalasan = 0;
int globalBanyakKicauanBerutas = 0; // jangan lupa increment 1
int globalLastTreeBalasanId = 0; // jangan lupa set last id pas inisialisasi
int globalBanyakPenggunaBerDraf = 0;
int globalBanyakPermintaanPertemanan;

void inisialisasiGlobal(){
    createListDinKicauan(&globalListDinKicauan,10);
    listStatikAkun_Create(&globalListStatikAkun);
    CreateAkun(globalCurrentAddrAkun);
}
