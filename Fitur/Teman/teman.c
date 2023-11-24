#include "teman.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../Perintah/perintah.h"
#include "../Global/global.h"

// Daftar teman
void daftarTeman(){
    int banyakTeman = countSalingTeman(globalGrafTeman, *globalCurrentAddrAkun);
    if(banyakTeman == 0){
        printf("\n%s belum mempunyai teman\n", globalCurrentAddrAkun->username);
        return;
    }

    printf("\n%s memiliki %d teman\n", globalCurrentAddrAkun->username.TabWord, banyakTeman);
    int i = 0;
    for(i = 0; i < GRAFTEMAN_SIZE(globalGrafTeman); i++){
        if(GRAFTEMAN_ELMT(globalGrafTeman, globalCurrentAddrAkun->id, i) && GRAFTEMAN_ELMT(globalGrafTeman, i, globalCurrentAddrAkun->id) && i!=globalCurrentAddrAkun->id){ // cek index akun.id 
            printf("| %s\n", globalListStatikAkun.contents[i].username.TabWord);
        }
    }
}

// Hapus teman
void hapusTeman(){
    printf("Masukkan nama pengguna: \n");
    readInput();

    int idxAkunTeman = findIdxByName(globalListStatikAkun, currentWord);
    if(idxAkunTeman == IDX_UNDEF){
        printf("%s bukan teman Anda.\n", currentWord.TabWord);
        return;
    }
    boolean isBerteman = isAkunBerteman(globalGrafTeman, *globalCurrentAddrAkun, globalListStatikAkun.contents[idxAkunTeman]);
    if(!isBerteman){
        printf("%s bukan teman Anda.\n", currentWord.TabWord);
        return;
    }

    printf("Apakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK) \n");
    Word YA, TIDAK;
    setWord(&YA, "YA");
    setWord(&TIDAK, "TIDAK");
    readInput();
    
    boolean isMasukanValid = false;
    while (!isMasukanValid)
    {
        if(compareWord(currentWord, YA)){
            GRAFTEMAN_ELMT(globalGrafTeman, globalCurrentAddrAkun->id, idxAkunTeman) = false;
            printf("Bob berhasil dihapus dari daftar teman Anda.\n");
            isMasukanValid = true;
        }else if(compareWord(currentWord, TIDAK)){
            printf("Penghapusan teman dibatalkan.\n");
            isMasukanValid = true;
        }
        else {
            isMasukanValid = false;
            printf("(YA/TIDAK)\n");
            readInput();
        }
    }
    


}

