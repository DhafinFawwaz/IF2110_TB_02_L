#include <stdio.h>
#include "inisialisasi.h"
#include "../../ADT/MesinKata/wordmachine.h"

char dataPath[] = "Config/";

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

Word cleanWord(Word w){
    int i = 0;
    for(i = w.Length; i < NMax; i++){
        w.TabWord[i] = '\0';
    }
    return w;
}

int wordToInt(Word w){
    int negativeMultiplier = 1;
    if(w.TabWord[0] == '-'){
        negativeMultiplier = -1;
    }
    int i = 0, result = 0;
    for(i = 0; i < w.Length; i++){
        result = result * 10 + (w.TabWord[i] - '0');
    }
    return result * negativeMultiplier;
}

void inisialisasi(){
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORD();
    ADVWORD(); // currentWord.TabWord = nama folder

    char balasanPath[NMax], drafPath[NMax], kicauanPath[NMax], penggunaPath[NMax], utasPath[NMax] = "";
    tripleConcat(dataPath, currentWord.TabWord, "/balasan.config", balasanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/draf.config", drafPath);
    tripleConcat(dataPath, currentWord.TabWord, "/kicauan.config", kicauanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/pengguna.config", penggunaPath);
    tripleConcat(dataPath, currentWord.TabWord, "/utas.config", utasPath);

    printf("\n");
    // Inisialisasi balasan
    freopen(balasanPath, "r", stdin);
    STARTWORD();
    int banyakKicauan = wordToInt(currentWord);
    printf("banyak kicauan: %d\n", banyakKicauan);
    int i = 0;
    for(i = 0; i < banyakKicauan; i++){
        ADVWORD();
        int id = wordToInt(currentWord);
        printf("id: %d\n", id);
        
    }
    printf("\n");
    

    // Inisialisasi balasan
    // freopen(drafPath, "r", stdin);
    // STARTWORD();
    // freopen(kicauanPath, "r", stdin);
    // STARTWORD();
    // freopen(kicauanPath, "r", stdin);
    // STARTWORD();
    // freopen(utasPath, "r", stdin);
    // STARTWORD();


    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
}