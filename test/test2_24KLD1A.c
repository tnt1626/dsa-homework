#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Phân tích hàm insertOrderedArray theo quy trình 4 bước:
// Bước 1: Base case là a[n - 1] <= value hoặc n == 0 (giá trị cần chèn >= giá trị cuối cùng hoặc mảng không có phần tử nào)
// Bước 2: Kết quả của base case là  a[n] = value hoặc a[0] = value
// Bước 3: 1 trường hợp trước trường hợp base case là n = 1, kết quả là a[1] = a[1 - 1] => a[1] = a[0]
// Bước 4: 1 trường hợp trước trường hợp ở bước 3 là n = 2, kết quả là a[2] = a[2 - 1] => a[2] = a[1]
void insertOrderedArray(float a[], int n, float value, int *assigns) {
    if (a[n - 1] <= value || n == 0) {
        a[n] = value;
        return;
    }
    (*assigns)++;
    a[n] = a[n - 1];
    insertOrderedArray(a, n - 1, value, assigns);
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
    float a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int assigns = 0;
    int frequency[11] = {0};
    for(int i = 0; i < 1000; i++) {
        // Cái sinh số ngẫu nhiên float này giống như đưa về vector đơn vị z ae =))
        float value = (float)rand() / RAND_MAX * 10;
        assigns = 0;
        for(int j = 0; j < 10; j++) {
            a[j] = j + 1;
        }
        insertOrderedArray(a, 10, value, &assigns);
        frequency[assigns]++;
    }
    printf("Observation\tFrequency\n");
    for(int i = 0; i < 11; i++) {
        printf("%-3d\t\t%-3d\n", i, frequency[i]);
    }
    printf("Mean: %-.5f\n", average(frequency, 11, 1000));
    return 0;
}

// Observation     Frequency
// 0               0  
// 1               78
// 2               107
// 3               97
// 4               90
// 5               104
// 6               104
// 7               102
// 8               106
// 9               110
// 10              102
// Mean: 5.65900