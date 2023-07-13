#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct AVLNode {
    void * data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;


// Function to get the height of a node
int getHeight(AVLNode* node);



// Function to calculate the maximum of two numbers
int max_reg(int a, int b);


// Function to create a new node
AVLNode* createNode(void * data);



// Function to right rotate subtree rooted with y
AVLNode* rightRotate(AVLNode* y);


// Function to left rotate subtree rooted with x
AVLNode* leftRotate(AVLNode* x);


// Function to get the balance factor of a node
int getBalance(AVLNode* node);


// Function to insert a node into the AVL tree
AVLNode* insert(AVLNode* node, void* data, int compare(void* a, void* b));


// Function to print the AVL tree in inorder traversal
void inorderTraversal(AVLNode* node, void print(void* p));


