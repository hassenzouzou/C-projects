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

int HTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftH = HTree(root->left);
        int rightH = HTree(root->right);

        if (leftH > rightH) {
            return leftH + 1;
        } else {
            return rightH + 1;
        }
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(12);
    root->right = createNode(3);
    root->left->left = createNode(3);
    root->left->right = createNode(15);

    int height = HTree(root);
    printf("high of tree: %d\n", height);

    return 0;
}