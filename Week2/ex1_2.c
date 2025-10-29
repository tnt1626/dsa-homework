#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6 // sai số nhỏ được sử dụng để so sánh bằng trong số thực
#define N 100

// Hàm giúp tìm kiếm phần tử trong mảng được sắp xếp
int orderedLinearSearch(float *array, int n, float value) {
    int index = -1;
    for(int i = 0; i < n; i++) {
        if(fabs(array[i] - value) < EPSILON) { // Điều kiện so sánh bằng 2 số thực
            index = i;
            break;
        }
        if(array[i] > value) {
            break;
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
    float value;
    scanf("%f", &value);
    int index = orderedLinearSearch(array, n, value);
    if(index == -1) {
        printf("Not found!\n");
    }
    else {
        printf("%d\n", index);
    }
    return 0;
}