#include "office.h"


// create office and return pointer to it
Office* create_office(char * bank_name, char* country, char* city, char* street, int building_number) {
	Office* office_p = (Office*)calloc(1, sizeof(Office));
	strncpy(office_p->bank_name, bank_name, LEN_BANK_NAME);
	office_p->address_p = create_address( country, city, street, building_number);
	return office_p;
}