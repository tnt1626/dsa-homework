#include <stdio.h>
#include <math.h>
#define N 100

// Hàm tìm phần tử trong mảng gần nhất với giá trị target
int findNearestNumber(float *array, int n, float target) {
    int nearestIndex = -1;      // chỉ số của phần tử gần nhất
    float minDistance = 1e9;    // khoảng cách nhỏ nhất ban đầu

    for (int i = 0; i < n; i++) {
        float distance = fabs(array[i] - target); // độ lệch tuyệt đối giữa phần tử và target
        if (distance < minDistance) {
            minDistance = distance;   // cập nhật khoảng cách nhỏ nhất
            nearestIndex = i;         // lưu vị trí gần nhất
        }
    }

    return nearestIndex;
}

int main() {
    float array[N];
    int n;
    float target;

    // Nhập số phần tử của mảng
    scanf("%d", &n);

    // Nhập các phần tử của mảng (số thực)
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    // Nhập giá trị cần tìm gần nhất
    scanf("%f", &target);

    // Tìm vị trí phần tử gần nhất
    int index = findNearestNumber(array, n, target);

    // In kết quả
    printf("%.2f at index %d nearest to %.2f\n", array[index], index, target);

    return 0;
}
