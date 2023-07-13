#include "user.h"


User* createUser(const char* firstName, const char* lastName, const char* email, const char* password) 
{
    User* user = (User*)malloc(sizeof(User));
    strncpy(user->firstName, firstName, LEN);
    strncpy(user->lastName, lastName, LEN);
    strncpy(user->email, email, LEN_EMAIL);
    strncpy(user->password, password, LEN);
    return user;
}


void printUser(void* p) 
{
    User* userP = (User*)p;
    printf("email: %s\n", userP->email);
}


// Function to compare two coampre two users by email
int compare_users_by_email(void* a, void* b) {
    User* user_a = (User*)a;
    User* user_b = (User*)b;
    return strcmp(user_a->email, user_b->email);
}