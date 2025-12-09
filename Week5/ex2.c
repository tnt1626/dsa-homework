#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % (2 * N + 1)) - N;
    }
}

void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%5d", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int n) {
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(array[j] < array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selectionSort(int array[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(array[j] > array[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(&array[i], &array[minIndex]);
        }
    }
}

void insertionSort(int array[], int n) {
    int i = 1;
    while(i < n) {
        int key = array[i];
        int j = i;
        while(j > 0 && key > array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        i++;
    }
}

int main() {
    srand(time(NULL));
    int array1[N], array2[N], array3[N];
    int n = 10;
    initializeArray(array1, n);
    initializeArray(array2, n);
    initializeArray(array3, n);
    bubbleSort(array1, n);
    selectionSort(array2, n);
    insertionSort(array3, n);
    printf("Array after bubble sort:");
    printArray(array1, n);
    printf("Array after selection sort:");
    printArray(array2, n);
    printf("Array after inertion sort:");
    printArray(array3, n);
    return 0;
}