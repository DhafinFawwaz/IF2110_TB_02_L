#include <stdio.h>
#include "Fitur/Inisialisasi/inisialisasi.h"
#include "Fitur/Perintah/perintah.h"
#include "ADT/Boolean/boolean.h"

boolean isRunning = true;

void exitProgram()
{
    isRunning = false;
}

int main()
{
    displayInisialisasi();
    inisialisasiConfig();

    while (isRunning)
    {
        handlePerintah();
    }
    
    return 0;
}
