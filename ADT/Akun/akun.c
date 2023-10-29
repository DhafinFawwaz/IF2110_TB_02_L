#include <stdio.h>
#include "boolean.h"
#include "akun.h"
#include "../Pcolor/pcolor.h"

Akun currentAkun; // Global variable
Akun listAkun[20]; // Global variable
int banyakAkun;

void CreateAkun(Akun* akun){

}
void DisplayAkun(Akun akun){

}

void debugAkun(Akun akun){
    printf("nama: %s\n", akun.profil.nama.TabWord);
    printf("password: %s\n", akun.password.TabWord);
    printf("bio: %s\n", akun.profil.bio.TabWord);
    printf("noHp: %s\n", akun.profil.noHp.TabWord);
    printf("weton: %s\n", akun.profil.weton.TabWord);
    printf("isPublic: %s\n", jenisAkunToWord(akun.isPublic).TabWord);
    displayFoto(akun.profil.foto);
}
void DebugListAkun(Akun lAkun[]){
    printf("======== [Debug listAkun] ========\n");
    printf("banyakAkun: %d\n", banyakAkun);
    int i = 0;
    for(i = 0; i < banyakAkun; i++){
        printf("Akun ke-%d\n", i);
        debugAkun(lAkun[i]);
    }
    printf("======== [Debug listAkun End] ========\n");
}


boolean jenisAkunToBoolean(Word w){
    Word publik;
    setWord(&publik, "Publik");
    Word privat;
    setWord(&privat, "Privat");
    
    if(CompareWord(w, publik)){
        return true;
    } else if(CompareWord(w, privat)){
        return false;
    }
    printf("Publik/Privat comparison has an error!\n");
    printf("Comparing %s \n", w.TabWord);
    DebugListAkun(listAkun);
    return false;
}

Word jenisAkunToWord(boolean b){
    if(b){
        Word publik;
        setWord(&publik, "Publik");
        return publik;
    }else{
        Word privat;
        setWord(&privat, "Privat");
        return privat;
    }
}

