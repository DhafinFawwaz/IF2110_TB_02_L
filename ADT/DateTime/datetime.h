#ifndef DATETIME_H
#define DATETIME_H
#include "../MesinKata/wordmachine.h"
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


#endif