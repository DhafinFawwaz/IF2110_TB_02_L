#include <stdio.h>
#include "Fitur/Inisialisasi/inisialisasi.h"
#include "Fitur/Perintah/perintah.h"
#include "Fitur/Global/global.h"

int main()
{
    inisialisasiGlobal();
    displayInisialisasi();
    inisialisasiConfig();

    while (globalIsRunning)
    {
        handlePerintah();
    }
    
    return 0;
}
