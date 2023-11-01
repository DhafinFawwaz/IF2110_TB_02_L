#ifndef TREEBALASAN_H
#define TREEBALASAN_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../Boolean/boolean.h"

#define LISTDIN_BALASAN_DEFAULT_CAPACITY 4

typedef struct treebalasan* TreeAddress;

typedef struct treebalasan
{
    int idParent;
    int id;
    int banyakBalasan;
    Word text;
    Word nama;
    DateTime dateTime;

    TreeAddress listdinBalasan; 
    int childCapacity;
    int childNeff;
} TreeBalasan;

extern int banyakKicauanBerbalasan;
extern TreeBalasan currentBalasan;
extern TreeBalasan listBalasan[LISTDIN_BALASAN_DEFAULT_CAPACITY];

void CreateBalasan(TreeBalasan *l, int capacity);

void dealocateBalasan(TreeBalasan *l);

boolean isListdinBalasanFull(TreeBalasan l);

// Memasukkan inserted ke *l
void insertAtBalasan(TreeBalasan *l, int idx, TreeBalasan inserted);

// Memasukkan inserted ke *l dari paling belakang
void insertLastBalasan(TreeBalasan *l, TreeBalasan inserted);

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted
void deleteAtBalasan(TreeBalasan *l, int idx, TreeBalasan *deleted);

void copyBalasan(TreeBalasan *destination, TreeBalasan source);

void DebugListBalasan();


#endif