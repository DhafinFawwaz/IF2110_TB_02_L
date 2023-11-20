#ifndef GRAFTEMAN_H
#define GRAFTEMAN_H

#include "../Boolean/boolean.h"
#include "../Akun/akun.h"

#define GRAFTEMAN_CAPACITY 20
#define GRAFTEMAN_SIZE(g) (g).size
#define GRAFTEMAN_ELMT(g, i, j) (g).buffer[i][j]

typedef struct grafteman
{
    boolean buffer[GRAFTEMAN_CAPACITY][GRAFTEMAN_CAPACITY];
    int size;

} GrafTeman;

// elemen[i][j] semuanya 0
void CreateGrafTeman(GrafTeman *g, int jumlahAkun);

// elemen[i][j] = isBerteman
void setGrafTeman(GrafTeman *g, int i, int j, boolean isBerteman);

// print
void displayGrafTeman(GrafTeman g);

// cek apakah akun1 berteman dengan akun2
boolean isAkunBerteman(GrafTeman g, Akun akun1, Akun akun2);

// resize graf teman
void resizeGrafTeman(GrafTeman *g, int newSize);

// Hitung banyak teman
int countTeman(GrafTeman g, Akun akun);

// Hitung banyak teman akun yang temannya juga berteman dengan akun
int countSalingTeman(GrafTeman g, Akun akun);

// Display list saling teman
// contoh:
// Daftar teman Alice
// | Bob
// | Carol
void displaySalingTeman(GrafTeman g, Akun akun);

#endif