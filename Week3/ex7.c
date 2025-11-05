#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}

void ascendingIntegers(int n, int *comps) {
    *comps = 0;
    while(n >= 10) {
        int num1 = n % 10;
        int num2 = n % 100;
        (*comps)++;
        if(num2 > num1) {
            return;
        }
        n /= 10;
    }
}

int main() {
    srand(time(NULL));

    int start = 1000, end = 10000;
    int comps;

    int frequency[N] = {0};
    for(int i = start; i < end; i++) {
        ascendingIntegers(i, &comps);
        frequency[comps]++;
    }

    printf("Mean: %5.3f\n", average(frequency, N, 9000));
    return 0;
}