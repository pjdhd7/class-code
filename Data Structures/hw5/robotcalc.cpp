//Name: Peter Dolan   ID: 12410657
//Instructor: Morales    Section: A    Date: 04/16/2015
//File: RoboCalc.cpp     Desc: Robot Calculator
#include <iostream>
#include "llstack.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
  string input = "\0";
  string temp = "\0";
  bool exit = false;
  LLStack<int> the_stack;
  
  while(exit == false)
  {
    cin >> input;  //gets the input
    istringstream iss(input.c_str());   //converts it to a string stream
    
    //[rant] I use stringstreams, since they are a bit easier to manipulate
    //word by word, rather than character by character that a C-string would
    //require. I DO understand we're not seeing too many words here, but it
    //breaks the up input stream by the location of whitespace [/rant]
    while(iss >> temp && exit == false) //standard guard
    {
      if(temp == "@")  //first checks if it should exit
      {
        exit = true;
		the_stack.clear();
      }
      else if(atoi(temp.c_str()))  //checks if it is a number
      {
        the_stack.push(atoi(temp.c_str()));
      }
      else if(temp == "+")  //checks if it should add things
      {
        the_stack.add2();
      }
      else if(temp == "-")  //checks if it should subtract things
      {
        the_stack.minus();
      }
      else if(temp == "*")  //checks if it should multiply things
      {
        the_stack.times();
      }
      else if(temp == "/")  //checks if it should divide things
      {
        the_stack.divide();
      }
      else if(temp == "%")  //checks if it should find the remainder
      {
        the_stack.mod();
      }
      else if(temp == "!")  //checks if it should make a negative integer
      {
        the_stack.negate();
      }
      else if(temp == "R")  //checks if it should reverse the stack
      {
        the_stack.reverse();
      }
      else if(temp == "SUM")  //checks if it should sum the stack
      {
        the_stack.sum();
      }
      else if(temp == "#")  //checks if it should output the stack
      {
		  cout << the_stack << endl;
      }
      else if(temp == "$")  //checks if it should clear the stack
      {
        the_stack.clear();
      }
      temp = "\0";  //set temp to NULL so it can get new input
    }
  }
  return 0;
}