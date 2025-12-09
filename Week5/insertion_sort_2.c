#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % (2 * N + 1)) - N;
    }
}

float average(int frequency[], int n, int round) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}


void insertionSort(int array[], int n, int *comps, int *shifts) {
    *comps = 0;
    *shifts = 0;
    int i = 1;
    while(i < n) {
        int key = array[i];
        int j = i;
        (*comps)++;
        while(j > 0 && key < array[j - 1]) {
            (*comps)++;
            (*shifts)++;
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        i++;
    }
}



int main() {
    srand(time(NULL));
    int array[N], n = 10;
    int comps, shifts;
    int k[] = {100, 1000, 10000, 100000};
    for(int i = 0; i < 4; i++) {
        int frequency[2][101] = {0};
        for(int j = 0; j < k[i]; j++) {
            initializeArray(array, n);
            insertionSort(array, n, &comps, &shifts);
            frequency[0][comps]++;
            frequency[1][shifts]++;
        }
        printf("K: %5d\n", k[i]);
        printf("frequency\tcomps\t\tshifts\n");
        for(int j = 0; j <= 55; j++) {
            printf("%5d\t\t%3d\t\t%3d\n", j, frequency[0][j], frequency[1][j]);
        }
        printf("Mean of comps: %5f\n", average(frequency[0], N + 1, k[i]));
        printf("Mean of shifts: %5f\n", average(frequency[1], N + 1, k[i]));
        printf("\n");
    }
    return 0;
}