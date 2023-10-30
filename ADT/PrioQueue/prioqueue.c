/* File: prioqueue.c */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if (IsEmpty(Q)){
		return 0;
	}
	else{
		if (Tail(Q) >= Head(Q)){
	        return (Tail(Q) - Head(Q) + 1);
	    }
        else{
            return (Tail(Q) - Head(Q) + MaxEl(Q) + 1);
	    }
	}
}

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (infotype *) malloc (Max * sizeof(infotype));
	MaxEl(*Q) = Max;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	free((*Q).T);
	MaxEl(*Q) = 0; 
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, infotype X){
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
	if (!IsEmpty(*Q)){
		Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
		InfoTail(*Q) = X;
		int i = (Tail(*Q));
		infotype temp;

		while (i != Head(*Q)){
			int idxBefore = (i - 1 + MaxEl(*Q)) % MaxEl(*Q);
			if (Prio(Elmt(*Q,i)) < Prio(Elmt(*Q,idxBefore))){
				temp = Elmt(*Q, i);
				Elmt(*Q, i) = Elmt(*Q, idxBefore);
				Elmt(*Q, idxBefore) = temp;
			}
			i = idxBefore;
		}
	}
    else{
		Head(*Q) =0;
		Tail(*Q) = 0;
		InfoTail(*Q) = X;
    }
}

void Dequeue (PrioQueue * Q, infotype * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1){
	        Head(*Q) = Nil;
	        Tail(*Q) = Nil;
    }
    else{
	    if (Head(*Q) == MaxEl(*Q) - 1){
	        Head(*Q) = 1;
	    }
        else{
	        Head(*Q)++;
	    }
    }
}

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q){
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
	if (IsEmpty(Q)){
 		printf("#\n");
	}
    else{
		int i, j;
		if (Tail(Q) - Head(Q) < 0){
            for (i = Head(Q); i < MaxEl(Q); i++){
                printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
            }
            for (j = 0; j < Tail(Q) + 1; j++){
                if (j != Tail(Q)){
                    printf("%d %c\n", Prio(Elmt(Q,j)), Info(Elmt(Q,j)));
                }
                else{
                    printf("%d %c\n", Prio(Elmt(Q,j)), Info(Elmt(Q,j)));
                }
            }
            printf("#\n");
        }
        else{
            for (i = Head(Q); i < Tail(Q) + 1; i++){
                if (i != Tail(Q)){
                    printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
                }else{
                    printf("%d %c\n", Prio(Elmt(Q,i)), Info(Elmt(Q,i)));
                }
            }
            printf("#\n");
        }
    }
}