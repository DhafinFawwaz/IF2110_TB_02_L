#include <stdio.h>
#include "../grafteman.h"

int main()
{
    int type;
    scanf("%d", &type);
    
    CreateGrafTeman(&currentGrafTemn, 5);
    setGrafTeman(&currentGrafTemn, 0, 1, true);
    setGrafTeman(&currentGrafTemn, 3, 2, true);
    setGrafTeman(&currentGrafTemn, 1, 4, true);
    setGrafTeman(&currentGrafTemn, 3, 0, true);
    setGrafTeman(&currentGrafTemn, 0, 3, true);
    setGrafTeman(&currentGrafTemn, 2, 2, true);

    switch (type)
    {
    case 1:
        // Test displayGrafTeman
        displayGrafTeman(currentGrafTemn);
        break;

    case 2:
        // Test resizeGrafTeman
        resizeGrafTeman(&currentGrafTemn, 10);
        displayGrafTeman(currentGrafTemn);
        break;

    case 3:
        // Test set setelah resize
        resizeGrafTeman(&currentGrafTemn, 10);
        setGrafTeman(&currentGrafTemn, 9, 9, true);
        displayGrafTeman(currentGrafTemn);
        break;
    }

    return 0;
}