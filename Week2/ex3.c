#include <stdio.h>
#include <string.h>
#define N 27

int findMissingCharacter(char str[N]) {
    int index = 'z' - 'a';
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] - 'a' != i) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    char str[N];
    scanf("%s", str);
    int index = findMissingCharacter(str);
    printf("%c at %d is missing!\n", 'a' + index, index);
    return 0;
}