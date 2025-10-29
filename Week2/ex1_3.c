#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6 // sai số nhỏ được sử dụng trong so sánh bằng 2 số thực
#define N 100

// Hàm tìm kiếm 1 giá trị trong mảng sắp xếp tăng dần bằng binary search
int binarySearch(float *array, int n, float value) {
    int lowerBound = 0, upperBound = n - 1;
    while(lowerBound <= upperBound) {
        int midPoint = (lowerBound + upperBound) / 2;
        if(fabs(array[midPoint] - value) < EPSILON) {
            return midPoint;
        }
        else if(array[midPoint] > value) {
            upperBound = midPoint - 1;
        }
        else {
            lowerBound = midPoint + 1;
        }
    }
    return -1;
}

int main() {
    float array[N], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }
    float value;
    scanf("%f", &value);
    int index = binarySearch(array, n, value);
    if(index == -1) {
        printf("Not found!\n");
    }
    else {
        printf("%d\n", index);
    }
    return 0;
}