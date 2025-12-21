#include <stdio.h>
#define N 20

void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%3d", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = array[right];
    int i = left, j = right - 1;
    while(i <= j) {
        while(array[i] < pivot) {
            i++;
        }
        while(array[j] > pivot && j >= left) {
            j--;
        }
        if(i <= j) {  
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    swap(&array[i], &array[right]);
    return i;
}



int main() {
    int array[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(array) / sizeof(array[0]);
    partition(array, 0, n - 1);
    printArray(array, n);
    return 0;
}