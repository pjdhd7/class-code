#ifndef MYLEXER_H
#define MYLEXER_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

//Used for finding if the input is an integer
bool is_integer(char* s);

//Used for finding if input is a decimal
bool is_decimal(char* s);

//Used for finding if input is a Scientific number
bool is_scientific(char* s);

//Used for finding if input is a Hex value
bool is_hex(char* s);

//Used for finding if input is a keyword
bool is_keyword(char* s);

//Used for find if input is an identifier
bool is_identifier(char* s);

//Used for find if input is an email address
bool is_email(char* s);

#endif