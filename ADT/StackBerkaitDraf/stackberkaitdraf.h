#ifndef STACKBerkaitDraf_H
#define STACKBerkaitDraf_H

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

void CreateDraftKicauan(DrafKicauan *drafkicauan);

typedef struct nodedraf* AddressDraf;
typedef struct nodedraf {
    DrafKicauan drafkicauan;
    AddressDraf next;
} NodeDraf;

#define     NEXT_DRAF(p) (p)->next
#define     INFO_DRAF(p) (p)->drafkicauan

typedef struct stackBerkaitDraf {
    AddressDraf addrTopDraf;
} StackBerkaitDraf;

/* Selektor */
#define ADDR_TOP_DRAF(s) (s).addrTopDraf
#define      TOP_DRAF(s) (s).addrTopDraf->drafkicauan 

AddressDraf newNodeStackBerkaitDraf(DrafKicauan x);

boolean isEmptyStackBerkaitDraf(StackBerkaitDraf s);
int lengthStackBerkaitDraf(StackBerkaitDraf s);

void createStackBerkaitDraf(StackBerkaitDraf *s);
void displayStackBerkaitDraf(StackBerkaitDraf s);

void pushStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan x);
void popStackBerkaitDraf(StackBerkaitDraf *s, DrafKicauan *x);

void DebugListDraftKicauan();

#endif