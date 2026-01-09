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

Node* insertHead(Node *head, int data) {
    Node *newNode = makeNode(data);
    newNode->next = head;
    return newNode;
}

Node* helperInsertAtK(Node *head, int data, int k) {
    if(k <= 1 || head == NULL) {
        head = insertHead(head, data);
        return head;
    }
    head->next = helperInsertAtK(head->next, data, k - 1);
    return head;
}

// 1.1
void insertAtK(LinkedList *list, int data, int k) {
    Node *head = list->head;
    head = helperInsertAtK(head, data, k);
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

Node* deleteHead(Node *head) {
    if(head == NULL) {
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* helperDeleteAtK(Node *head, int k) {
    if(head == NULL || k < 1) {
        return head;
    }
    if(k == 1) {
        return deleteHead(head);
    }
    head->next = helperDeleteAtK(head->next, k - 1);
    return head;
}

// 1.2
void deleteAtK(LinkedList *list, int k) {
    list->head = helperDeleteAtK(list->head, k);
}

void freeList(LinkedList *list) {
    while(list->head != NULL) {
        list->head = deleteHead(list->head);
    }
}

int main() {
    LinkedList list;
    init(&list);
    for(int i = 7; i >= 2; i--) {
        list.head = insertHead(list.head, i);
    } 
    printList(&list);
    while(1) {
        int k;
        scanf("%d", &k);
        deleteAtK(&list, k);
        printList(&list);
    }
    freeList(&list);
    return 0;
}