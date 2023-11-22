#include <stdio.h>
#include <stdlib.h>


#include "drafkicauan.h"

#include "../Perintah/perintah.h"
#include "../Kicauan/kicauan.h"

#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/StackDinDraf/stackdindraf.h"

Word BUAT_DRAF = {.TabWord = "BUAT_DRAF", .Length = 9};
Word LIHAT_DRAF = {.TabWord = "LIHAT_DRAF", .Length = 10};
Word UBAH_DRAF = {.TabWord = "UBAH", .Length = 4};
Word KEMBALI_DRAF = {.TabWord = "KEMBALI", .Length = 7};
Word HAPUS_DRAF = {.TabWord = "HAPUS", .Length = 5};
Word SIMPAN_DRAF = {.TabWord = "SIMPAN", .Length = 6};
Word TERBIT_DRAF = {.TabWord = "TERBIT", .Length = 6};

void hapus_draf(StackDinDraf s) {
    /* KAMUS LOKAL */
    DrafKicauan x;

    /* ALGORITMA */
    if (!isEmptyStackDinDraf(s)) {
        popStackDinDraf(&s, &x);
        printf("Draf telah berhasil dihapus!\n");
    } else {
        printf("Anda tidak memiliki draf untuk dihapus.\n");
    }
}

void simpan_draf(StackDinDraf s) {
    /* KAMUS LOKAL */
    DrafKicauan x;

    /* ALGORITMA */
    if (!isEmptyStackDinDraf(s)) {
        popStackDinDraf(&s, &x);
        printf("Draf telah berhasil disimpan!\n");
    } else {
        printf("Anda tidak memiliki draf untuk disimpan.\n");
    }
}

void terbit_draf(StackDinDraf s) {
    /* KAMUS LOKAL */
    DrafKicauan x;
    int currentID;

    /* ALGORITMA */
    if (!isEmptyStackDinDraf(s)) {
        popStackDinDraf(&s, &x);

        printf("Selamat! Draf kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        
        Kicauan dariDrafKicauan;
    
        createKicauan(&dariDrafKicauan,x.text);
        printKicauan(dariDrafKicauan);

    } else {
        printf("Tidak ada draf yang dapat diterbitkan.\n");
    }
}

void ubah_draf(StackDinDraf *s){
    /* KAMUS LOKAL */
    Word isiDrafKicauan;
    boolean validChoice;

    /* ALGORITMA */
    printf("Masukkan draf yang baru:");
    readInput();
    isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");

    readInput();
    validChoice = false;
    while (!validChoice) {
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
        readInput();

        if (compareWord(HAPUS_DRAF, currentWord)) {
            hapus_draf(*s);
            validChoice = true;
        } else if (compareWord(SIMPAN_DRAF, currentWord)) {
            simpan_draf(*s);
            validChoice = true;
        } else if (compareWord(TERBIT_DRAF, currentWord)) {
            terbit_draf(*s);
            validChoice = true;
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

void kembali_draf(StackDinDraf *s){
    printf("\n");
}

void buat_draf(StackDinDraf *s){
    /* KAMUS LOKAL */
    Word isiDrafKicauan;
    boolean validChoice;

    /* ALGORITMA */
    printf("Masukkan draf: ");
    readInput();
    isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");

    readInput();
    validChoice = false;
    while (!validChoice) {
        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini? ");
        readInput();

        if (compareWord(HAPUS_DRAF, currentWord)) {
            hapus_draf(*s);
            validChoice = true;
        } else if (compareWord(SIMPAN_DRAF, currentWord)) {
            simpan_draf(*s);
            validChoice = true;
        } else if (compareWord(TERBIT_DRAF, currentWord)) {
            terbit_draf(*s);
            validChoice = true;
        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

void lihat_draf(StackDinDraf s) {
    if (!isEmptyStackDinDraf(s)) {
        int lastIndex = lengthStackDinDraf(s) - 1;

        printf("Ini draf terakhir anda:\n");
        printf("| SetToCurrentDateTime(dt)");
        printf("| isiDrafKicauan <ID>");

    } else {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
}

