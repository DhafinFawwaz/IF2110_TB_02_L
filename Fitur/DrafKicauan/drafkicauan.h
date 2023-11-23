#ifndef DRAFKICAUAN_H
#define DRAFKICAUAN_H

#include "../../ADT/StackBerkaitDraf/stackberkaitdraf.h"

void hapus_draf(StackBerkaitDraf s);
void simpan_draf(StackBerkaitDraf s);
void terbit_draf(StackBerkaitDraf s);

void ubah_draf(StackBerkaitDraf *s);
void kembali_draf(StackBerkaitDraf *s);

void buat_draf(StackBerkaitDraf *s);
void lihat_draf(StackBerkaitDraf s);

void DebugListDraftKicauan();

#endif