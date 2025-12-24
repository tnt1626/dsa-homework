#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

// Phân tích hàm max theo quy trình 4 bước:
// Bước 1: Base case là n = 1
// Bước 2: Kết quả của base case là a[n - 1] = a[0] = 2
// Bước 3: 1 trường hợp trước trường hợp base case là n = 2, gọi hàm max(a, 1) trả về a[0] = 2, 
//           max(a, 2) trả về value = giá trị lớn hơn trong a[1] = 5 và a[0] = 2 => trả về 5
// Bước 4: 1 trường hợp trước trường hợp ở bước 3 là n = 3, gọi hàm max(a, 2) trả về value = 5,
//           max(a, 3) trả về giá trị lớn hơn trong a[2] = 7 và value = 5 => trả về 7

int max1(int a[], int n, int *assigns) {
    if (n == 1) {
        return a[n - 1];
    }
    int maxValue = max1(a, n - 1, assigns);
    if (a[n - 1] > maxValue) {
        (*assigns)++;
        maxValue = a[n - 1];
    }
    return maxValue;
}  

void initializeArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        array[i] = rand() % (2 * N + 1) - N;
    }
}

float average(int frequency[], int n, int k) {
    float sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += frequency[i] * i;
    }
    return sum / k;
}

int main() {
    srand(time(NULL));
    // int a[] = {2, 5, 7, 0, 12, 1, 4};
    int array[N], n = 10;
    int assigns = 0, k = 1000;
    int frequency[N] = {0};
    for(int i = 0; i < k; i++) {
        initializeArray(array, n);
        assigns = 0;
        max1(array, n, &assigns);
        frequency[assigns]++;
    }
    printf("Mean: %-5.3f\n", average(frequency, n + 1, k));
    return 0;
}

// Mean: 1.811