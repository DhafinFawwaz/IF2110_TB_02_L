#include "date.h"

void CreateDate(Date *d){
    
}

void date_SetFromWord(Date *d, Word w){
    int i = 0;
    int counter = 0;

    d->day = 0;
    d->month = 0;
    d->year = 0;

    for(i = 0; i < w.Length; i++){
        if(w.TabWord[i] == '/'){
            counter++;
        }else{
            if(counter == 0){
                d->day = d->day * 10 + (w.TabWord[i] - '0');
            }else if(counter == 1){
                d->month = d->month * 10 + (w.TabWord[i] - '0');
            }else if(counter == 2){
                d->year = d->year * 10 + (w.TabWord[i] - '0');
            }
        }
    }
}

void AddDate(){}

void SubtractDate(){}

void DisplayDate(Date d){
    char day[2] = {d.day/10+'0', d.day%10+'0'};
    char month[2] = {d.month/10+'0', d.month%10+'0'};
    printf("%c%c/%c%c/%d", day[0],day[1], month[0],month[1], d.year);
}
