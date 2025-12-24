#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

// Phân tích hàm đệ quy theo quy trình 4 bước:
// Bước 1: Base case là left == right (mảng chỉ có 1 phần tử)
// Bước 2: Kết quả của base case là trả về a[left] (phần tử duy nhất của mảng)
// Bước 3: 1 trường hợp trước trường hợp base case là right = left + 1 (mảng có 2 phần tử)
//      Ví dụ như left = 0, right = 1 => middle = 0
//      gọi hàm min(a, 0, 0) trả về a[0] và gọi hàm min(a, 1, 1) trả về a[1]
//      => trả về giá trị nhỏ hơn giữa a[0] và a[1]
// Bước 4: 1 trường hợp trước trường hợp ở bước 3 là right = left + 2 (mảng có 3 phần tử)
//      Ví dụ như left = 0, right = 2 => middle = 1
//      gọi hàm min(a, 0, 1) => trả về value = giá trị nhỏ hơn giữa a[0] và a[1]
//      gọi hàm min(a, 2, 2) => trả về a[2]
//      => trả về giá trị nhỏ hơn giữa value và a[2]

int minValue(int a[], int left, int right, int *calls) {
    if (left == right) {
        (*calls)++;
        return a[left];
    } 
    int middle = (left + right) / 2;
    int lvalue = minValue(a, left, middle, calls);
    int rvalue = minValue(a, middle + 1, right, calls);
    if (lvalue < rvalue) {
        return lvalue;
    }
    else {
        return rvalue;
    }
}

void initializeArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        array[i] = rand() % (2 * N) - N;
    }
}

float average(int frequency[], int n, int k) {
    float sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += i * frequency[i];
    }
    return sum / k;
}

int main() {
    srand(time(NULL));
    int array[N], n = 10;
    int frequency[N] = {0};
    int k = 1000;
    int calls = 0;
    for(int i = 0; i < k; i++) {
        initializeArray(array, n);
        calls = 0;
        minValue(array, 0, n - 1, &calls);
        frequency[calls]++;
    }
    printf("Observation\tFrequency\n");
    for(int i = 0; i < n + 1; i++) {
        printf("%-3d\t\t%-3d\n", i, frequency[i]);
    }
    printf("Mean: %-.3f\n", average(frequency, n + 1, k));
    return 0;
}