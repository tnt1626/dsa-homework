#include <stdio.h>
#define MAX 5

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

int isEmpty(Queue *q) {
    return q->tail - q->head + 1 == 0;
}

int isFull(Queue *q) {
    return q->tail == MAX - 1;
}

void put(Queue *q, int value) {
    q->a[++q->tail] = value;
}

int get(Queue *q) {
    return q->a[q->head++];
}

void displayQueue(Queue *q) {
    if(isEmpty(q)) {
        printf("QUEUE IS EMPTY\n");
    }
    else {
        printf("QUEUE:");
        for(int i = q->head; i <= q->tail; i++) {
            printf("%3d", q->a[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
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
            printf("QUEUE IS FULL\n");
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