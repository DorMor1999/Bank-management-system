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
		printf("5. Exit\n");
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			printf("\n-----------\nUser data\n");
			printUser(office_p->connected_user_p);
			printf("\n-----------\n");
			option = 0;
			break;
		case 2:
			deposit_or_withdraw(office_p, "Deposit");
			option = 0;
			break;
		case 3:
			deposit_or_withdraw(office_p, "Withdraw");
			option = 0;
			break;
		case 5:
			printf("-----------\n");
			office_p->connected_user_p = NULL;
			sign_in_or_register_or_about_menu(office_p);
			return;
			break;

		default:
			option = 0;
		}
		printf("-----------\n");
	}
}


void deposit_or_withdraw(Office* office_p, char * opearation_type) {
	int option = 0;
	int sum;
	Operation* operation_p = NULL;
	while (option == 0) {
		printf("\n-----------\n%s\n1. %s\n2. Back to user menu\n", opearation_type, opearation_type);
		printf("Please choose an option:");
		scanf_s("%d", &option);
		cleanBuffer();
		switch (option) {
		case 1:
			sum = sum_form();
			operation_p = add_operaion(opearation_type, office_p->connected_user_p, NULL, sum);
			add_operaion_to_hush_table(office_p, operation_p);
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



void cleanBuffer()
{
	char c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}