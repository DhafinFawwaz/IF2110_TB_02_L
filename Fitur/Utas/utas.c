
#include "utas.h"

void UTAS(int IDKicau){
	Word YA = {.TabWord = "YA", .Length = "2"};
	Word TIDAK = {.TabWord = "TIDAK", .Length = "5"};
	Utas currentUtas;

	if (IDKicau == true){ /*temp*/
		printf("Utas berhasil dibuat!");

		do{
			printf("\n\nMasukkan kicauan:\n");
			readInput();
			TEXT(currentUtas) = currentWord;
			SetToCurrentDateTime(&WAKTU(currentUtas));
			do
			{
				printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
				readInput();
			} while (!compareWord(currentWord,YA) || !compareWord(currentWord,TIDAK));

		} while (!compareWord(currentWord, TIDAK));
		
	}
	else if (IDKicau == false){ /*Utas ini bukan milik anda!*/

	}
	else{ /*Kicauan tidak ditemukan*/

	}
}

void SAMBUNG_UTAS(int IDUtas, int index){
	/*Jika input benar: */
	Utas currentUtas;
	printf("\n\nMasukkan kicauan:\n");
	readInput();

}
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);