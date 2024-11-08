#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int STree(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + STree(root->left) + STree(root->right);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(4);
    root->right = createNode(10);
    root->left->left = createNode(2);
    root->left->right = createNode(9);

    int size = STree(root);
    printf("size of tree: %d\n", size);

    return 0;
}