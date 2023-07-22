#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "user.h"


#define OPERATION_TYPE_LEN 9


typedef struct {
    int operation_id; // Remove initialization from struct definition
    //send , deposit, withdraw
    double sum;
    char operatioType[OPERATION_TYPE_LEN];
    struct User* userActive;
    struct User* userGet;
    struct tm* date_and_time;
} Operation;


Operation* createOperation(const char* operatioType,struct User * userActive,struct User * userGet, double sum);


void printOperation(void* p, User* user_p);


// Function to compare two opaeraions by time
int compare_operations_by_time(void* a, void* b);


// Function to compare two opaeraions by time or id
int compare_operations_by_time_or_id(void* a, void* b);


// Function to compare two opaeraions by id
int compare_operations_by_id(void* a, void* b);


void execute_operation(Operation* operation_p);


