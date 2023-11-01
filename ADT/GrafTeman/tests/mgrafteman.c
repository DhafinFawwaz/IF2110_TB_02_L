#include <stdio.h>
#include "../grafteman.h"

int main()
{
    int type;
    scanf("%d", &type);
    
    CreateGrafTeman(&currentGrafTeman, 5);
    setGrafTeman(&currentGrafTeman, 0, 1, true);
    setGrafTeman(&currentGrafTeman, 3, 2, true);
    setGrafTeman(&currentGrafTeman, 1, 4, true);
    setGrafTeman(&currentGrafTeman, 3, 0, true);
    setGrafTeman(&currentGrafTeman, 0, 3, true);
    setGrafTeman(&currentGrafTeman, 2, 2, true);

    switch (type)
    {
    case 1:
        // Test displayGrafTeman
        displayGrafTeman(currentGrafTeman);
        break;

    case 2:
        // Test resizeGrafTeman
        resizeGrafTeman(&currentGrafTeman, 10);
        displayGrafTeman(currentGrafTeman);
        break;

    case 3:
        // Test set setelah resize
        resizeGrafTeman(&currentGrafTeman, 10);
        setGrafTeman(&currentGrafTeman, 9, 9, true);
        displayGrafTeman(currentGrafTeman);
        break;
    
    case 4:
    
        // Test displayGrafTeman
        setGrafTeman(&currentGrafTeman, 4, 4, true);
        displayGrafTeman(currentGrafTeman);
        break;
    }

    return 0;
}