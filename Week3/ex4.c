#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = 1998 + rand() % 26;
    }
}

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}

int search(int *array, int n, int k) {
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(array[i] >= k) {
            index = i;
            break;
        }
    }
    return index;
}

void delete(int *array, int *n, int index, int *assignment) {
    if(index < 0 || index > (*n) - 1) {
        return;
    }
    *assignment = 0;
    for(int i = index; i < (*n) - 1; i++) {
        (*assignment)++;
        array[i] = array[i + 1];
    }
    (*n)--;
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

int caseA(int *array, int *n, int k) {
    initializeArray(array, *n);
    int assignment, result = 0;
    int i = 0;
    while(i < *n) {
        if(array[i] >= k) {
            delete(array, n, i, &assignment);
            result += assignment;
        }
        else {
            i++;
        }
    }   
    return result;
}

int caseB(int *array, int *n, int k) {
    initializeArray(array, *n);
    int result = 0, swaps;
    bubbleSort(array, *n, &swaps);
    result += swaps;
    int index = -1;
    for(int i = 0; i < *n; i++) {
        if(array[i] > k) {
            index = i;
            break;
        }
    }
    *n = index;
    return result;
}

int main() {
    srand(time(NULL));

    int array[N];
    int n = 100;
    int k = 2016;

    int stepsA = caseA(array, &n, k);
    int stepsB = caseB(array, &n, k);
    printf("Steps of case A: %4d\n", stepsA);
    printf("Steps of case B: %4d\n", stepsB);
    return 0;
}