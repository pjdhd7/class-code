//Name: Peter Dolan      ID: 12410657
//Instructor: Armita      Section: C    Date: 12/09/2014
//File: lab15.cpp      Description: Determines Armstrong numbers
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  long input_int;
  long test;
  short digit_count = 0;
  short stored_values[10];
  char exit_choice = 'a';
  bool exit = false;
  
  while(exit == false)
  {
    exit_choice = 'a';
	cout << "Please type an integer: ";
    cin >> input_int;
  
    try
    {
      if(!cin.good())
	    throw input_int;
	  
      test = input_int;
	
	  while(!test)
	  {
	    stored_values[digit_count] = test % 10;
	    test /= 10;
	   digit_count++;
	  }
	
	  for(int i = digit_count; i < 0; i--)
	    test += stored_values[i];
	
	  if(test == input_int)
	    cout <<"This number is an Armstrong number"<<endl;
	  else
	    cout <<"This number is not an Armstrong number"<<endl;
	  
	  while(exit_choice != 'y' && exit_choice != 'n')
	  {
        cout << "Would you like to try a new number (y/n):  ";
	    cin >> exit_choice;
	    if(exit_choice == 'n')
	      exit = true;
	    else if(exit_choice != 'y')
	      cout <<"ERROR, invalid input"<<endl;
	  }
    }
  
    catch(long e)
    {
      cout << "ERROR, invalid input"<<endl;
	  exit = true;
    }
  }
  return 0;
}