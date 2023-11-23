#include "kelompokTeman.h"

void initializeKelompokTeman(kelompokTeman* kt){
	int i;
	for (i=0; i<KELOMPOKTEMAN_CAPACITY; i++){
		kt->parent[i] = i;
	}
}

void KelompokTeman(){
	Akun currAkun = (*globalCurrentAddrAkun);
	initializeKelompokTeman(&globalKelompokTeman);
	int i;
	int j;
	int currentAkunId = currAkun.id;
	int count = 0;
	for (i=0; i<globalListStatikAkun.Neff; i++){
		if (isAkunBerteman(globalGrafTeman, currAkun, globalListStatikAkun.contents[i])) {
			kelompokTeman_union(&globalKelompokTeman,currentAkunId,i);
		}
	}
	for (j=0; j<globalListStatikAkun.Neff; j++){
		if (kelompokTeman_find(globalKelompokTeman,j) == kelompokTeman_find(globalKelompokTeman,currentAkunId)){
			count++;
		}
	}
	printf("\nTerdapat %d orang dalam Kelompok Teman ", count);
	printWord(currAkun.username);
	printf(" :\n");
	for (j=0; j<globalListStatikAkun.Neff; j++){
		if (kelompokTeman_find(globalKelompokTeman,j) == kelompokTeman_find(globalKelompokTeman,currentAkunId)){
			printWord(globalListStatikAkun.contents[j].username);
			printf("\n");
		}
	}
	printf("\n");

}