#include "date.h"

void CreateDate(Date *d){
    
}

void date_SetFromWord(Date *d, Word w){
    int i = 0;
    int counter = 0;
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
    printf("%d/%d/%d", d.day, d.month, d.year);
}
