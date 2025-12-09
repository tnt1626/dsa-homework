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


int main() {
    srand(time(NULL));
    int array1[N], array2[N], array3[N];
    int steps1, steps2, steps3;
    int n[] = {10, 20, 50, 100};
    printf("%-10s %-15s %-15s %-15s\n", "n", "bubble sort", "selection sort", "insertion sort");
    for(int i = 0; i < 4; i++) {
        initializeArray(array1, n[i]);
        initializeArray(array2, n[i]);
        initializeArray(array3, n[i]);
        bubbleSort(array1, n[i], &steps1);
        selectionSort(array2, n[i], &steps2);
        insertionSort(array3, n[i], &steps3);
        printf("%-10d %-15d %-15d %-15d\n", n[i], steps1, steps2, steps3);
    }
    return 0;
}