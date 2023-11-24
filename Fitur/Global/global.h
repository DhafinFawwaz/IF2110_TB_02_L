#include "../../ADT/Akun/akun.h"
// #include "../../ADT/DrafKicauan/drafkicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/Boolean/boolean.h"
#include "../../ADT/DSUKelompokTeman/dsuKelompokTeman.h"
#include "../../ADT/MapDin/mapdin.h"

extern boolean globalIsRunning;
extern boolean isLogin;

extern Akun * globalCurrentAddrAkun;
extern GrafTeman globalGrafTeman;
extern ListDinKicauan globalListDinKicauan;
extern ListStatikAkun globalListStatikAkun; 
extern MapDin globalMapTagarKicauan;
// extern DrafKicauan
extern TreeBalasanAddress globalTreeBalasan;
extern kelompokTeman globalKelompokTeman;

extern int globalBanyakKicauanBerbalasan;
extern int globalBanyakKicauanBerutas;
extern int globalLastTreeBalasanId;
extern int globalBanyakPenggunaBerDraf;
extern int globalBanyakPermintaanPertemanan;

void inisialisasiGlobal();