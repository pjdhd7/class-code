//Programmer: Peter Dolan      Student ID: 12410657
//Instructor: Armita       Section: C       Date: 10/07/2014
//File: randomizer.h         Description: Randomizer header file
#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <iostream>
using namespace std;

//Description: This function greets the user
//Pre-condition: N/A
//Post-condition: outputs a message to the screen
void greet();

//Description: Reads the numbers
//Pre-condition: N/A
//Post-condition: Alters the values of num1 and num2
void readNumbers(int & num1, int & num2);

//Description: This generates random numbers
//Pre-condition: 2 positive integers
//Post-condition: outputs five random numbers
void randomGenerator(int num1, int num2);

//Description: Outputs a farewell to the screen
//Pre-condition: N/A
//Post-condition: outputs a message to the screen
void signOff();
#endif
