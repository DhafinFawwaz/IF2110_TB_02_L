#include <stdio.h>
#include "../profile.h"

int main() {
    int type;
    Profile P;
    Word username = stringToWord("Novel");

    CreateProfil(&P);

    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test isAkunPrivat()
            if (isAkunPrivat(P)) {
                printf("Akun is private.\n");
            } else {
                printf("Akun is not private.\n");
            }
            break;

        case 2:
            // Test isAkunPublik()
            if (isAkunPublik(P)) {
                printf("Akun is public.\n");
            } else {
                printf("Akun is not public.\n");
            }
            break;

        case 3:
            // Test changeBio()
            printf("Enter new bio: ");
            readInput();
            changeBio(&P, currentWord);
            displayProfil(P, username);
            break;

        case 4:
            // Test changeNomorHP()
            printf("Enter new phone number: ");
            char nomor;
            do{
                scanf(" %c", &nomor);
                if (nomor != ';'){
                    queueLinked_enqueue(&NomorHP(P), nomor);
                }
            } while (nomor != ';');
            changeNomorHP(&P, NomorHP(P));
            displayProfil(P, username);
            break;

        case 5:
            // Test changeWeton()
            printf("Enter new weton: ");
            readInput();
            changeWeton(&P, currentWord);
            displayProfil(P, username);
            break;

        case 6:
            // Test changeJenisAkun()
            changeJenisAkun(&P);
            if (isAkunPrivat(P)) {
                printf("Akun is private.\n");
            } else {
                printf("Akun is public.\n");
            }
            break;

        default:
            printf("Invalid test type.\n");
            break;
    }

    return 0;
}
