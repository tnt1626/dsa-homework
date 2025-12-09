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

void insertionSort(int array[], int n) {
    int i = 1;
    printf("Mang ban dau: ");
    printArray(array, n);
    while(i < n) {
        int key = array[i];
        int j = i;
        while(j > 0 && key < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        printf("Buoc %d: ", i);
        printArray(array, n);
        i++;
    }
    printf("Mang sau khi sap xep: ");
    printArray(array, n);
}

int main() {
    srand(time(NULL));
    int array[N], n = 5;
    initializeArray(array, n);
    insertionSort(array, n);
    return 0;
}