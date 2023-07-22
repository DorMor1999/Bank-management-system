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


struct Operation* add_operaion(const char* operatioType, User* userActive, User* userGet, double sum) {
    Operation* operation_p = createOperation(operatioType, userActive, userGet, sum);
    userActive->treeOperations = insert(userActive->treeOperations, operation_p, compare_operations_by_time_or_id);
    if (userGet != NULL)
    {
        userGet->treeOperations = insert(userGet->treeOperations, operation_p, compare_operations_by_time_or_id);
    }
    return operation_p;
}


