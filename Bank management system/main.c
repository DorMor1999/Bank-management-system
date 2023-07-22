#include "office.h"
#include "menu.h"

void main() {
    Office* office_p = create_office("Goliath National bank","United States","New york","Broadway",1);
    sign_in_or_register_or_about_menu(office_p);
}