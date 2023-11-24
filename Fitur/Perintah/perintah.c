#include "perintah.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../Balasan/balasan.h"
#include "../Pengguna/pengguna.h"
#include "../Kicauan/kicauan.h"
#include "../DrafKicauan/drafkicauan.h"
#include "../Utas/utas.h"
#include "../Profil/profil.h"
#include "../KelompokTeman/kelompokTeman.h"
#include "../Tagar/tagar.h"
#include <stdio.h>

#define MAX_ARGUMENT 3

Word DAFTAR = {.TabWord = "DAFTAR", .Length = 6};
Word MASUK = {.TabWord = "MASUK", .Length = 5};
Word KELUAR = {.TabWord = "KELUAR", .Length = 6};
Word TUTUP_PROGRAM = {.TabWord = "TUTUP_PROGRAM", .Length = 13};

Word GANTI_PROFIL = {.TabWord = "GANTI_PROFIL", .Length = 12};
Word LIHAT_PROFIL = {.TabWord = "LIHAT_PROFIL", .Length = 12}; // LIHAT_PROFIL listAkun[i].nama;
Word ATUR_JENIS_AKUN = {.TabWord = "ATUR_JENIS_AKUN", .Length = 15};
Word UBAH_FOTO_PROFIL = {.TabWord = "UBAH_FOTO_PROFIL", .Length = 16};

Word DAFTAR_TEMAN = {.TabWord = "DAFTAR_TEMAN", .Length = 12};
Word HAPUS_TEMAN = {.TabWord = "HAPUS_TEMAN", .Length = 11};

Word TAMBAH_TEMAN = {.TabWord = "TAMBAH_TEMAN", .Length = 12};
Word DAFTAR_PERMINTAAN_PERTEMANAN = {.TabWord = "DAFTAR_PERMINTAAN_PERTEMANAN", .Length = 28};
Word SETUJUI_PERTEMANAN = {.TabWord = "SETUJUI_PERTEMANAN", .Length = 18};

Word KICAU = {.TabWord = "KICAU", .Length = 5};
Word KICAUAN = {.TabWord = "KICAUAN", .Length = 7};
Word SUKA_KICAUAN = {.TabWord = "SUKA_KICAUAN", .Length = 12}; // SUKA_KICAUAN <id kicauan>;
Word UBAH_KICAUAN = {.TabWord = "UBAH_KICAUAN", .Length = 12}; // UBAH_KICAUAN <id kicauan>;
Word CARI_KICAUAN = {.TabWord = "CARI_KICAUAN", .Length = 12}; // CARI_KICAUAN <tagar>;

Word BALAS = {.TabWord = "BALAS", .Length = 5}; // BALAS <id kicauan> <id balasan>;
Word BALASAN = {.TabWord = "BALASAN", .Length = 7}; // BALASAN <id kicauan>;
Word HAPUS_BALASAN = {.TabWord = "HAPUS_BALASAN", .Length = 13}; // HAPUS_BALASAN <id kicauan> <id balasan>;

Word BUAT_DRAF = {.TabWord = "BUAT_DRAF", .Length = 9};
Word LIHAT_DRAF = {.TabWord = "LIHAT_DRAF", .Length = 10};
Word UBAH_DRAF = {.TabWord = "UBAH", .Length = 4};
Word KEMBALI_DRAF = {.TabWord = "KEMBALI", .Length = 7};
Word HAPUS_DRAF = {.TabWord = "HAPUS", .Length = 5};
Word SIMPAN_DRAF = {.TabWord = "SIMPAN", .Length = 6};
Word TERBIT_DRAF = {.TabWord = "TERBIT", .Length = 6};

Word UTAS = {.TabWord = "UTAS", .Length = 4}; // UTAS <id kicauan>;
Word SAMBUNG_UTAS = {.TabWord = "SAMBUNG_UTAS", .Length = 12}; // SAMBUNG_UTAS <id utas> <index>;
Word HAPUS_UTAS = {.TabWord = "HAPUS_UTAS", .Length = 10}; // HAPUS_UTAS <id utas> <index>;
Word CETAK_UTAS = {.TabWord = "CETAK_UTAS", .Length = 10}; // CETAK_UTAS <id utas>;

Word KELOMPOK_TEMAN = {.TabWord = "KELOMPOK_TEMAN", .Length = 14}; // KELOMPOK_TEMAN;

Word SIMPAN = {.TabWord = "SIMPAN", .Length = 6};
Word MUAT = {.TabWord = "MUAT", .Length = 4};

Word LIST_PERINTAH = {.TabWord = "LIST_PERINTAH", .Length = 13};


void readInput(){
    int i;
    START();
    IgnoreBlanks();

    currentWord.Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    currentWord.Length = i;

    currentWord.TabWord[i] = '\0';
}
void extractPerintah(Word input, Word perintahArgumen[]){
    int i = 0;
    int j = 0;
    int blankCount = 0;
    while(i < input.Length){
        if(input.TabWord[i] == BLANK){
            blankCount++;
            j = 0;
            while(input.TabWord[i] == BLANK)i++;
        }else{
            perintahArgumen[blankCount].Length = j+1;
            perintahArgumen[blankCount].TabWord[j] = input.TabWord[i];
            perintahArgumen[blankCount].TabWord[j+1] = '\0';
            j++;
            i++;
        }
    }
    // set sisa array jadi \0
    for(i = blankCount+1; i < MAX_ARGUMENT; i++){
        perintahArgumen[i].TabWord[0] = '\0';
    }
}

void displayListPerintah(){
    
    printf("[LIST PERINTAH]\n");

    printf("| DAFTAR\n");
    printf("| MASUK\n");
    printf("| KELUAR\n");
    printf("| TUTUP_PROGRAM\n");
    printf("\n");

    printf("| GANTI_PROFIL\n");
    printf("| LIHAT_PROFIL <nama pengguna>\n");
    printf("| ATUR_JENIS_AKUN\n");
    printf("| UBAH_FOTO_PROFIL\n");
    printf("\n");

    printf("| DAFTAR_TEMAN\n");
    printf("| HAPUS_TEMAN\n");
    printf("\n");

    printf("| TAMBAH_TEMAN\n");
    printf("| DAFTAR_PERMINTAAN_PERTEMANAN\n");
    printf("| SETUJUI_PERTEMANAN\n");
    printf("\n");

    printf("| KICAU\n");
    printf("| KICAUAN\n");
    printf("| SUKA_KICAUAN <id kicauan>\n");
    printf("| UBAH_KICAUAN <id kicauan>\n");
    printf("\n");

    printf("| BALAS <id kicauan> <id balasan>\n");
    printf("| BALASAN <id kicauan>\n");
    printf("| HAPUS_BALASAN <id kicauan> <id balasan>\n");
    printf("\n");
    
    printf("| BUAT_DRAF\n");
    printf("| LIHAT_DRAF\n");
    printf("\n");

    printf("| UBAH_DRAF\n");
    printf("| KEMBALI_DRAF\n");
    printf("\n");

    printf("| HAPUS_DRAF\n");
    printf("| SIMPAN_DRAF\n");
    printf("| TERBIT_DRAF\n");
    printf("\n");
    
    printf("| UTAS <id kicauan>\n");
    printf("| SAMBUNG_UTAS <id utas> <index>\n");
    printf("| HAPUS_UTAS <id utas> <index>\n");
    printf("| CETAK_UTAS <id utas>\n");
    printf("\n");

    printf("| KELOMPOK_TEMAN\n");
    printf("\n");

    printf("| SIMPAN\n");
    printf("| MUAT\n");
    printf("\n");

    printf("| LIST_PERINTAH\n");
    printf("\n");
}

void displayBelumLogin(){
    printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
}

void handlePerintah(){
    printf(">> ");

    readInput();
    Word perintahArgumen[MAX_ARGUMENT];
    extractPerintah(currentWord, perintahArgumen);
    // printf("%s\n", perintahArgumen[0].TabWord);

    if(compareWord(perintahArgumen[0], DAFTAR))daftar();
    else if(compareWord(perintahArgumen[0], MASUK))masuk();
    else if(compareWord(perintahArgumen[0], KELUAR))keluar();
    else if(compareWord(perintahArgumen[0], TUTUP_PROGRAM))tutup_program();


    else if(compareWord(currentWord, GANTI_PROFIL)){
        if(!isLogin){ displayBelumLogin(); return; }
        ganti_profil();
    }
    else if(compareWord(perintahArgumen[0], LIHAT_PROFIL)){  // LIHAT_PROFIL <nama pengguna>;
        if(!isLogin){ displayBelumLogin(); return; }
        Word nama = getWordAfterFirstSpace(currentWord);
        lihat_profil_other(nama);
    }
    else if(compareWord(perintahArgumen[0], ATUR_JENIS_AKUN)){
        if(!isLogin){ displayBelumLogin(); return; }
        atur_jenis_akun();
    }
    else if(compareWord(perintahArgumen[0], UBAH_FOTO_PROFIL)){
        if(!isLogin){ displayBelumLogin(); return; }
        ubah_foto_profil();
    }

    else if(compareWord(perintahArgumen[0], DAFTAR_TEMAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        daftarTeman();
    }
    else if(compareWord(perintahArgumen[0], HAPUS_TEMAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        hapusTeman();
    }

    else if(compareWord(perintahArgumen[0], TAMBAH_TEMAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        tambah_teman();
    }
    else if(compareWord(perintahArgumen[0], DAFTAR_PERMINTAAN_PERTEMANAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        daftar_permintaan();
    }
    else if(compareWord(perintahArgumen[0], SETUJUI_PERTEMANAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        setujui_pertemanan();
    }

    else if(compareWord(perintahArgumen[0], KICAU)){
        if(!isLogin){ displayBelumLogin(); return; }
        kicau();
    }
    else if(compareWord(perintahArgumen[0], KICAUAN)){
        if(!isLogin){ displayBelumLogin(); return; }
        kicauan();
    }
    else if(compareWord(perintahArgumen[0], SUKA_KICAUAN)){ // SUKA_KICAUAN <id kicauan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        sukaKicauan(idKicauan);
    }
    else if(compareWord(perintahArgumen[0], UBAH_KICAUAN)){  // UBAH_KICAUAN <id kicauan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        ubahKicauan(idKicauan);
    }

    else if(compareWord(perintahArgumen[0], CARI_KICAUAN)){
        if(!isLogin){displayBelumLogin();return;}
        Word tagar;
        setWord(&tagar,perintahArgumen[1].TabWord);
        cariKicauan(tagar);
    }

    else if(compareWord(perintahArgumen[0], BALAS)){ // BALAS <id kicauan> <id balasan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        int idBalasan = wordToInt(perintahArgumen[2]);
        balas(idKicauan, idBalasan);
    }
    else if(compareWord(perintahArgumen[0], BALASAN)){ // BALASAN <id kicauan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        balasan(idKicauan);
    }
    else if(compareWord(perintahArgumen[0], HAPUS_BALASAN)){ // HAPUS_BALASAN <id kicauan> <id balasan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        int idBalasan = wordToInt(perintahArgumen[2]);
        hapusBalasan(idKicauan, idBalasan);
    }

    else if(compareWord(perintahArgumen[0], BUAT_DRAF)){
        if(!isLogin){ displayBelumLogin(); return; }
        buat_draf(globalCurrentAddrAkun->draf_kicauan);
    }
    else if(compareWord(perintahArgumen[0], LIHAT_DRAF)){
        if(!isLogin){ displayBelumLogin(); return; }
        lihat_draf();
    }

    else if(compareWord(perintahArgumen[0], UTAS)){ // UTAS <id kicauan>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idKicauan = wordToInt(perintahArgumen[1]);
        buatUtas(idKicauan);
    }
    else if(compareWord(perintahArgumen[0], SAMBUNG_UTAS)){ // SAMBUNG_UTAS <id utas> <index>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idUtas = wordToInt(perintahArgumen[1]);
        int index = wordToInt(perintahArgumen[2]);
        sambungUtas(idUtas, index);
    }
    else if(compareWord(perintahArgumen[0], HAPUS_UTAS)){ // HAPUS_UTAS <id utas> <index>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idUtas = wordToInt(perintahArgumen[1]);
        int index = wordToInt(perintahArgumen[2]);
        hapusUtas(idUtas, index);
    }
    else if(compareWord(perintahArgumen[0], CETAK_UTAS)){ // CETAK_UTAS <id utas>;
        if(!isLogin){ displayBelumLogin(); return; }
        int idUtas = wordToInt(perintahArgumen[1]);
        cetakUtas(idUtas);
    }

    else if(compareWord(perintahArgumen[0], KELOMPOK_TEMAN)) { // KELOMPOK_TEMAN
        if(!isLogin){ displayBelumLogin(); return; }
        KelompokTeman();
    }

    else if(compareWord(perintahArgumen[0], SIMPAN)){
        simpan();
    }
    else if(compareWord(perintahArgumen[0], MUAT)){
        if(isLogin){ printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n\n"); return; }
        muat();
    }

    else if(compareWord(perintahArgumen[0], LIST_PERINTAH))displayListPerintah();


    else {
        printf("Perintah tidak dikenali. Gunakan 'LIST_PERINTAH' untuk melihat list perintah yang bisa dilakukan.\n\n");
    } 
}