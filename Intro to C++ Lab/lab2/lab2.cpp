// Programmer: Peter Dolan 12410657 
// Instructor: Armita   Section: C  09/02/2014
// lab2.cpp  Description: Multiplication tool

//including the I/O stream library
#include <iostream>
using namespace std;

int main()
{
int multiplicand; // a within formula c = a * b
  int multiplier;  // b within formula c = a * b
  int product; // c within formula c = a * b
  
  // welcome message
  cout << "Welcome, Let's Do some Multiplication!" << endl;
  
  // read multiplicand from keyboard
  cout << "Enter the multiplicand: ";
  cin >> multiplicand;
  
  // read multiplier from keyboard
  cout << "Enter the multiplier: ";
  cin >> multiplier;
  
  // perform multiplication as * operator
  product = multiplicand * multiplier;
  
  // display the result
cout << multiplicand << " * " << multiplier << " = " << product << endl;
  
  return 0; 
}
