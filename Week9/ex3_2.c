#include <stdio.h>
#include <stdlib.h>

//                                          IMPLEMENT LINKED LIST
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

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        deleteHead(list);
    }
}
//                                              IMPLEMENT QUEUE
typedef struct {
    LinkedList *list;
} Queue;

void initQueue(Queue *queue) {
    queue->list = (LinkedList *)malloc(sizeof(LinkedList));
    init(queue->list);
}

int isEmpty(Queue *queue) {
    return queue->list->head == NULL;
}

void put(Queue *queue, int value) {
    insertTail(queue->list, value);
}

// Phải kiểm tra queue có rỗng hay không trước khi gọi hàm
int get(Queue *queue) {
    int data = queue->list->head->data;
    deleteHead(queue->list);
    return data;
}

void displayQueue(Queue *queue) {
    Node *node = queue->list->head;
    printf("Queue:");
    while(node) {
        printf("%4d", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteQueue(Queue *queue) {
    freeList(queue->list);
    free(queue->list);
}

int main() {
    return 0;
}