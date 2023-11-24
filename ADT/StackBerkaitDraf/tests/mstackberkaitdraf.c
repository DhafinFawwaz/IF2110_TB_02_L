#include <stdio.h>
#include "../stackberkaitdraf.h"

int main() {
    StackBerkaitDraf stack;
    DrafKicauan draf;
    int type;

    createStackBerkaitDraf(&stack);

    printf("Masukkan jenis uji (1-5): ");
    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test isEmptyStackBerkaitDraf
            if (isEmptyStackBerkaitDraf(stack)) {
                printf("Stack Berkait Draf kosong.\n");
            } else {
                printf("Stack Berkait Draf tidak kosong.\n");
            }
            break;

        case 2:
            // Test pushStackBerkaitDraf 
            CreateDraftKicauan(&draf);
            pushStackBerkaitDraf(&stack, draf);
            printf("Stack Berkait Draf setelah Push:\n");
            displayStackBerkaitDraf(stack);
            break;

        case 3:
            // Test popStackBerkaitDraf
            popStackBerkaitDraf(&stack, &draf);
            printf("Stack Berkait Draf setelah Pop:\n");
            displayStackBerkaitDraf(stack);
            break;

        case 4:
            // Test isEmptyStackBerkaitDraf() setelah popStackBerkaitDraf
            if (isEmptyStackBerkaitDraf(stack)) {
                printf("Stack Berkait Draf kosong setelah Pop.\n");
            } else {
                printf("Stack Berkait Draf tidak kosong setelah Pop.\n");
            }
            break;

        case 5:
            // Test lengthStackBerkaitDraf
            printf("Panjang Stack Berkait Draf: %d\n", lengthStackBerkaitDraf(stack));
            break;

        default:
            printf("Jenis uji tidak valid.\n");
            break;
    }

    return 0;
}