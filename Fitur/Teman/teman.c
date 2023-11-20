#include "teman.h"
#include "../../ADT/GrafTeman/grafteman.h"
#include "../Perintah/perintah.h"
#include "../Global/global.h"

// Daftar teman
void daftarTeman(){
    int banyakTeman = countSalingTeman(globalGrafTeman, *globalCurrentAddrAkun);
    if(banyakTeman == 0){
        prinf("\n%s belum mempunyai teman\n", globalCurrentAddrAkun->username);
        return;
    }

    prinf("\n%s memiliki %d teman\n", globalCurrentAddrAkun->username, banyakTeman);

}

// Hapus teman
void hapusTeman(){
    printf("Masukkan nama pengguna: \n");
    readInput();

    printf("Apakah anda yakin ingin menghapus Bob dari daftar teman anda?(YA/TIDAK) \n");
    readInput();
}

