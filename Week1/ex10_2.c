#include <stdio.h>
#include <string.h>
#define N 1001
#define M 100

// Hàm so sánh hai chuỗi trong 'length' ký tự
// Trả về 1 nếu giống nhau hoàn toàn trong 'length' ký tự, ngược lại trả về 0
int compareString(char str1[], char str2[], int length) {
    int i = 0;
    while (i < length) {
        if (str1[i] == '\0') {
            return 0;  // kết thúc sớm => không khớp
        }
        if (str1[i] != str2[i]) {
            return 0;  // ký tự khác nhau => không khớp
        }
        i++;
    }
    return 1;  // trùng khớp hoàn toàn
}

// Hàm tìm tất cả các vị trí xuất hiện của các chuỗi "mã độc"
// Lưu kết quả vào mảng index (mỗi hàng là danh sách vị trí của 1 chuỗi con)
void findPoisonCode(char str[N], char subStrs[M][M], int k, int index[M][M], int *rows, int cols[M]) {
    *rows = k;
    int lenStr = strlen(str);

    for (int i = 0; i < k; i++) {
        int len = strlen(subStrs[i]);
        int col = 0;

        // Bỏ qua nếu chuỗi con rỗng hoặc dài hơn chuỗi chính
        if (len == 0 || len > lenStr) {
            cols[i] = 0;
            continue;
        }

        // Duyệt qua từng vị trí có thể khớp
        for (int j = 0; j <= lenStr - len; j++) {
            if (str[j] == subStrs[i][0] && compareString(str + j, subStrs[i], len) == 1) {
                index[i][col++] = j; // lưu vị trí khớp
            }
        }
        cols[i] = col; // số lần xuất hiện của subStrs[i]
    }
}

// Hàm xóa một chuỗi con khỏi chuỗi chính tại vị trí index, độ dài length
void deleteString(char str[N], int index, int length) {
    int lenStr = strlen(str);
    // Dịch toàn bộ phần sau chuỗi con sang trái
    for (int i = index; i < lenStr - length; i++) {
        str[i] = str[i + length];
    }
    str[lenStr - length] = '\0'; // kết thúc chuỗi
}

// Hàm xóa toàn bộ các chuỗi con "mã độc" ra khỏi chuỗi chính
void deletePoisonCode(char str[N], char subStrs[M][M], int k) {
    int index[M][M];
    int rows, cols[M];

    // Tìm tất cả vị trí xuất hiện của các chuỗi con
    findPoisonCode(str, subStrs, k, index, &rows, cols);

    // Duyệt từng chuỗi con
    for (int i = 0; i < rows; i++) {
        // Xóa từ phải sang trái để không làm lệch vị trí các đoạn còn lại
        for (int j = cols[i] - 1; j >= 0; j--) {
            int length = strlen(subStrs[i]);
            deleteString(str, index[i][j], length);
        }
    }
}

int main() {
    char str[N], subStrs[M][M];
    int k;

    // Nhập chuỗi chính
    fgets(str, N, stdin);
    str[strcspn(str, "\n")] = '\0'; // xóa '\n' ở cuối

    // Nhập số lượng chuỗi con cần xóa
    scanf("%d", &k);
    getchar(); // bỏ '\n'

    // Nhập danh sách chuỗi con
    for (int i = 0; i < k; i++) {
        fgets(subStrs[i], M, stdin);
        subStrs[i][strcspn(subStrs[i], "\n")] = '\0'; // xóa '\n'
    }

    // Gọi hàm xóa "mã độc"
    deletePoisonCode(str, subStrs, k);

    // In kết quả sau khi xóa
    printf("%s\n", str);
    return 0;
}
