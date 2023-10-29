#ifndef PROFILE_H
#define PROFILE_H

#include "boolean.h"
#include "../MesinKata/wordmachine.h"
#include "../Foto/foto.h"

#define NAMA(p) (p).nama
#define BIO(p) (p).bio
#define NOHP(p) (p).noHp
#define WETON(p) (p).weton
#define FOTO(p) (p).foto

typedef struct profile
{
    Word nama;
    Word bio;
    Word noHp;
    Word weton;
    Foto foto;
} Profile;

void CreateProfile(Profile* profile);
void DisplayProfile(Profile profile);

#endif