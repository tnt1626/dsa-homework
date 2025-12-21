#include <stdio.h>
#define N 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int n, int *steps) {
    *steps = 0;
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            (*steps)++;
            if(array[j] > array[j + 1]) {
                (*steps)++;
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selectionSort(int array[], int n, int *steps) {
    *steps = 0;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            (*steps)++;
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            (*steps)++;
            swap(&array[i], &array[minIndex]);
        }
    }
}

void insertionSort(int array[], int n, int *steps) {
    *steps = 0;
    int i = 1;
    while(i < n) {
        int key = array[i];
        int j = i;
        (*steps)++;
        while(j > 0 && key < array[j - 1]) {
            (*steps)++;
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        i++;
    }
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
    int array1[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    int array2[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    int array3[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    int array4[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 17, 14, 15, 16, 13, 18, 19, 20};
    int n = 20;
    int steps1, steps2, steps3, counts;
    counts = 0;
    bubbleSort(array1, n, &steps1);
    selectionSort(array2, n, &steps2);
    insertionSort(array3, n, &steps3);
    quicksort(array4, 0, n - 1, &counts);
    printf("Steps of bubble sort: %3d\n", steps1);
    printf("Steps of selection sort: %3d\n", steps2);
    printf("Steps of insertion sort: %3d\n", steps3);
    printf("Steps of quick sort: %3d\n", counts);
    return 0;
}