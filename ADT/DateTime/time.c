#include "time.h"

void CreateTime(Time *t){}

void time_SetFromWord(Time *t, Word w){
    int i = 0;
    int counter = 0;

    t->hour = 0;
    t->minute = 0;
    t->second = 0;

    for(i = 0; i < w.Length; i++){
        if(w.TabWord[i] == ':'){
            counter++;
        }else{
            if(counter == 0){
                t->hour = t->hour * 10 + (w.TabWord[i] - '0');
            }else if(counter == 1){
                t->minute = t->minute * 10 + (w.TabWord[i] - '0');
            }else if(counter == 2){
                t->second = t->second * 10 + (w.TabWord[i] - '0');
            }
        }
    }
}

void AddTime(){}

void SubtractTime(){}

void DisplayTime(Time t){
    char hour[2] = {t.hour/10+'0', t.hour%10+'0'};
    char minute[2] = {t.minute/10+'0', t.minute%10+'0'};
    char second[2] = {t.second/10+'0', t.second%10+'0'};

    printf("%c%c:%c%c:%c%c", hour[0],hour[1], minute[0],minute[1], second[0],second[1]);
}
