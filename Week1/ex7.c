#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100   // Kích thước tối đa cho mảng và chuỗi

// Cấu trúc Pair: lưu một chuỗi và chỉ số index tương ứng
struct Pair {
    char str[N]; // Chuỗi ký tự
    int index;   // Chỉ số (được trích ra từ chuỗi)
};

// Hàm so sánh hai phần tử Pair dựa vào index (dùng cho qsort)
int compare(const void *a, const void *b) {
    struct Pair *x = (struct Pair *)a;
    struct Pair *y = (struct Pair *)b;
    return x->index - y->index; // Trả về giá trị âm nếu x < y, dương nếu x > y
}

// Hàm chuyển mỗi chuỗi trong mảng insertStrs thành một Pair (gồm chuỗi và index)
// Giả sử: hai ký tự đầu tiên của chuỗi là chỉ số (ví dụ: "03apple" → index = 3)
void convertToIndexAndString(char insertStrs[N][N], int m, struct Pair pair[]) {
    int size = 0;
    for(int i = 0; i < m; i++) {
        int index = 0;
        // Lấy 2 ký tự đầu tiên làm chỉ số (chuyển từ ký tự sang số)
        for(int j = 0; j < 2; j++) {
            index = index * 10 + (insertStrs[i][j] - '0');
        }
        pair[size].index = index;            // Gán chỉ số
        strcpy(pair[size].str, insertStrs[i]); // Sao chép toàn bộ chuỗi
        size++;
    }
}

// Hàm chèn các chuỗi mới (insertStrs) vào mảng strs sao cho đúng thứ tự chỉ số index
void insert(char strs[N][N], int *n, char insertStrs[N][N], int m) {
    struct Pair pair1[N], pair2[N];

    // Chuyển cả hai mảng chuỗi thành mảng Pair (chuỗi + index)
    convertToIndexAndString(strs, *n, pair1);
    convertToIndexAndString(insertStrs, m, pair2);

    // Sắp xếp mảng pair2 theo index tăng dần
    qsort(pair2, m, sizeof(struct Pair), compare);

    // Trộn hai mảng pair1 và pair2 (giống merge trong merge sort)
    int i = (*n) - 1;      // con trỏ cuối của mảng gốc
    int j = m - 1;         // con trỏ cuối của mảng cần chèn
    int newSize = (*n) + m; 
    int k = newSize - 1;   // con trỏ cuối của mảng kết quả

    // Trộn từ cuối về đầu để tránh ghi đè
    while(i >= 0 && j >= 0) {
        if(pair1[i].index >= pair2[j].index) {
            strcpy(strs[k--], pair1[i--].str); // lấy từ mảng cũ
        }
        else {
            strcpy(strs[k--], pair2[j--].str); // lấy từ mảng mới (insert)
        }
    }

    // Sao chép phần còn lại nếu một mảng đã hết
    while(i >= 0) {
        strcpy(strs[k--], pair1[i--].str);
    }
    while(j >= 0) {
        strcpy(strs[k--], pair2[j--].str);
    }

    (*n) = newSize; // Cập nhật lại kích thước mảng
}

int main() {
    const int size = 10; // Giới hạn ký tự đọc vào mỗi dòng
    int n, m;
    char strs[N][N], insertStrs[N][N];

    // Nhập số lượng chuỗi ban đầu
    scanf("%d", &n);
    getchar(); // bỏ ký tự '\n' sau khi nhập số

    // Nhập n chuỗi ban đầu
    for(int i = 0; i < n; i++) {
        fgets(strs[i], N, stdin); // đọc chuỗi
        strs[i][size] = '\0';     // đảm bảo kết thúc chuỗi
    }

    // Nhập số lượng chuỗi cần chèn
    scanf("%d", &m);
    getchar();

    // Nhập m chuỗi cần chèn
    for(int i = 0; i < m; i++) {
        fgets(insertStrs[i], N, stdin);
        insertStrs[i][size] = '\0';
    }

    // Gọi hàm chèn
    insert(strs, &n, insertStrs, m);

    // In kết quả sau khi chèn
    printf("%d\n", n);
    for(int i = 0; i < n; i++) {
        printf("%s ", strs[i]);
    }
    printf("\n");

    return 0;
}
