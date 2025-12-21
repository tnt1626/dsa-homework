#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int a[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    s->a[++s->top] = value;
}

int pop(Stack *s) {
    return s->a[s->top--];
}

void displayStack(Stack *s) {
    if(isEmpty(s)) {
        printf("STACK IS EMPTY\n");
    }
    else {
        printf("STACK:");
        for(int i = 0; i <= s->top; i++) {
            printf("%3d", s->a[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    init(&s);
    int nums[] = {-1, 2, -3, 4, -5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("MAX = %d\n", MAX);
    printf("--------------PUSH--------------\n");
    for(int i = 0; i < n; i++) {
        printf("push %d\n", nums[i]);
        if(!isFull(&s)) {
            push(&s, nums[i]);
            displayStack(&s);
        }
        else {
            printf("STACK IS FULL\n");
        }
    }
    printf("\n--------------POP--------------\n");
    int i = 0;
    while(!isEmpty(&s)) {
        printf("pop %d: %d\n", i, pop(&s));
        displayStack(&s);
        i++;
    }
    return 0;
}