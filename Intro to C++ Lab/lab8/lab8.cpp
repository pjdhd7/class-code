//Programmer: Peter Dolan         ID: 12410657
//Instructor: Armita     Section: C         Date: 10/14/2014
//File: lab8.cpp        Description: Area calculator
#include "lab8.h"
#include <iostream>
using namespace std;

int main()
{
  triangle tri;
  rectangle rect;
  diamond di;
  circle circ;
  
  greet();
  cout <<"Enter the Base of a Triangle: ";
  tri.m_base = read();
  cout <<"Enter the Height of a Triangle: ";
  tri.m_height = read();
  cout <<endl<<"Enter the Base of a Diamond: ";
  di.m_base = read();
  cout <<"Enter the Height of a Diamond: ";
  di.m_height = read();
  cout <<endl<<"Enter the Height of a Rectangle: ";
  rect.m_length = read();
  cout <<"Enter the Width of a Rectangle: ";
  rect.m_width = read();
  cout <<endl<<"Enter the Radius of a Circle: ";
  circ.m_radius = read();
  cout <<endl<<"Area of Triangle is: "<<area(tri)<<endl;
  cout <<"Area of Diamond is: "<<area(di)<<endl;
  cout <<"Area of Rectangle is: "<<area(rect)<<endl;
  cout <<"Area of Circle is: "<<area(circ)<<endl;  
  signoff();
  return 0;
}
  
