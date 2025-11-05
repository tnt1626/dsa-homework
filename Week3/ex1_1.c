#include <stdio.h>
#define N 100

int minIndex(float *array, int n) {
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] < array[index]) {
            index = i;
        }
    }
    return index;
}

int main() {
    float array[N];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }
    int index = minIndex(array, n);
    printf("%d\n", index);
    return 0;
}