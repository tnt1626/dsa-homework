#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20

void initializeArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        array[i] = rand() % 2000 - 1000;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = right;
    right--;
    while(left <= right) {
        while(array[left] < array[pivot]) {
            left++;
        }
        while(right >= left && array[right] > array[pivot]) {
            right--;
        }
        if(left <= right) {
            swap(&array[left], &array[right]);
            left++;
            right--;
        }
    }
    swap(&array[left], &array[pivot]);
    return left;
}

void quicksort(int array[], int left, int right, int *counts) {
    if(left > right) {
        return;
    }
    (*counts)++;
    int index = partition(array, left, right);
    quicksort(array, left, index - 1, counts);
    quicksort(array, index + 1, right, counts);
}

int main() {
    srand(time(NULL));
    int array[N];
    int n = 10;
    int counts;
    int k[] = {10, 100, 1000, 10000};
    for(int i = 0; i < 4; i++) {
        int frequency[N] = {0};
        for(int j = 0; j < k[i]; j++) {
            initializeArray(array, n);
            counts = 0;
            quicksort(array, 0, n - 1, &counts);
            frequency[counts]++;
        }
        printf("K: %-4d\n", k[i]);
        printf("%s\t%s\n", "Observations", "Frequency");
        for(int j = 0; j < 20; j++) {
            printf("%5d\t\t%5d\n", j, frequency[j]);
        }
        printf("\n");
    }
    return 0;
}