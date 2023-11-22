#ifndef STACKDINDRAF_H
#define STACKDINDRAF_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"
#include "../StackDin/stackdin.h"


#define NIL NULL

typedef struct DrafKicauan
{
    int id;
    Word text;
    Word nama;
    DateTime dateTime;
} DrafKicauan;

typedef struct nodedraf* AddressDraf;
typedef struct nodedraf {
    DrafKicauan drafkicauan;
    AddressDraf next;
} NodeDraf;

#define     NEXT_DRAF(p) (p)->next
#define     INFO_DRAF(p) (p)->drafkicauan

typedef struct stackDinDraf {
    AddressDraf addrTopDraf;
} StackDinDraf;

/* Selektor */
#define ADDR_TOP_DRAF(s) (s).addrTopDraf
#define      TOP_DRAF(s) (s).addrTopDraf->drafkicauan 

extern int banyakDraf;
extern DrafKicauan listDraftkicauan[100]; // sementara di array aja dulu

AddressDraf newNodeStackDinDraf(DrafKicauan x);

boolean isEmptyStackDinDraf(StackDinDraf s);
int lengthStackDinDraf(StackDinDraf s);

void createStackDinDraf(StackDinDraf *s);
void displayStackDinDraf(StackDinDraf s);

void pushStackDinDraf(StackDinDraf *s, DrafKicauan x);
void popStackDinDraf(StackDinDraf *s, DrafKicauan *x);

void DebugListDraftKicauan();

#endif