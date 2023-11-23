
#include "dsuKelompokTeman.h"

int kelompokTeman_find(kelompokTeman kt, int idAkun) {
    if (kt.parent[idAkun] == idAkun) {
        return idAkun;
    }
    else {
        return kelompokTeman_find(kt, kt.parent[idAkun]);
    }
}

void kelompokTeman_union(kelompokTeman* kt, int idAkun1, int idAkun2) {
    int irep = kelompokTeman_find(*kt, idAkun1);
    int jrep = kelompokTeman_find(*kt, idAkun2);

    (*kt).parent[irep] = jrep;
}