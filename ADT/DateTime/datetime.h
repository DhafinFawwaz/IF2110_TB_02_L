#ifndef DATETIME_H
#define DATETIME_H
#include "../MesinKata/wordmachine.h"
#include "../Boolean/boolean.h"
#include "date.h"
#include "time.h"


typedef struct datetime
{
    Date date;
    Time time;
} DateTime;

void CreateDateTime(DateTime *dt);
void DisplayDateTime(DateTime dt);
void SetToCurrentDateTime(DateTime *dt);
void SetDateFromWord(DateTime *dt, Word w);
void SetTimeFromWord(DateTime *dt, Word w);

boolean compareDateTime(DateTime dt1, DateTime dt2);


#endif