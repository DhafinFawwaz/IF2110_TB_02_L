#include <stdio.h>
#include <sys/stat.h>
#include "inisialisasi.h"
#include "../Global/global.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/DrafKicauan/drafkicauan.h"
#include "../../ADT/DateTime/datetime.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../Perintah/perintah.h"

const char dataPath[] = "Config/";

void tripleConcat(char *s1, char *s2, char *s3, char *result){
    int i = 0, j = 0;
    while(s1[i] != '\0'){
        result[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0'){
        result[i] = s2[j];
        i++;
        j++;
    }
    j = 0;
    while(s3[j] != '\0'){
        result[i] = s3[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

void displayInisialisasi(){
    printf(".______    __    __  .______      .______    __  .______ \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\ \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  | \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      / \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----. \n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____| \n\n");

    printf("Selamat datang di BurBir. \n\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode \n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya. \n\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
}

boolean isDirectoryExists(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    if (S_ISDIR(stats.st_mode))
        return true;
    return false;
}

void inisialisasiConfig(){
    char folderPath[NMax] = "";
    
    readInput(); // currentWord.TabWord = nama folder
    tripleConcat(dataPath, currentWord.TabWord, "/", folderPath);
    
    while(!isDirectoryExists(folderPath)){
        printf("Tidak ada folder yang dimaksud!\n\n");
        printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    
        readInput();
        tripleConcat(dataPath, currentWord.TabWord, "/", folderPath);
    }
    assignGlobalVariablesFromFiles();
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}

void simpan(){
    printf("\nMasukkan nama folder penyimpanan.\n");
    char folderPath[NMax] = "";
    
    readInput(); // currentWord.TabWord = nama folder
    tripleConcat(dataPath, currentWord.TabWord, "/", folderPath);
    
    if(!isDirectoryExists(folderPath)){
        printf("Belum terdapat %s. Akan dilakukan pembuatan %s terlebih dahulu.\n\nMohon tunggu...\n1...\n2...\n3...", currentWord.TabWord, currentWord.TabWord);
        createDirectory(folderPath);
        printf("\n\n%s sudah berhasil dibuat.\n\n", currentWord.TabWord);
    }

    printf("Anda akan melakukan penyimpanan di %s.\n\nMohon tunggu...\n1...\n2...\n3...", currentWord.TabWord);
    writeGlobalVariablesToFiles();
    printf("\n\nPenyimpanan telah berhasil dilakukan!\n\n");
}

void muat(){
    printf("Masukkan nama folder yang hendak dimuat.\n");
    char folderPath[NMax] = "";
    
    readInput(); // currentWord.TabWord = nama folder
    tripleConcat(dataPath, currentWord.TabWord, "/", folderPath);
    
    if(!isDirectoryExists(folderPath)){
        printf("Tidak ada folder yang dimaksud!\n\n");
    }else{
        printf("Anda akan melakukan pemuatan dari %s.\n\nMohon tunggu...\n1...\n2...\n3...", currentWord.TabWord);
        assignGlobalVariablesFromFiles();
        printf("\n\nPemuatan selesai!\n\n");
    }
    
}

void assignGlobalVariablesFromFiles(){
    char balasanPath[NMax], drafPath[NMax], kicauanPath[NMax], penggunaPath[NMax], utasPath[NMax] = "";
    tripleConcat(dataPath, currentWord.TabWord, "/balasan.config", balasanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/draf.config", drafPath);
    tripleConcat(dataPath, currentWord.TabWord, "/kicauan.config", kicauanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/pengguna.config", penggunaPath);
    tripleConcat(dataPath, currentWord.TabWord, "/utas.config", utasPath);
    int i = 0;
/*
    // Inisialisasi balasan
    printf("\n[Balasan]\n");
    STARTWORDFILE(balasanPath);
    banyakKicauanBerbalasan = wordToInt(currentWord); // banyak kicauan yang memiliki balasan
    printf("banyakKicauanBerbalasan: %d\n", banyakKicauanBerbalasan);
    
    for(i = 0; i < banyakKicauanBerbalasan; i++){
        ADVWORD();
        listBalasan[i].idParent = wordToInt(currentWord); // ID parent = 5

        ADVWORD();
        listBalasan[i].banyakBalasan = wordToInt(currentWord); // Memiliki 4 balasan

        int j = 0;
        for(j = 0; j < listBalasan[i].banyakBalasan; j++){
            ADVWORD();
            listBalasan[j].idParent = wordToInt(currentWord); // ID balasan = 1

            ADVWORD();
            listBalasan[j].id = wordToInt(currentWord); // ID balasan = 1

            ADVLINE();// Ini Balasan dari Node Utama, yaitu Kicauan ke-5
            listBalasan[j].text = cleanWord(currentWord);

            ADVLINE();
            listBalasan[j].nama = cleanWord(currentWord);
            
            ADVWORD();
            SetDateFromWord(&listBalasan[i].dateTime, cleanWord(currentWord));

            ADVWORD();
            SetTimeFromWord(&listBalasan[i].dateTime, cleanWord(currentWord));
        }
    }

*/
    // Inisialisasi draf
    // printf("\n[Draf]\n");
    STARTWORDFILEREADER(drafPath);
    banyakDraf = wordToInt(currentWord);// 5 # Banyak draf

    for(i = 0; i < banyakDraf; i++){
        
        ADVWORD();
        listDraftkicauan[i].id = wordToInt(currentWord); // 1 # draf dengan ID ke-1
        
        ADVLINE();
        listDraftkicauan[i].text = cleanWord(currentWord); // Hehe
        
        ADVLINE();
        listDraftkicauan[i].nama = cleanWord(currentWord); // Tuan Hak

        ADVWORD();
        SetDateFromWord(&listDraftkicauan[i].dateTime, cleanWord(currentWord)); // 14/10/2023

        ADVWORD();
        SetTimeFromWord(&listDraftkicauan[i].dateTime, cleanWord(currentWord)); // 11:09:18
    }


 
    // Inisialisasi kicauan
    STARTWORDFILEREADER(kicauanPath);

    NEFF_LIST_KICAUAN(globalListDinKicauan) = wordToInt(currentWord); // 2 # Banyak kicauan sebanyak 2
    
    for(i = 0; i < NEFF_LIST_KICAUAN(globalListDinKicauan); i++){
        ADVWORD();
        // listDinKicauan.contents[i]->id = wordToInt(currentWord); // 1 # ID kicauan 1

        ADVLINE();
        // listDinKicauan.contents[i]->text = cleanWord(currentWord); // Halooo

        ADVWORD();
        // listDinKicauan.contents[i]->likeCount = wordToInt(currentWord); // 12 # Like

        ADVLINE();
        // listDinKicauan.contents[i]->namaPembuat = cleanWord(currentWord); // Tuan Bus

        ADVWORD();
        // SetDateFromWord(&(listDinKicauan.contents[i]->dateTime), cleanWord(currentWord)); // 14/10/2023

        ADVWORD();
        // SetTimeFromWord(&(listDinKicauan.contents[i]->dateTime), cleanWord(currentWord)); // 11:09:18
    }
    // DebugListKicauan();

    // Inisialisasi pengguna
    STARTWORDFILEREADER(penggunaPath);

    NEFF(globalListStatikAkun) = wordToInt(currentWord); // 2 # Banyak pengguna
    for(i = 0; i < NEFF(globalListStatikAkun); i++){
        CreateAkun(&CONTENT(globalListStatikAkun, i));

        ADVLINE();
        CONTENT(globalListStatikAkun, i).username = cleanWord(currentWord);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).password = cleanWord(currentWord);
        
        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.bio = cleanWord(currentWord);
        
        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.nomor_hp = cleanWord(currentWord);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.weton = cleanWord(currentWord);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).isPublic = jenisAkunToBoolean(cleanWord(currentWord));

        Foto foto;
        CreateFotoProfil(&foto);
        int j = 0;
        for(j = 0; j < FOTO_ROW_CAP; j++){
            int k = 0;
            for(k = 0; k < FOTO_COL_CAP; k++){
                ADVWORD();
                Warna(foto, j, k) = currentWord.TabWord[0];

                ADVWORD();
                Simbol(foto, j, k) = currentWord.TabWord[0];
            }
        }
        CONTENT(globalListStatikAkun, i).profil.foto = foto;
    }
    // Matriks Pertemanan
    CreateGrafTeman(&globalGrafTeman, NEFF(globalListStatikAkun));
    for(i = 0; i < NEFF(globalListStatikAkun); i++){
        int j = 0;
        for(j = 0; j < NEFF(globalListStatikAkun); j++){
            ADVWORD();
            if(currentWord.TabWord[0] == '1') setGrafTeman(&globalGrafTeman, i, j, true);
            else setGrafTeman(&globalGrafTeman, i, j, false);
        }
    }
    
    // DebugListAkun();
/*
    // Inisialisasi pengguna
    printf("\n[Utas]\n");
    STARTWORDFILE(utasPath);

    int banyakKicauanBerutas = wordToInt(currentWord); // 2 # Banyak kicauan yang memiliki utas
    for(i = 0; i < banyakKicauanBerutas; i++) {
        ADVWORD();
        printf("idKicauan: %d\n", wordToInt(currentWord)); // 1 # ID kicauan ke-2

        ADVWORD();
        int banyakUtas = wordToInt(currentWord); 
        printf("banyakUtas: %d\n", wordToInt(currentWord)); // 3 # memiliki 3 utas

        int j = 0;
        for(j = 0; j < banyakUtas; j++){
            ADVWORD();
            printf("idUtas: %d\n", wordToInt(currentWord)); // 1 # ID utas ke-1

            ADVLINE();
            printf("text: %s\n", cleanWord(currentWord).TabWord); // Nyonya Hil

            ADVLINE();
            printf("nama: %s\n", cleanWord(currentWord).TabWord); // Nyonya Hil

            ADVWORD();
            printf("date: %s\n", cleanWord(currentWord).TabWord); // 14/10/2023

            ADVWORD();
            printf("time: %s\n", cleanWord(currentWord).TabWord); // 11:09:18
        }
    }

*/

    



    // freopen("/dev/tty", "r", stdin);

}

void writeGlobalVariablesToFiles(){
    char balasanPath[NMax], drafPath[NMax], kicauanPath[NMax], penggunaPath[NMax], utasPath[NMax] = "";
    tripleConcat(dataPath, currentWord.TabWord, "/balasan.config", balasanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/draf.config", drafPath);
    tripleConcat(dataPath, currentWord.TabWord, "/kicauan.config", kicauanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/pengguna.config", penggunaPath);
    tripleConcat(dataPath, currentWord.TabWord, "/utas.config", utasPath);
    int i = 0;
    
    STARTWORDFILEWRITER(balasanPath);

    Word w;
    setWord(&w, "a\nb\nc\n");
    WRITEWORD(w);

    WRITEINT(1345);

    // STARTWORDFILEWRITER(drafPath);
    // STARTWORDFILEWRITER(kicauanPath);
    // STARTWORDFILEWRITER(penggunaPath);
    // STARTWORDFILEWRITER(utasPath);

}

void createDirectory(char folderPath[NMax]){
    mkdir(folderPath, 0777);
    
}