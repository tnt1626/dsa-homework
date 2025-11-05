#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MIN -200
#define MAX 200

void initializeArray(float *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = rand() % (MAX - MIN + 1);
    }
}

void minIndex(float *array, int n, int *assignment) {
    *assignment = 0;
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] < array[index]) {
            (*assignment)++;
            index = i;
        }
    }
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

    float array[N];
    int n = 10;
    int assignment;
    int round[] = {100, 1000};
    for(int i = 0; i < 2; i++) {
        int frequency[N] = {0};
        for(int j = 0; j < round[i]; j++) {
            initializeArray(array, n);
            minIndex(array, n, &assignment);
            frequency[assignment]++;
        }
        printf("assignment:    ");
        for(int k = 0; k <= n; k++) {
            printf("%6d", k);
        }
        printf("\n");
        printf("frequency: ");
        for(int k = 0; k <= n; k++) {
            printf("%6d", frequency[k]);
        }
        printf("\n");
        printf("mean: %.3f\n\n", average(frequency, n, round[i]));
    }
    return 0;
}