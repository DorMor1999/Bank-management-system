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
		createUser(firstName, lastName, email, password);
		return 1;
	}
	return 0;
}