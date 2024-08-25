#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// function defined to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function defined to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    // condition to check if the tree is empty
    if (root == NULL) {
        return createNode(value);
    }
    struct TreeNode** queue = (struct TreeNode*)malloc(100 * sizeof(struct TreeNode));
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct TreeNode* current = queue[++front];
        if (current->left != NULL) {
            queue[++rear] = current->left;
        } else {
            current->left = createNode(value);
            free(queue);
            return root;
       }

        if (current->right != NULL) {
            queue[++rear] = current->right;
        } else {
            current->right = createNode(value);
            free(queue);
            return root;
        }
    }
    free(queue);
    return root;
}

// function defined to do an in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, int value);

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root);

int main() {
    struct TreeNode* root = NULL; // Initialize the root of the binary tree
    int nodeValue, n;
    scanf("%d",&n); // number of nodes
    for(int i = 0; i<n; i++)        
    {
        scanf("%d", &nodeValue);    // enter input data to each node
        root = insertNode(root, nodeValue);
    }

    inOrderTraversal(root);

    
    return 0;
}
