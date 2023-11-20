#include "treebalasan.h"
#include "stdlib.h"
#include "stdio.h"

TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan){
    TreeBalasanAddress new = (TreeBalasanAddress) malloc(sizeof(TreeBalasan));
    new->id = treebalasan.id;
    new->idParent = treebalasan.idParent;
    SetToCurrentDateTime(&new->dateTime);
    new->akunPembuat = treebalasan.akunPembuat;
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
    new->id = curr->id + 1;
    curr->nextSibling = new;
    new->prevSibling = curr;
    new->parent = l->parent;
}

void replyTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    if(l->child == NULL){
        TreeBalasanAddress new = newTreeBalasan(inserted);
        new->id = 1;
        l->child = new;
        new->parent = l;
    }else{
        inserted.idParent = l->id;
        inserted.id = lengthTreeBalasan(*l->child) + 1;
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

// leftMargin nentuin seberapa maju textnya ke kanan.
void displayTreeBalasan(TreeBalasan t, int leftMargin){
    int i = 0;
    for(i = 0; i < leftMargin; i++){
        printf(" ");
    }
    printf("| ID = %d\n", t.id);
    for(i = 0; i < leftMargin; i++){
        printf(" ");
    }

    printf("| %s\n", t.akunPembuat->username.TabWord);
    for(i = 0; i < leftMargin; i++){
        printf(" ");
    }
    printf("| "); DisplayDateTime(t.dateTime); printf("\n");
    for(i = 0; i < leftMargin; i++){
        printf(" ");
    }
    printf("| %s\n", t.text.TabWord);
}
void displayTreeBalasanRecursive(TreeBalasanAddress t, int depth){
    if(t == NULL) return;
    else{
        displayTreeBalasan(*t, depth);
        debugTreeBalasan(t->child, depth+1);
        debugTreeBalasan(t->nextSibling, depth);
    }
}
void displayAllTreeBalasan(TreeBalasan t){
    displayTreeBalasanRecursive(&t, 0);
}

TreeBalasanAddress getTreeBalasanById(TreeBalasan treebalasan, int id){
    if(treebalasan.id == id) return &treebalasan;
    else{
        TreeBalasanAddress curr = treebalasan.child;
        while (curr != NULL)
        {
            TreeBalasanAddress res = getTreeBalasanById(*curr, id);
            if(res != NULL) return res;
            curr = curr->nextSibling;
        }
        return NULL;
    }
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
// void DebugCurrentTreeBalasan(){
//     printf("====================== Debug currentTreeBalasan ======================\n");
//     debugTreeBalasan(currentTreeBalasan, 0);
//     printf("====================== Debug currentTreeBalasan End ======================\n");
// }