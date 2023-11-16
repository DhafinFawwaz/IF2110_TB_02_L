#include "utas.h"

boolean isUtasMilikOrangLain(IDKicau){
	return (
		!(compareWord((*ADDR_AKUN_KICAUAN(*ADDR_KICAUAN(listKicauan,IDKicau-1))).username, (*currentAkun).username))
	);
}

/*Mengeluarkan Utas pada List Kicauan, dan NULL jika tidak ketemu*/
Utas getUtasInListKicauan(int IDUtas){
	return (*ADDR_KICAUAN(listKicauan,IDUtas-1)).firstUtas;
}

Utas buatUtas(int IDKicau){
	Word YA = {.TabWord = "YA", .Length = "2"};
	Word TIDAK = {.TabWord = "TIDAK", .Length = "5"};
	Utas currentUtas, firstUtas, p;
	Utas_CreateUtas(&firstUtas);
	Utas_CreateUtas(&currentUtas);
	Utas_CreateUtas(&p);

	if (!(isInListKicauan(IDKicau))){ /*Kicauan tidak ditemukan*/
		printf("Kicauan tidak ditemukan\n");
	}
	else if (isUtasMilikOrangLain(IDKicau)){ /*Utas milik akun lain*/
		printf("Utas ini bukan milik anda!\n");
	}	
	else{
		printf("Utas berhasil dibuat!");

		do{
			printf("\n\nMasukkan kicauan:\n");
			readInput();
			
			Utas_setUtasFromWord(&currentUtas, currentWord);
			if (Utas_isEmpty(firstUtas)) {
				firstUtas = currentUtas; 
				p = firstUtas;
			}
			else {
				NEXT(p) = currentUtas; 
				p = NEXT(p);
			}

			do
			{
				printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
				readInput();
			} while (!compareWord(currentWord,YA) || !compareWord(currentWord,TIDAK));

		} while (!compareWord(currentWord, TIDAK));
		
	}
	return firstUtas;
}

void sambungUtas(int IDUtas, int index){
	Utas mainUtas = getUtasInListKicauan(IDUtas);
	if (mainUtas == NULL){ 
		printf("Utas tidak ditemukan!\n");
	}
	else if (isUtasMilikOrangLain(IDUtas)){
		printf("Anda tidak bisa menyambung utas ini!\n");
	}
	else if (index > length(mainUtas)){
		printf("Index terlalu tinggi!\n");
	}
	else{
		Utas newUtas;
		Utas_CreateUtas(&newUtas);
		printf("Masukkan kicauan:\n");
		readInput();
		Utas_setUtasFromWord(&newUtas, currentWord);
		Utas_insertAt(&mainUtas, INFO(newUtas), IDUtas);
	}
}

void hapusUtas(int IDUtas, int index){
	Utas mainUtas = getUtasInListKicauan(IDUtas);
	ElType temp;
	if (mainUtas == NULL){ 
		printf("Utas tidak ditemukan!\n");
	}
	else if (isUtasMilikOrangLain(IDUtas)){
		printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
	}
	else if (index == 0){
		printf("Anda tidak bisa menghapus kicauan utama!\n");
	}
	else if (index > length(mainUtas)){
		/*Asumsi kondisi Utas tidak ditemukan hanya terjadi ketika index melebihi length mainUtas*/
		printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
	}
	else{
		Utas_deleteAt(&mainUtas, IDUtas, &temp);
		printf("Kicauan sambungan berhasil dihapus!\n");
	}
}

void cetakUtas(int IDUtas){
	Kicauan kicauUtas = (*ADDR_KICAUAN(listKicauan,IDUtas-1));
	Utas p = kicauUtas.firstUtas;
	int idxUtas = 1;

    printf("| ID = %d\n", IDKICAU(kicauUtas));
    printf("| ");
    Word pembuat = (*ADDR_AKUN_KICAUAN(kicauUtas)).username;
    printWord(pembuat);
    printf("\n");
    printf("| ");
    DisplayDateTime(WAKTU(kicauUtas));
    printf("\n");
    printf("| ");
    printWord(TEXT_KICAU(kicauUtas));
    printf("\n");
	while (p != NULL){
		printf("   | INDEX = %d\n", idxUtas);
		printf("   | "); printWord(pembuat); printf("\n");
		printf("   | "); DisplayDateTime(WAKTU(kicauUtas)); printf("\n");
		printf("   | "); printWord(TEXT(p));printf("\n");
		p = NEXT(p);
	}
}
