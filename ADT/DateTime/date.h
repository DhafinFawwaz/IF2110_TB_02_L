#ifndef DATE_H
#define DATE_H
#include <stdio.h>
#include <time.h>
#include "../MesinKata/wordmachine.h"

typedef struct date
{
    int day;
    int month;
    int year;
} Date;

void CreateDate(Date *d);

void date_SetFromWord(Date *d, Word w);

void AddDate();

void SubtractDate();

void DisplayDate(Date d);

#endif