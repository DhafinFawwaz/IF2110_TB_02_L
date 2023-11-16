#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/ListStatikAkun/liststatikakun.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "balasan.h"
#include "../Perintah/perintah.h"
#include <stdio.h>

// Balas kicauan dengan idKicau dan idBalasan
void balas(int idKicau, int idBalasan){
    if(!isInListKicauan(idKicau)){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
        return;
    }
    Akun* akunYangDibalas = ADDR_KICAUAN(listKicauan, idKicau)->akunKicauan;;
    if(!akunYangDibalas->isPublic && !isAkunBerteman(currentGrafTeman,*akunYangDibalas, currentAkun)){
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
        return;
    }

    printf("\nMasukkan balasan:\n");
    readInput();
    TreeBalasan newTreeBalasan;
    CreateTreeBalasan(&newTreeBalasan);
    newTreeBalasan.akunPembuat = &currentAkun;
    newTreeBalasan.text = currentWord;

    if(idBalasan == -1){
        ADDR_KICAUAN(listKicauan, idKicau)->balasan = &newTreeBalasan;
    }else{
        TreeBalasanAddress balasanToReply = getTreeBalasanById(*currentTreeBalasan, idBalasan);
        replyTreeBalasan(balasanToReply, newTreeBalasan);
    }

    printf("\n\nSelamat! balasan telah diterbitkan!\n");

    printf("Detil balasan:\n");
    displayTreeBalasan(newTreeBalasan, 0);
    printf("\n");
}

// Tampilkan balasan dari kicauan dengan idKicau
void balasan(int idKicau){
    if(!isInListKicauan(idKicau)){
        printf("Tidak terdapat kicauan dengan id tersebut!\n\n");
        return;
    }
    Kicauan* kicauan = ADDR_KICAUAN(listKicauan, idKicau);
    Akun* akunYangBerkicau = kicauan->akunKicauan;
    if(!akunYangBerkicau->isPublic){
        printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n\n");
        return;
    }
    if(kicauan->balasan == NULL){
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n\n");
    }
    displayAllTreeBalasan(*kicauan->balasan);
}

// Hapus balasan dengan idBalasan dari kicauan dengan idKicau
void hapusBalasan(int idKicau, int idBalasan){
    Kicauan* kicauan = ADDR_KICAUAN(listKicauan, idKicau);
    if(kicauan->balasan == NULL){
        printf("Balasan tidak ditemukan.\n\n");
        return;
    }

    TreeBalasanAddress balasan = getTreeBalasanById(*(kicauan->balasan), idBalasan);
    if(balasan == NULL){
        printf("Balasan tidak ditemukan.\n\n");
    }
    if(balasan->akunPembuat != &currentAkun){
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!.\n\n");
    }

    deleteCascadeTreeBalasan(balasan);
    kicauan->balasan = NULL;
    printf("Balasan berhasil dihapus.\n\n");

}