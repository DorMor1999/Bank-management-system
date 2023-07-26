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
    if (strcmp(operation_p->operatioType,"Send") == 0)
    {
        ((User *)(operation_p->userActive))->money -= operation_p->sum;
        ((User*)(operation_p->userGet))->money += operation_p->sum;
    }
    else if (strcmp(operation_p->operatioType, "Deposit") == 0) {
        ((User*)(operation_p->userActive))->money += operation_p->sum;
    }
    //"Withdraw"
    else {
        ((User*)(operation_p->userActive))->money -= operation_p->sum;
    }
}


void printOperation(void* p)
{
    printf("\n\nOperation data\n");
    Operation* operationP = (Operation*)p;
    if (strcmp(operationP->operatioType, "Deposit") == 0 || strcmp(operationP->operatioType, "Withdraw") == 0)
    {
        printf("Operation id: %d\nType: %s\nSum: %.2f$\nDate: %d/%d/%d\nTime: %d:%d", operationP->operation_id, operationP->operatioType, operationP->sum, operationP->date_and_time->tm_wday, operationP->date_and_time->tm_mon, operationP->date_and_time->tm_year, operationP->date_and_time->tm_hour, operationP->date_and_time->tm_min);
    }
    //the type is send
    else
    {
        printf("Operation id: %d\nType: %s %s send money to %s %s\nSum: %.2f$\nDate: %d/%d/%d\nTime: %d:%d", operationP->operation_id, ((User*)(operationP->userActive))->firstName, ((User*)(operationP->userActive))->lastName, ((User*)(operationP->userGet))->firstName, ((User*)(operationP->userGet))->lastName, operationP->sum, operationP->date_and_time->tm_wday, operationP->date_and_time->tm_mon, operationP->date_and_time->tm_year, operationP->date_and_time->tm_hour, operationP->date_and_time->tm_min);
    }
}


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

    return 0;
}



// Function to compare two opaeraions by time or id
int compare_operations_by_time_or_id(void* a, void* b) {
    int res = compare_operations_by_time(a, b);
    if (res == 0)
    {
        //if everting the same we compare them by id
        return compare_operations_by_id(a, b);
    }
    return res;
}


// Function to compare two opaeraions by id
int compare_operations_by_id(void* a, void* b) {
    //if everting the same we compare them by id
    Operation* operation_a_p = (Operation*)a;
    Operation* operation_b_p = (Operation*)b;
    return operation_a_p->operation_id - operation_b_p->operation_id;
}