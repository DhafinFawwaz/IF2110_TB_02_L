#include <stdio.h>
#include "boolean.h"
#include "akun.h"
#include "../Pcolor/pcolor.h"

Akun currentAkun; // Global variable

void CreateAkun(Akun* akun){

}
void DisplayAkun(Akun akun){

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

