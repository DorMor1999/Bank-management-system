#include "user.h"


User* createUser(const char* firstName, const char* lastName, const char* email, const char* password) 
{
    User* user = (User*)calloc(1, sizeof(User));
    strncpy(user->firstName, firstName, LEN_OTHERS_ATTRIBUTES);
    strncpy(user->lastName, lastName, LEN_OTHERS_ATTRIBUTES);
    strncpy(user->email, email, LEN_EMAIL);
    strncpy(user->password, password, LEN_OTHERS_ATTRIBUTES);
    user->money = 0;
    return user;
}


void printUser(void* p) 
{
    User* userP = (User*)p;
    printf("First name: %s\n", userP->firstName);
    printf("Last name: %s\n", userP->lastName);
    printf("Email: %s\n", userP->email);
    printf("Password: %s\n", userP->password);
    printf("Money: %.2f$", userP->money);
}


// Function to compare two coampre two users by email
int compare_users_by_email(void* a, void* b) {
    User* user_a = (User*)a;
    User* user_b = (User*)b;
    return strcmp(user_a->email, user_b->email);
}


