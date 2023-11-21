/* File: permintaan.c */
/* Fitur Permintaan Pertemanan */

#include <stdio.h>
#include "permintaan.h"

/* *** DAFTAR PERINTAH FITUR PERMINTAAN PERTEMANAN *** */
/* I.S. terdapat pengguna yang login */
void tambah_teman(){
/* Mengirim permintaan pertemanan ke suatu pengguna */
    if (!isDaftarEmpty(DaftarPermintaan(*globalCurrentAddrAkun))){
        printf("\nTerdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    }
    else{ // Daftar permintaan pertemanan kosong
        printf("\nMasukkan nama pengguna:\n");
        readInput();
        Word nama = currentWord;
        int othersID = findIdxByName(globalListStatikAkun, nama);
        if (othersID == IDX_UNDEF){
            printf("\nPengguna bernama %s tidak ditemukan.\n", wordToString(nama));
        } 
        else{ // Pengguna yang ingin dikirimi permintaan pertemanan ditemukan
            Akun akunTujuan = CONTENT(globalListStatikAkun, othersID);
            if (isAkunBerteman(globalGrafTeman, *globalCurrentAddrAkun, akunTujuan)){
                printf("\nAnda sudah berteman dengan %s.\n", wordToString(nama));
            }
            else{ // Belum berteman
                if (isAkunMintaBerteman(globalGrafTeman, *globalCurrentAddrAkun, akunTujuan)){
                    printf("\nAnda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n", wordToString(nama));
                }
                else{ // Belum mengirimkan permintaan pertemanan
                    GRAFTEMAN_ELMT(globalGrafTeman, globalCurrentAddrAkun->id, akunTujuan.id) = true;
                    permintaan currPermintaan;
                    NamaMinta(currPermintaan) = Username(*globalCurrentAddrAkun);
                    JumlahTeman(currPermintaan) = countTeman(globalGrafTeman, *globalCurrentAddrAkun);
                    enqueuePermintaan(&DaftarPermintaan(akunTujuan), currPermintaan);
                    printf("\nPermintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n", wordToString(nama));
                }
            }
        }
    }
}

void daftar_permintaan(){
/* Melihat daftar permintaan pertemanan pengguna */
    if (isDaftarEmpty(DaftarPermintaan(*globalCurrentAddrAkun))){
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n");
    }
    else{
        printf("\nTerdapat %d permintaan pertemanan untuk Anda.\n", panjangDaftar(DaftarPermintaan(*globalCurrentAddrAkun)));
        displayDaftar(DaftarPermintaan(*globalCurrentAddrAkun));
    }
}

void setujui_pertemanan(){
/* Menentukan apakah ingin menyetujui suatu permintaan pertemanan atau tidak */
    if (isDaftarEmpty(DaftarPermintaan(*globalCurrentAddrAkun))){
        printf("\nTidak ada permintaan pertemanan untuk Anda.\n");
    }
    else{
        displayTopPermintaan(DaftarPermintaan(*globalCurrentAddrAkun));
        Word namaPeminta = NamaMinta(HeadPermintaan(DaftarPermintaan(*globalCurrentAddrAkun)));
        int othersID = findIdxByName(globalListStatikAkun, namaPeminta);
        Akun akunPeminta = CONTENT(globalListStatikAkun, othersID);
        permintaan teratas;
        printf("\nApakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        readInput();
        if (compareWord(currentWord, stringToWord("YA"))){
            GRAFTEMAN_ELMT(globalGrafTeman, globalCurrentAddrAkun->id, akunPeminta.id) = true;
            dequeuePermintaan(&DaftarPermintaan(*globalCurrentAddrAkun), &teratas);
            printf("\n\nPermintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.\n", wordToString(namaPeminta));
        }
        else if (compareWord(currentWord, stringToWord("TIDAK"))){
            GRAFTEMAN_ELMT(globalGrafTeman, akunPeminta.id, globalCurrentAddrAkun->id) = false;
            dequeuePermintaan(&DaftarPermintaan(*globalCurrentAddrAkun), &teratas);
            printf("\n\nPermintaan pertemanan dari %s telah ditolak.\n", wordToString(namaPeminta));
        }
    }
}