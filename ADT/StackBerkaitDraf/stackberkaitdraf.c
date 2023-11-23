#include <stdio.h>
#include <stdlib.h>
#include "stackberkaitdraf.h"

#include "../MesinKata/wordmachine.h"
#include "../StackDin/stackdin.h"
#include "../Profile/profile.h"
#include "../DateTime/datetime.h"
#include "../../Fitur/Perintah/perintah.h"
#include "../../Fitur/Kicauan/kicauan.h"

int banyakDraf;
DrafKicauan listDraftkicauan[100];

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
    return ADDR_TOP_DRAF(s) == NIL;
}

int lengthStackBerkaitDraf(StackBerkaitDraf s) {
    int count = 0;
    AddressDraf current = ADDR_TOP_DRAF(s);
    while (current != NIL) {
        count++;
        current = current->next;
    }
    return count;
}

void createStackBerkaitDraf(StackBerkaitDraf *s) {
    ADDR_TOP_DRAF(*s) = NIL;
}

void pushStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan x) {
    /* KAMUS LOKAL */
    AddressDraf p;

    /* ALGORITMA */
    p = newNodeStackBerkaitDraf(x);
    if (p != NIL) {
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
    NEXT(p) = NIL;
    free(p);
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