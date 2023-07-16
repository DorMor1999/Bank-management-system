#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include "operation.h"


typedef struct {
    int size;
    Operation** arrey_pointers;
} Hash_table;


//add opearion to arrey of pointers
Hash_table* add_operation_to_arrey(Hash_table* hash_table_p, Operation* operation_p);


// return the right index of elemnt in arrey
int hash_function(int size, int id);


//find operation arrey
Operation* find_operation_in_arrey_by_id(Hash_table* hash_table_p, int id);