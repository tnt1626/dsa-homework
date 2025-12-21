#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

// Khởi tạo mảng ngẫu nhiên, tồn tại ít nhất 1 phần tử có giá trị 1
void initializeArray(int array[], int n) {
    int index = rand() % 20;
    array[index] = 1;
    for(int i = 0; i < N; i++) {
        if(index != i) {
            array[i] = rand() % 10 + 1;
        }
    }
}

// Hàm đệ quy tạo hộp chứa các giá trị ngẫu nhiên:
//    1. Lưu phần tử vào stack
//    2. Nếu là 1 thì dừng, ngược lại thì thêm tiếp
// Phân tích theo quy trình 4 bước:
    // 1. Base case array[i] == 1
    // 2. Kết quả của base case: dừng thêm phần tử
    // 3. Một trường hợp trước base case: thêm phần tử vào mảng
    // 4. Một trường hợp trước bước 3: thêm phần tử vào mảng
void createBox(int stack[], int *top, int array[], int index) {
    (*top)++;
    stack[(*top)] = array[index];
    if(array[index] == 1) {
        return;
    }
    createBox(stack, top, array, index + 1);
}

// Hàm đệ quy tổng các phần tử trong hộp
//    1. Nếu hết phần tử (top == -1) thì dừng lại
//    2. Ngược lại, cứ lấy ra rồi cộng vào thêm
// Phân tích theo quy trình 4 bước:
    // 1. Base case top == -1
    // 2. Kết quả của base case: dừng lấy phần tử để cộng
    // 3. Một trường hợp trước base case: lấy 1 phần tử, cộng phần tử đó vào kết quả
    // 4. Một trường hợp trước bước 3: lấy 1 phần tử, cộng phần tử đó vào kết quả
void sumElements(int stack[], int top, int *result) {
    if(top == -1) {
        return;
    }
    *result += stack[top];
    sum(stack, top - 1, result);
}

int main() {
    srand(time(NULL));
    int array[N];
    int n = 20;
    // Khởi tạo và in các giá trị trong mảng 
    // để kiểm tra các phần tử có được thêm đúng hay không
    initializeArray(array, n);
    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%4d", array[i]);
    }
    printf("\n");
    // Khởi tạo stack
    int stack[N], top = -1;
    createBox(stack, &top, array, 0);
    printf("Stack: ");
    for(int i = 0; i <= top; i++) {
        printf("%4d", stack[i]);
    }
    // In ra tổng
    int result = 0;
    sum(stack, top, &result);
    printf("\nResult: %4d\n", result);
    return 0;
}