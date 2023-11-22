#include <stdio.h>
#include "../treebalasan.h"
#include "../../DateTime/datetime.h"
#include "../../../Fitur/Global/global.h"

DateTime getZero(){
    DateTime zero;
    zero.date.day = 0;
    zero.date.month = 0;
    zero.date.year = 0;
    zero.time.hour = 0;
    zero.time.minute = 0;
    zero.time.second = 0;
    return zero;
}

int main()
{
    int type;
    scanf("%d", &type);
    
    Akun akunPembuat;
    CreateAkun(&akunPembuat);
    setWord(&akunPembuat.username.TabWord, "Tuan Hak");
    Word balasan;
    setWord(&balasan, "Ini sebuah balasan.");

    TreeBalasan root;
    CreateTreeBalasan(&root, &akunPembuat);
    root.id = 1;
    TreeBalasanAddress currentTreeBalasan = newTreeBalasan(root);

    currentTreeBalasan->dateTime = getZero();
    currentTreeBalasan->text = balasan;

    int i = 1;
    for(i = 1; i < 10; i++){
        globalLastTreeBalasanId++;
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan, &akunPembuat);
        newBalasan.dateTime = getZero();
        newBalasan.text = balasan;
        newBalasan.id = globalLastTreeBalasanId;
        insertLastTreeBalasan(currentTreeBalasan, newBalasan);
    }
    for(i = 0; i < 7; i++){
        globalLastTreeBalasanId++;
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan, &akunPembuat);
        newBalasan.dateTime = getZero();
        newBalasan.text = balasan;
        newBalasan.id = globalLastTreeBalasanId;
        replyTreeBalasan(currentTreeBalasan, newBalasan);
    }
    
    for(i = 0; i < 5; i++){
        globalLastTreeBalasanId++;
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan, &akunPembuat);
        newBalasan.dateTime = getZero();
        newBalasan.id = globalLastTreeBalasanId;
        replyTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling, newBalasan);
    }
    for(i = 0; i < 5; i++){
        globalLastTreeBalasanId++;
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan, &akunPembuat);
        newBalasan.dateTime = getZero();
        newBalasan.id = globalLastTreeBalasanId;
        replyTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling->child->nextSibling->nextSibling, newBalasan);
    }

    for(i = 0; i < 7; i++){
        globalLastTreeBalasanId++;
        TreeBalasan newBalasan;
        CreateTreeBalasan(&newBalasan, &akunPembuat);
        newBalasan.dateTime = getZero();
        newBalasan.id = globalLastTreeBalasanId;
        replyTreeBalasan(currentTreeBalasan->child->nextSibling->nextSibling, newBalasan);
    }


    switch (type)
    {
        case 1:
            displayAllTreeBalasan(*currentTreeBalasan);
            break;
        case 2:
            deleteCascadeTreeBalasan(currentTreeBalasan->nextSibling->nextSibling->nextSibling->child->nextSibling->nextSibling);
            displayAllTreeBalasan(*currentTreeBalasan);
            break;
    }
    return 0;
}