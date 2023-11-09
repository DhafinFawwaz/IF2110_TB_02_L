#ifndef DRAFKICAUAN_H
#define DRAFKICAUAN_H
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"

typedef struct drafkicauan
{
    int id;
    Word text;
    Word nama;
    DateTime dateTime;
} DrafKicauan;

extern int banyakDraf;
extern DrafKicauan listDraftkicauan[100]; // sementara di array aja dulu

void DebugListDraftKicauan();

void buat_draf();
void lihat_draf();

void hapus_draf();
void simpan_draf();
void terbit_draf();
void ubah_draf();

#endif