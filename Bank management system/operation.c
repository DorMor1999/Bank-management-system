#include "operation.h"


int static id = 1; // Initialize id outside the struct


Operation* createOperation(const char* operatioType, User* userActive, User* userGet) {
    Operation* operation = malloc(sizeof(Operation));
    operation->operation_id = id++; // Increment id and assign to operation_id
    strcpy(operation->operatioType, operatioType);
    operation->userActive = userActive;
    operation->userGet = userGet;
    time_t currentTime = time(NULL); // Get the current time
    operation->date_and_time = localtime(&currentTime); // Convert to local time and assign
    return operation;
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