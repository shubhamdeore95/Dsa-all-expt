#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder traversal:  ");
    printPreorder(root);
    printf("\n");

    printf("Inorder traversal:   ");
    printInorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}
