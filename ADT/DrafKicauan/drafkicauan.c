#include <stdio.h>
#include "drafkicauan.h"
#include "../MesinKata/wordmachine.h"
#include "../../Fitur/Perintah/perintah.h"

int banyakDraf;
DrafKicauan listDraftkicauan[100];

void hapus_draf(){
    printf("Draf telah berhasil dihapus!");
}

void simpan_draf(){
    // [TO DO] currentAkun.drafKicauan.ID++ 
    printf("Draf telah berhasil disimpan!");
}

void terbit_draf(){
    // [TO DO] ubah nama variabel
    printf("Selamat! Draf kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    printf("| ID ");
    printf("| username");
    printf("| SetToCurrentDateTime(dt)");
    printf("| isiDrafKicauan <ID>");
    printf("| Disukai: ");
}

void buat_draf(){
    printf("Masukkan draf: ");
    readInput();
    Word isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
    readInput();

    // while ((compareWord("HAPUS", currentWord) != true) && (compareWord("SIMPAN", currentWord) != true) && (compareWord("TERBIT", currentWord) != true)){
    //     readInput();
    // }

    // if (compareWord(HAPUS_DRAF, currentWord)){
    //     hapus_draf();
    // } else if (compareWord(SIMPAN_DRAF, currentWord)){
    //     simpan_draf();
    // } else if (compareWord(TERBIT_DRAF, currentWord)){
    //     terbit_draf();
    // }
}
void ubah_draf(){
    printf("Masukkan draf yang baru:");
    readInput();

    Word isiDrafKicauan = currentWord;

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?");
    readInput();

    // sama kaya buat_draf
}

void lihat_draf(){
    printf("Ini draf terakhir anda: ");
    printf("| SetToCurrentDateTime(dt)");
    printf("| isiDrafKicauan <ID>");
}

void DebugDraftKicauan(DrafKicauan list){
    printf("id: %d\n", list.id);
    printf("text: ");
    printf("%s", list.text.TabWord);
    printf("\n");
    printf("nama: ");
    printf("%s", list.nama.TabWord);
    printf("\n");
    printf("dateTime: ");
    DisplayDateTime(list.dateTime);
    printf("\n");
}
void DebugListDraftKicauan(){
    printf("======== [Debug listDraftkicauan] ========\n");
    int i = 0;
    for(i = 0; i < banyakDraf; i++){
        printf("[Draf ke-%d]\n", i+1);
        DebugDraftKicauan(listDraftkicauan[i]);
    }
    printf("======== [Debug listDraftkicauan End] ========\n");
}