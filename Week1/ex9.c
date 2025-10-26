#include <stdio.h>
#include <math.h>
#define N 100
#define EPSILON 1e-6   // Ngưỡng sai số cho phép khi so sánh hai số thực (float)

// Cấu trúc lưu một cặp số thực (tọa độ x, y)
struct Pair {
    float x, y;
};

// Hàm tìm tất cả các vị trí (chỉ số) trong mảng point[]
// mà phần tử trùng với deletePoint (xét theo sai số EPSILON)
void findIndex(struct Pair point[], int n, struct Pair deletePoint, int index[], int *size) {
    *size = 0;  // Khởi tạo số lượng phần tử cần xóa = 0
    for(int i = 0; i < n; i++) {
        // So sánh hai cặp số thực gần bằng nhau theo EPSILON
        if(fabs(point[i].x - deletePoint.x) < EPSILON && fabs(point[i].y - deletePoint.y) < EPSILON) {
            index[(*size)++] = i;  // Ghi lại chỉ số của phần tử trùng
        }
    }
}

// Hàm xóa 1 phần tử tại vị trí index trong mảng point[]
void deleteOnePoint(struct Pair point[], int *n, int index) {
    // Dịch các phần tử sau index lên 1 vị trí
    for(int i = index; i < (*n) - 1; i++) {
        point[i] = point[i + 1];
    }
    (*n)--;  // Giảm kích thước mảng đi 1
}

// Hàm xóa tất cả các phần tử trùng với deletePoint trong mảng
void deletePoints(struct Pair point[], int *n, struct Pair deletePoint, int index[], int *size) {
    // Tìm tất cả chỉ số cần xóa
    findIndex(point, *n, deletePoint, index, size);
    if(*size == 0) {  // Không tìm thấy điểm nào trùng
        return;
    }
    // Xóa lần lượt từng phần tử (theo thứ tự ngược để tránh xáo trộn chỉ số)
    for(int i = *size - 1; i >= 0; i--) {
        deleteOnePoint(point, n, index[i]);
    }
}

int main() {
    struct Pair point[N], deletedPoint;
    int n;
    scanf("%d", &n);  // Nhập số lượng phần tử

    // Nhập n điểm (mỗi điểm gồm 2 số thực x, y)
    for(int i = 0; i < n; i++) {
        scanf("%f %f", &point[i].x, &point[i].y);
    }

    // Nhập điểm cần xóa
    scanf("%f %f", &deletedPoint.x, &deletedPoint.y);

    printf("\n");
    int index[N], size;

    // Gọi hàm xóa
    deletePoints(point, &n, deletedPoint, index, &size);

    // In mảng sau khi xóa
    for(int i = 0; i < n; i++) {
        printf("%.2f %.2f\n", point[i].x, point[i].y);
    }

    // Thông báo kết quả
    if(size == 0) {
        printf("Can not delete %.2f %.2f from the array!\n", deletedPoint.x, deletedPoint.y);
    }
    else {
        printf("Delete %.2f %.2f at ", deletedPoint.x, deletedPoint.y);
        for(int i = 0; i < size; i++) {
            printf("%d", index[i]);
            if(i == size - 1) {
                printf("\n");
            }
            else {
                printf(", ");
            }
        }
    }

    return 0;
}
