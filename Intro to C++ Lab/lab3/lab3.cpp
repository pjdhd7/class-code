//Programmer: Peter Dolan    Student ID: 12410657
//Instructor Name: Armita    Section: C         Date 09/09/2014
//File: lab2.cpp             Description: BMI calculator
#include <iostream>
using namespace std;
int main()
{
  short Wt; //Weight input
  short Ht; //Height input
  float BMI; //BMI Output
  const float CONV_FACTOR = 703; //Conversion factor
  
  cout<<"Welcome to the BMI calculator"<<endl;
  cout<<"Please enter your weight (in pounds):  ";
  cin>>Wt;
  cout<<"Please enter your height (in inches):  ";
  cin>>Ht;
  
  BMI = (Wt * CONV_FACTOR) / (Ht * Ht);
    
  cout<<"The BMI for "<<Wt<<" pounds and "<<Ht<<" inches is "<<BMI<<endl;
  return 0;
}
