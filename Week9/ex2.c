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

int findIndexToInsert(LinkedList *list, int data) {
    int k = 1;
    Node *node = list->head;
    while(node) {
        if(node->data >= data) {
            return k;
        }
        node = node->next;
        k++;
    }
    return k;
}

// 2.1
void insert(LinkedList *list, int data) {
    int k = findIndexToInsert(list, data);
    insertAtK(list, data, k);
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
    if(curr == NULL) { 
        return 0;
    }
    Node *temp = curr;
    prev->next = curr->next;
    free(temp);
    return 1;
}

int findIndexToDelete(LinkedList *list, int value) {
    int k = 1;
    Node *node = list->head;
    while(node) {
        if(node->data == value) {
            return k;
        }
        node = node->next;
        k++;
    }
    return k;
}

// 2.2
int delete(LinkedList *list, int value) {
    int k = findIndexToDelete(list, value);
    int status = deleteAtK(list, k);
    return status;
}

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        deleteHead(list);
    }
}


// Cả 2 bài đều sử tận dụng 2 hàm của bài trước, 
// thực hiện bằng cách tìm số k và gọi hàm insert/delete 
// tại chỉ số k

int main() {
    LinkedList list;
    init(&list);
    for(int i = 0; i < 7; i++) {
        insertHead(&list, i);
    }
    while(1) {
        printList(&list);
        int data;
        printf("Data: ");
        scanf("%d", &data);
        delete(&list, data);
    }
    freeList(&list);
    return 0;
}