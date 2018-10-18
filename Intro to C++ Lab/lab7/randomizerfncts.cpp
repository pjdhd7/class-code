//Programmer: Peter Dolan      Student ID: 12410657
//Instructor: Armita     Section: C         Date: 10/07/2014
//File randomizerfncts.cpp       Desciption: Random number functions
#include "randomizer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void greet()
{
  cout <<"/----------WELCOME----------/"<<endl;
  cout <<"TO THE RANDOM NUMBER GENERATOR"<<endl;
  return;
}

void readNumbers(int & num1, int & num2)
{
  do
  {
    cout <<"Enter the lower limit[>0]:  ";
    cin >> num1;
    if(num1 <= 0)
      cout <<"That's not valid, please try again"<<endl;
  }while(num1 <= 0);
  
  do
  {
    cout<<"The Upper Limit must be two times greater than the lower limit"
        <<endl;
    cout<<"Please enter the Upper Limit [>"<<(num1 * 2 - 1)<<"]:  ";
    cin >> num2;
    if(num2 < (num1 * 2))
      cout <<"That's not valid, please try again"<<endl;
  }while(num2 < (num1 * 2));
  
  return;
}

void randomGenerator(int num1, int num2)
{
  for(int i = 1; i <= 5; i++)
  {  
    cout <<i<<". Random Number between "<<num1<<" and "<<num2<<", inclusively,";
    cout <<" is: " << num1 + rand() % (num2 + 1 - num1) <<endl;
  }
  return;
}  

void signOff()
{
  cout <<"Thank you for using the random number generator"<<endl;
  cout <<"Goodbye!" <<endl<<endl;
  return;
}
