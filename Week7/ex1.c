#include <stdio.h>

int f(int n) {
    if(n == 2) {
        return 1;
    }
    return f(n - 1) * 2;
}

int new_f(int n) {
    return 1 << (n - 1);
}

float g(int n) {
    if(n == 1) {
        return 1.0;
    }
    return n * n + g(n - 1);
}

int F(int n) {
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 1;
    }
    return F(n - 1) + F(n - 2);
}

int new_F(int n) {
    int num1, num2, num;
    num1 = num2 = num = 1;
    for(int i = 3; i <= n; i++) {
        num = num1 + num2;
        num1 = num2;
        num2 = num;
    }
    return num;
}

float new_g(int n) {
    float result = 1.0;
    for(int i = 2; i <= n; i++) {
        result += i * i;
    }
    return result;
}

int P(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 2;
    }
    if(n == 2) {
        return 3;
    }
    return P(n - 1) + P(n - 3);
}

int new_P(int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 2;
    }
    if(n == 2) {
        return 3;
    }
    int num, num1, num2, num3;
    num1 = 1;
    num2 = 2;
    num3 = 3;
    for(int i = 3; i <= n; i++) {
        num = num3 + num1;
        num1 = num2;
        num2 = num3;
        num3 = num;
    }
    return num;
}

int main() {
    int n = 20;
    printf("%d\n", P(n));
    printf("%d\n", new_P(n));
    return 0;
}