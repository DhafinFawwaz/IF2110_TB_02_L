#include <stdio.h>
#include "../drafkicauan.h"

int main() {
    StackDinDraf stackDraf;
    createStackDinDraf(&stackDraf);

    DateTime dateTime1, dateTime2;
    CreateDateTime(&dateTime1);
    CreateDateTime(&dateTime2);

    SetToCurrentDateTime(&dateTime1);
    SetToCurrentDateTime(&dateTime2);

    printf("DateTime 1: ");
    DisplayDateTime(dateTime1);
    printf("\nDateTime 2: ");
    DisplayDateTime(dateTime2);

    DrafKicauan draf1 = {1, {"Hello, World!"}, {"Sunshine"}, dateTime1};
    DrafKicauan draf2 = {2, {"Ini adalah draf kicauan."}, {"Alstruk"}, dateTime2};

    pushStackDinDraf(&stackDraf, draf1);
    pushStackDinDraf(&stackDraf, draf2);

    printf("\nDraf kicauan di dalam tumpukan:\n");
    displayStackDinDraf(stackDraf);

    DrafKicauan drafKeluar;
    popStackDinDraf(&stackDraf, &drafKeluar);
    printf("\nDraf kicauan teratas yang dieluarkan:\n");
    printf("ID: %d\n", drafKeluar.id);
    printf("Teks: %s\n", drafKeluar.text.TabWord);
    printf("Nama: %s\n", drafKeluar.nama.TabWord);
    printf("Tanggal dan Waktu: ");
    DisplayDateTime(drafKeluar.dateTime);

    return 0;
}