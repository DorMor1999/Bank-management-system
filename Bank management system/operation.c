#include "operation.h"
#include "user.h"


int static id = 1; // Initialize id outside the struct


Operation* createOperation(const char* operatioType, User* userActive, User* userGet, double sum) {
    Operation* operation = calloc(1, sizeof(Operation));
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


// Function to compare two opaeraions by time
int compare_operations_by_time(void* a, void* b) {
    struct tm* date_and_time1 = ((Operation*)a)->date_and_time;
    struct tm* date_and_time2 = ((Operation*)b)->date_and_time;

    // Compare the years
    if (date_and_time1->tm_year > date_and_time2->tm_year)
        return 1;
    else if (date_and_time1->tm_year < date_and_time2->tm_year)
        return -1;

    // Compare the months
    if (date_and_time1->tm_mon > date_and_time2->tm_mon)
        return 1;
    else if (date_and_time1->tm_mon < date_and_time2->tm_mon)
        return -1;

    // Compare the days
    if (date_and_time1->tm_mday > date_and_time2->tm_mday)
        return 1;
    else if (date_and_time1->tm_mday < date_and_time2->tm_mday)
        return -1;

    // Compare the hours
    if (date_and_time1->tm_hour > date_and_time2->tm_hour)
        return 1;
    else if (date_and_time1->tm_hour < date_and_time2->tm_hour)
        return -1;

    // Compare the minutes
    if (date_and_time1->tm_min > date_and_time2->tm_min)
        return 1;
    else if (date_and_time1->tm_min < date_and_time2->tm_min)
        return -1;

    // Compare the seconds
    if (date_and_time1->tm_sec > date_and_time2->tm_sec)
        return 1;
    else if (date_and_time1->tm_sec < date_and_time2->tm_sec)
        return -1;

    //if everting the same we compare them by id
    return compare_operations_by_id(a, b);

}


// Function to compare two opaeraions by id
int compare_operations_by_id(void* a, void* b) {
    //if everting the same we compare them by id
    Operation* operation_a_p = (Operation*)a;
    Operation* operation_b_p = (Operation*)b;
    return operation_a_p->operation_id - operation_b_p->operation_id;
}