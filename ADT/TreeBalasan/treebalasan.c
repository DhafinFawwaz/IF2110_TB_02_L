#include "treebalasan.h"
#include "stdlib.h"
#include "stdio.h"

int banyakKicauanBerbalasan;
TreeBalasanAddress currentTreeBalasan;

TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan){
    TreeBalasanAddress new = (TreeBalasanAddress) malloc(sizeof(TreeBalasan));
    new->id = treebalasan.id;
    new->idParent = treebalasan.idParent;
    SetToCurrentDateTime(&new->dateTime);
    new->nama = treebalasan.nama;
    new->text = treebalasan.text;
    return new;
}

void CreateTreeBalasan(TreeBalasanAddress l){
    l = (TreeBalasanAddress) malloc(sizeof(TreeBalasan));
    l->idParent = -1;
    l->id = -1;
    SetToCurrentDateTime(&l->dateTime);
}

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    TreeBalasanAddress curr = l;
    while (curr->nextSibling != NULL)
    {
        curr = curr->nextSibling;
    }
    TreeBalasanAddress new = newTreeBalasan(inserted);
    curr->nextSibling = new;
    new->prevSibling = curr;
    new->parent = l->parent;
}

void replyTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    if(l->child == NULL){
        TreeBalasanAddress new = newTreeBalasan(inserted);
        l->child = new;
        new->parent = l;
    }else{
        insertLastTreeBalasan(l->child, inserted);
    }
}


// free semua child dan nextSibling dari l
void deleteTreeBalasanRecursive(TreeBalasanAddress l){
    if(l == NULL) return;
    else{
        if(l->child != NULL) deleteCascadeTreeBalasan(l->child);
        if(l->nextSibling != NULL) deleteCascadeTreeBalasan(l->nextSibling);
        free(l);
    }
}

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted. delete secara cascade
void deleteCascadeTreeBalasan(TreeBalasanAddress l){
    if(l->prevSibling == NULL && l->nextSibling == NULL){ // satu elemen
        if(l->child != NULL){
            deleteTreeBalasanRecursive(l->child);
            l->child = NULL;
        }
        if(l->parent != NULL){
            l->parent->child = NULL;
        }
        l = NULL;
    }else if(l->prevSibling == NULL){ // elemen pertama
        if(l->child != NULL){
            deleteTreeBalasanRecursive(l->child);
            l->child = NULL;
        }
        if(l->parent != NULL){
            l->parent->child = l->nextSibling;
        }
        l->nextSibling->prevSibling = NULL;
        *l = *(*l).nextSibling;
        free(l->prevSibling);
    }else if(l->nextSibling == NULL){ // elemen terakhir
        if(l->child != NULL){
            deleteTreeBalasanRecursive(l->child);
            l->child = NULL;
        }
        l->prevSibling->nextSibling = NULL;
        free(l);
    }else{ // elemen tengah
        if(l->child != NULL){
            deleteTreeBalasanRecursive(l->child);
            l->child = NULL;
        }
        l->prevSibling->nextSibling = l->nextSibling;
        l->nextSibling->prevSibling = l->prevSibling;
        free(l);
    }
}

int lengthTreeBalasan(TreeBalasan l){
    int count = 0;
    TreeBalasanAddress curr = &l;
    while (curr != NULL)
    {
        count++;
        curr = curr->nextSibling;
    }
    return count;
}
void debugTreeBalasan(TreeBalasanAddress l, int depth){
    if(l == NULL) return;
    else{
        int i = 0;
        for(i = 0; i < depth; i++){
            printf(" ");
        }
        printf("%d", l->id);
        if(l->prevSibling != NULL) printf("   %d<-", l->prevSibling->id);else printf("      ");
        if(l->parent != NULL) printf("   ^%d", l->parent->id);else printf("      ");
        if(l->nextSibling != NULL) printf("   ->%d", l->nextSibling->id);else printf("      ");
        printf("\n");

        debugTreeBalasan(l->child, depth+1);
        debugTreeBalasan(l->nextSibling, depth);
    }
}
void DebugCurrentTreeBalasan(){
    printf("====================== Debug currentTreeBalasan ======================\n");
    debugTreeBalasan(currentTreeBalasan, 0);
    printf("====================== Debug currentTreeBalasan End ======================\n");
}