#ifndef TIME_H
#define TIME_H
#include <stdio.h>
#include <time.h>
#include "../MesinKata/wordmachine.h"

typedef struct time
{
    int hour;
    int minute;
    int second;
} Time;

void CreateTime(Time *t);

void time_SetFromWord(Time *t, Word w);

void AddTime();

void SubtractTime();

void DisplayTime(Time t);

#endif