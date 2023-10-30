#ifndef TREEBALASAN_H
#define TREEBALASAN_H

#include "boolean.h"
#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"

typedef struct treebalasan
{
    int id;
    Word text;
    Word namaPenulis;
    // ListDin listNextBalasan;    
} TreeBalasan;

TreeBalasan treeBalasan; // Global variable

void CreateTreeBalasan(TreeBalasan *g){
    (*g).id = 0;
    setWord(&(*g).text, "");
    setWord(&(*g).namaPenulis, "");
}

void insertLastBalasan(TreeBalasan *current, TreeBalasan *next){

}

void displayTreeBalasan(TreeBalasan t){

}

TreeBalasan* nextBalasan(TreeBalasan *t, int idx){
    
}


#endif