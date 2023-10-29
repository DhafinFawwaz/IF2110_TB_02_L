#include "balasan.h"

int banyakKicauanBerbalasan;
Balasan currentBalasan;
Balasan listBalasan[100];

void DebugListBalasan(){
    printf("======== [Debug listBalasan] ========\n");
    int i = 0;
    for(i = 0; i < banyakKicauanBerbalasan; i++){
        printf("[Balasan ke-%d]\n", i+1);
        displayBalasan(listBalasan[i]);
    }
    printf("======== [Debug listBalasan End] ========\n");
}

void displayBalasan(Balasan balasan){
    printf("idParent: %d\n", balasan.idParent);
    printf("id: %d\n", balasan.id);
    printf("banyakBalasan: %d\n", balasan.banyakBalasan);
    printf("text: ", balasan.text.TabWord);
    printf("nama: ", balasan.nama.TabWord);
}