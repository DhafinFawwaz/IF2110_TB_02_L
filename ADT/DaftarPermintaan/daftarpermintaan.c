/* File: daftarpermintaan.c */
/* Definisi ADT Daftar Permintaan menggunakan Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include <stdio.h>
#include <stdlib.h>
#include "daftarpermintaan.h"

/* ********* Prototype ********* */
/* *** KREATOR *** */
void CreateDaftar(DaftarPermintaan *D, int Max){
/* Membuat daftar permintaan kosong */
	(*D).P = (permintaan *) malloc (Max * sizeof(permintaan));
	MaxPermintaan(*D) = Max;
	Head(*D) = Nil;
	Tail(*D) = Nil;
}

/* *** PEMERIKSAAN NILAI *** */
boolean isDaftarEmpty(DaftarPermintaan D){
/* Mengirim true jika daftar permintaan kosong */
	return (Head(D) == Nil && Tail(D) == Nil);
}

boolean isDaftarFull(DaftarPermintaan D){
/* Mengirim true jika daftar permintaan sudah penuh */
	return (panjangDaftar(D) == MaxPermintaan(D));
}

int panjangDaftar(DaftarPermintaan D){
/* Mengirimkan banyaknya akun di dalam daftar permintaan */
	if (isDaftarEmpty(D)){
		return 0;
	}
	else{
		if (Tail(D) >= Head(D)){
	        return (Tail(D) - Head(D) + 1);
	    }
        else{
            return (Tail(D) - Head(D) + MaxPermintaan(D) + 1);
	    }
	}
}

/* *** PENGUBAHAN NILAI *** */
void enqueuePermintaan(DaftarPermintaan *D, permintaan p){
/* Menambahkan permintaan pada daftar permintaan dengan aturan priority queue, terurut mengecil berdasarkan jumlah teman */
	if (!isDaftarEmpty(*D)){
		Tail(*D) = (Tail(*D) + 1) % MaxPermintaan(*D);
		TailPermintaan(*D) = p;
		int i = (Tail(*D));
		permintaan temp;
		while (i != Head(*D)){
			int idxBefore = (i - 1 + MaxPermintaan(*D)) % MaxPermintaan(*D);
			if (JumlahTeman(Elmt(*D,i)) > JumlahTeman(Elmt(*D,idxBefore))){
				temp = Elmt(*D, i);
				Elmt(*D, i) = Elmt(*D, idxBefore);
				Elmt(*D, idxBefore) = temp;
			}
			i = idxBefore;
		}
	}
    else{
		Head(*D) =0;
		Tail(*D) = 0;
		TailPermintaan(*D) = p;
    }
}

void dequeuePermintaan(DaftarPermintaan *D, permintaan *p){
/* Menghapus permintaan teratas pada daftar permintaan */
	*p = HeadPermintaan(*D);
	if (panjangDaftar(*D) == 1){
	        Head(*D) = Nil;
	        Tail(*D) = Nil;
    }
    else{
	    if (Head(*D) == MaxPermintaan(*D) - 1){
	        Head(*D) = 1;
	    }
        else{
	        Head(*D)++;
	    }
    }
}

/* *** PENAMPILAN NILAI *** */
void displayTopPermintaan(DaftarPermintaan D){
/* Menampilkan permintaan pertemanan teratas */
	printf("\nPermintaan pertemanan teratas dari ");
	printWord(NamaMinta(HeadPermintaan(D)));
	printf("\n\n| ");
	printWord(NamaMinta(HeadPermintaan(D)));
	printf("\n| Jumlah teman: %d\n", JumlahTeman(HeadPermintaan(D)));
}

void displayDaftar(DaftarPermintaan D){
/* Menampilkan isi daftar permintaan ke layar */
	int i, j;
	if (Tail(D) - Head(D) < 0){
		for (i = Head(D); i < MaxPermintaan(D); i++){
			printf("\n| ");
			printWord(NamaMinta(Elmt(D,i)));
			printf("\n| Jumlah teman: %d\n", JumlahTeman(Elmt(D,i)));
		}
		for (j = 0; j < Tail(D) + 1; j++){
			printf("\n| ");
			printWord(NamaMinta(Elmt(D,j)));
			printf("\n| Jumlah teman: %d\n", JumlahTeman(Elmt(D,j)));
		}
		printf("\n");
	}
	else{
		for (i = Head(D); i < Tail(D) + 1; i++){
			printf("\n| ");
			printWord(NamaMinta(Elmt(D,i)));
			printf("\n| Jumlah teman: %d\n", JumlahTeman(Elmt(D,i)));
		}
		printf("\n");
	}
}