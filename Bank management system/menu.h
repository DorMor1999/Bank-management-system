#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "office.h"


//choose register or sign in or about
void sign_in_or_register_or_about_menu(Office* office_p);


void sign_in_menu(Office* office_p);


void register_menu(Office* office_p);


void about_menu(Office* office_p);


void email_and_password_form(char* email_p, char* password_p);


void firstName_and_lastName_form(char* firstName_p, char* lastName_p);


void deposit_or_withdraw_or_send(Office* office_p, char* opearation_type);


void get_spesific_operation(Office* office_p);


int id_form(Office* office_p);


User* email_form_and_get_user(Office* office_p);


int sum_form();


void user_menu(Office* office_p);


void cleanBuffer();