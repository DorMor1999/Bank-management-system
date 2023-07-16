#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL_TREE.h"


#define LEN_OTHERS_ATTRIBUTES 40
#define LEN_EMAIL 60


typedef struct{
    char firstName[LEN_OTHERS_ATTRIBUTES];
    char lastName[LEN_OTHERS_ATTRIBUTES];
    char email[LEN_EMAIL];
    char password[LEN_OTHERS_ATTRIBUTES];
    double money;
    struct AVLNode * treeOperations;
} User;


User * createUser(const char * firstName, const char * lastName, const char * email, const char * password);


void printUser(void* p);


// Function to compare two coampre two users by email
int compare_users_by_email(void* a, void* b);




