#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 51

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

int peek(Stack *s) {
    return s->a[s->top];
}

int precedence(char c) {
    if(c == '*' || c == '/') {
        return 2;
    }
    if(c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

void reversePolishNotation(char str[], char postfixStr[]) {
    Stack s;
    init(&s);
    int n = strlen(str);
    int size = 0;
    for(int i = 0; i < n; i++) {
        char c = str[i];
        if(isdigit(c)) {
            postfixStr[size++] = c; 
        }
        else {
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                postfixStr[size++] = pop(&s);   
            }
            push(&s, c);
        }
    }
    while(!isEmpty(&s)) {
        postfixStr[size++] = pop(&s); 
    }
    postfixStr[size] = '\0';
}

int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int evaluateRPN(char postfixStr[]) {
    float nums[MAX];
    int size = 0;
    int n = strlen(postfixStr);
    for(int i = 0; i < n; i++) {
        char c = postfixStr[i];
        if(isOperator(c)) {
            float nums1 = nums[size - 1];
            float nums2 = nums[size - 2];
            size -= 2;
            if(c == '+') {
                nums[size++] = nums2 + nums1;
            }
            else if (c == '-') {
                nums[size++] = nums2 - nums1;
            }
            else if(c == '*') {
                nums[size++] = nums2 * nums1;
            }
            else {
                nums[size++] = (float)nums2 / nums1;
            }
        }
        else {
            nums[size++] = c - '0';
        }
    }
    return nums[size - 1];
}

int main() {
    char str[MAX] = "2+3*4-5";
    char postfixStr[MAX];
    reversePolishNotation(str, postfixStr);
    printf("%s\n", postfixStr);
    float result = evaluateRPN(postfixStr);
    printf("%f\n", result);
    return 0;
}