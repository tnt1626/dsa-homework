#include <stdio.h>
#include <string.h>
#define N 100

int isSortedString(char str[N]) {
    int sorted = 1;
    int len = strlen(str);
    for(int i = 0; i < len - 1; i++) {
        if(str[i] > str[i + 1]) {
            sorted = 0;
            break;
        }
    }
    return sorted;
}

int linearSearch(char str[N], char value) {
    int index = -1;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == value) {
            index = i;
            break;
        }
        if(str[i] > value) {
            break;
        }
    }
    return index;
}

int binarySearch(char str[N], char value) {
    int left = 0, right = strlen(str) - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(str[mid] == value) {
            return mid;
        }
        else if(str[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    char str[N];
    char value;
    fgets(str, N, stdin);
    str[strcspn(str, "\n")] = '\0';
    scanf("%c", &value);
    if(!isSortedString(str)) {
        printf("Not a sorted string\n");
    }
    else {
        int index1 = linearSearch(str, value);
        int index2 = binarySearch(str, value);
        printf("Index of linear search: %d\n", index1);
        printf("Index of binary search: %d\n", index2);
    }
    return 0;
}