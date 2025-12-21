#include <stdio.h>
#define N 10

// 1
void printOrderedArray(int array[], int n) {
    if(n == 0) {
        printf("%3d", array[n]);
        return;
    }
    int temp = array[n - 1];
    printOrderedArray(array, n - 1);
    printf("%3d", temp);
    return;
}

// 2
int linearSearch(int array[], int n, int nums) {
    if(n == -1) {
        return -1;
    }
    if(array[n - 1] == nums) {
        return n - 1;
    }
    return linearSearch(array, n - 1, nums);
}

// 3a
void pop(int stack[], int *top) {
    if((*top) - 1 == -1) {
        return;
    }
    printf("%3d", stack[(*top) - 1]);
    (*top)--;
    pop(stack, top);
}

// 3b
void get(int queue[], int *head, int *tail) {
    if((*tail) - (*head) + 1 == 0) {
        return;
    }
    int temp = queue[(*head)];
    (*head)++;
    get(queue, head, tail);
    printf("%3d", temp);
}

// 4
int binarySearch(int array[], int left, int right, int value) {
    if(left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if(array[mid] == value) {
        return mid;
    }
    else if(array[mid] > value) {
        return binarySearch(array, left, mid - 1, value);
    }
    return binarySearch(array, mid + 1, right, value);
}

int main() {
    int array[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int head = 0, tail = 8;
    int n = 9;
    int value = 4;
    printf("%3d", binarySearch(array, 0, n - 1, value));
    return 0;
}