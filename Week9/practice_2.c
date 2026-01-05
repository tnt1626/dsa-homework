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

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        deleteHead(list);
    }
}

int main() {
    LinkedList list;
    init(&list);
    int array[] = {2, 12, 9, 0, 11, 3, 4, 8};
    for(int i = 0; i < 8; i++) {
        insertHead(&list, array[i]);
    }
    insertHead(&list, 19);
    insertTail(&list, -3);
    printList(&list);
    deleteTail(&list);
    deleteTail(&list);
    printList(&list);
    freeList(&list);
    return 0;
}