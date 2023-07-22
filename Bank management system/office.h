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
	User* connected_user_p;
} Office;


Office* create_office(char* bank_name, char* country, char* city, char* street, int building_number);


User* sign_in(Office* office_p, const char* email, const char* password);


User* get_user_p_by_email(Office* office_p, const char* email);


int registration(Office* office_p, const char* firstName, const char* lastName, const char* email, const char* password);


void print_office_data(Office* office_p);