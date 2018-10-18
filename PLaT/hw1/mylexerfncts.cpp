#include "mylexer.h"
#include <string>

//Used for finding if the input is an integer
bool is_integer(char* s) {
	int state = 1;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			if (s[i] == '+' || s[i] == '-' || isdigit(s[i]))
			{
				state = 2;
				i++;
			}
			else {
				return false;
			}
			break;
		case 2:
			if (isdigit(s[i]))
				i++;
			else
				return false;
			break;
		}
	}
	return true;

}

//Used for finding if input is a decimal
bool is_decimal(char* s) {
	int state = 1;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			if (s[i] == '+' || s[i] == '-' || isdigit(s[i]))
			{
				state = 2;
				i++;
			}
			else {
				return false;
			}
			break;
		case 2:
			if (isdigit(s[i]))
				i++;
			else if (s[i] == '.') {
				i++;
				state = 3;
			}
			else
				return false;
			break;
		case 3:
			if (isdigit(s[i])) {
				i++;
				state = 4;
			}
			else
				return false;
			break;
		case 4:
			if (isdigit(s[i])) {
				i++;
			}
			else
				return false;
			break;
		}
	}
	if (state == 4)
		return true;
	return false;
}

//Used for finding if input is a Scientific number
bool is_scientific(char* s){
	int state = 1;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			if (s[i] == '+' || s[i] == '-' || isdigit(s[i]))
			{
				state = 2;
				i++;
			}
			else {
				return false;
			}
			break;
		case 2:
			if (isdigit(s[i]))
				i++;
			else if (s[i] == '.') {
				i++;
				state = 3;
			}
			else
				return false;
			break;
		case 3:
			if (isdigit(s[i]))
				i++;
			else if (s[i] == 'E')
			{
				i++;
				state = 4;
			}
			else
				return false;
			break;
		case 4:
			if (s[i] == '+' || s[i] == '-') {
				i++;
				state = 5;
			}
			else if (isdigit(s[i]) && s[i] != '0')
			{
				i++;
				state = 6;
			}
			else {
				return false;
			}
			break;
		case 5:
			if (isdigit(s[i]) && s[i] != '0')
			{
				i++;
				state = 6;
			}
			else {
				return false;
			}
			break;
		case 6:
			if (isdigit(s[i]))
				i++;
			else
				return false;
			break;
		}
	}
	if(state == 6)
		return true;
	return false;
}

//Used for finding if input is a Hex value
bool is_hex(char* s) {
	int state = 1;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			//Checks for a digit
			if (isdigit(s[i]))
			{
				i++;
				state = 2;
			}
			//Checks for letters A-F in ASCII values
			else if (65 <= s[i] && s[i] <= 70) {
				i++;
				state = 2;
			}
			else
				return false;
			break;
		case 2:
			//Checks for a digit
			if (isdigit(s[i]))
			{
				i++;
			}
			//Checks for letters A-F in ASCII values
			else if (65 <= s[i] && s[i] <= 70) {
				i++;
			}
			//Checks for termination
			else if (s[i] == 'H')
			{
				i++;
				state = 3;
			}
			else
				return false;
			break;
		case 3:
			return false;
			break;
		}

	}
	if(state == 3)
		return true;
	return false;
}

//Used for finding if input is a keyword
bool is_keyword(char* s) {
	string cmp_if = "if";
	string cmp_while = "while";
	string cmp_else = "else";
	string cmp_print = "print";

		if (cmp_if == s) {
			return true;
		}
		else if (cmp_while == s) {
			return true;
		}
		else if (cmp_else == s) {
			return true;
		}
		else if (cmp_print == s) {
			return true;
		}
	return false;
}

//TODO: This function
//Used for find if input is an identifier
bool is_identifier(char*s) {
	int state = 1;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			if ((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) {
				state = 2;
				i++;
			}
			else
				return false;
			break;
		case 2:
			if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_')
				i++;
			else 
				return false;
		}
	}
	return true;
}

//TODO: This function
//Used for find if input is an email address
bool is_email(char*s) {
	int state = 1;
	int suffix = 0;
	int i = 0;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
		case 1:
			if ((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) {
				state = 2;
				i++;
			}
			else
				return false;
			break;
		case 2:
			if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_')
				i++;
			else if (s[i] == '.') {
				i++;
				state = 1;
			}
			else if (s[i] == '@') {
				i++;
				state = 3;
			}
			else
				return false;
			break;
		case 3:
			if ((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) {
				state = 4;
				i++;
			}
			break;
		case 4:
			if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_')
				i++;
			else if (s[i] == '.') {
				i++;
				state = 5;
			}
			else
				return false;
			break;
		case 5:
			if (s[i] == 'c') {
				i++;
				state = 6;
				suffix = 1;
			}
			else if (s[i] == 'n') {
				i++;
				state = 6;
				suffix = 2;
			}
			else if (s[i] == 'e') {
				i++;
				state = 6;
				suffix = 3;
			}
			else if ((97 <= s[i] && s[i] <= 122) || (65 <= s[i] && s[i] <= 90)) {
				i++;
				state = 4;
			}
			else
				return false;
		case 6:
			if (s[i] == 'o') {
				i++;
				state = 7;
			}
			else if (s[i] == 'e') {
				i++;
				state = 7;
			}
			else if (s[i] == 'd') {
				i++;
				state = 7;
			}
			else if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_') {
				i++;
				state = 4;
			}
			else
				return false;
		case 7:
			if (s[i] == 'm') {
				i++;
				state = 8;
			}
			else if (s[i] == 't') {
				i++;
				state = 8;
			}
			else if (s[i] == 'u') {
				i++;
				state = 8;
			}
			else if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_') {
				i++;
				state = 4;
			}
			else
				return false;
			break;
		case 8:
			if ((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90)
				|| (97 <= s[i] && s[i] <= 122) || s[i] == '_') {
				i++;
				state = 4;
			}
			else
				return false;
			break;
		}
	}
	if (state == 8) {
		return true;
	}
	return false;
}