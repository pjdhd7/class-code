//Programmer: Peter Dolan         ID: 12410657
//Instructor: Armita     Section: C         Date: 10/14/2014
//File: lab8.h        Description: Header for Area calculator
#ifndef LAB_8
#define LAB_8
#include <iostream>
using namespace std;

struct triangle
{
  float m_base;
  float m_height;
};

struct diamond
{
  float m_base;
  float m_height;
};

struct rectangle
{
  float m_length;
  float m_width;
};

struct circle
{
  float m_radius;
};

//Description: Outputs a greeting
//Pre-conditions: None
//Post-conditions: Outputs a greeting to the screen
void greet();

//Description: Checks if the values are positive
//Pre-conditions: A numeric variable
//Post-conditions: Outputs if the variable is positive or negative
float read();

//Description: Calculates the area of a shape
//Pre-conditions: Two positive numeric values
//Post-conditions: Outputs the area of the shape

template<typename T>
float area(const T & shape)
{
  return (shape.m_base * shape.m_height * 0.5);
}

//Description: Calculates the area of a circle
//Pre-conditions: A positive numeric value
//Post-conditions: Outputs the are of a circle
float area(const circle & circ);

//Description: Calculates the area of a rectangle
//Pre-conditions: Two positive numeric values
//Post-conditions: The area of the rectangle
float area(const rectangle & rect);

//Description: Displays a goodbye message
//Pre-conditions: None
//Post-conditions: Outputs a message to the screen
void signoff();

#endif
