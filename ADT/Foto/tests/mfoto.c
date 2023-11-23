#include <stdio.h>
#include "../foto.h"

int main(){
    int type;
    Foto foto;

    scanf("%d", &type);

    switch (type){
        case 1:
            // Test CreateFotoProfil
            CreateFotoProfil(&foto);
            displayFotoProfil(foto);
            break;

        case 2:
            // Test changeFotoProfil
            // setWord(&foto, "R * R * R * R * R *\nR * G @ B * G @ R *\nR * G @ G @ G @ R *\nR * G @ B * G @ R *\nR * R * R * R * R *");
            readInput();
            changeFotoProfil(&foto, currentWord);
            displayFotoProfil(foto);
            break;

        default:
            printf("Invalid test type.\n");
            break;
    }

    return 0;
}