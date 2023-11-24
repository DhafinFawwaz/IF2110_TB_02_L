#include <stdio.h>
#include "../queue.h"

int main() {
    int type;
    Queue q;
    ElType val;

    scanf("%d", &type);
    queue_CreateQueue(&q);

    switch (type) {
        case 1:
            // Test isEmpty() on empty Queue
            if (queue_isEmpty(q)) {
                printf("Queue is empty.\n");
            } else {
                printf("Queue is not empty.\n");
            }
            break;

        case 2:
            // Test enqueue
            for (int i = 1; i <= 5; i++) {
                queue_enqueue(&q, i * 10);
            }
            printf("Queue after enqueue:\n");
            queue_displayQueue(q);
            break;

        case 3:
            // Test dequeue
            for (int i = 1; i <= 5; i++) {
                queue_enqueue(&q, i * 10);
            }
            queue_dequeue(&q, &val);
            printf("Dequeued element: %d\n", val);
            printf("Queue after dequeue:\n");
            queue_displayQueue(q);
            break;

        case 4:
            // Test isFull() on empty Queue
            if (queue_isFull(q)) {
                printf("Queue is full.\n");
            } else {
                printf("Queue is not full.\n");
            }
            break;

        case 5:
            // Test length() on empty Queue
            for (int i = 1; i <= 5; i++) {
                queue_enqueue(&q, i * 10);
            }
            printf("Queue length: %d\n", queue_length(q));
            break;

        default:
            printf("Invalid test type.\n");
            break;
    }

    return 0;
}
