//Programmer: Peter Dolan      Date: 10/11/2014
//Instructor: Price       Section: A        Date: 10/11/2014
//File: hw6fncts.cpp       Description: Functions for the main program
#include <iostream>
#include <string>
#include <ctime>
#include "hw6.h"
using namespace std;
void getName(string & name)
{
  cout <<"Please type the patient's name:  ";
  cin >> name;
  return;
}

//Do-while loops have been inserted around all rand functions due to continuous
//issues with the values exceeding the limitss that it should be limited by. I
//have been unable to procure a solution outside of this "nuclear option."
void tone1(proteins & levels)
{
  short chance;
  do
  {
    chance = ((11 * rand() + 42) % CHANCE);
  }while(chance < 0 || chance > 100);
  if (chance <= 5)
    cout <<"Uh-oh! The cockroach didn't hear the first tone!"<<endl;
  while (chance > 5)
  {
    do
    {
      levels.m_p1 = ((33 * rand() + 92) % P1_RANGE);
    }while(levels.m_p1 < 0 || levels.m_p1 > 100);
    if (levels.m_p1 < 10)
      levels.m_p1 = 0;
    do
    {
      levels.m_p2 = (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 
                     P2_RANGE)));
    }while(levels.m_p2 < 0 || levels.m_p2 > 100);
    do
    {
      levels.m_p3 = ((18 * rand() + 51) % P3_RANGE);
    }while(levels.m_p3 < 0 || levels.m_p3 > 10);
    chance = 0;
  }
  return;
}

void tone2(proteins & levels)
{
  short chance;
  float test2;
  do
  {
    chance = ((34 * rand() + 55) % CHANCE);
  }while(chance < 0 || chance > 100);
  if (chance <= 5)
    cout <<"Oh dear! The cockroach didn't hear the second tone!"<<endl;
  while (chance > 5)
  {
    do
    {
      test2 = (static_cast<float>(rand()) / (static_cast<float>(RAND_MAX 
                     / P2_RANGE)));
    }while(test2 < 0 || test2 > 100);
                       
    if (test2 < levels.m_p2)
      levels.m_p2 = test2;
    do
    {
      levels.m_p4 = (((57 * rand() + 86) % P4_RANGE) + 10);
    }while(levels.m_p4 < 10 || levels.m_p4 > 50);
    chance = 0;
  }
  return;
}

void tone3(proteins & levels)
{
  short test1, test4, chance;
  do
  {
    chance = ((22 * rand() + 33) % CHANCE);
  }while(chance < 0 || chance > 100);
  if (chance <= 5)
    cout <<"Oh no! The cockroach didn't hear the third tone!"<<endl;
  while (chance > 5)
  {
    do
    {
      test1 = ((64 * rand() + 23) % P1_RANGE);
    }while(test1 < 0 || test1 > 100);  
    if(test1 < 10)
      test1 = 0;
    do
    {
      test4 = (((27 * rand() + 74) % P4_RANGE) + 10);
    }while(test4 < 10 || test4 > 50);
    if(levels.m_p1 < test1)
      levels.m_p1 = test1;
    if(levels.m_p4 < test4)
      levels.m_p4 = test4;
    do
    {
      levels.m_p5 = ((84 * rand() + 59) % P5_RANGE);
    }while(levels.m_p5 < 0 || levels.m_p5 > 10);
    chance = 0;
  }
  return;
}

void prognosis(const proteins & levels, string name)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  
  if(levels.m_p1 > 0)
  {
    if(levels.m_p5 < 2 && levels.m_p4 > 20 && levels.m_p4 < 40 
    && levels.m_p3 > 6)
    {
      cout <<"We tested "<<name<<endl;
      cout <<"The levels of p1 is "<<levels.m_p1<<endl;
      cout <<"The levels of p2 is "<<levels.m_p2<<endl;
      cout <<"The levels of p3 is "<<levels.m_p3<<endl;
      cout <<"The levels of p4 is "<<levels.m_p4<<endl;
      cout <<"The levels of p5 is "<<levels.m_p5<<endl;
      cout <<name<<" has Jejunal Hemorrhage Syndrome"<<endl;
    }
    else if(levels.m_p5 > 2 && (levels.m_p1 + levels.m_p2 + levels.m_p3 < 75))
    {
      cout <<"We tested "<<name<<endl;
      cout <<"The levels of p1 is "<<levels.m_p1<<endl;
      cout <<"The levels of p2 is "<<levels.m_p2<<endl;
      cout <<"The levels of p3 is "<<levels.m_p3<<endl;
      cout <<"The levels of p4 is "<<levels.m_p4<<endl;
      cout <<"The levels of p5 is "<<levels.m_p5<<endl;
      cout <<name<<" has Jejunal Hemorrhage Syndrome"<<endl;
    }
    else if(levels.m_p2 <= 14.6)
    {
      cout <<"We tested "<<name<<endl;
      cout <<"The levels of p1 is "<<levels.m_p1<<endl;
      cout <<"The levels of p2 is "<<levels.m_p2<<endl;
      cout <<"The levels of p3 is "<<levels.m_p3<<endl;
      cout <<"The levels of p4 is "<<levels.m_p4<<endl;
      cout <<"The levels of p5 is "<<levels.m_p5<<endl;
      cout <<name<<" has Jejunal Hemorrhage Syndrome"<<endl;
    }
    else
    {
      cout <<"We tested "<<name<<endl;
      cout <<"The levels of p1 is "<<levels.m_p1<<endl;
      cout <<"The levels of p2 is "<<levels.m_p2<<endl;
      cout <<"The levels of p3 is "<<levels.m_p3<<endl;
      cout <<"The levels of p4 is "<<levels.m_p4<<endl;
      cout <<"The levels of p5 is "<<levels.m_p5<<endl;
      cout <<name<<" does not have Jejunal Hemorrhage Syndrome"<<endl;
    }
  }   
  else
  {
    cout <<"We tested "<<name<<endl;
    cout <<"The levels of p1 is "<<levels.m_p1<<endl;
    cout <<"The levels of p2 is "<<levels.m_p2<<endl;
    cout <<"The levels of p3 is "<<levels.m_p3<<endl;
    cout <<"The levels of p4 is "<<levels.m_p4<<endl;
    cout <<"The levels of p5 is "<<levels.m_p5<<endl;
    cout <<name<<" does not have Jejunal Hemorrhage Syndrome"<<endl;
  }
  return;
}

void WantToQuit(bool & quit)
{
  char yes_or_no;
  do
  {
    cout <<"Would you like to test another patient (y/n):  ";
    cin >> yes_or_no;
    switch (yes_or_no)
    {
      case 'n':
        cout <<"You have chosen to quit"<<endl;
        quit = true;
        break;
      case 'y':
        cout <<"You have chosen to try again"<<endl;
        quit = false;
        break;
      default:
        cout <<"ERROR, that's not a valid option"<<endl;
        break;
    }
  }while(yes_or_no != 'y' && yes_or_no != 'n');
  return;
}

void reset(proteins & levels)
{
  levels.m_p1 = 0;
  levels.m_p2 = 0.0;
  levels.m_p3 = 0;
  levels.m_p4 = 0;
  levels.m_p5 = 0;
  return;
}
