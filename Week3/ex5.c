#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void initializeArray(int *array, int n) {
    for(int i = 0; i < n; i++) {
        array[i] = (rand() % (2 * N + 1)) - N;
    }
}

int negativeSum(int *array, int n, int *assignment) {
    *assignment = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] < 0) {
            (*assignment)++;
            sum += array[i];
        }
    }
    return sum;
}


int main() {
    srand(time(NULL));

    int array[N];
    int n = 10;
    int assignment;
    int round = 1000;
    int frequency[11] = {0};
    for(int j = 0; j < round; j++) {
        initializeArray(array, n);
        negativeSum(array, n, &assignment);
        frequency[assignment]++;
    }
    printf("assignment: ");
    for(int j = 0; j <= n; j++) {
        printf("%6d", j);
    }
    printf("\n");
    printf("frequency:  ");
    for(int j = 0; j <= n; j++) {
        printf("%6d", frequency[j]);
    }
    printf("\n");
    return 0;
}