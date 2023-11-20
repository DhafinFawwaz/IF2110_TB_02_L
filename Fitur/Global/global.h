#include "../../ADT/Akun/akun.h"
// #include "../../ADT/DrafKicauan/drafkicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/TreeBalasan/treebalasan.h"

extern Akun * globalCurrentAddrAkun;
// extern DrafKicauan
extern GrafTeman globalGrafTeman;
extern ListDinKicauan globalListDinKicauan;
extern ListStatikAkun globalListStatikAkun; 
extern int globalBanyakKicauanBerbalasan;
extern TreeBalasanAddress globalTreeBalasan;


void inisialisasiGlobal();