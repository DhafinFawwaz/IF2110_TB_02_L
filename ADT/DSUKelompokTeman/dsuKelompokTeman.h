
#ifndef KELT_H_
#define KELT_H_
#include "../GrafTeman/grafteman.h"

#define KELOMPOKTEMAN_CAPACITY 20

typedef struct kelompokteman {
	int parent[KELOMPOKTEMAN_CAPACITY];
} kelompokTeman;

int kelompokTeman_find(kelompokTeman kt, int i);
void kelompokTeman_union(kelompokTeman* kt,int i, int j);

#endif
