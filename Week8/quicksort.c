#include <stdio.h>
#define N 20

void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%3d", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int left, int right) {
    int pivot = right;
    right--;
    while(left <= right) {
        while(array[left] < array[pivot]) {
            left++;
        }
        while(right >= left && array[right] > array[pivot]) {
            right--;
        }
        if(left <= right) {
            swap(&array[left], &array[right]);
            left++;
            right--;
        }
    }
    swap(&array[left], &array[pivot]);
    return left;
}

void quicksort(int array[], int left, int right) {
    if(left > right) {
        return;
    }
    int index = partition(array, left, right);
    printArray(array + left, right - left + 1);
    quicksort(array, left, index - 1);
    quicksort(array, index + 1, right);
}

// Bước 1: base case n = 1
// Bước 2: kết quả của base case là array[] không đổi
// Bước 3: 1 trường hợp trước base case là n = 2, quicksort(array, 0, 1) kết quả là -4, -4
// Bước 4: 1 trường hợp trước bước 3 là n = 3, quicksort(array, 0, 2):
    // Chọn pivot = 2, dời các phần tử bé hơn array[2] qua trái, lớn hơn array[2] qua phải
    // Có được mảng tăng dần 3 phần tử

int main() {
    int array[] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9, -2};
    int n = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}