#include "time.h"

void CreateTime(Time *t){}

void time_SetFromWord(Time *d, Word w){
    int i = 0;
    int counter = 0;
    for(i = 0; i < w.Length; i++){
        if(w.TabWord[i] == ':'){
            counter++;
        }else{
            if(counter == 0){
                d->hour = d->hour * 10 + (w.TabWord[i] - '0');
            }else if(counter == 1){
                d->minute = d->minute * 10 + (w.TabWord[i] - '0');
            }else if(counter == 2){
                d->second = d->second * 10 + (w.TabWord[i] - '0');
            }
        }
    }
}

void AddTime(){}

void SubtractTime(){}

void DisplayTime(Time t){
    printf("%d:%d:%d", t.hour, t.minute, t.second);
}
