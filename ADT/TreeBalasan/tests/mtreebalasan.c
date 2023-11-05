#include <stdio.h>
#include "../treebalasan.h"

int main()
{
    int type;
    scanf("%d", &type);
    
    TreeBalasan t;
    t.id = 0;
    currentTreeBalasan = newTreeBalasan(t);
    if(currentTreeBalasan == NULL){
        printf("currentTreeBalasan   == NULL\n");
    }

    int i = 0;
    for(i = 0; i < 10; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        insertLastTreeBalasan(currentTreeBalasan, newBalasan);
    }
    for(i = 0; i < 7; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        replyTreeBalasan(currentTreeBalasan, newBalasan);
    }
    
    for(i = 0; i < 5; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        replyTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling, newBalasan);
    }

    for(i = 0; i < 7; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        replyTreeBalasan(currentTreeBalasan->child->nextSibling->nextSibling, newBalasan);
    }

    switch (type)
    {
    case 1:
        DebugCurrentTreeBalasan();
        break;

    case 2:
        // Test resizeGrafTeman
        break;

    case 3:
        // Test set setelah resize
        break;
    
    case 4:
    
        // Test displayGrafTeman
        break;
    }

    return 0;
}