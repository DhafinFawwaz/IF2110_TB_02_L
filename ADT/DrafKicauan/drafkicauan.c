#include <stdio.h>
#include "drafkicauan.h"

int banyakDraf;
DrafKicauan listDraftkicauan[100];

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