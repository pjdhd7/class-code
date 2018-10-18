//Programmer: Peter Dolan    ID: 12410657
//Instructor: Armita     Section: C     Date: 11/11/2014
//File: lab12.cpp      Description: Time main function
#include "lab12.h"
#include <iostream>


int main ()
{
  Time setTime;
  setTime.read_in();
  setTime.print_out();
  setTime.nextSecond();
  return 0;
}
