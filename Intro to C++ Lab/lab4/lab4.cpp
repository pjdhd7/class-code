//Programmer: Peter Dolan     Student ID: 12410657
//Instructer: Armita       Section: C      Date 09/16/2014
//File: lab4.cpp         Description: Average Calculator
#include <iostream>
using namespace std;
int main ()
{
//Establishing of the variables
  short New_Input;
  short Num_Of_Input = 0;
  short Total_Input = 0;
  float Average;
  char Yes_No;

//Greetings and Initial Values  
  cout << "/-------------WELCOME-------------/" <<endl;
  cout << "Let's calculate some averages!" <<endl;
  cout << "Would you like to enter a number (y/n):  ";
  cin >> Yes_No;

//While Statement set up for calculating averages or proceeding
//to the end of the program
  while (Yes_No == 'y')
  {
    cout << "Please enter your number:   ";
    cin >> New_Input;
    if (New_Input >= 0 && New_Input <= 50 && (New_Input%3 == 0 || New_Input%5 == 0))
    {
      Num_Of_Input++;
      Total_Input = (New_Input + Total_Input);
    }
      
    cout << "Would you like to enter a new number (y/n):   ";
    cin >> Yes_No;
  }
  
//Calculating the values  
  Average = Total_Input /  static_cast<float>(Num_Of_Input);
  
//Output  
  cout << endl;
  cout << "The average of all of the valid numbers is " << Average <<endl <<endl;
  cout << "Thank you for using the Average Calculator!" <<endl;
  
  return 0;
}
