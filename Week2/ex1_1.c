#include <stdio.h>
#define N 100

// Chèn 1 giá trị value cho trước vào mảng đã được sắp xếp
void insertOrderedArray(float *array, int *n, float value) {
    int index = (*n) - 1;
    for(int i = 0; i < (*n); i++) { // Tìm vị trí cần chèn value vào mảng
        if(array[i] >= value) {
            index = i;
            break;
        }
    }
    (*n)++;
    for(int i = (*n) - 1; i > index; i--) { // Chèn 1 phần tử vào chỉ số index
        array[i] = array[i - 1];
    }
    array[index] = value;
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
    insertOrderedArray(array, &n, value);
    for(int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    return 0;
}