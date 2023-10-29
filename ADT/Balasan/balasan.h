#ifndef BALASAN_H
#define BALASAN_H

#include "../MesinKata/wordmachine.h"
#include "../DateTime/datetime.h"

typedef struct balasan
{
    int idParent;
    int id;
    int banyakBalasan;
    Word text;
    Word nama;
    DateTime dateTime;
} Balasan;

extern int banyakKicauanBerbalasan;
extern Balasan currentBalasan;
extern Balasan listBalasan[100];

void DebugListBalasan();


#endif