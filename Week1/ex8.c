#include <stdio.h>
#include <string.h>
#define N 100  // Kích thước tối đa của chuỗi

// Hàm xóa 1 ký tự trong chuỗi tại vị trí index
void deleteCharacter(char *str, int index) {
    int len = strlen(str);  // Lấy độ dài hiện tại của chuỗi

    // Dịch tất cả ký tự sau vị trí index lên trước 1 vị trí
    for(int i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }

    len--;               // Giảm độ dài chuỗi đi 1
    str[len] = '\0';     // Gắn ký tự kết thúc chuỗi (null character)
}

int main() {
    char str[N];   // Chuỗi ký tự đầu vào
    int index;     // Vị trí ký tự cần xóa

    // Nhập chuỗi và vị trí xóa
    // Ví dụ: hello 1  → sẽ xóa ký tự 'e'
    scanf("%s %d", str, &index);

    // Gọi hàm xóa
    deleteCharacter(str, index);

    // In chuỗi sau khi xóa
    printf("%s\n", str);

    return 0;
}
