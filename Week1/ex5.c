#include <stdio.h>
#include <string.h>
#define N 100

// Hàm chèn một chuỗi mới vào mảng chuỗi tại vị trí chỉ định
void insertString(char strs[N][N], int *n, int index, char *str) {
    (*n)++; // tăng số lượng chuỗi lên 1 vì có thêm phần tử mới

    // Dịch các chuỗi phía sau sang phải để chừa chỗ cho chuỗi mới
    for (int i = (*n) - 1; i > index; i--) {
        strcpy(strs[i], strs[i - 1]);  // sao chép chuỗi phía trước sang vị trí hiện tại
    }

    // Sao chép chuỗi mới vào vị trí được chỉ định
    strcpy(strs[index], str);
}

int main() {
    int n, m;
    char strs[N][N]; // mảng chứa n chuỗi, mỗi chuỗi dài tối đa N ký tự
    int index;       // vị trí muốn chèn
    char str[N];     // chuỗi cần chèn

    // Nhập số lượng chuỗi ban đầu (n) và độ dài tối đa mỗi chuỗi (m)
    scanf("%d %d", &n, &m);
    while (getchar() != '\n'); // loại bỏ ký tự '\n' còn sót lại trong bộ đệm

    // Nhập n chuỗi ban đầu
    for (int i = 0; i < n; i++) {
        fgets(strs[i], N, stdin); // đọc cả dòng (kể cả khoảng trắng)
        strs[i][m] = '\0';        // đảm bảo chuỗi kết thúc đúng độ dài m
    }

    // Nhập vị trí muốn chèn
    scanf("%d", &index);
    getchar(); // loại bỏ '\n' trước khi đọc chuỗi mới

    // Nhập chuỗi mới cần chèn
    fgets(str, N, stdin);
    str[m] = '\0'; // đảm bảo độ dài không vượt quá m

    // Gọi hàm chèn
    insertString(strs, &n, index, str);

    // In ra mảng chuỗi sau khi chèn
    for (int i = 0; i < n; i++) {
        printf("%s ", strs[i]);
    }
    
    return 0;
}
