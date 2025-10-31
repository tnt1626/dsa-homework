#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define N 100

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % (2 * MAX + 1)) - MAX;
    }
}

void insert(int *array, int *n, int value, int index, int *assignment) {
    if(index < 0 || index > *n) {
        return;
    }
    *assignment = 0;
    (*n)++;
    for(int i = (*n) - 2; i > index; i--) {
        (*assignment)++;
        array[i + 1] = array[i];
    }
    (*assignment)++;
    array[index] = value;
}

float average(int *frequency, int n, int round) {
    float sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i * frequency[i];
    }
    return sum / round;
}

int main() {
    srand(time(NULL));

    int array[N];
    int n = 10;
    int assignment;
    int round[] = {100, 1000, 10000};
    for(int i = 0; i < 3; i++) {
        int frequency[11] = {0};
        for(int j = 0; j < round[i]; j++) {
            initializeArray(array, n);
            int value = rand() % MAX;
            int index = rand() % n;
            n = 10;
            insert(array, &n, value, index, &assignment);
            frequency[assignment]++;
        }
        printf("assignment: ");
        for(int j = 0; j < n; j++) {
            printf("%6d", j);
        }
        printf("\n");
        printf("frequency:  ");
        for(int j = 0; j < n; j++) {
            printf("%6d", frequency[j]);
        }
        printf("\n");
        printf("mean: %.3f\n\n", average(frequency, n - 1, round[i]));
    }
    return 0;
}