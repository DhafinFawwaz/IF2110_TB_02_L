#include "mapdin.h"
#include <stdlib.h>
#include "../MesinKata/wordmachine.h"
#include "../Boolean/boolean.h"

AddressNodeMap newNodeValMap(Kicauan * k){
    AddressNodeMap p = (NodeValMap*) malloc(sizeof(nodeValMap));
    if(p!=NULL){
        INFO_VAL_MAP(p) = k;
        NEXT_VAL_MAP(p) = NULL;
    }
    return AddressNodeMap;
}

void insertFirstListValue(LinkedListValue * l, Kicauan * k){
    AddressNodeMap pK = newNodeValMap(k);
    if(pK!=NULL){
        NEXT_VAL_MAP(pK) = *l;
        *l = pK;
    }
}

void createMapDin(MapDin * m, int cap){
    NEFF_MAPDIN(*m) = 0;
    CAP_MAPDIN(*m) = cap;
    BUFFER_MAP(*m) = (MapEntry*) malloc (cap*sizeof(MapEntry));
    int i;
    for(i=0;i<NEFF_MAPDIN(*m);i++){
        ELMT_MAP_VALUE(*m,i) = NULL;
        ELMT_MAP_TAGAR(*m,i).Length = 0;
        ELMT_MAP_KEY(*m) = -1;
    }
}

void rehashing(MapDin * m){
    MapDin mOld = *m;
    expandMapDin(m);
    int i;
    for(i=0;i<CAP_MAPDIN(mOld);i++){
        if(ELMT_MAP_KEY!=-1){
            insertMapDin(m,INFO_VAL_MAP(ELMT_MAP_VALUE(*m,i)));
        }
    }
}

void expandMapDin(MapDin * m){
    int new_cap = 2 * CAP_MAPDIN(*m);
    MapDin mNew;
    createListDinKicauan(&mNew, new_cap);
    free(m);
    *m = mNew;
}

int hash(Word tagW, int capMap){
    return (wordToInt(tagW))%capMap;
}


void insertMapDin(MapDin * m, Kicauan * k){
    int key = hash(TAGAR(*k), CAP_MAPDIN(*m));
    int idx = findIdx(*m, TAGAR(*k),key);
    if(compareWord(ELMT_MAP_TAGAR(m,idx),TAGAR(*k))){
        insertFirstListValue(&ELMT_MAP_VALUE(*m,idx),k);
    }else{
        ELMT_MAP_KEY(*m,idx) = key;
        setWord(&ELMT_MAP_TAGAR(*m,idx), TAGAR(*k).TabWord);
        ELMT_MAP_VALUE(*m,idx) = newNodeValMap(k);
    }
}

void findIdx(MapDin m, Word tag, int key){
    int idx = key;
    boolean isFound = false;
    while(!isFound){
        if((ELMT_MAP_KEY(m,idx) == -1) || (ELMT_MAP_TAGAR(m,idx).Length!=0 && compareWord(ELMT_MAP_TAGAR(m,idx),tag))){
            isFound = true;
        }else{
            idx = (idx+1)%CAP_MAPDIN(m);
        }
    }
    return idx;
}

boolean isFullMapDin(MapDin m){
    return (NEFF_MAPDIN(m)==CAP_MAPDIN(m));
}


