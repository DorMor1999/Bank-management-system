#include "Hash_table.h"


//add opearion to arrey of pointers
Hash_table* add_operation_to_arrey(Hash_table* hash_table_p,Operation* operation_p) {
	if (hash_table_p == NULL)
		hash_table_p = (Hash_table*)calloc(1, sizeof(Hash_table));
	hash_table_p->size++;
	hash_table_p->arrey_pointers = (Hash_table**)realloc(hash_table_p->arrey_pointers, hash_table_p->size * sizeof(Operation*));
	hash_table_p->arrey_pointers[hash_table_p->size - 1] = operation_p;
	return hash_table_p;
}


// return the right index of elemnt in arrey
int hash_function(int id) {
	return id - 1;
}


//find operation arrey
Operation* find_operation_in_arrey_by_id(Hash_table* hash_table_p, int id) {
	int index = hash_function(hash_table_p->size, id);
	return hash_table_p->arrey_pointers[index];
}