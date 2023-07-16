#include "operation.h"
#include "user.h"


int static id = 1; // Initialize id outside the struct


Operation* createOperation(const char* operatioType, User* userActive, User* userGet, double sum) {
    Operation* operation = malloc(sizeof(Operation));
    operation->operation_id = id++; // Increment id and assign to operation_id
    strcpy(operation->operatioType, operatioType);
    operation->userActive = userActive;
    operation->userGet = userGet;
    time_t currentTime = time(NULL); // Get the current time
    operation->date_and_time = localtime(&currentTime); // Convert to local time and assign
    operation->sum = sum;
    execute_operation(operation);
    return operation;
}


void execute_operation(Operation * operation_p) {
    if (strcmp(operation_p->operatioType,"send") == 0)
    {
        ((User *)(operation_p->userActive))->money -= operation_p->sum;
        ((User*)(operation_p->userGet))->money += operation_p->sum;
    }
    else if (strcmp(operation_p->operatioType, "deposit") == 0) {
        ((User*)(operation_p->userActive))->money += operation_p->sum;
    }
    //"withdraw"
    else {
        ((User*)(operation_p->userActive))->money -= operation_p->sum;
    }
}


void printOperation(void* p)
{
    Operation* operationP = (Operation*)p;
    printf("operation_id: %d\n", operationP->operation_id);
}


// Function to compare two opaeraions by id
int compare_operations_by_id(void* a, void* b) {
    Operation* operation_a_p = (Operation*)a;
    Operation* operation_b_p = (Operation*)b;
    return operation_a_p->operation_id - operation_b_p->operation_id;
}