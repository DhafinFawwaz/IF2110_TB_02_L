#include "../../ADT/Akun/akun.h"
// #include "../../ADT/DrafKicauan/drafkicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/Boolean/boolean.h"

extern Akun * globalCurrentAddrAkun;
// extern DrafKicauan
extern GrafTeman globalGrafTeman;
extern ListDinKicauan globalListDinKicauan;
extern ListStatikAkun globalListStatikAkun; 
extern int globalBanyakKicauanBerbalasan;
extern TreeBalasanAddress globalTreeBalasan;

extern boolean isLoginGlobal;
extern GrafTeman globalGrafTeman;
extern ListDinKicauan globalListDinKicauan;
extern ListStatikAkun globalListStatikAkun; 
extern int banyakKicauanBerbalasan;
extern TreeBalasanAddress globalTreeBalasan;

void inisialisasiGlobal();