#include "mapdin.h"
#include <stdlib.h>
#include "../MesinKata/wordmachine.h"
#include "../Boolean/boolean.h"

void createMapDin(MapDin * m, int cap){
    NEFF_MAPDIN(*m) = 0;
    CAP_MAPDIN(*m) = cap;
    BUFFER_MAP(*m) = (MapEntry*) malloc (cap*sizeof(MapEntry));
    int i;
    for(i=0;i<NEFF_MAPDIN(*m);i++){
        ELMT_MAP_TAGAR(*m,i).Length = 0;
    }
}

void rehashing(MapDin * m){

}

void expandMapDin(MapDin * m){
    int new_cap = 2 * CAP_MAPDIN(*m);
    MapDin mNew;
    createListDinKicauan(&mNew, new_cap);
    rehashing(m);
    *m = mNew;
}

int hash(Word tagW, int capMap){
    return (wordToInt(tagW))%capMap;
}

void insertMapDin(MapDin * m, Kicauan * k){
    int key = hash(TAGAR(*k), CAP_MAPDIN(*m));
    if(isFullMapDin(*m)){

    }else{

    }
}

void findIdx(MapDin m, Word tag, int key){
    int idx = key;
    while(ELMT_MAP_TAGAR(m,idx).Length!=0){
        idx = (idx+1)%CAP_MAPDIN(m);
    }
    return idx;
}

boolean isFullMapDin(MapDin m){
    return (NEFF_MAPDIN(m)==CAP_MAPDIN(m));
}


