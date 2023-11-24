#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/ListStatikAkun/liststatikakun.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../Global/global.h"
#include "balasan.h"
#include "../Perintah/perintah.h"
#include <stdio.h>

// Balas kicauan dengan idKicau dan idBalasan
void balas(int idKicau, int idBalasan){
    // 
    if(!isInListKicauan(idKicau, globalListDinKicauan)){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
        return;
    }
    Akun* akunYangDibalas = getKicauanById(globalListDinKicauan, idKicau).akunKicauan;
    if(!JenisAkun(Profil(*akunYangDibalas)) && !isAkunBerteman(globalGrafTeman,*akunYangDibalas, *globalCurrentAddrAkun)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
        return;
    }

    
    TreeBalasan newBalasan;
    CreateTreeBalasan(&newBalasan, globalCurrentAddrAkun);
    newBalasan.akunPembuat = globalCurrentAddrAkun;
    globalLastTreeBalasanId++;
    newBalasan.id = globalLastTreeBalasanId;

    if(idBalasan == -1){
        printf("\nMasukkan balasan:\n");
        readInput();
        newBalasan.text = currentWord;

        if(GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan == NULL){
            TreeBalasanAddress currentTreeBalasan = newTreeBalasan(newBalasan);
            GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan = currentTreeBalasan;
            globalBanyakKicauanBerbalasan++; // update global untuk config
        }else{
            TreeBalasanAddress balasanToReply = GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan;
            insertLastTreeBalasan(balasanToReply, newBalasan);
        }
    }else{
        
        TreeBalasanAddress balasanToReply = getTreeBalasanById(GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan, idBalasan);
        if(balasanToReply == NULL){
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
            return;
        }
        printf("\nMasukkan balasan:\n");
        readInput();
        newBalasan.text = currentWord;
        
        replyTreeBalasan(balasanToReply, newBalasan);
    }

    printf("\n\nSelamat! balasan telah diterbitkan!\n");

    printf("Detil balasan:\n");
    displayTreeBalasan(newBalasan, 0);
}




// leftMargin nentuin seberapa maju textnya ke kanan.
void displayTreeBalasanByAkun(TreeBalasan t, int leftMargin){

    int i = 0;
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    printf("| ID = %d\n", t.id);

    boolean isBerteman = isAkunBerteman(globalGrafTeman, *globalCurrentAddrAkun, *t.akunPembuat);

    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)) || !isBerteman)
        printf("| PRIVAT\n");
    else printf("| %s\n", t.akunPembuat->username.TabWord);
    
    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)) || !isBerteman)
        printf("| PRIVAT\n");
    else {printf("| "); DisplayDateTime(t.dateTime); printf("\n");}
    
    
    for(i = 0; i < leftMargin; i++){
        printf(LEFT_MARGIN_BLANK);
    }
    if(!JenisAkun(Profil(*t.akunPembuat)) || !isBerteman)
        printf("| PRIVAT\n");
    else printf("| %s\n", t.text.TabWord);
    printf("\n");
}
void displayTreeBalasanRecursiveByAkun(TreeBalasanAddress t, int depth){
    if(t == NULL) return;
    else{
        displayTreeBalasan(*t, depth);
        displayTreeBalasanRecursive(t->child, depth+1);
        displayTreeBalasanRecursive(t->nextSibling, depth);
    }
}
void displayAllTreeBalasanByAkun(TreeBalasan t){
    displayTreeBalasanRecursive(&t, 0);
}


// Tampilkan balasan dari kicauan dengan idKicau
void balasan(int idKicau){
    if(!isInListKicauan(idKicau, globalListDinKicauan)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n\n");
        return;
    }
    Kicauan kicauan = getKicauanById(globalListDinKicauan, idKicau);
    Akun* akunYangBerkicau = kicauan.akunKicauan;
    if(!JenisAkun(Profil(*akunYangBerkicau))){
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n\n");
        return;
    }

    if(kicauan.firstBalasan == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n\n");
        return;
    }
    displayAllTreeBalasanByAkun(*kicauan.firstBalasan);
}

// Hapus balasan dengan idBalasan dari kicauan dengan idKicau
void hapusBalasan(int idKicau, int idBalasan){
    if(GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan == NULL){
        printf("Balasan tidak ditemukan.\n\n");
        return;
    }

    TreeBalasanAddress balasanAddr = getTreeBalasanById(GET_ELMT_KICAUAN(globalListDinKicauan, idKicau-1).firstBalasan, idBalasan);
    if(balasanAddr == NULL){
        printf("Balasan tidak ditemukan.\n\n");
        return;
    }
    if(balasanAddr->akunPembuat->id != globalCurrentAddrAkun->id){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!.\n\n");
        return;
    }

    deleteCascadeTreeBalasan(balasanAddr);
    printf("Balasan berhasil dihapus.\n\n");

}