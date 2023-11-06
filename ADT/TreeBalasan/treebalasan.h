#ifndef TREEBALASAN_H
#define TREEBALASAN_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../Boolean/boolean.h"

typedef struct treebalasan* TreeBalasanAddress;

typedef struct treebalasan
{
    int idParent;
    int id;
    Word text;
    Word nama;
    DateTime dateTime;

    TreeBalasanAddress child; 
    TreeBalasanAddress parent;
    TreeBalasanAddress prevSibling; 
    TreeBalasanAddress nextSibling; 
} TreeBalasan;

extern int banyakKicauanBerbalasan;
extern TreeBalasanAddress currentTreeBalasan;

TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan);

void CreateTreeBalasan(TreeBalasanAddress t);

int lengthTreeBalasan(TreeBalasan t);

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

// Kalau childnya kosong, maka insert ke child, kalau tidak, insert ke child->nextSibling yang paling belakang
void replyTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted
void deleteCascadeTreeBalasan(TreeBalasanAddress t);

void DebugCurrentTreeBalasan();


#endif