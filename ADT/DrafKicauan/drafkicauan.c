#include <stdio.h>
#include <stdlib.h>
#include "drafkicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../StackDin/stackdin.h"
#include "../Profile/profile.h"
#include "../DateTime/datetime.h"

#include "../../Fitur/Perintah/perintah.h"
#include "../../Fitur/Kicauan/kicauan.h"

int banyakDraf;
DrafKicauan listDraftkicauan[100];

AddressDraf newNodeStackDinDraf(DrafKicauan x) {
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
    atau NULL jika alokasi gagal */   
    AddressDraf new = malloc(sizeof(NodeDraf));
    if (new != NULL) {
        new->drafkicauan = x;
        new->next = NULL;
    }
    return new;
}

boolean isEmptyStackDinDraf(StackDinDraf s) {
    return ADDR_TOP_DRAF(s) == NIL;
}

int lengthStackDinDraf(StackDinDraf s) {
    int count = 0;
    AddressDraf current = ADDR_TOP_DRAF(s);
    while (current != NIL) {
        count++;
        current = current->next;
    }
    return count;
}

void createStackDinDraf(StackDinDraf *s) {
    ADDR_TOP_DRAF(*s) = NIL;
}

void pushStackDinDraf(StackDinDraf *s, DrafKicauan x) {
    /* KAMUS LOKAL */
    AddressDraf p;

    /* ALGORITMA */
    p = newNodeStackDinDraf(x);
    if (p != NIL) {
        NEXT(p) = ADDR_TOP_DRAF(*s);
        ADDR_TOP_DRAF(*s) = p;
    }
}

void popStackDinDraf(StackDinDraf *s, DrafKicauan *x) {
    /* KAMUS LOKAL */
    AddressDraf p;

    /* ALGORITMA */
    *x = TOP_DRAF(*s);
    p = ADDR_TOP_DRAF(*s);
    ADDR_TOP_DRAF(*s) = NEXT(ADDR_TOP_DRAF(*s));
    NEXT(p) = NIL;
    free(p);
}

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
        // printKicauan(x);
    } else {
        printf("Tidak ada draf yang dapat diterbitkan.\n");
    }
}

void ubah_draf(StackDinDraf *s){
    Word isiDrafKicauan;

    printf("Masukkan draf yang baru:");
    readInput();
    isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
}

void buat_draf(StackDinDraf *s){
    Word isiDrafKicauan;

    printf("Masukkan draf: ");
    readInput();
    
    isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
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

void DebugDraftKicauan(DrafKicauan list){
    printf("id: %d\n", list.id);
    printf("text: ");
    printf("%s", list.text.TabWord);
    printf("\n");
    printf("nama: ");
    printf("%s", list.nama.TabWord);
    printf("\n");
    printf("dateTime: ");
    DisplayDateTime(list.dateTime);
    printf("\n");
}

void DebugListDraftKicauan(){
    printf("======== [Debug listDraftkicauan] ========\n");
    int i = 0;
    for(i = 0; i < banyakDraf; i++){
        printf("[Draf ke-%d]\n", i+1);
        DebugDraftKicauan(listDraftkicauan[i]);
    }
    printf("======== [Debug listDraftkicauan End] ========\n");
}