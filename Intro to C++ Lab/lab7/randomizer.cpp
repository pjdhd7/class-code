//Programmer: Peter Dolan      Student ID: 12410657
//Instructor: Armita     Section: C         Date: 10/07/2014
//File randomizer.cpp          Desciption: Random number generator
#include <iostream>
using namespace std;
#include "randomizer.h"

int main()
{
  //Declaring variables
  int num1, num2;
  
  //Function calls
  greet();
  readNumbers(num1, num2);
  randomGenerator(num1, num2);
  signOff();
  
  return 0;
}
