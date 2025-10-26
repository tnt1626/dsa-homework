#include <stdio.h>
#include <string.h>
#define N 1001
#define M 100

// Hàm so sánh hai chuỗi trong 'length' ký tự
// Trả về 1 nếu giống nhau hoàn toàn trong 'length' ký tự, ngược lại trả về 0
int compareString(char str1[], char str2[], int length) {
    int i = 0;
    while (i < length) {
        // Nếu một trong hai chuỗi kết thúc sớm thì không khớp
        if (str1[i] == '\0') {
            return 0;
        }
        // Nếu ký tự khác nhau thì không khớp
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    // Nếu duyệt hết 'length' ký tự mà không sai -> khớp
    return 1;
}

// Hàm tìm vị trí xuất hiện của các "mã độc" (chuỗi con) trong chuỗi chính
// - str: chuỗi chính
// - subStrs: danh sách các chuỗi con cần tìm
// - k: số lượng chuỗi con
// - index: mảng 2 chiều lưu các vị trí xuất hiện
// - rows: số hàng thực tế (bằng k)
// - cols: số cột (số lần xuất hiện của mỗi chuỗi con)
void findPoisonCode(char str[N], char subStrs[M][M], int k, int index[M][M], int *rows, int cols[M]) {
    *rows = k; // số hàng bằng số chuỗi con cần tìm
    int lenStr = strlen(str); // độ dài chuỗi chính

    for (int i = 0; i < k; i++) {
        int len = strlen(subStrs[i]); // độ dài chuỗi con thứ i
        int col = 0; // số lần xuất hiện

        // Nếu chuỗi con rỗng hoặc dài hơn chuỗi chính thì bỏ qua
        if (len == 0 || len > lenStr) {
            cols[i] = 0;
            continue;
        }

        // Duyệt qua từng vị trí có thể khớp trong chuỗi chính
        for (int j = 0; j <= lenStr - len; j++) {
            // Nếu ký tự đầu trùng nhau và phần còn lại cũng khớp
            if (str[j] == subStrs[i][0] && compareString(str + j, subStrs[i], len) == 1) {
                index[i][col++] = j; // lưu vị trí bắt đầu khớp
            }
        }
        cols[i] = col; // lưu số lần xuất hiện
    }
}

int main() {
    char str[N], subStrs[M][M];
    int k;

    // Nhập chuỗi chính (có thể chứa khoảng trắng)
    fgets(str, N, stdin);
    str[strcspn(str, "\n")] = '\0'; // xóa ký tự '\n' ở cuối chuỗi

    // Nhập số lượng chuỗi con
    scanf("%d", &k);
    getchar(); // loại bỏ ký tự '\n' còn lại sau khi nhập số

    // Nhập k chuỗi con
    for (int i = 0; i < k; i++) {
        fgets(subStrs[i], M, stdin);
        subStrs[i][strcspn(subStrs[i], "\n")] = '\0'; // xóa '\n' ở cuối mỗi chuỗi
    }

    // Mảng lưu kết quả vị trí xuất hiện
    int index[M][M];
    int rows, cols[M];

    // Gọi hàm xử lý
    findPoisonCode(str, subStrs, k, index, &rows, cols);

    // In kết quả
    for (int i = 0; i < rows; i++) {
        printf("%d %s ", cols[i], subStrs[i]); // in số lần xuất hiện và chuỗi con

        if (cols[i] == 0) {
            printf("\n");
            continue;
        }

        // In ra danh sách các vị trí xuất hiện
        for (int j = 0; j < cols[i]; j++) {
            printf("%d", index[i][j]);
            if (j == cols[i] - 1) {
                printf("\n");
            } else {
                printf(", ");
            }
        }
    }

    return 0;
}
