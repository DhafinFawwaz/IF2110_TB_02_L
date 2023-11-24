#include <stdio.h>
#include <sys/stat.h>
#include "inisialisasi.h"
#include "../Global/global.h"
#include "../../ADT/MesinKata/wordmachine.h"
#include "../../ADT/ListStatikAkun/liststatikAkun.h"
#include "../../ADT/StackBerkaitDraf/stackberkaitdraf.h"
#include "../../ADT/DateTime/datetime.h"
#include "../../ADT/ListDinKicauan/listdinkicauan.h"
#include "../../ADT/TreeBalasan/treebalasan.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../../ADT/StackBerkaitDraf/stackberkaitdraf.h"
#include "../../ADT/listKaitUtas/listkaitUtas.h"
#include "../Perintah/perintah.h"
#include "../../ADT/QueueBerkait/queuelinked.h"

const char dataPath[] = "Config/";

void createDirectory(char folderPath[NMax]){
    mkdir(folderPath, 0777);
    
}

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

void assignGlobalVariablesFromFiles(){
    char balasanPath[NMax], drafPath[NMax], kicauanPath[NMax], penggunaPath[NMax], utasPath[NMax] = "";
    tripleConcat(dataPath, currentWord.TabWord, "/balasan.config", balasanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/draf.config", drafPath);
    tripleConcat(dataPath, currentWord.TabWord, "/kicauan.config", kicauanPath);
    tripleConcat(dataPath, currentWord.TabWord, "/pengguna.config", penggunaPath);
    tripleConcat(dataPath, currentWord.TabWord, "/utas.config", utasPath);
    int i = 0;




    // =================================== Inisialisasi pengguna ===================================
    STARTWORDFILEREADER(penggunaPath);

    NEFF(globalListStatikAkun) = wordToInt(currentWord); // 2 # Banyak pengguna
    for(i = 0; i < NEFF(globalListStatikAkun); i++){
        CreateAkun(&CONTENT(globalListStatikAkun, i));
        CONTENT(globalListStatikAkun, i).id = i;

        ADVLINE();
        CONTENT(globalListStatikAkun, i).username = cleanWord(currentWord);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).password = cleanWord(currentWord);
        
        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.bio = cleanWord(currentWord);
        
        ADVLINE();
        QueueLinked ql;
        CONTENT(globalListStatikAkun, i).profil.nomor_hp = WordToQueueLinked(cleanWord(currentWord), &ql);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.weton = cleanWord(currentWord);

        ADVLINE();
        CONTENT(globalListStatikAkun, i).profil.jenis_akun = jenisAkunToBoolean(cleanWord(currentWord));

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
    // Prio queue permintaan pertemanan

    // debug
    // printf("%s\n", globalListStatikAkun.contents[0].username.TabWord);
    // printf("%s\n", globalListStatikAkun.contents[1].username.TabWord);
    // printf("%s\n", globalListStatikAkun.contents[2].username.TabWord);
    //

    
    // =================================== Inisialisasi kicauan ===================================
    // Harus setelah inisialisasi globalListStatikAkun
    STARTWORDFILEREADER(kicauanPath); 
    
    NEFF_LIST_KICAUAN(globalListDinKicauan) =  wordToInt(currentWord);// wordToInt(currentWord); 2 # Banyak kicauan sebanyak 2
    int lengthList = NEFF_LIST_KICAUAN(globalListDinKicauan);
    
    for(i = 0; i < lengthList; i++){
        Kicauan newKicauan;
        Word emptyWord;
        setWord(&emptyWord, "");
        createKicauan(&newKicauan, emptyWord);


        ADVWORD();
        newKicauan.id = wordToInt(currentWord); // 1 # ID kicauan 1

        ADVLINE();
        newKicauan.text = cleanWord(currentWord); // Halooo

        ADVWORD();
        newKicauan.likeCount = wordToInt(currentWord); // 12 # Like

        ADVLINE();
        // cari username di listStatikAkun
        Word username = cleanWord(currentWord);
        int idxAkun = findIdxByName(globalListStatikAkun, username);
        newKicauan.akunKicauan = &(CONTENT(globalListStatikAkun, idxAkun)); // Tuan Bus

        ADVWORD();
        SetDateFromWord(&newKicauan.dateTime, cleanWord(currentWord)); // 14/10/2023

        ADVWORD();
        SetTimeFromWord(&newKicauan.dateTime, cleanWord(currentWord)); // 11:09:18

        // insert at
        insertByIDKicauan(newKicauan, &globalListDinKicauan, newKicauan.id);
    }

    // debug
    // printf("%s\n", globalListDinKicauan.contents[0].text.TabWord);
    // printf("%s\n", globalListDinKicauan.contents[1].text.TabWord);
    //



    // =================================== Inisialisasi balasan ===================================
    // printf("\n[Balasan]\n");
    STARTWORDFILEREADER(balasanPath);
    globalBanyakKicauanBerbalasan = wordToInt(currentWord); // banyak kicauan yang memiliki balasan
    // printf("banyakKicauanBerbalasan: %d\n", banyakKicauanBerbalasan);
    
    
    for(i = 0; i < globalBanyakKicauanBerbalasan; i++){

        ADVWORD();
        int idKicauan = wordToInt(currentWord); // ID parent = 5

        Word emptyText;
        setWord(&emptyText, "");
        GET_KICAUAN_BY_ID(globalListDinKicauan, i).id = idKicauan;

        ADVWORD();
        int banyakBalasan = wordToInt(currentWord); // Memiliki 4 balasan

        int j = 0;
        for(j = 0; j < banyakBalasan; j++){
            TreeBalasan newBalasan;

            ADVWORD();
            newBalasan.idParent = wordToInt(currentWord); // ID parent = -1

            ADVWORD();
            newBalasan.id = wordToInt(currentWord); // ID balasan = 1
            globalLastTreeBalasanId = newBalasan.id; // update global untuk config

            ADVLINE();// Ini Balasan dari Node Utama, yaitu Kicauan ke-5
            newBalasan.text = cleanWord(currentWord);

            ADVLINE();
            int idxAkun = findIdxByName(globalListStatikAkun, cleanWord(currentWord));
            newBalasan.akunPembuat = &globalListStatikAkun.contents[idxAkun]; // Tuan Bri
            
            ADVWORD();
            SetDateFromWord(&newBalasan.dateTime, cleanWord(currentWord));

            ADVWORD();
            SetTimeFromWord(&newBalasan.dateTime, cleanWord(currentWord));
            
            if(newBalasan.idParent = -1){
                GET_ELMT_KICAUAN(globalListDinKicauan, i).firstBalasan = newTreeBalasan(newBalasan);
            }else{
                replyTreeBalasan(GET_ELMT_KICAUAN(globalListDinKicauan, i).firstBalasan, newBalasan);
            }
        }

        // masukin ke listdin
    }




    // =================================== Inisialisasi draf ===================================
    // printf("\n[Draf]\n");
    STARTWORDFILEREADER(drafPath);
    globalBanyakPenggunaBerDraf = wordToInt(currentWord);// 2 # Banyak draf

    for(i = 0; i < globalBanyakPenggunaBerDraf; i++){

        // Tuan Hak 3 # username pengguna dan banyak draf
        ADVLINE();
        Word username;
        int banyakDraf;
        setWordIntAfterLatestSpace(currentWord, &username, &banyakDraf);
        // printf("nama: %s| banyak: %d|\n", username.TabWord, banyakDraf);
        
        int idxAkun = findIdxByName(globalListStatikAkun, username);

        int j;
        for(j = 0; j < banyakDraf; j++){
            DrafKicauan newDraf;
            CreateDraftKicauan(&newDraf);
            
            ADVLINE();

            newDraf.text = cleanWord(currentWord); // Hehe 3     # isi draf

            ADVWORD();
            SetDateFromWord(&(newDraf.dateTime), cleanWord(currentWord)); // 14/10/2023

            ADVWORD();
            SetTimeFromWord(&(newDraf.dateTime), cleanWord(currentWord)); // 11:09:18
            
            // pushStackBerkaitDraf(&(globalListStatikAkun.contents[idxAkun].draf_kicauan), newDraf);
            // harus masukin dari belakang
            if(globalListStatikAkun.contents[idxAkun].draf_kicauan.addrTopDraf == NULL){
                pushStackBerkaitDraf(&globalListStatikAkun.contents[idxAkun].draf_kicauan, newDraf);
            }else{
                AddressDraf curr = globalListStatikAkun.contents[idxAkun].draf_kicauan.addrTopDraf;
                AddressDraf p = newNodeStackBerkaitDraf(newDraf);
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = p;
            }
        }
    }

    // Debug draf
    // for(i = 0; i < globalListStatikAkun.Neff; i++){
    //     printf("Username: %s\n", globalListStatikAkun.contents[i].username.TabWord);
    //     printf("Banyak draf: %d\n", lengthStackBerkaitDraf(globalListStatikAkun.contents[i].draf_kicauan));
    //     printf("Isi draf: \n");
    //     StackBerkaitDraf tempStack = globalListStatikAkun.contents[i].draf_kicauan;
    //     while(!isEmptyStackBerkaitDraf(tempStack)){
    //         DrafKicauan tempDraf;
    //         popStackBerkaitDraf(&tempStack, &tempDraf);
    //         printf("%s\n", tempDraf.text.TabWord);
    //         DisplayDateTime(tempDraf.dateTime);
    //         printf("\n");
    //     }
    // }
    // End debug draf


    
    // =================================== Inisialisasi Utas ===================================
    // printf("\n[Utas]\n");
    STARTWORDFILEREADER(utasPath);

    globalBanyakKicauanBerutas = wordToInt(currentWord); // 2 # Banyak kicauan yang memiliki utas
    for(i = 0; i < globalBanyakKicauanBerutas; i++) {
        ADVWORD(); // 1 # ID kicauan ke-2
        int idKicauan = wordToInt(currentWord);

        ADVWORD();
        int banyakUtas = wordToInt(currentWord); // 3 # memiliki 3 utas

        // GET_KICAUAN_BY_ID(globalListDinKicauan, idKicauan);

        int j = 0;
        for(j = 0; j < banyakUtas; j++){
            
            isi_utas newUtas;
            
            ADVLINE();
            newUtas.text = cleanWord(currentWord); // Utas ke-1

            ADVLINE(); // Nyonya Hil, ga guna

            ADVWORD();
            SetDateFromWord(&(newUtas.waktu), cleanWord(currentWord)); // 14/10/2023

            ADVWORD();
            SetTimeFromWord(&(newUtas.waktu), cleanWord(currentWord)); // 11:09:18

            Utas_insertLast(&(GET_KICAUAN_BY_ID(globalListDinKicauan, idKicauan).firstUtas), newUtas);

        }
    }


    // ============== Debug ================

    // ============== End Debug ================

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


    Word newLineWord;
    setWord(&newLineWord, "\n");
    
    // =================================== Save pengguna ===================================
    STARTWORDFILEWRITER(penggunaPath);

    WRITEINT(NEFF(globalListStatikAkun));
    WRITENL();

    for(i = 0; i < NEFF(globalListStatikAkun); i++){
        WRITEWORD(CONTENT(globalListStatikAkun, i).username);
        WRITENL();

        WRITEWORD(CONTENT(globalListStatikAkun, i).password);
        WRITENL();
        
        WRITEWORD(CONTENT(globalListStatikAkun, i).profil.bio);
        WRITENL();
        
        // WRITEWORD(CONTENT(globalListStatikAkun, i).profil.nomor_hp); // belum
        WRITENL();

        WRITEWORD(CONTENT(globalListStatikAkun, i).profil.weton);
        WRITENL();

        WRITEWORD(jenisAkunToWord(CONTENT(globalListStatikAkun, i).profil.jenis_akun));
        WRITENL();

        int j = 0;
        for(j = 0; j < FOTO_ROW_CAP; j++){
            int k = 0;
            for(k = 0; k < FOTO_COL_CAP; k++){
                WRITECHAR(Warna(CONTENT(globalListStatikAkun, i).profil.foto, j, k));
                WRITECHAR(' ');

                WRITECHAR(Simbol(CONTENT(globalListStatikAkun, i).profil.foto, j, k));
                if(k != FOTO_COL_CAP-1) // jangan print spasi di akhir
                    WRITECHAR(' ');
            }
            WRITENL();
        }
    }

    // Matriks Pertemanan
    for(i = 0; i < NEFF(globalListStatikAkun); i++){
        int j = 0;
        for(j = 0; j < NEFF(globalListStatikAkun); j++){
            WRITEINT(globalGrafTeman.buffer[i][j]);
            
            if(j != NEFF(globalListStatikAkun)-1)
                WRITECHAR(' ');
        }
        WRITENL();
    }

    // prio queue daftar pertemanan

    
    
    // =================================== Save kicauan ===================================
    // Harus setelah inisialisasi globalListStatikAkun
    STARTWORDFILEWRITER(kicauanPath); 
    
    WRITEINT(NEFF_LIST_KICAUAN(globalListDinKicauan));
    WRITENL();

    int lengthList = NEFF_LIST_KICAUAN(globalListDinKicauan);
    
    for(i = 0; i < lengthList; i++){
        Kicauan newKicauan = globalListDinKicauan.contents[i];

        WRITEINT(newKicauan.id);
        WRITENL();

        WRITEWORD(newKicauan.text);
        WRITENL();

        WRITEINT(newKicauan.likeCount);
        WRITENL();

        WRITEWORD(newKicauan.akunKicauan->username);
        WRITENL();

        WRITEWORD(dateTimeToWord(newKicauan.dateTime));
        WRITENL();

    }
    WRITENL();

    

    /*

    // =================================== Save balasan ===================================
    // printf("\n[Balasan]\n");
    STARTWORDFILEWRITER(balasanPath);
    WRITEINT(globalBanyakKicauanBerbalasan);    
    
    // BFS
    for(i = 0; i < globalBanyakKicauanBerbalasan; i++){

        ADVWORD();
        int idKicauan = wordToInt(currentWord); // ID parent = 5

        Word emptyText;
        setWord(&emptyText, "");
        GET_KICAUAN_BY_ID(globalListDinKicauan, i).id = idKicauan;

        ADVWORD();
        int banyakBalasan = wordToInt(currentWord); // Memiliki 4 balasan

        int j = 0;
        for(j = 0; j < banyakBalasan; j++){
            TreeBalasan newBalasan;

            ADVWORD();
            newBalasan.idParent = wordToInt(currentWord); // ID parent = -1

            ADVWORD();
            newBalasan.id = wordToInt(currentWord); // ID balasan = 1
            globalLastTreeBalasanId = newBalasan.id; // update global untuk config

            ADVLINE();// Ini Balasan dari Node Utama, yaitu Kicauan ke-5
            newBalasan.text = cleanWord(currentWord);

            ADVLINE();
            int idxAkun = findIdxByName(globalListStatikAkun, cleanWord(currentWord));
            newBalasan.akunPembuat = &globalListStatikAkun.contents[idxAkun]; // Tuan Bri
            
            ADVWORD();
            SetDateFromWord(&newBalasan.dateTime, cleanWord(currentWord));

            ADVWORD();
            SetTimeFromWord(&newBalasan.dateTime, cleanWord(currentWord));
            
            if(newBalasan.idParent = -1){
                GET_ELMT_KICAUAN(globalListDinKicauan, i).firstBalasan = newTreeBalasan(newBalasan);
            }else{
                replyTreeBalasan(GET_ELMT_KICAUAN(globalListDinKicauan, i).firstBalasan, newBalasan);
            }
        }

        // masukin ke listdin
    }

    */


    // =================================== Save draf ===================================
    // printf("\n[Draf]\n");
    STARTWORDFILEWRITER(drafPath);
    WRITEINT(globalBanyakPenggunaBerDraf);
    WRITENL();


    for(i = 0; i < globalListStatikAkun.Neff; i++){

        if(globalListStatikAkun.contents[i].draf_kicauan.addrTopDraf == NULL) continue;

        // Tuan Hak 3 # username pengguna dan banyak draf
        WRITEWORD(globalListStatikAkun.contents[i].username);
        WRITECHAR(' ');
        int banyakDraf = lengthStackBerkaitDraf(globalListStatikAkun.contents[i].draf_kicauan);
        WRITEINT(banyakDraf);
        WRITENL();

        int j = 0;
        for(j = 0; j < banyakDraf; j++){
            DrafKicauan newDraf;
            // CreateDraftKicauan(&newDraf);
            popStackBerkaitDraf(&(globalListStatikAkun.contents[i].draf_kicauan), &newDraf);
            
            // Hehe 3     # isi draf
            WRITEWORD(newDraf.text);
            WRITENL();

            WRITEWORD(dateTimeToWord(newDraf.dateTime));
            WRITENL();
        }
    }

    
 
    
    // =================================== Save Utas ===================================
    // printf("\n[Utas]\n");
    STARTWORDFILEWRITER(utasPath);
    WRITEINT(globalBanyakKicauanBerutas);
    WRITENL();

    Utas currentFirstUtas;
    Word currentFirstUtasOwnerName;
    Utas currentUtas;
    int currentFirstUtas_length;

    for(i = 0; i < globalListDinKicauan.nEff; i++) {
        if (!Utas_isEmpty(globalListDinKicauan.contents[i].firstUtas)){
            currentFirstUtas = globalListDinKicauan.contents[i].firstUtas;
            currentFirstUtas_length = Utas_length(currentFirstUtas);
            currentFirstUtasOwnerName = globalListDinKicauan.contents[i].akunKicauan->username;
            currentUtas = currentFirstUtas;
            WRITEINT(i+1);
            WRITENL();
            
            WRITEINT(currentFirstUtas_length);
            WRITENL();
            int j;
            
            for(j = 0; j < currentFirstUtas_length; j++){
                
                WRITEWORD(currentUtas->info_utas.text);
                WRITENL();
                WRITEWORD(currentFirstUtasOwnerName);
                WRITENL();
                WRITEWORD(dateTimeToWord(currentUtas->info_utas.waktu));
                WRITENL();
                currentUtas = NEXT_UTAS(currentUtas);

            }
            
            
        }
        
    }
    WRITENL();

    



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