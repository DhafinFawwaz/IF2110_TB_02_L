#include "utas.h"
#include "../Global/global.h"
#include "../../ADT/GrafTeman/grafteman.h"

Word currentUtas;


boolean isUtasMilikOrangLain(IDKicau){
	return (
		!(compareWord((*ADDR_AKUN_KICAUAN(GET_ELMT_KICAUAN(globalListDinKicauan,IDKicau-1))).username, (*globalCurrentAddrAkun).username))
	);
}

void buatUtas(int IDKicau){
	Word YA = {.TabWord = "YA", .Length = 2};
	Word TIDAK = {.TabWord = "TIDAK", .Length = 5};
	Utas currentUtas, p;
	Utas_CreateUtas(&currentUtas);
	Utas_CreateUtas(&p);

	if (!(isInListKicauan(IDKicau, globalListDinKicauan))){ /*Kicauan tidak ditemukan*/
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
			if (Utas_isEmpty(UtasInKicau(IDKicau))) {
				UtasInKicau(IDKicau) = currentUtas;
				globalBanyakKicauanBerutas++; // update global untuk config
			}
			else {
				p = UtasInKicau(IDKicau);
				while (NEXT_UTAS(p) != NULL){
					p = NEXT_UTAS(p);
				}
				NEXT_UTAS(p) = currentUtas; 
			}

			do
			{
				printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
				readInput();
			} while (!compareWord(currentWord,TIDAK) && !compareWord(currentWord,YA));

		} while (!compareWord(currentWord, TIDAK));
		
	}
}

void sambungUtas(int IDUtas, int index){
	if (UtasInKicau(IDUtas) == NULL){ 
		printf("Utas tidak ditemukan!\n");
	}
	else if (isUtasMilikOrangLain(IDUtas)){
		printf("Anda tidak bisa menyambung utas ini!\n");
	}
	else if ((index-1) > Utas_length(UtasInKicau(IDUtas))){
		printf("Index terlalu tinggi!\n");
	}
	else{
		Utas newUtas;
		Utas_CreateUtas(&newUtas);
		printf("Masukkan kicauan:\n");
		readInput();
		Utas_setUtasFromWord(&newUtas, currentWord);
		Utas_insertAt(&UtasInKicau(IDUtas), INFO_UTAS(newUtas), index-1);
	}
}

void hapusUtas(int IDUtas, int index){
	isi_utas temp;
	if (UtasInKicau(IDUtas) == NULL){ 
		printf("Utas tidak ditemukan!\n");
	}
	else if (isUtasMilikOrangLain(IDUtas)){
		printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
	}
	else if (index == 0){
		printf("Anda tidak bisa menghapus kicauan utama!\n");
	}
	else if (index > Utas_length(UtasInKicau(IDUtas))){
		/*Asumsi kondisi Utas tidak ditemukan hanya terjadi ketika index melebihi length mainUtas*/
		printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
	}
	else{
		Utas_deleteAt(&UtasInKicau(IDUtas), index-1, &temp);
		printf("Kicauan sambungan berhasil dihapus!\n");
	}
}

void cetakUtas(int IDUtas){
	Kicauan kicauUtas = GET_ELMT_KICAUAN(globalListDinKicauan,IDUtas-1);
	Utas p = kicauUtas.firstUtas;
	Word pembuat = (*ADDR_AKUN_KICAUAN(kicauUtas)).username;
	Akun OP = *ADDR_AKUN_KICAUAN(kicauUtas);
	if (p == NULL){
		printf("Utas tidak ditemukan!\n");
	}
	else if (!JenisAkun(Profil(*ADDR_AKUN_KICAUAN(kicauUtas))) && !isAkunBerteman(globalGrafTeman, OP, *globalCurrentAddrAkun)){
		printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!");
	}
	else{
		int idxUtas = 1;
		printf("| ID = %d\n", IDKICAU(kicauUtas));
		printf("| ");
		printWord(pembuat);
		printf("\n");
		printf("| ");
		DisplayDateTime(WAKTU(kicauUtas));
		printf("\n");
		printf("| ");
		printWord(TEXT_KICAU(kicauUtas));
		printf("\n\n");
		while (p != NULL){
			printf("   | INDEX = %d\n", idxUtas);
			printf("   | "); printWord(pembuat); printf("\n");
			printf("   | "); DisplayDateTime(WAKTU(kicauUtas)); printf("\n");
			printf("   | "); printWord(TEXT_UTAS(p));printf("\n\n");
			p = NEXT_UTAS(p);
			idxUtas++;
		}
	}
}
