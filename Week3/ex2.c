#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(float *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (float)rand() / (float)RAND_MAX * 10;
    }
}

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int minIndex(float *array, int start, int n, int *comparision) {
    int index = start;
    for(int i = start + 1; i < n; i++) {
        (*comparision)++;
        if(array[i] < array[index]) {
            index = i;
        }
    }
    return index;
}

void sort(float *array, int n, int *comparision) {
    *comparision = 0;
    for(int i = 0; i < n - 1; i++) {
        int index = minIndex(array, i, n, comparision);
        swap(&array[i], &array[index]);
    }
}

int main() {
    srand(time(NULL));

    float array[N];
    int n = 40;
    int comparision;
    initializeArray(array, n);
    for(int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    sort(array, n, &comparision);
    printf("Comparision: %4d\n", comparision);
    for(int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    return 0;
}