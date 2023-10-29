#include "kicauan.h"

int banyakKicauan;
Kicauan currentKicauan;
Kicauan listKicauan[100]; // sementara array dulu

void createKicauan();

void printKicauan(Kicauan kicauan);
void printKicauan(Kicauan kicauan){
    printf("| ID = %d\n", IDKICAU(kicauan));
    printf("| ");
    // --> printWord(PEMBUAT(kicauan)); printf("\n");
    printf("| ");
    // --> printDatetime(WAKTU(kicauan)); printf("\n");
    printf("| ");
    // --> printWord(TEXT_KICAU(kicauan)); printf("\n");
    printf("| Disukai : %d", JUMLAH_LIKE(kicauan));
}

void KICAU(Word currPengguna);
void KICAU(Word currPengguna){
    // Word input_kicauan;
    printf("Masukkan kicauan:\n");
    // <--Disini nanti diminta masukan input_kicauan
    printf("\n");
    // # Case 1 : input_kicauan hanya mengandung spasi saja

        // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");

    // # Case 2 : input_kicauan valid, terima maksimal 280 character

    // --> buat kicauan baru, masukin ke list_kicauan (ListDin)

    // Cetak pesan
    printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
    // printKicauan(getKicauan(l_kicauan,getLastIdx(l_kicauan)));
}
/*
void KICAUAN(ListDinKicauan l_kicauan, Word currPengguna);
void KICAUAN(ListDinKicauan l_kicauan, Word currPengguna){
    int i;
    if(isEmpty(l_kicauan)){
        printf("Belum ada kicauan nihh\n");
    }else{
        for(i=getLastIdx(l_kicauan); i>=0;i--){
            //if (isBerteman(currPengguna, getPembuatByIdx(l_kicauan,i))){printKicauan(getKicauan(l_kicauan,i))}
        }
    }
}

boolean isAkunPublicByPengguna(Word pengguna){}
boolean isBerteman(ListDinKicauan l, int id){}

void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan);
void SUKA_KICAUAN(int id_kicau, Word currPengguna,ListDinKicauan l_kicauan){
    // printf("\n");
    // if(!isIn(id_kicau,l_kicauan)){
    //     printf("Tidak ditemukan kicauan dengan ID = %d", id_kicau);
    // }else if(!isAkunPublicByPengguna(getPembuatById(l_kicauan,id_kicau)) && !isBerteman(currPengguna,getPembuatById(l_kicauan,id_kicau))){
    //     printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya!")
    // }else{
    //     setLike(id_kicau, l_kicauan, 1+getLike(id_kicau, l_kicauan));
    //     printf("Selamat! kicauan telah disukai!\nDetil kicauan:\n");
    //     printKicauan(getKicauan(l_kicauan,id_kicau));
    // }
    // printf("\n\n");
}

boolean isSama(Word w1, Word w2){}

void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan);
void UBAH_KICAUAN(int id_kicau, Word currPengguna, ListDinKicauan l_kicauan){
    if(!isIn(id_kicau,l_kicauan)){
        printf("Tidak ditemukan kicauan dengan ID = %d!", id_kicau);
    }else if(!isSama(currPengguna,getPembuatById(l_kicauan,id_kicau))){ // pre-requisite: boolean isSama(Word w1, Word w2)
        printf("Kicauan dengan ID = %d bukan milikmu!",id_kicau);
    }else{
        // Word input_kicauan;
        printf("Masukkan kicauan baru:\n");
        // <--Disini nanti diminta masukan input_kicauan
        printf("\n");
        // # Case 1 : input_kicauan hanya mengandung spasi saja

            // --> printf("Kicauan tidak boleh hanya berisi spasi!\n\n");

        // # Case 2 : input_kicauan valid, terima maksimal 280 character

        // --> buat kicauan baru, masukin ke list_kicauan (ListDin)

        // Cetak pesan
        printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        printKicauan(getKicauan(l_kicauan,getLastIdx(l_kicauan)));
    } 
}


*/
void DebugListKicauan(){
    printf("======== [Debug listKicauan] ========\n");
    int i;
    for(i=0;i<banyakKicauan;i++){
        printf("[Kicauan ke-%d]\n",i+1);
        displayKicauan(listKicauan[i]);
        printf("\n");
    }
    printf("======== [Debug listKicauan End] ========\n");
}
void displayKicauan(Kicauan kicauan){
    printf("id: %d\n", IDKICAU(kicauan));
    printf("text: %s\n", TEXT_KICAU(kicauan).TabWord);
    printf("like: %d\n", JUMLAH_LIKE(kicauan));
    printf("nama: %s\n", PEMBUAT(kicauan).TabWord);
    DisplayDateTime(WAKTU(kicauan));
}