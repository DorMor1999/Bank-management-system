#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "AVL_TREE.h"
#include "Hash_table.h"
#include "address.h"


#define LEN_BANK_NAME 40


typedef struct {
	char bank_name[LEN_BANK_NAME];
	Address* address_p;
	AVLNode* tree_p_users;
	Hash_table* table_p_opeartions;
} Office;


Office* create_office(char* bank_name, char* country, char* city, char* street, int building_number);