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
void SetToCurrentDateTime(DateTime *dt){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    (*dt).date.day = tm.tm_mday;
    (*dt).date.month = tm.tm_mon + 1;
    (*dt).date.year = tm.tm_year + 1900;
    (*dt).time.hour = tm.tm_hour;
    (*dt).time.minute = tm.tm_min;
    (*dt).time.second = tm.tm_sec;
}
void SetDateFromWord(DateTime *dt, Word w){
    date_SetFromWord(&(dt->date), w);
}
void SetTimeFromWord(DateTime *dt, Word w){
    time_SetFromWord(&(dt->time), w);
}

Word dateTimeToWord(DateTime dt){
    Word day = intToWord(dt.date.day);
    Word month = intToWord(dt.date.month);
    Word year = intToWord(dt.date.year);

    Word hour = intToWord(dt.time.hour);
    Word minute = intToWord(dt.time.minute);
    Word second = intToWord(dt.time.second);

    printf("\n");

    Word result;

    // concat day, month, year, space, hour, minute, second
    int i = 0;
    int currIndex = 0;

    
    for(i = 0; i < day.Length; i++){
        result.TabWord[currIndex] = day.TabWord[i];
        currIndex++;
    }
    result.TabWord[currIndex] = '/';
    currIndex++;

    
    for(i = 0; i < month.Length; i++){
        result.TabWord[currIndex] = month.TabWord[i];
        currIndex++;
    }
    result.TabWord[currIndex] = '/';
    currIndex++;

    
    for(i = 0; i < year.Length; i++){
        result.TabWord[currIndex] = year.TabWord[i];
        currIndex++;
    }

    //
    result.TabWord[currIndex] = ' ';
    currIndex++;
    //

    for(i = 0; i < hour.Length; i++){
        result.TabWord[currIndex] = hour.TabWord[i];
        currIndex++;
    }
    result.TabWord[currIndex] = ':';
    currIndex++;

    
    for(i = 0; i < minute.Length; i++){
        result.TabWord[currIndex] = minute.TabWord[i];
        currIndex++;
    }
    result.TabWord[currIndex] = ':';
    currIndex++;

    
    for(i = 0; i < second.Length; i++){
        result.TabWord[currIndex] = second.TabWord[i];
        currIndex++;
    }
    result.Length = currIndex;
    return result;
}

boolean compareDateTime(DateTime dt1, DateTime dt2){
    return (
        (dt1).date.day == (dt2).date.day &&
        (dt1).date.month == (dt2).date.month &&
        (dt1).date.year == (dt2).date.year &&
        (dt1).time.hour == (dt2).time.hour &&
        (dt1).time.minute == (dt2).time.minute &&
        (dt1).time.second == (dt2).time.second
    );
}