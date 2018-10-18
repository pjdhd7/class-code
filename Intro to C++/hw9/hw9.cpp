//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: hw9.cpp    Description: driver for hw9 classes
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "x_rayer.h"
#include "patient_class.h"
#include "hospital_room.h"
using namespace std;

int main()
{
  srand(time(NULL));
  hospital_room room1;
  patient pat1, pat2, pat3;
  
  cout<<"/~*~Before the testing~*~/"<<endl<<endl
      <<"Hospital room"<<endl<<room1<<endl
      <<"Patient 1"<<endl<<pat1<<endl
      <<"Patient 2"<<endl<<pat2<<endl
      <<"Patient 3"<<endl<<pat3<<endl;
  
  for(int i = 1; i <= 5; i++)
    room1.admit(pat1);
  
  cout<<"/*~*After the testing*~*/"<<endl<<endl
      <<"Hospital room"<<endl<<room1<<endl
      <<"Patient 1"<<endl<<pat1<<endl
      <<"Patient 2"<<endl<<pat2<<endl
      <<"Patient 3"<<endl<<pat3<<endl;
  
  return 0;
}