#include <stdio.h>
#include "akun.h"

#include "../Boolean/boolean.h"
#include "../Pcolor/pcolor.h"
#include "../Profile/profile.h"
#include "../GrafTeman/grafteman.h"

void CreateAkun(Akun* akun){
    akun = (Akun*) malloc(sizeof(Akun));

    (akun)->id = 0;
    CreateProfil(&(akun)->profil);

    setWord(&(akun)->username, "");
    setWord(&(akun)->password, "");

    CreateDaftar(&DaftarPermintaan(*akun), 19);
    createStackBerkaitDraf(&(akun)->draf_kicauan);
}

void DisplayAkun(Akun akun){
    printf("ID: %d\n", akun.id);

    displayProfil(Profil(akun), Username(akun));

    printf("Username: ");
    printWord(Username(akun));
    printf("Password: ");
    printWord(Password(akun));

    // list permintaan pertemanan
}


boolean jenisAkunToBoolean(Word w){
    Word publik;
    setWord(&publik, "Publik");
    Word privat;
    setWord(&privat, "Privat");
    
    if(compareWord(w, publik)){
        return true;
    } else if(compareWord(w, privat)){
        return false;
    }
    printf("Publik/Privat comparison has an error!\n");
    printf("Comparing %s \n", w.TabWord);
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

