//Programmer: Peter Dolan         ID: 12410657
//Instructor: Armita     Section: C         Date: 10/14/2014
//File: lab8fncts.cpp        Description: functions for Area calculator
#include <iostream>
#include "lab8.h"
using namespace std;

void greet()
{
  cout <<"~*~Welcome to the Area Calculator~*~"<<endl;
  return;
}

float read()
{
  float input;
  cin >> input;
  return input;
}

float area(const circle & circ)
{
  const float PI = 3.14159;
  return (PI * circ.m_radius * circ.m_radius);
}

float area(const rectangle & rect)
{
  return(rect.m_length * rect.m_width);
}

void signoff()
{
  cout <<"Have a Good Day!"<<endl;
  return;
}
