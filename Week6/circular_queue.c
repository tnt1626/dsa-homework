#include <stdio.h>
#define MAX 5

typedef struct {
    int size;
    int head, tail;
    int a[MAX];
} Circular_Queue;

void init(Circular_Queue *q) {
    q->size = 0;
    q->head = 0;
    q->tail = -1;
}

int isEmpty(Circular_Queue *q) {
    return q->size == 0;
}

int isFull(Circular_Queue *q) {
    return q->size == MAX;
}

void put(Circular_Queue *q, int value) {
    q->tail = (q->tail + 1) % MAX;
    q->a[q->tail] = value;
    q->size++;
}

int get(Circular_Queue *q) {
    int value = q->a[q->head];
    q->head = (q->head + 1) % MAX;
    q->size--;
    return value;
}

void displayQueue(Circular_Queue *q) {
    if(isEmpty(q)) {
        printf("CIRCULAR QUEUE IS EMPTY\n");
    }
    else {
        printf("CIRCULAR QUEUE:");
        for(int i = 0; i < q->size; i++) {
            printf("%3d", q->a[(q->head + i) % MAX]);
        }
        printf("\n");
    }
}

int main() {
    Circular_Queue q;
    init(&q);
    int nums[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("MAX = %d\n", MAX);
    printf("--------------PUSH--------------\n");
    for(int i = 0; i < n; i++) {
        printf("put %d\n", nums[i]);
        if(!isFull(&q)) {
            put(&q, nums[i]);
            displayQueue(&q);
        }
        else {
            printf("CIRCULAR QUEUE IS FULL\n");
        }
    }
    printf("\n--------------POP--------------\n");
    int i = 0;
    while(!isEmpty(&q)) {
        printf("get %d: %d\n", i, get(&q));
        displayQueue(&q);
        i++;
    }
    return 0;
}