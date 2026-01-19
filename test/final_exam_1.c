#include <stdio.h>

int checkNumber(int array[], int n) {
    if(n <= 0) {
        return 1;
    }
    if(array[n - 1] % 2 == 1) {
        return 0;
    }
    return checkNumber(array, n - 1);
}

int main() {
    int array[] = {0, 2, 2, 2, 6, 8, 10, 2, 2};
    int n = sizeof(array) / sizeof(int);
    int res = checkNumber(array, n);
    printf("%d\n", res);
    return 0;
}