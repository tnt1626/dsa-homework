#include <stdio.h>
#include <stdlib.h>
#define N 10    

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

struct Node *findInorderSuccessor(struct Node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int data) {
    if(!root) {
        return root;
    }
    if(data < root->data) {
        root->left = __deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = __deleteNode(root->right, data);
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

// 3.1
int minDepth(struct Node *root) {
    if(!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        return 1;
    }
    if(!root->left) {
        return minDepth(root->right) + 1;
    }
    if(!root->right) {
        return minDepth(root->left) + 1;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}

int minDepthOfBinaryTree(struct BinaryTree *tree) {
    return minDepth(tree->root);
}


// 3.2
// Giả sự: luôn cấp phát bộ nhớ thành công
void findLevelWithMostChild(struct Node *root, int **childs, int *size, int level) {
    if(!root) {
        return;
    }
    if(level >= *size) {
        *size *= 2;
        *childs = (int *)realloc(*childs, sizeof(int) * (*size));
        for(int i = *size / 2; i < *size; i++) {
            (*childs)[i] = 0;
        }
    }
    (*childs)[level]++;
    findLevelWithMostChild(root->left, childs, size, level + 1);
    findLevelWithMostChild(root->right, childs, size, level + 1);
}

// Quy ước: level của cây sẽ bất đầu từ 0 đến n - 1
int findLevelWithMostChildOfTree(struct BinaryTree *tree) {
    int size = 10;
    int *childs = (int *)calloc(size, sizeof(int));
    int level = 0;
    findLevelWithMostChild(tree->root, &childs, &size, level);
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(childs[i] > childs[index]) {
            index = i;
        }
    }
    free(childs);
    return index;
}

// 3.3
void sumOfOneChildNode(struct Node *root, int *sum) {
    if(!root) {
        return;
    }
    if((!root->left && root->right) || (!root->right && root->left)) {
        *sum += root->data;
    }
    sumOfOneChildNode(root->left, sum);
    sumOfOneChildNode(root->right, sum);
}

int sumOfOneChildNodeInTree(struct BinaryTree *tree) {
    int sum = 0;
    sumOfOneChildNode(tree->root, &sum);
    return sum;
}

// 3.4
// Tổng node 1 con bên phải = tổng node 1 con - tổng node 1 con bên trái
void sumOfOneRightChildNode(struct Node *root, int *sum) {
    if(!root) {
        return;
    }
    if(!root->left && root->right) {
        *sum += root->data;
    }
    sumOfOneRightChildNode(root->left, sum);
    sumOfOneRightChildNode(root->right, sum);
}

int sumOfOneRightChildNodeInTree(struct BinaryTree *tree) {
    int sum = 0;
    sumOfOneRightChildNode(tree->root, &sum);
    return sum;
}

// 3.5
void findClosestNode(struct Node *root, int target, struct Node **closestNode) {
    if(!root) {
        return;
    }
    if(!(*closestNode) || abs(root->data - target) < abs((*closestNode)->data - target)) {
        *closestNode = root;
    }
    findClosestNode(root->left, target, closestNode);
    findClosestNode(root->right, target, closestNode);
}

struct Node *findClosestNodeInTree(struct BinaryTree *tree) {
    int target = sumOfOneRightChildNodeInTree(tree);
    struct Node *closestNode = NULL;
    findClosestNode(tree->root, target, &closestNode);
    return closestNode;
}

void freeTree(struct Node *root) {
    if(!root) {
        return ;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void freeBinaryTree(struct BinaryTree *tree) {
    freeTree(tree->root);
    tree->root = NULL;
}


int main() {
    int array[] = {5, 3, 2, 1, 4, 7, 6, 9, 8, 12, 54, -5, -4};
    int n = sizeof(array) / sizeof(array[0]);
    struct BinaryTree tree;
    init(&tree);
    for(int i = 0; i < n; i++) {
        insert(&tree, array[i]);
    }
    struct Node *closestNode = findClosestNodeInTree(&tree);
    printf("Value: %4d\n", closestNode->data);
    freeBinaryTree(&tree);
    return 0;
}
// Nếu có sai gì ae nhớ phản hồi nhé