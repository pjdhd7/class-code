#include "mylexer.h"
#include <string>

//Used for finding if the input is an integer
bool is_integer(const char* s) {
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
bool is_decimal(const char* s) {
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

//Used for finding if input is a keyword
bool is_keyword(const char* s) {
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
bool is_identifier(const char* s) {
	int state = 1;
	int i = 0;
	int max = strlen(s);
	if (s == "OR" || s == "AND" || s == "PRINT" || s == "IF" || s == "ELSE"
		|| s == "FI" || s == "LOOP" || s == "POOL" ||s == "FUNC" || s == "RET"
		|| s == "BEGIN" || s == "END.")
		return false;

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

//Used for finding if an input is a string literal
bool is_string(const char* s) {
	int i = 0;
	int state = 1;
	int max = strlen(s);

	while (i < max) {
		switch (state) {
			case 1:
				if (s[i] == '\"')
					state = 2;
				else
					return false;
				break;
			case 2:
				if (s[i] == '\"')
					state = 3;
				else if (s[i] == ' ')
					return false;
				break;
			case 3:
				return false;
		}
		i++;
	}
	if (state == 3)
		return true;
	return false;
}