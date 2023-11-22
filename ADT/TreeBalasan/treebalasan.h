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

// Mengembalikan address balasan baru
TreeBalasanAddress newTreeBalasan(TreeBalasan treebalasan);

// Membuat address balasan baru
void CreateTreeBalasan(TreeBalasanAddress t, Akun *akunPembuat);

// Mengembalikan panjang tree balasan, tanpa anak
int lengthTreeBalasan(TreeBalasan t);

// Memasukkan inserted ke *l dari paling belakang
void insertLastTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

// Kalau childnya kosong, maka insert ke child, kalau tidak, insert ke child->nextSibling yang paling belakang
void replyTreeBalasan(TreeBalasanAddress t, TreeBalasan inserted);

// Display balasan ke layar dengan indentasi sesuai depth
void displayTreeBalasan(TreeBalasan t, int depth);

// Display balasan beserta anak anaknya
void displayAllTreeBalasan(TreeBalasan t);

// Hapus balasan beserta anak anaknya
void deleteCascadeTreeBalasan(TreeBalasanAddress t);

// Mengembalikan address balasan dengan id yang dicari
TreeBalasanAddress getTreeBalasanById(TreeBalasanAddress treebalasan, int id);


#endif