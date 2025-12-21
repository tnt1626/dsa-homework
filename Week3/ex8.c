#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % 100) + 1;
    }
}

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}

void f(int a[], int n, int *shifts, int *assigns) {
    *shifts = *assigns = 0;
    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            (*assigns)++;
            int t = a[i];
            int j;
            for (j = i; j >=d && a[j-d] > t; j -= d) {
                (*shifts)++;
                a[j] = a[j-d];
            }
            (*assigns)++;
            a[j] = t;
        }
    }
}

int main() {
    int a[] = {34, 29, 10, 3, 2, 44, 88, 1, 21, 12, 3, 18, 21, 23, 37, 17, 8, 9, 4, 0};
    int shifts, assigns;
    int n = 20;
    f(a, n, &shifts, &assigns);
    printf("Shifts: %3d\n", shifts);
    printf("Assigns: %3d\n", assigns);
    return 0;
}
