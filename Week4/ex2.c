#include <stdio.h>
#define N 50

// Phương án 1

// Hàm dùng để xóa 1 phần tử tại index
void delete(int *arr, int *n, int index, int *steps) {
    if(index == -1) {
        return;
    }
    for(int i = index; i < *n - 1; i++) {
        (*steps)++;
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void solution1(int *arr, int *n, int *steps) {
    *steps = 0;
    int i = 0;
    while(i < *n) {
        (*steps)++;

        int j = i + 1;
        while(j < *n) { // Xóa tất cả các phần tử trùng với arr[i]
            (*steps)++;
            if(arr[i] == arr[j]) { // Nếu tìm thấy phần tử trùng thì xóa
                delete(arr, n, j, steps);
            }
            else {
                j++;
            }
        }

        i++;
    }
}

// Phương án 2
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sắp xếp các phần tử tăng dần bằng bubble sort
void bubbleSort(int *array, int n, int *steps) {
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            (*steps)++;
            if(array[j] > array[j + 1]) {
                (*steps)++; // Đếm số bước sắp xếp
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void solution2(int *arr, int *n, int *steps) {
    *steps = 0;
    bubbleSort(arr, *n, steps);
    int i = 0;
    while(i < *n) {
        (*steps)++;

        // TÌm độ dài của dãy phần tử trùng
        int j = i + 1;
        while(j < *n && arr[i] == arr[j]) { 
            (*steps)++;
            j++;
        }

        // Nếu không có phần tử trùng thì 
        // không thực hiện dời các phần tử phía sau
        int length = j - i - 1;
        if(length == 0) { 
            i++;
            continue;
        }
        
        // Dời các phần tử phía sau đè lên phần tử trùng
        for(int k = i; k < *n - length; k++) {
            (*steps)++;
            arr[k] = arr[k + length];
        }
        (*n) -= length; // Giảm đi chiều dài của mảng sau khi xóa

        i++;
    }
}


int main() {
    // int arr1[N] = {5, 2, 8, 5, 6, 2, 9, 8, 7, 5};
    // int arr2[N] = {5, 2, 8, 5, 6, 2, 9, 8, 7, 5};
    // int n1 = 10, n2 = 10;
    int arr1[N] = {
        3, 7, 1, 12, 5, 9, 3, 14, 2, 7,
        10, 5, 8, 11, 1, 6, 13, 15, 9, 4,
        2, 14, 7, 3, 10, 11, 6, 1, 8, 5,
        12, 13, 9, 15, 2, 4, 14, 7, 11, 6,
        10, 8, 13, 3, 9, 5, 1, 12, 4, 2
    };
    int arr2[N] = {
        3, 7, 1, 12, 5, 9, 3, 14, 2, 7,
        10, 5, 8, 11, 1, 6, 13, 15, 9, 4,
        2, 14, 7, 3, 10, 11, 6, 1, 8, 5,
        12, 13, 9, 15, 2, 4, 14, 7, 11, 6,
        10, 8, 13, 3, 9, 5, 1, 12, 4, 2
    };
    int n1 = 50, n2 = 50;

    int steps1, steps2;
    solution1(arr1, &n1, &steps1);
    solution2(arr2, &n2, &steps2);
    printf("arr1:");
    for(int i = 0; i < n1; i++) {
        printf("%4d", arr1[i]);
    }
    printf("\n");
    printf("arr2:");
    for(int i = 0; i < n2; i++) {
        printf("%4d", arr2[i]);
    }
    printf("\n");
    printf("Steps of solution 1: %4d\n", steps1);
    printf("Steps of solution 2: %4d\n", steps2);
    return 0;
}