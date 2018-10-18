//Programmer: Peter Dolan    ID: 12410657
//Instructor: Armita     Section: C      Date 11/11/2014
//File: lab12.h      Description: Time header
#ifndef LAB12_H
#define LAB12_H
#include <iostream>
using namespace std;

class Time
{
  private:
    int m_hour;
    int m_minute;
    int m_second;
  public:
    //Description: Allows a user to alter the value of the time
    //Pre-Conditions: N/A
    //Post-Conditions: Alters the values of variables in a Time class object
    void read_in();
    
    //Description: Prints the time to the screen
    //Pre-Conditions: N/A
    //Post-Conditions: Prints the time on the screen
    void print_out();
    
    //Description: Prints the next second of the assigned time
    //Pre-Conditions: N/A
    //Post-Conditions: Alters the Time class object and prints the result
    void nextSecond();
};
#endif
