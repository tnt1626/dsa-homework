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

void printList(LinkedList *list) {
    Node *node = list->head;
    while(node != NULL) {
        printf("Node address: %p |", &(node->data));
        printf("Data = %3d | ", node->data);
        printf("Next node address: %p |\n", node->next);
        node = node->next;
    }
    printf("\n\n");
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

int main() {
    LinkedList list;
    init(&list);
    for(int i = 0; i < 10; i++) {
        insertHead(&list, i);
    }
    insertHead(&list, 15);
    printList(&list);
    deleteHead(&list);
    printList(&list);
    freeList(&list);
    printList(&list);
    return 0;
}