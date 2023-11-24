#include "treebalasan.h"
#include "stdlib.h"
#include "stdio.h"

TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan){
    TreeBalasanAddress new = (TreeBalasanAddress) malloc(sizeof(TreeBalasan));
    new->idParent = treebalasan.idParent;
    new->id = treebalasan.id;
    new->akunPembuat = treebalasan.akunPembuat;
    new->text = treebalasan.text;
    new->dateTime = treebalasan.dateTime;
    new->child = treebalasan.child; 
    new->parent = treebalasan.parent;
    new->prevSibling = treebalasan.prevSibling;  
    new->nextSibling = treebalasan.nextSibling; 
    return new;
}

void CreateTreeBalasan(TreeBalasanAddress l, Akun *akunPembuat){
    l->idParent = -1;
    l->id = 1;
    l->akunPembuat = akunPembuat;
    
    l->nextSibling = NULL;
    l->prevSibling = NULL;
    l->parent = NULL;
    l->child = NULL;
    SetToCurrentDateTime(&l->dateTime);
}

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    // case 1: l kosong
    if(l == NULL){
        l = newTreeBalasan(inserted);
        return;
    }
    TreeBalasanAddress curr = l;
    while (curr->nextSibling != NULL)
    {
        curr = curr->nextSibling;
    }
    TreeBalasanAddress new = newTreeBalasan(inserted);
    new->idParent = l->idParent;
    curr->nextSibling = new;
    new->prevSibling = curr;
    new->parent = l->parent;
}

void replyTreeBalasan(TreeBalasanAddress l, TreeBalasan inserted){
    if(l->child == NULL){
        TreeBalasanAddress new = newTreeBalasan(inserted);
        new->idParent = l->id;
        l->child = new;
        new->parent = l;
    }else{
        inserted.idParent = l->id;
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
        printf(LEFT_MARGIN_BLANK);
    }
    printf("| ID = %d\n", t.id);

    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)) )
        printf("| PRIVAT\n");
    else printf("| %s\n", t.akunPembuat->username.TabWord);
    
    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)))
        printf("| PRIVAT\n");
    else printf("| "); DisplayDateTime(t.dateTime); printf("\n");
    
    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)))
        printf("| PRIVAT\n");
    else printf("| %s\n", t.text.TabWord);
    printf("\n");
}
void displayTreeBalasanRecursive(TreeBalasanAddress t, int depth){
    if(t == NULL) return;
    else{
        displayTreeBalasan(*t, depth);
        displayTreeBalasanRecursive(t->child, depth+1);
        displayTreeBalasanRecursive(t->nextSibling, depth);
    }
}
void displayAllTreeBalasan(TreeBalasan t){
    displayTreeBalasanRecursive(&t, 0);
}

TreeBalasanAddress getTreeBalasanById(TreeBalasanAddress treebalasan, int id){
    if(treebalasan == NULL) return NULL;
    else if(treebalasan->id == id) return treebalasan;
    else{
        TreeBalasanAddress curr = treebalasan->child;
        while (curr != NULL)
        {
            TreeBalasanAddress res = getTreeBalasanById(curr, id);
            if(res != NULL) return res;
            curr = curr->nextSibling;
        }
        return NULL;
    }
}

// TreeBalasanAddress getTreeBalasanById(TreeBalasanAddress treebalasan, int id){

// }
