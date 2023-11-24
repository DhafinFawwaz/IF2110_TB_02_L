#include <stdio.h>
#include "akun.h"
#include "../MesinKata/wordmachine.h"

int main() {
    Akun akun;
    int type;

    printf("Masukkan jenis uji (1-3): ");
    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test CreateAkun
            CreateAkun(&akun);
            printf("Akun berhasil dibuat.\n");
            break;

        case 2:
            // Test DisplayAkun
            CreateAkun(&akun);
            printf("Informasi Akun:\n");
            DisplayAkun(akun);
            printf("\n");
            break;

        case 3:
            // Test jenisAkunToBoolean and jenisAkunToWord
            printf("Masukkan kata (Publik/Privat): ");
            Word kata;
            readWord(&kata);
            boolean jenisBool = jenisAkunToBoolean(kata);
            Word jenisWord = jenisAkunToWord(jenisBool);
            printf("Boolean Value: %s\n", jenisBool ? "true" : "false");
            printf("Converted Word: ");
            printWord(jenisWord);
            printf("\n");
            break;

        default:
            printf("Jenis uji tidak valid.\n");
            break;
    }

    return 0;
}