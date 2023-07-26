#include "menu.h"


//choose register or sign in or about
void sign_in_or_register_or_about_menu(Office* office_p) {
	int option = 0;
	while (option == 0)
	{
		printf("\n-----------\nWelcome to the %s system\nMenu:\n", office_p->bank_name);
		printf("1. Sign in\n");
		printf("2. Register\n");
		printf("3. About\n");
		printf("4. Exit\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		printf("-----------\n");
		switch (option) {
		case 1:
			sign_in_menu(office_p);
			break;

		case 2:
			register_menu(office_p);
			break;

		case 3:
			about_menu(office_p);
			option = 0;
			break;

		case 4:
			printf("\nGoodbye\n");
			return;
			break;

		default:
			option = 0;
		}
	}
}


void sign_in_menu(Office* office_p) {
	int option = 0;
	char email_p[LEN_EMAIL];
	char password_p[LEN_OTHERS_ATTRIBUTES];
	while (option == 0)
	{
		printf("\n-----------\nSign in\n1. Sign in\n2. Back to menu\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			printf("Sign in:\n");
			email_and_password_form(email_p, password_p);
			office_p->connected_user_p = sign_in(office_p, email_p, password_p);
			//get in
			if (office_p->connected_user_p != NULL)
			{
				printf("Correct email and password!\n-----------\n");
				user_menu(office_p);
				return;
			}
			//wrong password or email
			else
			{
				printf("Wrong password or email!\n");
				option = 0;
			}
			break;

		case 2:
			printf("-----------\n");
			sign_in_or_register_or_about_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		printf("-----------\n");
	}
}


void register_menu(Office* office_p) {
	int option = 0;

	char email_p[LEN_EMAIL];
	char password_p[LEN_OTHERS_ATTRIBUTES];
	char firstName_p[LEN_OTHERS_ATTRIBUTES];
	char lastName_p[LEN_OTHERS_ATTRIBUTES];
	while (option == 0)
	{
		printf("\n-----------\nRegister\n1. Register\n2. Back to menu\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			printf("Register:\n");
			firstName_and_lastName_form(firstName_p, lastName_p);
			email_and_password_form(email_p, password_p);
			int check_registration = registration(office_p, firstName_p, lastName_p, email_p, password_p);
			//register sucsess
			if (check_registration == 1)
			{
				printf("Register sucsess!\n-----------\n");
				sign_in_or_register_or_about_menu(office_p);
				return;
			}
			//regigster not sucsess
			else
			{
				printf("We have user with that email!\n");
				option = 0;
			}
			break;

		case 2:
			printf("-----------\n");
			sign_in_or_register_or_about_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		printf("-----------\n");
	}
}


void about_menu(Office* office_p) {
	printf("\n-----------\nAbout\n");
	print_office_data(office_p);
	printf("\n-----------\n");
}


void email_and_password_form(char * email_p,char * password_p) {
	printf("Please enter your email:");
	gets_s(email_p, LEN_EMAIL);
	printf("Please enter your password:");
	gets_s(password_p, LEN_OTHERS_ATTRIBUTES);
}


void firstName_and_lastName_form(char * firstName_p, char* lastName_p) {
	printf("Please enter your first name:");
	gets_s(firstName_p, LEN_OTHERS_ATTRIBUTES);
	printf("Please enter your last name:");
	gets_s(lastName_p, LEN_OTHERS_ATTRIBUTES);
}


void user_menu(Office* office_p) {
	int option = 0;
	while (option == 0) {
		printf("\n-----------\nHey %s %s\nMoney: %.2f$\nUser menu:\n", office_p->connected_user_p->firstName, office_p->connected_user_p->lastName, office_p->connected_user_p->money);
		printf("1. User data\n");
		printf("2. Deposit money in your account\n");
		printf("3. Withdraw money from your account\n");
		printf("4. Send money from you to another user account\n");
		printf("5. Get all operations\n");
		printf("6. Get spesific operation\n");
		printf("7. Exit\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		printf("-----------\n");
		switch (option) {
		case 1:
			printf("\n-----------\nUser data\n");
			printUser(office_p->connected_user_p);
			printf("\n-----------\n");
			option = 0;
			break;
		case 2:
			deposit_or_withdraw_or_send(office_p, "Deposit");
			option = 0;
			break;
		case 3:
			deposit_or_withdraw_or_send(office_p, "Withdraw");
			option = 0;
			break;
		case 4:
			deposit_or_withdraw_or_send(office_p, "Send");
			option = 0;
			break;
		case 5:
			printf("\n-----------\nUser opearations");
			if (((User*)office_p->tree_p_users->data)->treeOperations == NULL)
			{
				printf("0 operations!");
			}
			else
			{
				inorderTraversal(((User*)office_p->tree_p_users->data)->treeOperations, printOperation);
			}
			printf("\n-----------\n");
			option = 0;
			break;
		case 6:
			get_spesific_operation(office_p);
			option = 0;
			break;
		case 7:
			office_p->connected_user_p = NULL;
			sign_in_or_register_or_about_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		
	}
}


void deposit_or_withdraw_or_send(Office* office_p, char * opearation_type) {
	int option = 0;
	int sum;
	User* other_user_p = NULL;
	while (option == 0) {
		printf("\n-----------\n%s\n1. %s\n2. Back to user menu\n", opearation_type, opearation_type);
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			if (strcmp(opearation_type, "Send") == 0) {
				other_user_p = email_form_and_get_user(office_p);
			}
			sum = sum_form();
			add_operation_tree_and_hush(office_p,opearation_type, other_user_p, sum);
			printf("%s sucsess!\n-----------\n", opearation_type);
			return;
			break;

		case 2:
			printf("-----------\n");
			user_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		printf("-----------\n");
	}
}


User * email_form_and_get_user(Office* office_p) {
	User * user_p = NULL;
	char email[LEN_EMAIL];
	do
	{
		printf("Please enter the email of the user:");
		gets_s(email, LEN_EMAIL);
		user_p = get_user_p_by_email(office_p, email);
	} while (user_p == NULL || compare_users_by_email(office_p->connected_user_p, user_p) == 0);
	return user_p;
}


int sum_form() {
	double value = -1;
	do
	{
		printf("Please enter sum of money:");
		scanf_s("%lf", &value);
	} while (value <= 0);
	cleanBuffer();
	return value;
}


void get_spesific_operation(Office* office_p) {
	int option = 0;
	int id;
	while (option == 0) {
		printf("\n-----------\nGet spesific operation\n1. Get spesific operation\n2. Back to user menu\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			id = id_form(office_p);
			Operation* operation_p = get_operation_from_hush(office_p, id);
			if (operation_p == NULL)
			{
				printf("You don't have access to this operation!");
			}
			else
			{
				printOperation(operation_p);
			}
			printf("\n-----------\n");
			return;
			break;

		case 2:
			printf("-----------\n");
			user_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		printf("-----------\n");
	}
}


int id_form(Office* office_p) {
	int value = -1;
	do
	{
		printf("Please enter id of operation:");
		scanf_s("%d", &value);
	} while (value <= 0 || value > office_p->table_p_opeartions->size);
	cleanBuffer();
	return value;
}


void cleanBuffer()
{
	char c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}