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
    curr->nextSibling = newTreeBalasan(inserted);
}

void replyTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    if(l->child == NULL){
        l->child = newTreeBalasan(inserted);
    }else{
        insertLastTreeBalasan(l->child, inserted);
    }
}

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted. delete secara cascade
void deleteAtTreeBalasan(TreeBalasanAddress l, int idx, TreeBalasan *deleted){
    if(idx == 0){
        *deleted = *l;
        *l = *(l->nextSibling);
    }else{
        TreeBalasanAddress curr = l;
        int i = 0;
        while (i < idx-1)
        {
            curr = curr->nextSibling;
            i++;
        }
        *deleted = *(curr->nextSibling);
        curr->nextSibling = curr->nextSibling->nextSibling;
    }
    if(deleted->child != NULL){
        deleteAtTreeBalasan(deleted->child, 0, deleted);
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
        printf("%d\n", l->id);
        debugTreeBalasan(l->child, depth+1);
        debugTreeBalasan(l->nextSibling, depth);
    }
}
void DebugCurrentTreeBalasan(){
    printf("====================== Debug currentTreeBalasan ======================\n");
    debugTreeBalasan(currentTreeBalasan, 0);
    printf("====================== Debug currentTreeBalasan End ======================\n");
}