#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % (2 * N + 1)) - N;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *array, int n, int *swaps) {
    *swaps = 0;
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(array[j] > array[j + 1]) {
                (*swaps)++;
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}


int main() {
    srand(time(NULL));

    int array[N];
    int n = 10;
    int swaps;
    int k[] = {10, 20, 50, 100, 1000, 10000};

    printf("N = %3d\n", n);
    for(int j = 0; j < 6; j++) {
        int frequency[101] = {0};
        for(int l = 0; l < k[j]; l++) {
            initializeArray(array, n);
            bubbleSort(array, n, &swaps);
            frequency[swaps]++;
        }
        printf("k = %5d\n", k[j]);
        printf("index\t\tswaps\n");
        for(int l = 0; l <= 45; l++) {
            printf("%3d\t\t%3d\n", l, frequency[l]);
        }
        printf("mean: %5f\n\n", average(frequency, N + 1, k[j]));
    }

    return 0;
}