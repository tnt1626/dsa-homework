#include <stdio.h>
#include <string.h>
#define N 100

// Hàm tìm kiếm một chuỗi 'str' trong mảng các chuỗi 'serialKey'
// Trả về vị trí (index) nếu tìm thấy, ngược lại trả về -1
int findString(char serialKey[][N], int n, char *str) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        // so sánh chuỗi tại serialKey[i] với chuỗi str
        if (strcmp(serialKey[i], str) == 0) { 
            index = i;   // lưu lại vị trí tìm thấy
            break;       // dừng ngay sau khi tìm được
        }
    }
    return index;
}

int main() {
    int n, k;
    char serialKey[N][N];  // mảng chứa n chuỗi (mỗi chuỗi dài tối đa N ký tự)
    char str[N];           // chuỗi cần tìm

    // Nhập n (số chuỗi) và k (độ dài tối đa mỗi chuỗi)
    scanf("%d %d", &n, &k);
    while (getchar() != '\n'); // loại bỏ ký tự '\n' còn sót lại trong bộ đệm

    // Nhập n chuỗi lần lượt
    for (int i = 0; i < n; i++) {
        fgets(serialKey[i], N, stdin); // đọc từng dòng (bao gồm cả khoảng trắng)
        serialKey[i][k] = '\0';        // đảm bảo chuỗi không vượt quá k ký tự
    }

    // Nhập chuỗi cần tìm
    fgets(str, N, stdin);
    str[k] = '\0'; // đảm bảo chuỗi tìm không dài quá k ký tự

    // Gọi hàm tìm kiếm
    int index = findString(serialKey, n, str);

    // Xuất kết quả
    if (index == -1) {
        printf("Not found\n");
    } else {
        printf("Found %s at %d\n", str, index);
    }
    return 0;
}
