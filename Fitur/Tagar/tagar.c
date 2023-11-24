#include "tagar.h"
#include "../../ADT/MapDin/mapdin.h"
#include "../Global/global.h"

void cariKicauan(Word tagar){
    int key = hash(tagar, CAP_MAPDIN(globalMapTagarKicauan));
    boolean isFound = false;
    int idx = key;
    if(compareWord(ELMT_MAP_TAGAR(globalMapTagarKicauan,idx),tagar)){
        isFound = true;
    }
    do{
        idx = (idx+1)%CAP_MAPDIN(globalMapTagarKicauan);
        if(compareWord(ELMT_MAP_TAGAR(globalMapTagarKicauan,idx),tagar)){
            isFound = true;
        }
    }while (!isFound || idx == key);

    if(!isFound){
        printf("Tidak ditemukan kicauan dengan tagar ");
        printWord(tagar);
        printf("\n\n");
    }else{
        displayKicauanTagar(ELMT_MAP_VALUE(globalMapTagarKicauan,idx));
    }
    
}

void displayKicauanTagar(LinkedListValue l){
    AddressNodeMap p = l;
    while (p!=NULL)
    {
        printf("| ");
        printWord(ADDR_AKUN_KICAUAN(*(INFO_VAL_MAP(p)))->username);
        printf("\n");
        printf("| ");
        DisplayDateTime(WAKTU(*(INFO_VAL_MAP(p))));
        printf("\n");
        printf("| ");
        printWord(TEXT_KICAU(*(INFO_VAL_MAP(p))));
        printf("\n");
        printf("| ");
        printWord(TAGAR(*(INFO_VAL_MAP(p))));
        printf("\n");
        printf("| Disukai : %d", JUMLAH_LIKE(*(INFO_VAL_MAP(p))));
        printf("\n");
        printf("\n");
        p = NEXT_VAL_MAP(p);
    }
    
}