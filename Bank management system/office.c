#include "office.h"


// create office and return pointer to it
Office* create_office(char * bank_name, char* country, char* city, char* street, int building_number) {
	Office* office_p = (Office*)calloc(1, sizeof(Office));
	strncpy(office_p->bank_name, bank_name, LEN_BANK_NAME);
	office_p->address_p = create_address( country, city, street, building_number);
	return office_p;
}


User* get_user_p_by_email(Office* office_p, const char* email) {
	User* user_to_find = createUser("", "", email, "");
	AVLNode * node = search(office_p->tree_p_users, user_to_find, compare_users_by_email);
	if (node != NULL)
	{
		User* return_user_p = node->data;
		free(user_to_find);
		return return_user_p;
	}
	return NULL;
}


User * sign_in(Office* office_p,const char* email, const char* password) {
	User* check_exist_user_p = get_user_p_by_email(office_p, email);
	//find user with that email
	if (check_exist_user_p != NULL)
	{
		//passwords are equals
		if (strcmp(check_exist_user_p->password, password) == 0)
		{
			office_p->connected_user_p = check_exist_user_p;
			return check_exist_user_p;
		}
	}
	return NULL;
}


int registration(Office* office_p,const char * firstName, const char * lastName ,  const char* email, const char* password) {
	User* check_exist_user_p = get_user_p_by_email(office_p, email);
	//donsnt find user with that email
	if (check_exist_user_p == NULL)
	{
		User * new_user_p = createUser(firstName, lastName, email, password);
		office_p->tree_p_users = insert(office_p->tree_p_users, new_user_p, compare_users_by_email);
		return 1;
	}
	return 0;
}


void print_office_data(Office* office_p) {
	printf("%s\nCountry: %s\nCity: %s\nStreet: %s\nBuilding number: %d",office_p->bank_name, office_p->address_p->country, office_p->address_p->city, office_p->address_p->street, office_p->address_p->building_number);
}


void add_operaion_to_hush_table(Office* office_p, Operation* operation_p) {
	office_p->table_p_opeartions = add_operation_to_arrey(office_p->table_p_opeartions, operation_p);
}