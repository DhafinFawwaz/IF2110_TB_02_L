#include <stdio.h>
#include "foto.h"
#include "../Pcolor/pcolor.h"

#define MATRIX(foto) (foto).buffer

void CreateFoto(Foto* foto){
    int i = 0;
    for(i = 0; i < FOTO_ROW_CAP; i++){
        int j = 0;
        for(j = 0; j < FOTO_COL_CAP; j++){
            Pixel pixel;
            pixel.color = RED_CHAR;
            pixel.val = '*';
            setPixel(foto,i,j,pixel);
        }
    }
}

void setPixel(Foto* foto, IdxType row, IdxType col, Pixel pixel){
    MATRIX(*foto)[row][col] = pixel;
}
void setColor(Foto* foto, IdxType row, IdxType col, char c){
    MATRIX(*foto)[row][col].color = c;
}
void setVal(Foto* foto, IdxType row, IdxType col, char val){
    MATRIX(*foto)[row][col].val = val;
}
void displayFoto(Foto foto){
    int j = 0;
    for(j = 0; j < FOTO_ROW_CAP; j++){
        int k = 0;
        for(k = 0; k < FOTO_COL_CAP; k++){
            printPixel(foto.buffer[j][k]);
            printf(" ");
        }
        printf("\n");
    }
}
void printPixel(Pixel p){
    if(p.color == NORMAL_CHAR) printf("%c", p.val);
    else if(p.color == RED_CHAR) print_red(p.val);
    else if(p.color == GREEN_CHAR) print_green(p.val);
    else if(p.color == BLUE_CHAR) print_blue(p.val);
}