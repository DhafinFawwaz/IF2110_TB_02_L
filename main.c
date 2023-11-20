#include <stdio.h>
#include "Fitur/Inisialisasi/inisialisasi.h"
#include "Fitur/Perintah/perintah.h"
#include "ADT/Boolean/boolean.h"
#include "Fitur/Global/global.h"

boolean isRunning = true;

void exitProgram()
{
    isRunning = false;
}

int main()
{
    inisialisasiGlobal();
    displayInisialisasi();
    inisialisasiConfig();

    while (isRunning)
    {
        handlePerintah();
    }
    
    return 0;
}
