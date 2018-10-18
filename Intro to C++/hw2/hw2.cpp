//Programmer: Peter Dolan   Student ID: 12410657
//Instructor Name: Clayton Price   Section: A   Date: 09/02/2014
//File: hw2.cpp   Description: Dr. Eloe's Formula
#include <iostream>
using namespace std;
int main()
{
  float Dose; // Dosage output in formula
  float Age; // Age input in formula
  short IQ; // IQ input in formula
  short Freq; // Pills per day input in formula
  bool Gen; // Gender input in formula, 1 for male, 0 for female
  float Wt; // Weight input, in kg, in formula
  const short DEC = 20; // Dr. Eloe's Constant input in formula
  const float TS = 250; // Tablet Strength constant input in formula
   
   //Input of the variables
  cout<<"Hello, Dr. Eloe! Let's calculate some dosages!" <<endl;
  cout<<"Please type the patient's age: ";
  cin>>Age;
  cout<<"Please type the patient's IQ: ";
  cin>>IQ;
  cout<<"Please type how many pills the patient takes per day: ";
  cin>>Freq;
  cout<<"What is the patient's gender? (Man -> 1, Woman -> 0): ";
  cin>>Gen;
  cout<<"Please enter the patient's weight in kilograms: ";
  cin>>Wt;
  cout<<endl<<endl;
  
  //Calculate Money brought in-er, Dosage for...patient
  Dose = static_cast<short>((Age/IQ) * ((Wt/Freq) + 1) * ((TS/1000) + Gen) + DEC + 0.5);

    
  //Display output
  cout<<"Dr. Eloe"<<endl;
  cout<<"For the values input:"<<endl;
  cout<<"   Age is "<<Age<<endl;
  cout<<"   Weight is "<<Wt<<endl;
  cout<<"   IQ is "<<IQ<<endl;
  if (Gen == 1)
   cout<<"   Gender is Male"<<endl;
  else
   cout<<"   Gender is Female"<<endl;
  cout<<"   Frequency is "<<Freq<<endl;
  cout<<"   Tablet Strength of 250 mg"<<endl;
  cout<<"The recommend dosage is "<<Dose<<" tablets"<<endl;
  
  return 0;
}  
