#include "address.h"


//create address and return that address
Address* create_address(char* country, char* city, char* street, int building_number) {
	Address* address_p = (Address*)malloc(sizeof(Address));
	strncpy(address_p->country, country, LENS_OF_ADDRESS_ATTRIBUTES);
	strncpy(address_p->city, city, LENS_OF_ADDRESS_ATTRIBUTES);
	strncpy(address_p->street, street, LENS_OF_ADDRESS_ATTRIBUTES);
	address_p->building_number = building_number;
	return address_p;
}