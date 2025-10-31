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
            int index = rand() % n;
            n = 10;
            delete(array, &n, index, &assignment);
            frequency[assignment]++;
        }
        printf("assignment: ");
        for(int j = 0; j <= n + 1; j++) {
            printf("%6d", j);
        }
        printf("\n");
        printf("frequency:  ");
        for(int j = 0; j <= n + 1; j++) {
            printf("%6d", frequency[j]);
        }
        printf("\n");
        printf("mean: %.3f\n\n", average(frequency, n + 1, round[i]));
    }
    return 0;
}