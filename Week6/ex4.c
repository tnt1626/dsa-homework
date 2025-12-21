#include <stdio.h>
#define MAX 51

typedef struct {
    int head, tail;
    int a[MAX];
} Queue;

void init(Queue *q) {
    q->head = 0;
    q->tail = -1;
}

int isEmpty(Queue *q) {
    return q->tail - q->head + 1 == 0;
}

int isFull(Queue *q) {
    return q->tail == MAX - 1;
}

void put(Queue *q, int user) {
    q->a[++q->tail] = user;
}

int get(Queue *q) {
    return q->a[q->head++];
}

int findPosition(Queue *q, int user) {
    if(isEmpty(q)) {
        return -1;
    }
    int index = -1;
    for(int i = q->head; i <= q->tail; i++) {
        if(q->a[i] == user) {
            index = i;
            break;
        }
    }
    return index;
}

void cancelRegistration(Queue *q, int user) {
    int index = findPosition(q, user);
    if(index == -1) {
        printf("CANNOT FIND THE CORRECT USER\n");
        return;
    }
    for(int i = index; i < q->tail; i++) {
        q->a[i] = q->a[i + 1];
    }
    q->tail--;
    printf("CANCEL REGISTRATION SUCCESFULLY\n");
}

void displayQueue(Queue *q) {
    if(isEmpty(q)) {
        printf("NO ONE IN QUEUE RIGHT NOW\n");
    }
    else {
        printf("QUEUE:");
        for(int i = q->head; i <= q->tail; i++) {
            printf("%3d", q->a[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    init(&q);
    
    while(1) {
        printf("-----------------MENU-----------------\n");
        printf("1. Add registration\n");
        printf("2. Get the top user\n");
        printf("3. Cancel registration\n");
        printf("4. Display queue\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Your selection here: ");
        int selection;
        scanf("%d", &selection);
        if(selection == 1) {
            int user;
            printf("Enter user code: ");
            scanf("%d", &user);
            if(isFull(&q)) {
                printf("THE QUEUE IS FULL RIGHT NOT\n");
            }
            else {
                put(&q, user);
                printf("ADD REGISTRATION SUCCESSFULLY\n");
            }
        }
        else if(selection == 2) {
            if(isEmpty(&q)) {
                printf("NO ONE IN QUEUE RIGHT NOW\n");
            }
            else {
                get(&q);
                printf("GET INFORMATION SUCCESSFULLY\n");
            }
        }
        else if(selection == 3) {
            int user;
            printf("Enter user code: ");
            scanf("%d", &user);
            cancelRegistration(&q, user);
        }
        else if (selection == 4) {
            displayQueue(&q);
        }
        else {
            break;
        }
    }

    return 0;
}