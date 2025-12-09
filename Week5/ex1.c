#include <stdio.h>
#define N 20


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int n, int *steps) {
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

void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%5d", array[i]);
    }
    printf("\n");
}

int main() {
    int array1[N] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int array2[N] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int array3[N] = {3, 1, 8, 2, 6, 5, 3, 9, 1, 0};
    int n = 10;
    int steps1, steps2, steps3;
    bubbleSort(array1, n, &steps1);
    selectionSort(array2, n, &steps2);
    insertionSort(array3, n, &steps3);
    printf("Steps of bubble sort: %3d\n", steps1);
    printf("Steps of selection sort: %3d\n", steps2);
    printf("Steps of insertion sort: %3d\n", steps3);
    return 0;
}