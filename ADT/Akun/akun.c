#include <stdio.h>
#include "../Boolean/boolean.h"
#include "akun.h"
#include "../Pcolor/pcolor.h"

void CreateAkun(Akun* akun){
    
}
void DisplayAkun(Akun akun){

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

