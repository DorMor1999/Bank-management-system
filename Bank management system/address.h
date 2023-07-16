#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>


#define LENS_OF_ADDRESS_ATTRIBUTES 40


typedef struct {
	char country[LENS_OF_ADDRESS_ATTRIBUTES];
	char city[LENS_OF_ADDRESS_ATTRIBUTES];
	char street[LENS_OF_ADDRESS_ATTRIBUTES];
	int building_number;
}Address;


//create address and return that address pointer
Address* create_address(char * country, char * city, char * street, int building_number);