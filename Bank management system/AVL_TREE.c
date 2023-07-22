#include "AVL_TREE.h"


// Function to get the height of a node
int getHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}


// Function to calculate the maximum of two numbers
int max_reg(int a, int b) {
    if (a > b)
        return a;
    return b;
}






// Function to create a new node
AVLNode* createNode(void * data) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}


// Function to right rotate subtree rooted with y
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max_reg(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max_reg(getHeight(x->left), getHeight(x->right)) + 1;

    // Return the new root
    return x;
}


// Function to left rotate subtree rooted with x
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max_reg(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max_reg(getHeight(y->left), getHeight(y->right)) + 1;

    // Return the new root
    return y;
}


// Function to get the balance factor of a node
int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}


// Function to insert a node into the AVL tree
AVLNode* insert(AVLNode* node, void * data, int compare(void* a, void * b) ) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);
    
    if (compare(data, node->data) < 0)
        node->left = insert(node->left, data, compare);
    else if (compare(data, node->data) > 0)
        node->right = insert(node->right, data, compare);
    else // Equal data values are not allowed in AVL tree
        return node;

    // Update the height of the current node
    node->height = 1 + max_reg(getHeight(node->left), getHeight(node->right));

    // Get the balance factor of this node to check if it became unbalanced
    int balance = getBalance(node);

    // Left-Left case 
    if (balance > 1 && compare(data, node->left->data) < 0)
        return rightRotate(node);

    // Right-Right case
    if (balance < -1 && compare(data, node->right->data) > 0)
        return leftRotate(node);

    // Left-Right case
    if (balance > 1 && compare(data, node->left->data) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left case
    if (balance < -1 && compare(data, node->right->data) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // If the node is already balanced, return it
    return node;
}


// Function to print the AVL tree in inorder traversal
void inorderTraversal(AVLNode* node, void func(void * p)) {
    if (node != NULL) {
        inorderTraversal(node->left, func);
        func(node->data);
        inorderTraversal(node->right, func);
    }
}


//function that find the right node in the avl tree
AVLNode* search(AVLNode* root, void* value, int compare(void* a, void* b) ) {
    
    if (root == NULL) {
        return root;
    }

    int difference = compare(value, root->data);
    if (difference == 0)
    {
        return root;
    }
    else if (difference < 0) {
        return search(root->left, value, compare);
    }
    else {
        return search(root->right, value, compare);
    }
}