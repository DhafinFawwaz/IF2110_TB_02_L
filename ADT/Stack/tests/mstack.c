#include <stdio.h>
#include "../stack.h"

int main() {
    int type;
    Stack S;
    infotype X;

    stack_CreateEmpty(&S);

    scanf("%d", &type);

    switch (type) {
        case 1:
            // Test IsEmpty() on empty Stack
            if (stack_IsEmpty(S)) {
                printf("Stack is empty.\n");
            } else {
                printf("Stack is not empty.\n");
            }
            break;

        case 2:
            // Test Push()
            for (int i = 1; i <= 5; i++) {
                stack_Push(&S, i * 10);
            }
            printf("Stack after Push:\n");
            stack_displayStack(S);
            break;

        case 3:
            // Test Pop()
            for (int i = 1; i <= 5; i++) {
                stack_Push(&S, i * 10);
            }
            stack_Pop(&S, &X);
            printf("Popped element: %d\n", X);
            printf("Stack after Pop:\n");
            stack_displayStack(S);
            break;

        case 4:
            // Test IsFull() on empty Stack
            if (stack_IsFull(S)) {
                printf("Stack is full.\n");
            } else {
                printf("Stack is not full.\n");
            }
            break;

        default:
            printf("Invalid test type.\n");
            break;
    }

    return 0;
}