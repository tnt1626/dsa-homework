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

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        deleteHead(list);
    }
}

//                                              IMPLEMENT STACK
typedef struct {
    LinkedList *list;
} Stack;

void initStack(Stack *stack) {
    stack->list = (LinkedList *)malloc(sizeof(LinkedList));
    init(stack->list);
}

int isEmpty(Stack *stack) {
    return stack->list->head == NULL;
}

void push(Stack *stack, int value) {
    insertHead(stack->list, value);
}

// Phải kiểm tra stack có rỗng hay không trước khi gọi hàm
int pop(Stack *stack) {
    int data = stack->list->head->data;
    deleteHead(stack->list);
    return data;
}

void displayStack(Stack *stack) {
    Node *node = stack->list->head;
    printf("Stack:");
    while(node) {
        printf("%4d", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteStack(Stack *stack) {
    freeList(stack->list);
    free(stack->list);
}

// Viết hàm main debug lại có gì báo lại tui nha ae
int main() {
    Stack stack;
    initStack(&stack);
    deleteStack(&stack);
    return 0;
}