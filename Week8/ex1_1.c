#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

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
    int array[N] = {10, 6, 7, 8, 9, 5, 5, 3, 2, 1};
    int n = 10;
    int counts = 0;
    quicksort(array, 0, n - 1, &counts);
    printf("Counts: %3d\n", counts);
    return 0;
}