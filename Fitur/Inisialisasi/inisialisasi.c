#include <stdio.h>
#include "inisialisasi.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/Akun/akun.h"

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


void inisialisasi(){
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORD();
    ADVWORD(); // currentWord.TabWord = nama folder

    char dataPath[] = "Config/";
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
    freopen(balasanPath, "r", stdin);
    STARTWORD();
    int banyakKicauan = wordToInt(currentWord); // banyak kicauan yang memiliki balasan
    printf("banyakKicauan: %d\n", banyakKicauan);
    
    for(i = 0; i < banyakKicauan; i++){
        ADVWORD();
        int idKicauan = wordToInt(currentWord); // ID kicauan = 5
        printf("id kicauan: %d\n", idKicauan);

        ADVWORD();
        int banyakBalasan = wordToInt(currentWord); // Memiliki 4 balasan
        printf("banyak balasan: %d\n", banyakBalasan);

        int j = 0;
        for(j = 0; j < banyakBalasan; j++){
            ADVWORD();
            int idParentBalasan = wordToInt(currentWord);
            printf("id parent balasan: %d\n", idParentBalasan);

            ADVWORD();
            int idBalasan = wordToInt(currentWord);
            printf("id balasan: %d\n", idBalasan);

            ADVLINE();// Ini Balasan dari Node Utama, yaitu Kicauan ke-5
            Word text = cleanWord(currentWord);
            printf("text: %s\n", text.TabWord);

            ADVLINE();
            printf("nama: %s\n", cleanWord(currentWord).TabWord);
            
            ADVWORD();
            printf("date: %s\n", cleanWord(currentWord).TabWord);

            ADVWORD();
            printf("time: %s\n", cleanWord(currentWord).TabWord);
        }
    }

    // Inisialisasi draf
    printf("\n[Draf]\n");
    freopen(drafPath, "r", stdin);
    STARTWORD();
    int banyakDraf = wordToInt(currentWord);// 5 # Banyak draf
    for(i = 0; i < banyakDraf; i++){
        ADVWORD();
        printf("idDraf: %d\n", wordToInt(currentWord)); // 1 # draf dengan ID ke-1
        
        ADVLINE();
        printf("text: %s\n", cleanWord(currentWord).TabWord); // Hehe
        
        ADVLINE();
        printf("nama: %s\n", cleanWord(currentWord).TabWord); // Tuan Hak

        ADVWORD();
        printf("date: %s\n", cleanWord(currentWord).TabWord); // 14/10/2023

        ADVWORD();
        printf("time: %s\n", cleanWord(currentWord).TabWord); // 11:09:18
    }
    

   
    // Inisialisasi kicauan
    printf("\n[Kicauan]\n");
    freopen(kicauanPath, "r", stdin);
    STARTWORD();
    banyakKicauan = wordToInt(currentWord); // 2 # Banyak kicauan sebanyak 2
    for(i = 0; i < banyakKicauan; i++){
        ADVWORD();
        printf("idKicauan: %d\n", wordToInt(currentWord)); // 1 # ID kicauan 1

        ADVLINE();
        printf("text: %s\n", cleanWord(currentWord).TabWord); // Halooo

        ADVWORD();
        printf("like: %d\n", wordToInt(currentWord)); // 12 # Like

        ADVLINE();
        printf("nama: %s\n", cleanWord(currentWord).TabWord); // Tuan Bus

        ADVWORD();
        printf("date: %s\n", cleanWord(currentWord).TabWord); // 14/10/2023

        ADVWORD();
        printf("time: %s\n", cleanWord(currentWord).TabWord); // 11:09:18
    }
*/

    // Inisialisasi pengguna
    printf("\n[Pengguna]\n");
    freopen(penggunaPath, "r", stdin);
    STARTWORD();
    banyakAkun = wordToInt(currentWord); // 2 # Banyak pengguna
    for(i = 0; i < banyakAkun; i++){
        CreateAkun(&listAkun[i]);

        ADVLINE();
        listAkun[i].profil.nama = cleanWord(currentWord);

        ADVLINE();
        listAkun[i].password = cleanWord(currentWord);
        
        ADVLINE();
        listAkun[i].profil.bio = cleanWord(currentWord);
        
        ADVLINE();
        listAkun[i].profil.noHp = cleanWord(currentWord);

        ADVLINE();
        listAkun[i].profil.weton = cleanWord(currentWord);

        ADVLINE();
        listAkun[i].isPublic = jenisAkunToBoolean(cleanWord(currentWord));

        int j = 0;
        for(j = 0; j < FOTO_ROW_CAP; j++){
            int k = 0;
            for(k = 0; k < FOTO_COL_CAP; k++){
                ADVWORD();
                setColor(&(listAkun[i].profil.foto), j, k, currentWord.TabWord[0]);
                ADVWORD();
                setVal(&(listAkun[i].profil.foto), j, k, currentWord.TabWord[0]);
            }
        }
    }
    // Matriks Pertemanan
    DebugListAkun(listAkun);

/*
    // Inisialisasi pengguna
    printf("\n[Utas]\n");
    freopen(utasPath, "r", stdin);
    STARTWORD();
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
    // DebugListAkun(listAkun);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}