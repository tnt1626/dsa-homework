#include <stdio.h>
#include <string.h>
#define N 100

// 1.3
struct TripleFloat {
    float a, b, c;
};

float F(struct TripleFloat object) {
    return object.a - 2 * object.b + 3 * object.c;
}

void swapTripleFloat(struct TripleFloat *obj1, struct TripleFloat *obj2) {
    struct TripleFloat temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}

void bubbleSort3(struct TripleFloat *array, int n) {
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(F(array[j]) > F(array[j + 1])) {
                swapTripleFloat(&array[j], &array[j + 1]);
            }
        }
    }
}

// 1.1 Sắp xếp mảng số thực
void swapFloatNumber(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort1(float *array, int n) {
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(array[j] > array[j + 1]) {
                swapFloatNumber(&array[j], &array[j + 1]);
            }
        }
    }
}

// 1.2 Sắp xếp chuỗi kí tự
void swapCharacter(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort2(char *array) {
    int n = strlen(array);
    for(int i = 0; i  < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(array[j] > array[j + 1]) {
                swapCharacter(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    struct TripleFloat array[N];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%f %f %f", &array[i].a, &array[i].b, &array[i].c);
    }
    bubbleSort3(array, n);
    for(int i = 0; i < n; i++) {
        printf("(%5.2f,%5.2f,%5.2f)\n", array[i].a, array[i].b, array[i].c);
    }
    return 0;
}