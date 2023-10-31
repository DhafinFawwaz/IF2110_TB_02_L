#ifndef PIXEL_H
#define PIXEL_H

#include "../Matriks/matrix.h"

#define COLOR_UNDEF ' '
#define NORMAL_CHAR 'N'
#define RED_CHAR 'R'
#define GREEN_CHAR 'G'
#define BLUE_CHAR 'B'

typedef struct pixel
{
    char val;
    char color;
} Pixel;

#endif