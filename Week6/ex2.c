#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51


// Định nghĩa 1 cấu trúc stack
typedef struct {
    char a[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char value) {
    s->a[++s->top] = value;
}

int pop(Stack *s) {
    return s->a[s->top--];
}

int isValidPair(char c1, char c2) {
    if((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')) {
        return 1;
    }
    return 0;
}

// Các hàm phụ bao gồm:
//  - Kiểm tra có phải là ngoặc mở hay không ?
//  - Tìm ngoặc đóng của ngoặc mở tương ứng
//  - Kiểm tra có phải là dấu ngoặc hay không ? (Để bỏ qua các chữ số và các phép toán)
int isOpenParenthesis(char c) {
    if(c == '(' || c == '{' || c == '[') {
        return 1;
    }
    return 0;
}

char isClosedParenthesisOf(char c) {
    if(c == '(') {
        return ')';
    }
    if(c == '{') {
        return '}';
    }
    return ']';
}

int isParenthesis(char c) {
    if(c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') {
        return 1;
    }
    return 0;
}

/* Vì có ràng buộc "Biết rằng các dấu ngoặc luôn được nhập vào theo cặp một cách đầy đủ và luôn đứng đúng vị trí."
nên ta chỉ kiểm tra các trường hợp sau:
    - Nếu là 1 dấu ngoặc mở -> đẩy vào stack (1)
    - Ngược lại -> lấy dấu ngoặc ở đỉnh stack để kiểm tra có phải là 1 cặp dấu ngoặc hợp lệ (2)
        + Nếu không hợp lệ -> lưu lại vị trí sai và dấu ngoặc hợp lệ cho vị trí đó (3)
*/
void checkParenthesis(char str[], int error[], char validParenthesis[], int *size) {
    Stack s;
    init(&s);
    *size = 0; // Kích thước mảng cũng là số lượng ngoặc bị sai
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        if(isParenthesis(str[i])) { // Bỏ qua các chữ số và các phép toán
            if(isOpenParenthesis(str[i])) { // (1)
                push(&s, str[i]);
            }
            else {
                char temp = pop(&s); // (2)
                if(!isValidPair(temp, str[i])) { // (3)
                    error[*size] = i;
                    validParenthesis[*size] = isClosedParenthesisOf(temp);
                    (*size)++;
                }
            }
        }
    }
}

int main() {
    char str[MAX] = "(1+2)*3+(4*5)";
    int error[MAX] = {0}; // Dùng để lưu các chỉ số có dấu ngoặc bị sai
    char validParenthesis[MAX]; // Lưu dấu ngoặc phù hợp tại vị trí error
    int size;
    checkParenthesis(str, error, validParenthesis, &size);
    if(size == 0) {
        printf("No error.\n");
    }
    else {
        // In và thay thế các dấu ngoặc bị sai
        printf("Error:");
        for(int i = 0; i < size; i++) {
            printf("%3d", error[i]); // In
            str[error[i]] = validParenthesis[i]; // Thay thế
        }
        printf("\n");
    }
    printf("%s\n", str);
    return 0;
}