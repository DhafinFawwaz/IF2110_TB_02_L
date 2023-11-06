#include <stdio.h>
#include "../treebalasan.h"

int main()
{
    int type;
    scanf("%d", &type);
    
    TreeBalasan t;
    t.id = 1;
    currentTreeBalasan = newTreeBalasan(t);
    if(currentTreeBalasan == NULL){
        printf("currentTreeBalasan   == NULL\n");
    }

    int i = 1;
    for(i = 1; i < 10; i++){
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
    for(i = 0; i < 5; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        replyTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling->child->nextSibling->nextSibling, newBalasan);
    }

    for(i = 0; i < 7; i++){
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan);
        newBalasan.id = i+1;
        replyTreeBalasan(currentTreeBalasan->child->nextSibling->nextSibling, newBalasan);
    }

    deleteCascadeTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling->child->nextSibling->nextSibling);

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