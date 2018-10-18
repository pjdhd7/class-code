//Programmer: Peter Dolan      Date: 10/11/2014
//Instructor: Price       Section: A        Date: 10/11/2014
//File: hw6.cpp       Description: Main function
#include <iostream>
#include <string>
#include <ctime>
#include "hw6.h"
using namespace std;

int main()
{
  srand(time(NULL));
  proteins levels;
  string name;
  bool quit = false;
  
  cout <<"~*~WELCOME~*~"<<endl;
  cout <<"So, the patient might have Jejunal Hemorrhage Syndrome?"<<endl;
  do
  {
    getName(name);
    reset(levels);
    tone1(levels);
    tone2(levels);
    tone3(levels);
    prognosis(levels, name);
    WantToQuit(quit);
    reset(levels);
  }while(!quit);
  
  cout <<"Goodbye, Dr. Eloe!"<<endl;
  return 0;
}
