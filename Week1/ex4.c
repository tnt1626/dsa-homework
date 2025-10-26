#include <stdio.h>
#include <string.h>
#define N 100

// Hàm chèn một ký tự 'c' vào chuỗi 'str' tại vị trí 'index'
void insertCharacter(char *str, char c, int index) {
    int len = strlen(str); // lấy độ dài hiện tại của chuỗi
    len++;                 // tăng độ dài lên 1 vì sẽ thêm một ký tự mới

    // Dịch các ký tự từ cuối chuỗi sang phải để tạo chỗ trống
    for (int i = len - 1; i > index; i--) {
        str[i] = str[i - 1];
    }

    // Chèn ký tự mới vào vị trí chỉ định
    str[index] = c;

    // Gắn ký tự kết thúc chuỗi '\0' để đảm bảo chuỗi hợp lệ
    str[len] = '\0';
}

int main() {
    char str[N], c; // str: chuỗi ban đầu, c: ký tự cần chèn
    int index;      // vị trí chèn ký tự

    // Nhập chuỗi, ký tự cần chèn và vị trí chèn
    scanf("%s %c %d", str, &c, &index);

    // Gọi hàm chèn ký tự
    insertCharacter(str, c, index);

    // In ra chuỗi sau khi chèn
    printf("%s\n", str);

    return 0;
}
