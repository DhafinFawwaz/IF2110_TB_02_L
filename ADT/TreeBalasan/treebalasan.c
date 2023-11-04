#include "treebalasan.h"
#include "stdlib.h"

int banyakKicauanBerTreeBalasan;
TreeBalasan currentTreeBalasan;
TreeBalasan listTreeBalasan[LISTDIN_BALASAN_DEFAULT_CAPACITY];

void CreateTreeBalasan(TreeBalasan *l, int capacity){
    l = (TreeBalasan*) malloc(capacity*sizeof(TreeBalasan));
    (*l).childNeff = 0;
    (*l).childCapacity = capacity;
}

void dealocateTreeBalasan(TreeBalasan *l){
    free(l);
    (*l).childNeff = 0;
    (*l).childCapacity = 0;
}

boolean isListdinTreeBalasanFull(TreeBalasan l){
    return (l.childNeff == l.childCapacity);
}

// Memasukkan inserted ke *l
void insertAtTreeBalasan(TreeBalasan *l, int idx, TreeBalasan inserted){
    if(isListdinTreeBalasanFull(*l)){
        (*l).childCapacity *= 2;
        (*l).listdinBalasan = (TreeBalasan*) realloc((*l).listdinBalasan, (*l).childCapacity*sizeof(TreeBalasan));
    }else{
        int i;
        for(i = (*l).childNeff; i > idx; i--){
            (*l).listdinBalasan[i] = (*l).listdinBalasan[i-1];
        }
        (*l).listdinBalasan[idx] = inserted;
        (*l).childNeff++;
    }
}

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasan *l, TreeBalasan inserted){

}

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted
void deleteAtTreeBalasan(TreeBalasan *l, int idx, TreeBalasan *deleted){

}

void copyTreeBalasan(TreeBalasan *destination, TreeBalasan source){
    // int i = destination->childNeff;

}


void DebugListTreeBalasan();

/*
void DebugListTreeBalasan(){
    printf("======== [Debug listTreeBalasan] ========\n");
    int i = 0;
    for(i = 0; i < banyakKicauanBerTreeBalasan; i++){
        printf("[TreeBalasan ke-%d]\n", i+1);
        displayTreeBalasan(listTreeBalasan[i]);
    }
    printf("======== [Debug listTreeBalasan End] ========\n");
}

void displayTreeBalasan(TreeBalasan TreeBalasan){
    printf("idParent: %d\n", TreeBalasan.idParent);
    printf("id: %d\n", TreeBalasan.id);
    printf("banyakTreeBalasan: %d\n", TreeBalasan.banyakTreeBalasan);
    printf("text: ", TreeBalasan.text.TabWord);
    printf("nama: ", TreeBalasan.nama.TabWord);
}
*/