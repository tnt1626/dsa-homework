#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct BinaryTree {
    struct Node *root;
};

void init(struct BinaryTree *tree) {
    tree->root = NULL;
}

struct Node *makeNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Duyệt theo thứ tự left-root-right
void inorderTraversal(struct Node *root) {
    if(!root) {
        return;
    }
    inorderTraversal(root->left);
    printf("%3d", root->data);
    inorderTraversal(root->right);
}

void printTree(struct BinaryTree *tree) {
    printf("Tree:");
    inorderTraversal(tree->root);
    printf("\n");
}

// Quy định: cây nhị phân không có 2 node có cùng giá trị
struct Node *insertNode(struct Node *root, int data) {
    if(!root) {
        return makeNode(data);
    }
    if(data == root->data) {
        return root;
    }
    else if(data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void insert(struct BinaryTree *tree, int data) {
    tree->root = insertNode(tree->root, data);
}

int searchNode(struct Node *root, int data) {
    if(!root) {
        return 0;
    }
    if(data == root->data) {
        return 1;
    }
    if(data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

int search(struct BinaryTree *tree, int data) {
    return searchNode(tree->root, data);
}


// Một phiên bản thay thế của cách viết này
// struct Node *findInorderSuccessor(struct Node *root) {
//     while (root && root->left != NULL) {
//         root = root->left;
//     }
//     return root;
// }

struct Node *findInorderSuccessor(struct Node *root) {
    if(root == NULL|| root->left == NULL) {
        return root;
    }
    return findInorderSuccessor(root->left);
}

// Quy trình xóa 1 node như sau:
//     - Liên tục tìm kiếm node cần xóa
//         + Nếu không tồn tại thì trả về cây nguyên vẹn
//         + Nếu có tới bước tiếp theo
//     - Ta có 3 trường hợp của 1 node cần xóa (là node lá, có 1 con và có 2 con)
//         + Node lá: chỉ việc giải phóng node đó và trả về null
//         + Có 1 con: gán "nhánh con" của node hiện tại cho "ông nội" của node hiện tại
//         + Có 2 con: tìm node "successor", ta đổi giá trị với node cần xóa và xóa node "successor"
//         ** Nhưng khi cài đặt, ta chỉ quan tâm đến việc "node hiện tại có node con bên trái hoặc bên phải hay không ?"
//         nghe có vẻ kỳ lạ nhưng với cách cài đặt như thế mang tính tổng quát và dễ cài đặt hơn
struct Node *deleteNode(struct Node *root, int data) {
    if(!root) {
        return root;
    }
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if(root->left == NULL) {
            struct Node *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if(root->right == NULL) {
            struct Node *leftChild = root->left;
            free(root);
            return leftChild;
        }
        else {
            struct Node *inorderSuccessor = findInorderSuccessor(root->right);
            root->data = inorderSuccessor->data;
            root->right = deleteNode(root->right, inorderSuccessor->data);
        }
    }
    return root;
}

void delete(struct BinaryTree *tree, int data) {
    tree->root = deleteNode(tree->root, data);
}

int main() {

    return 0;
}