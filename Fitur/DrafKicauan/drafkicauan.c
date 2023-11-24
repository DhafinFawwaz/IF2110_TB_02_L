#include <stdio.h>
#include <stdlib.h>

#include "drafkicauan.h"

#include "../Global/global.h"
#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"

#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/StackBerkaitDraf/stackberkaitdraf.h"

Word HAPUSDRAF = {.TabWord = "HAPUS", .Length = 5};
Word SIMPANDRAF = {.TabWord = "SIMPAN", .Length = 6};
Word TERBITDRAF= {.TabWord = "TERBIT", .Length = 6};
Word KEMBALIDRAF= {.TabWord = "KEMBALI", .Length = 7};
Word UBAHDRAF= {.TabWord = "UBAH", .Length = 4};
Word EMPTYWORD= {.TabWord = "", .Length = 0};

void hapus_draf(StackBerkaitDraf *s) {
    /* KAMUS LOKAL */
    DrafKicauan x;

    /* ALGORITMA */
    if (!isEmptyStackBerkaitDraf(*s)) {
        popStackBerkaitDraf(s, &x);
        printf("Draf telah berhasil dihapus!\n");
    } else {
        printf("Anda tidak memiliki draf untuk dihapus.\n");
    }
}

void simpan_draf(StackBerkaitDraf s) {
    /* KAMUS LOKAL */
    DrafKicauan x;

    /* ALGORITMA */
    if (!isEmptyStackBerkaitDraf(s)) {
        printf("Draf telah berhasil disimpan!\n");
    } else {
        printf("Anda tidak memiliki draf untuk disimpan.\n");
    }
}

void terbit_draf(StackBerkaitDraf s) {
    /* KAMUS LOKAL */
    DrafKicauan x;
    int currentID;

    /* ALGORITMA */
    if (!isEmptyStackBerkaitDraf(s)) {
        popStackBerkaitDraf(&s, &x);

        printf("Selamat! Draf kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        
        Kicauan dariDrafKicauan;
    
        createKicauan(&dariDrafKicauan,x.text);
        TAGAR(dariDrafKicauan)=EMPTYWORD;
        IDKICAU(dariDrafKicauan) = NEFF_LIST_KICAUAN(globalListDinKicauan)+1;
        ADDR_AKUN_KICAUAN(dariDrafKicauan) = globalCurrentAddrAkun;
        insertKicauan(dariDrafKicauan, &globalListDinKicauan);
        printKicauan(dariDrafKicauan);
        printf("\n");
        printf("\n");

    } else {
        printf("Tidak ada draf yang dapat diterbitkan.\n");
    }
}

void ubah_draf(StackBerkaitDraf *s){
    /* KAMUS LOKAL */
    DrafKicauan x;
    boolean validChoice;

    /* ALGORITMA */
    popStackBerkaitDraf(s, &x);
    printf("Masukkan draf yang baru: \n");
    readInput();
    capCurrentWord(280);
    setWord(&(x.text),currentWord.TabWord);
    SetToCurrentDateTime(&(x.dateTime));

    pushStackBerkaitDraf(&globalCurrentAddrAkun->draf_kicauan, x);

    validChoice = false;
    while (!validChoice) {
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
        printf("\n");
        readInput();

        if (compareWord(HAPUSDRAF, currentWord)) {
            hapus_draf(&(globalCurrentAddrAkun->draf_kicauan));
            validChoice = true;
        } else if (compareWord(SIMPANDRAF, currentWord)) {
            simpan_draf(globalCurrentAddrAkun->draf_kicauan);
            validChoice = true;
        } else if (compareWord(TERBITDRAF, currentWord)) {
            terbit_draf(globalCurrentAddrAkun->draf_kicauan);
            validChoice = true;
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        printf("\n");
    }
}


void buat_draf(){
    /* KAMUS LOKAL */
    DrafKicauan data;
    boolean validChoice;
    Word isiDrafKicauan;

    /* ALGORITMA */
    printf("Masukkan draf: \n");
    readInput();
    capCurrentWord(280);

    setWord(&(data.text),currentWord.TabWord);
    SetToCurrentDateTime(&(data.dateTime));

    pushStackBerkaitDraf(&globalCurrentAddrAkun->draf_kicauan, data);
    
    validChoice = false;
    while (!validChoice) {
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
        printf("\n");
        readInput();

        if (compareWord(HAPUSDRAF, currentWord)) {
            hapus_draf(&(globalCurrentAddrAkun->draf_kicauan));
            validChoice = true;
        } else if (compareWord(SIMPANDRAF, currentWord)) {
            simpan_draf(globalCurrentAddrAkun->draf_kicauan);
            validChoice = true;
        } else if (compareWord(TERBITDRAF, currentWord)) {
            terbit_draf(globalCurrentAddrAkun->draf_kicauan);
            validChoice = true;
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        printf("\n");
    }
}

void lihat_draf() {
    /* KAMUS LOKAL */
    DrafKicauan data;
    boolean validChoice;

    /* ALGORITMA */
    if (!isEmptyStackBerkaitDraf(globalCurrentAddrAkun->draf_kicauan)) {
        data = TOP_DRAF(globalCurrentAddrAkun->draf_kicauan);

        printf("Ini draf terakhir anda:\n");
        printf("| ");
        DisplayDateTime(data.dateTime);
        printf("\n| ");
        printWord(data.text);
        printf("\n\n");
    } else {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }

    validChoice = false;
    while (!validChoice) {
        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)");
        printf("\n");
        readInput();

        if (compareWord(UBAHDRAF, currentWord)) {
            ubah_draf(&(globalCurrentAddrAkun->draf_kicauan));
            validChoice = true;
        } else if (compareWord(HAPUSDRAF, currentWord)) {
            hapus_draf(&(globalCurrentAddrAkun->draf_kicauan));
            validChoice = true;
        } else if (compareWord(TERBITDRAF, currentWord)) {
            terbit_draf(globalCurrentAddrAkun->draf_kicauan);
            validChoice = true;
        } else if (compareWord(KEMBALIDRAF, currentWord)) {
            validChoice = true; 
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
        printf("\n");
    }
}

