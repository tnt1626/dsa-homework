#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % 100) + 1;
    }
}

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}

void maxProduct(int *array, int n, int *steps, int *assignment) {
    *steps = *assignment = 0;
    if(n < 2) {
        return;
    }
    (*steps)++;
    (*assignment)++;
    long long max = array[0] * array[1];
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            (*steps)++;
            long long product = array[i] * array[j];
            if(product > max) {
                (*assignment)++;
                max = product;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int array[N];
    int n = 4, k = 10000;
    int steps, assignment;

    int frequency[2][N] = {0};
    for(int i = 0; i < k; i++) {
        initializeArray(array, n);
        maxProduct(array, n, &steps, &assignment);
        frequency[0][steps]++;
        frequency[1][assignment]++;
    }
    printf("frequency\tsteps\t   assignment\n");
    for(int i = 0; i <= 7; i++) {
        printf("%7d\t\t%5d\t\t%5d\n", i, frequency[0][i], frequency[1][i]);
    }
    printf("mean steps of assignment: %5.3f\n", average(frequency[1], n, k));
    return 0;
}