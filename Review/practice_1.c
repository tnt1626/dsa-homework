#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 1e-6

struct Node {
    double x;
    double y;
    double z;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

struct Plane {
    double a, b, c, d;
};

void makePlane(struct Plane *plane) {
    printf("Nhập a, b, c, d: ");
    scanf("%lf %lf %lf %lf", &plane->a, &plane->b, &plane->c, &plane->d);
}

void init(struct LinkedList *points) {
    points->head = NULL;
}

double distance(struct Plane *plane, double x, double y, double z) {
    double temp = abs(plane->a * x + plane->b * y + plane->c * z + plane->d);
    if(abs(temp) < EPSILON) {
        return 0.0;
    }
    return temp / sqrt(plane->a * plane->a + plane->b * plane->b + plane->c * plane->c + EPSILON);
}

double getDistance(struct Plane *plane, struct Node *head) {
    if(head == NULL) {
        return 0.0;
    }
    return distance(plane, head->x, head->y, head->z);
}

struct Node *makeNode(double x, double y, double z) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Cấp phát không thành công\n");
        return NULL;
    }
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    return newNode;
}

struct Node *insertHead(struct Node *head, double x, double y, double z) {
    struct Node *newPoint = makeNode(x, y, z);
    newPoint->next = head;
    return newPoint;
}

struct Node *insertNode(struct Plane *plane, struct Node *head, double x, double y, double z) {
    if(head == NULL || distance(plane, x, y, z) - getDistance(plane, head) <= EPSILON) {
        return insertHead(head, x, y, z);
    }
    head->next = insertNode(plane, head->next, x, y, z);
    return head;
}

void insert(struct Plane *plane, struct LinkedList *points, double x, double y, double z) {
    points->head = insertNode(plane, points->head, x, y, z);
}

void printList(struct Plane *plane, struct LinkedList *points) {
    struct Node *head = points->head;
    if(head == NULL) {
        printf("Không có điểm nào trong danh sách\n");
        return;
    }
    printf("Danh sách các điểm là:\n");
    while(head) {
        printf("Tọa độ: (%3.1lf, %3.1lf, %3.1lf), khoảng cách: %3.2lf\n", head->x, head->y, head->z, getDistance(plane, head));
        head = head->next;
    }
}

struct Node *deleteHead(struct Node *head) {
    if(head == NULL) {
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void freeList(struct LinkedList *points) {
    while(points->head != NULL) {
        points->head = deleteHead(points->head);
    }
}

int main() {
    struct LinkedList points;
    init(&points);
    struct Plane plane;
    makePlane(&plane);
    while(1) {
        double x, y, z;
        printf("Nhập x, y, z: ");
        scanf("%lf %lf %lf", &x, &y, &z);
        insert(&plane, &points, x, y, z);
        // printList(&plane, &points);
        if(abs(x) < EPSILON && abs(y) < EPSILON && abs(z) < EPSILON) {
            break;
        }
    }
    printList(&plane, &points);
    freeList(&points);
    return 0;
}

// Nhập a, b, c, d:  1 2 -2 1
// Nhập x, y, z: 1 1 1
// Nhập x, y, z: 2 3 -4
// Nhập x, y, z: 3 3 2
// Nhập x, y, z: 0 0 0
// Danh sách các điểm là:
// Tọa độ: (0.0, 0.0, 0.0), khoảng cách: 0.33
// Tọa độ: (1.0, 1.0, 1.0), khoảng cách: 0.67
// Tọa độ: (3.0, 3.0, 2.0), khoảng cách: 2.00
// Tọa độ: (2.0, 3.0, -4.0), khoảng cách: 5.67