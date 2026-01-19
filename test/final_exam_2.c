#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-6

struct Node {
    int a;
    int i;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void init(struct LinkedList *list) {
    list->head = NULL;
}
// Hàm tạo 1 node
struct Node *makeNode(int a, int i) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Cap phat khong thanh cong\n");
        return NULL;
    }
    newNode->a = a;
    newNode->i = i;
    newNode->next = NULL;
}
// Hàm chèn 1 node
struct Node *insertNode(struct Node *head, int a, int i) {
    struct Node *newNode = makeNode(a, i);
    newNode->next = head;
    return newNode;
}

void insert(struct LinkedList *list, int a, int i) {
    list->head = insertNode(list->head, a, i);
}

// Tính giá trị của x với mũ âm, dương bằng không
void computeNode(struct Node *head, float x, float *result) {
    if(head == NULL) {
        return;
    }
    float temp = 1.0;
    if(fabs(x) < EPSILON || head->i == 0) {
        temp = 0.0;
    }
    else if(head->i < 0) {
        for(int i = 0; i < -head->i; i++) {
            temp /= x;
        }
    }
    else {
        for(int i = 0; i < head->i; i++) {
            temp *= x;
        }
    }
    *result += head->a * temp;
    computeNode(head->next, x, result);
}

float compute(struct LinkedList *list, float x) {
    float result = 0;
    computeNode(list->head, x, &result);
    return result;
}

struct Node* deleteHead(struct Node *head) {
    if(head == NULL) {
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void freeList(struct LinkedList *list) {
    while(list->head != NULL) {
        list->head = deleteHead(list->head);
    }
}

void printList(struct LinkedList *list, float x) {
    struct Node *temp = list->head;
    while(temp != NULL) {
        printf("%d*%.2f^%d +", temp->a, x, temp->i);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList list;
    init(&list);
    while(1) {
        int a, i;
        printf("Nhap a, i: ");
        scanf("%d %d", &a, &i);
        if(a == 0 && i == 0) {
            break;
        }
        insert(&list, a, i);
    }
    float x;
    printf("Nhap x: ");
    scanf("%f", &x);
    // printList(&list, x);
    float result = compute(&list, x);
    printf("Ket qua: %5.2f\n", result);
    freeList(&list);
    return 0;
}

// Testcase 1:
// Nhap a, i: 1 3
// Nhap a, i: 2 4
// Nhap a, i: 0 0
// Nhap x: 2.2
// Ket qua: 57.50

// Testcase 2:
// Nhap a, i: 1 0
// Nhap a, i: 2 0
// Nhap a, i: 3 0
// Nhap a, i: 0 0
// Nhap x: 55435
// Ket qua:  0.00