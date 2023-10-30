#include "../GrafTeman/grafteman.h"

GrafTeman currentGrafTemn; // Global variable

// elemen[i][j] semuanya 0
void CreateGrafTeman(GrafTeman *g, int jumlahAkun){
    GRAFTEMAN_SIZE(*g) = jumlahAkun;
}

// elemen[i][j] = isBerteman
void setGrafTeman(GrafTeman *g, int i, int j, boolean isBerteman){
    GRAFTEMAN_ELMT(*g, i, j) = isBerteman;
}

// print
void displayGrafTeman(GrafTeman g){
    int i = 0, j = 0;
    for(i = 0; i < GRAFTEMAN_SIZE(g); i++){
        for(j = 0; j < GRAFTEMAN_SIZE(g); j++){
            printf("%d ", GRAFTEMAN_ELMT(g, i, j));
        }
        printf("\n");
    }
}

// cek apakah akun1 berteman dengan akun2. Tapi bukan berarti akun2 berteman dengan akun1
boolean isAkunBerteman(GrafTeman g, Akun akun1, Akun akun2){
    return GRAFTEMAN_ELMT(g, akun1.id, akun2.id);
}
