#include "../listdinkicauan.h"
#include "../../../Fitur/Kicauan/kicauan.h"

int main(){
    ListDinKicauan listDin;
    createListDinKicauan(&listDin,10);
    int numCase;
    scanf("%d",&numCase);
    switch (numCase)
    {
    case 1: // Kicau kosong
        kicau();
        kicauan();
        sukaKicauan();
        break;
    
    case 2: // Kicauan saat List kosong
        kicau();
        kicauan();
        break;

    case 3: // Kicau valid
        kicau();
        break;

    case 4: // Kicauan saat List tidak kosong
        kicauan();
        break;

    case :5
        sukaKicauan(1);
        break;
    
    case 6:
        sukaKicauan(2);
        break;

    case 4:
        sukaKicauan(2);
        break;

    case 4:
        sukaKicauan(2);
        break;

    
    }
    
    return 0;
}