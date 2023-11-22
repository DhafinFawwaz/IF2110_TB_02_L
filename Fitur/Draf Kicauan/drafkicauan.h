#ifndef DRAFKICAUAN_H
#define DRAFKICAUAN_H

#include "../../ADT/StackDinDraf/stackdindraf.h"

void hapus_draf(StackDinDraf s);
void simpan_draf(StackDinDraf s);
void terbit_draf(StackDinDraf s);

void ubah_draf(StackDinDraf *s);
void kembali_draf(StackDinDraf *s);

void buat_draf(StackDinDraf *s);
void lihat_draf(StackDinDraf s);

void DebugListDraftKicauan();

#endif