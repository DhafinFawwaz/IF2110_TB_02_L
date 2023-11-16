
#include "utas.h"

boolean isUtasMilikOrangLain(IDKicau){
	return (
		!(compareWord(*ADDR_AKUN_KICAUAN(*ADDR_KICAUAN(listKicauan,IDKicau-1)).username, currentAkun.username))
	);
}

Utas UTAS(int IDKicau){
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

void SAMBUNG_UTAS(int IDUtas, int index){
	/*Asumsi: IDUtas == IDKicau*/
	if (!(isInListKicauan(IDUtas))){ 
		printf("Utas tidak ditemukan!\n");
	}
	else if (isUtasMilikOrangLain(IDUtas)){
		printf("Anda tidak bisa menyambung utas ini!\n");
	}
	else if (index > length(/**/)){
		printf("Index terlalu tinggi!\n");
	}
	else{
		Utas currentUtas;
		printf("Masukkan kicauan:\n");
		readInput();
		Utas_insertAt()
	}
}
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);