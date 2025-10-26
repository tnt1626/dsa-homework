#include <stdio.h>
#define N 100

// Cấu trúc Pair dùng để chứa 1 giá trị thực và vị trí muốn chèn
struct Pair {
    float value;  // giá trị cần chèn
    int index;    // vị trí chèn (tính theo chỉ số mảng ban đầu)
};

// Hàm chèn m phần tử mới (pair[]) vào mảng arr[]
void insert(float arr[], int *n, struct Pair pair[], int m) {
    int i = (*n) - 1;       // i: chỉ số phần tử cuối của mảng gốc
    int j = m - 1;          // j: chỉ số phần tử cuối của mảng cần chèn
    int newSize = (*n) + m; // kích thước mới sau khi chèn
    int k = newSize - 1;    // k: vị trí ghi dữ liệu vào mảng mới (từ cuối lên)

    // duyệt ngược để tránh ghi đè dữ liệu chưa xử lý
    while (k >= 0) {
        // nếu vẫn còn phần tử cần chèn và vị trí chèn nằm ngay sau i
        if (j >= 0 && i + 1 == pair[j].index) {
            arr[k--] = pair[j].value; // chèn giá trị mới
            j--;                       // giảm số phần tử cần chèn
        }
        else {
            arr[k--] = arr[i]; // sao chép phần tử cũ sang vị trí mới
            i--;
        }
    }
    (*n) = newSize; // cập nhật lại kích thước mảng
}

int main() {
    int n;
    float arr[N];
    int m;
    struct Pair pair[N];

    // Nhập mảng ban đầu
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    
    // Nhập các phần tử cần chèn (giá trị + vị trí)
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%f %d", &pair[i].value, &pair[i].index);
    }

    // Thực hiện chèn
    insert(arr, &n, pair, m);

    // Xuất kết quả sau khi chèn
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
