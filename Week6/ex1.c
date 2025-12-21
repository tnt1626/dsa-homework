#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

typedef struct {
    char a[MAX];
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

void push(Stack *s, char value) {
    s->a[++s->top] = value;
}

int pop(Stack *s) {
    return s->a[s->top--];
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while(i < j) {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
}

void reverseStringUsingStack(char str[]) {
    Stack s;
    init(&s);
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        push(&s, str[i]);
    }
    for(int i = 0; i < n; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[][MAX] = {"abcdef", "123456", "gnuhnoomalhpoahtvh"};
    for(int i = 0; i < 3; i++) {
        char str1[MAX], str2[MAX];
        strcpy(str1, str[i]);
        strcpy(str2, str[i]);
        printf("--------------CASE %d--------------\n", i + 1);
        reverseString(str1);
        printf("Reverse string: %s\n", str1);
        reverseStringUsingStack(str2);
        printf("Reverse string using stack: %s\n", str2);
    }
    return 0;
}