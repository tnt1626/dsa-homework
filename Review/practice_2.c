#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if(!newNode) {
        printf("Cấp phát không thành công\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int data) {
    if(root == NULL) {
        return makeNode(data);
    }
    if(data == root->data) {
        return root;
    }
    if(data < root->data) {
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

void createTree(struct BinaryTree *tree) {
    for(int i = 0; i < 10; i++) {
        int data = rand() % 101;
        insert(tree, data);
    }
}

void countLeafNode(struct Node *root, int *count) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        *count += 1;
        return;
    }
    countLeafNode(root->left, count);
    countLeafNode(root->right, count);
}

int countLeafNodeOfTree(struct BinaryTree *tree) {
    int count = 0;
    countLeafNode(tree->root, &count);
    return count;
}

void freeNode(struct Node *root) {
    if(root == NULL) {
        return;
    }
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

void freeTree(struct BinaryTree *tree) {
    freeNode(tree->root);
    tree->root = NULL;
}

double getMean(int frequency[], int n, int k) {
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += frequency[i] * i;
    }
    return sum / k;
}

int main() {
    srand(time(NULL));
    struct BinaryTree tree;
    init(&tree);
    int frequency[11] = {0};
    for(int i = 0; i < 1000; i++) {
        createTree(&tree);
        int count = countLeafNodeOfTree(&tree);
        freeTree(&tree);
        frequency[count]++;
    }
    printf("Observation\tFrequency\n");
    for(int i = 0; i < 11; i++) {
        printf("%5d\t\t%5d\n", i, frequency[i]);
    }
    double mean = getMean(frequency, 11, 1000);
    printf("Mean: %5.3lf\n", mean);
    return 0;
}

// Observation     Frequency
//     0               0
//     1               1
//     2              57
//     3             405
//     4             457
//     5              80
//     6               0
//     7               0
//     8               0
//     9               0
//    10               0
// Mean: 3.558