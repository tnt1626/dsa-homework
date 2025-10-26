#include <stdio.h>
#include <string.h>
#include <ctype.h> // thư viện để dùng hàm tolower()
#define N 100

// Hàm chuyển toàn bộ chuỗi sang chữ thường
void toLowerCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]); // chuyển từng ký tự sang chữ thường
    }
}

// Hàm tìm ký tự 'c' trong chuỗi 'str' (không phân biệt hoa thường)
int findCharacter(char *str, char c) {
    toLowerCase(str); // Chuyển chuỗi sang chữ thường
    c = tolower(c);   // Chuyển ký tự cần tìm sang chữ thường

    int index = -1;   // giá trị mặc định nếu không tìm thấy
    int len = strlen(str);

    // Duyệt từng ký tự trong chuỗi
    for (int i = 0; i < len; i++) {
        if (str[i] == c) { // nếu trùng ký tự cần tìm
            index = i;     // lưu vị trí
            break;         // dừng lại ngay khi tìm thấy
        }
    }
    return index; // trả về vị trí tìm thấy hoặc -1 nếu không có
}

int main() {
    char str[N], c;

    // Nhập chuỗi và ký tự cần tìm
    scanf("%s %c", str, &c);

    // Gọi hàm tìm ký tự
    int index = findCharacter(str, c);

    // In kết quả
    if (index == -1) {
        printf("Not found\n");
    } else {
        printf("Found %c at %d\n", c, index);
    }

    return 0;
}
