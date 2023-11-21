#ifndef TREEBALASAN_H
#define TREEBALASAN_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../Boolean/boolean.h"
#include "../Akun/akun.h"

#define LEFT_MARGIN_BLANK "   " 

typedef struct treebalasan* TreeBalasanAddress;

typedef struct treebalasan
{
    int idParent;
    int id;
    Akun *akunPembuat;
    Word text;
    DateTime dateTime;

    TreeBalasanAddress child; 
    TreeBalasanAddress parent;
    TreeBalasanAddress prevSibling; 
    TreeBalasanAddress nextSibling; 
} TreeBalasan;

TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan);

void CreateTreeBalasan(TreeBalasanAddress t, Akun *akunPembuat);

int lengthTreeBalasan(TreeBalasan t);

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

// Kalau childnya kosong, maka insert ke child, kalau tidak, insert ke child->nextSibling yang paling belakang
void replyTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

void displayTreeBalasan(TreeBalasan t, int depth);

void displayAllTreeBalasan(TreeBalasan t);

// Hapus elemen di index idx dan nilainya dimasukkan ke deleted
void deleteCascadeTreeBalasan(TreeBalasanAddress t);

TreeBalasanAddress getTreeBalasanById(TreeBalasan treebalasan, int id);

void DebugCurrentTreeBalasan();


#endif