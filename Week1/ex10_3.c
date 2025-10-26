#include <stdio.h>
#include <string.h>
#define N 1001
#define M 100

// So sánh 'length' ký tự giữa str1 và str2
// Trả về 1 nếu khớp, ngược lại 0
int compareString(char str1[], char str2[], int length) {
    int i = 0;
    while (i < length) {
        if (str1[i] == '\0') {
            return 0;   // str1 kết thúc sớm
        }
        if (str1[i] != str2[i]) {
            return 0; // khác ký tự => không khớp
        }
        i++;
    }
    return 1;
}

// Tìm tất cả vị trí xuất hiện của từng chuỗi trong subStrs
// index[i][*] lưu các vị trí của subStrs[i], cols[i] là số lần xuất hiện
void findPoisonCode(char str[N], char subStrs[M][M], int k, int index[M][M], int *rows, int cols[M]) {
    *rows = k;
    int lenStr = strlen(str);

    for (int i = 0; i < k; i++) {
        int len = strlen(subStrs[i]);
        int col = 0;
        if (len == 0 || len > lenStr) { 
            cols[i] = 0; continue; // bỏ qua
        } 
        for (int j = 0; j <= lenStr - len; j++) {
            // kiểm tra nhanh ký tự đầu rồi so sánh đầy đủ
            if (str[j] == subStrs[i][0] && compareString(str + j, subStrs[i], len) == 1) {
                index[i][col++] = j;
            }
        }
        cols[i] = col;
    }
}

// Biến đổi bắt đầu từ con trỏ str: chèn sau mỗi ký tự của poisonCode một ký tự ASCII liền kề
// (thực hiện tại chỗ; caller phải đảm bảo đủ bộ nhớ)
void transformCode(char str[], char poisonCode[]) {
    int len1 = strlen(str);
    int len2 = strlen(poisonCode);
    for (int i = len1 - 1; i >= 0; i--) {
        str[i + len2] = str[i]; // dịch sang phải
    }
    str[len1 + len2] = '\0';
    for (int j = len2 - 1; j >= 0; j--) {
        str[2 * j + 1] = str[j] + 1; // ký tự liền kề ASCII
        str[2 * j] = str[j];         // ký tự gốc
    }
}

// Gọi transformCode cho mọi occurrence đã tìm (duyệt từ phải sang trái để không làm lệch)
void decodePoison(char str[N], char subStrs[M][M], int k) {
    int index[M][M];
    int rows, cols[M];
    findPoisonCode(str, subStrs, k, index, &rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = cols[i] - 1; j >= 0; j--) {
            transformCode(str + index[i][j], subStrs[i]);
        }
    }
}

/*
CHÚ Ý: Hàm trên chỉ đúng trong trường hợp chỉ số của mã độc được sắp xếp như sau:
- Các chỉ số bắt đầu của mã độc được tìm thấy trong chuỗi là tăng dần
- Chỉ số nhỏ nhất của mã độc ở vị trí (i - 1) phải lớn hơn chỉ số lớn nhất của mã độc ở vị trí (i)
*/
// Nếu đề bài có ràng buộc khác mình sẽ sửa lại sau nhé

int main() {
    char str[N], subStrs[M][M];
    int k;

    // Đọc chuỗi chính
    fgets(str, N, stdin);
    str[strcspn(str, "\n")] = '\0'; // xóa newline

    // Đọc số lượng mã độc
    scanf("%d", &k);
    getchar(); // bỏ newline sau số

    // Đọc danh sách mã độc
    for (int i = 0; i < k; i++) {
        fgets(subStrs[i], M, stdin);
        subStrs[i][strcspn(subStrs[i], "\n")] = '\0';
    }

    // Xử lý: chèn ký tự liền kề sau mỗi ký tự trong mã độc
    decodePoison(str, subStrs, k);

    // In kết quả
    printf("%s\n", str);
    return 0;
}
