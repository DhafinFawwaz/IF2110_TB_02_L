#include <stdio.h>
#include <time.h>
#include "datetime.h"

void CreateDateTime(DateTime *dt){
    CreateDate(&(dt->date));
    CreateTime(&(dt->time));
}
void DisplayDateTime(DateTime dt){
    DisplayDate(dt.date);
    printf(" ");
    DisplayTime(dt.time);
}
void SetToCurrentDateTime(DateTime *dt){}
void SetDateFromWord(DateTime *dt, Word w){
    date_SetFromWord(&(dt->date), w);
}
void SetTimeFromWord(DateTime *dt, Word w){
    time_SetFromWord(&(dt->time), w);
}
