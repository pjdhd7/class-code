#ifndef MYLEXER_H
#define MYLEXER_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

//Used for finding if the input is an integer
bool is_integer(const char* s);

//Used for finding if input is a decimal
bool is_decimal(const char* s);

//Used for finding if input is a keyword
bool is_keyword(const char* s);

//Used for finding if input is an identifier
bool is_identifier(const char* s);

//Used for finding if an input is a string literal
bool is_string(const char* s);

#endif