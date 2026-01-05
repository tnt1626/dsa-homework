#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int data;
    struct NodeType *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void init(LinkedList *list) {
    list->head = NULL;
}

Node* makeNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertHead(LinkedList *list, int data) {
    Node *newNode = makeNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertTail(LinkedList *list, int data) {
    if(list->head == NULL) {
        insertHead(list, data);
        return;
    }
    Node *node = list->head;
    while(node->next != NULL) {
        node = node->next;
    }
    Node *newNode = makeNode(data);
    node->next = newNode;
}

// 1.1
// Nếu k lớn hơn chiều dài list thì sẽ chèn vào vị trí cuối cùng
// Mặc định k <= 1 sẽ chèn ở đầu để tránh lỗi
// Mặc định là chèn được nên không có giá trị trả về
void insertAtK(LinkedList *list, int data, int k) {
    if(k <= 1) {
        insertHead(list, data);
        return;
    }
    Node *prev = NULL, *curr = list->head;
    while(--k) {
        prev = curr;
        curr = curr->next;
        if(curr == NULL) {
            break;
        }
    }
    Node *newNode = makeNode(data);
    newNode->next = curr;
    prev->next = newNode;
}

void printList(LinkedList *list) {
    Node *node = list->head;
    printf("Linked list:");
    while(node != NULL) {
        printf("%3d", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteHead(LinkedList *list) {
    if(list->head == NULL) {
        return;
    }
    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
}

void deleteTail(LinkedList *list) {
    if(list->head == NULL) {
        return;
    }
    Node *prev = NULL, *curr = list->head;
    if(curr->next == NULL) {
        deleteHead(list);
        return;
    }
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    free(curr);
}

// 1.2
// Nếu k < 1 hoặc k lớn hơn độ dài list -> không xóa được (trả về 0)
// Có thể xóa được hoặc không nên phải có giá trị trả về để biết được trạng thái
int deleteAtK(LinkedList *list, int k) {
    if(list->head == NULL | k < 1) {
        return 0;
    }
    if(k == 1) {
        deleteHead(list);
        return 1;
    }
    Node *prev = NULL, *curr = list->head;
    while(--k) {
        prev = curr;
        curr = curr->next;
        if(curr == NULL) {
            break;
        }
    }
    if(curr == NULL) { // k lớn hơn độ dài list
        return 0;
    }
    Node *temp = curr;
    prev->next = curr->next;
    free(temp);
    return 1;
}

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        deleteHead(list);
    }
}

int main() {
    LinkedList list;
    init(&list);
    for(int i = 7; i >= 2; i--) {
        insertHead(&list, i);
    } 
    printList(&list);
    int status = 1;
    while(status) {
        int k;
        scanf("%d", &k);
        status = deleteAtK(&list, k);
        printList(&list);
    }
    printList(&list);
    freeList(&list);
    return 0;
}