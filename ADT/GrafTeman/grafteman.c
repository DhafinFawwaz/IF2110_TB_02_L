#include <stdio.h>
#include "../GrafTeman/grafteman.h"
#include "../MesinKata/wordmachine.h"

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
            // Handle last element
            if(j == GRAFTEMAN_SIZE(g) - 1)
                printf("%d", GRAFTEMAN_ELMT(g, i, j));
            else
                printf("%d ", GRAFTEMAN_ELMT(g, i, j));
        }
        printf("\n");
    }
}

// cek apakah akun1 berteman dengan akun2. Tapi bukan berarti akun2 berteman dengan akun1
boolean isAkunBerteman(GrafTeman g, Akun akun1, Akun akun2){
    return (GRAFTEMAN_ELMT(g, akun1.id, akun2.id) && GRAFTEMAN_ELMT(g, akun2.id, akun1.id));
}

boolean isAkunMintaBerteman(GrafTeman g, Akun akun1, Akun akun2){
    return GRAFTEMAN_ELMT(g, akun1.id, akun2.id);
}

boolean isAkunTidakBerteman(GrafTeman g, Akun akun1, Akun akun2){
    return GRAFTEMAN_ELMT(g, akun1.id, akun2.id);
}


// resize graf, sekalian kalau size baru lebih besar, jadiin false semua
void resizeGrafTeman(GrafTeman *g, int newSize){
    int currentSize = GRAFTEMAN_SIZE(*g);
    GRAFTEMAN_SIZE(*g) = newSize;
    int i = 0, j = 0;
    
    // bottomleft to bottomright
    for(i = currentSize; i < newSize; i++){
        for(j = 0; j < newSize; j++){
            GRAFTEMAN_ELMT(*g, i, j) = false;
        }
    }

    // topright
    for(i = 0; i < currentSize; i++){
        for(j = currentSize; j < newSize; j++){
            GRAFTEMAN_ELMT(*g, i, j) = false;
        }
    }
}

// Hitung banyak teman
int countTeman(GrafTeman g, Akun akun){
    int i = 0;
    int count = 0;
    for(i = 0; i < GRAFTEMAN_SIZE(g); i++){
        if(GRAFTEMAN_ELMT(g, akun.id, i)){
            count++;
        }
    }
    return count;
}

// Hitung banyak teman akun yang temannya juga berteman dengan akun
int countSalingTeman(GrafTeman g, Akun akun){
    int i = 0;
    int count = 0;
    for(i = 0; i < GRAFTEMAN_SIZE(g); i++){
        if(GRAFTEMAN_ELMT(g, akun.id, i) && GRAFTEMAN_ELMT(g, i, akun.id)){ // cek index akun.id 
            count++;
        }
    }
    return count;
}
