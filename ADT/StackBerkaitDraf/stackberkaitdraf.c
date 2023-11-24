#include <stdio.h>
#include <stdlib.h>
#include "stackberkaitdraf.h"

#include "../MesinKata/wordmachine.h"
#include "../StackDin/stackdin.h"
#include "../Profile/profile.h"
#include "../DateTime/datetime.h"
#include "../../Fitur/Perintah/perintah.h"
#include "../../Fitur/Kicauan/kicauan.h"


void CreateDraftKicauan(DrafKicauan *drafkicauan){
    drafkicauan->id = 1;
    SetToCurrentDateTime(&(drafkicauan->dateTime));
}

AddressDraf newNodeStackBerkaitDraf(DrafKicauan x) {
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
    atau NULL jika alokasi gagal */   
    AddressDraf new = malloc(sizeof(NodeDraf));
    if (new != NULL) {
        new->drafkicauan = x;
        new->next = NULL;
    }
    return new;
}

boolean isEmptyStackBerkaitDraf(StackBerkaitDraf s) {
    return ADDR_TOP_DRAF(s) == NULL;
}

int lengthStackBerkaitDraf(StackBerkaitDraf s) {
    int count = 0;
    AddressDraf current = ADDR_TOP_DRAF(s);
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void createStackBerkaitDraf(StackBerkaitDraf *s) {
    ADDR_TOP_DRAF(*s) = NULL;
}

void pushStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan x) {
    /* KAMUS LOKAL */
    AddressDraf p;

    /* ALGORITMA */
    p = newNodeStackBerkaitDraf(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP_DRAF(*s);
        ADDR_TOP_DRAF(*s) = p;
    }
}

void popStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan *x) {
    /* KAMUS LOKAL */
    AddressDraf p;

    /* ALGORITMA */
    *x = TOP_DRAF(*s);
    p = ADDR_TOP_DRAF(*s);
    ADDR_TOP_DRAF(*s) = NEXT(ADDR_TOP_DRAF(*s));
    NEXT(p) = NULL;
    free(p);
}

void displayStackBerkaitDraf(StackBerkaitDraf *s) {
    AddressDraf current = ADDR_TOP_DRAF(*s);

    printf("Stack Berkait Draft:\n");

    if (isEmptyStackBerkaitDraf(*s)) {
        printf("Stack Berkait Draft kosong.\n");
    } else {
        while (current != NULL) {
            // printf("| Date and Time: ");
            // DisplayDateTime(current->drafkicauan.dateTime);
            printf("| ");
            printWord(current->drafkicauan.text);
            printf("| ");
            printWord(current->drafkicauan.nama);
            printf("\n");

            current = current->next;

            if (current != NULL) {
                printf("\n---\n");
            }
        }
    }
}