#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int ISBN;
    char *title;
    struct Node *left;
    struct Node *right;
};

struct BinaryTree {
    struct Node *root;
};

void init(struct BinaryTree *tree) {
    tree->root = NULL;
}

// Hàm tạo 1 node
struct Node *makeNode(int ISBN, char title[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Cấp phát không thành công\n");
        return NULL;
    }
    newNode->title = (char *)malloc(sizeof(strlen(title) + 1));
    if(newNode->title == NULL) {
        free(newNode);
        printf("Cấp phát không thành công\n");
        return NULL;
    } 
    newNode->ISBN = ISBN;
    strcpy(newNode->title, title);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn 1 node
struct Node *insertNode(struct Node *root, int ISBN, char title[]) {
    if(root == NULL) {
        return makeNode(ISBN, title);
    }
    if(ISBN == root->ISBN) {
        return root;
    }
    if(ISBN < root->ISBN) {
        root->left = insertNode(root->left, ISBN, title);
    }
    else {
        root->right = insertNode(root->right, ISBN, title);
    }
    return root;
}

// Hàm gọi hàm chèn 1 node thông qua struct BinaryTree tree
void insert(struct BinaryTree *tree, int ISBN, char title[]) {
    tree->root = insertNode(tree->root, ISBN, title);
}

// Hàm tìm node
struct Node *searchNode(struct Node *root, int ISBN) {
    if(!root) {
        return NULL;
    }
    if(ISBN == root->ISBN) {
        return root;
    }
    if(ISBN < root->ISBN) {
        return searchNode(root->left, ISBN);
    }
    return searchNode(root->right, ISBN);
}

// Hàm gọi hàm tìm 1 node thông qua struct BinaryTree tree
// Nếu có thì in thông tin node đó
void search(struct BinaryTree *tree, int ISBN) {
    struct Node *node = searchNode(tree->root, ISBN);
    if(node == NULL) {
        printf("Khong tim thay sach\n");
        return;
    }
    printf("ISBN: %d\n", node->ISBN);
    printf("Tua de: %s\n", node->title);
}

// Hàm giải phóng node
void freeNode(struct Node *root) {
    if(root == NULL) {
        return;
    }
    freeNode(root->left);
    freeNode(root->right);
    free(root->title);
    free(root);
}

// Hàm giải phóng cây
void freeTree(struct BinaryTree *tree) {
    freeNode(tree->root);
    tree->root = NULL;
}

int main() {
    struct BinaryTree tree;
    init(&tree);
    while(1) {
        int ISBN;
        char title[20];
        printf("Nhap ISBN: ");
        scanf("%d", &ISBN);
        if(ISBN == 0) { // Nhập ISBN = 0 thì dừng thêm sách
            break;
        }
        printf("Nhap tua de: ");
        scanf("\n%s", title);
        insert(&tree, ISBN, title);
    }
    int ISBN;
    printf("Nhap ISBN de tim sach: ");
    scanf("%d", &ISBN);
    search(&tree, ISBN);
    freeTree(&tree);
    return 0;
}

// Testcase 1:
// Nhap ISBN: 12
// Nhap tua de: hehe
// Nhap ISBN: 13
// Nhap tua de: hihi
// Nhap ISBN: 0
// Nhap ISBN de tim sach: 12
// ISBN: 12
// Tua de: hehe

// Testcase 2:
// Nhap ISBN: 1
// Nhap tua de: hehe
// Nhap ISBN: 2
// Nhap tua de: hihi
// Nhap ISBN: 3
// Nhap tua de: haha
// Nhap ISBN: 0
// Nhap ISBN de tim sach: 5
// Khong tim thay sach