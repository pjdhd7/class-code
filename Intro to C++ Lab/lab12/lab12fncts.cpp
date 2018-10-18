//Programmer: Peter Dolan     ID: 12410657
//Instructor: Armita    Section: C     Date: 11/11/2014
//File: lab12fncts.cpp      Description: Time functions
#include "lab12.h"
#include <iostream>


void Time::read_in()
{
  do
  {
    cout <<"What is the hour:  ";
    cin >> m_hour;
    if(m_hour < 0)
      cout <<"That's not a valid time"<<endl;
  }while(m_hour < 0  && m_hour > 23);
  
  do
  {
    cout <<"What is the minute:  ";
    cin >> m_minute;
    if(m_minute < 0 && m_minute > 59)
      cout <<"That's not a valid time"<<endl;
  }while(m_minute < 0);
  
  do
  {
    cout <<"What is the second:  ";
    cin >> m_second;
    if(m_second < 0 && m_second > 59)
      cout <<"That's not a valid time"<<endl;
  }while(m_second < 0);
  return;
}

void Time::print_out()
{
  if(m_hour > 9)
    cout<<"The time is "<<m_hour<<":";
  else
    cout<<"The time is 0"<<m_hour<<":";
  
  if(m_minute > 9)
    cout<<m_minute<<":";
  else
    cout<<"0"<<m_minute<<":";
  
  if(m_second > 9)
    cout<<m_second<<endl;
  else
    cout<<"0"<<m_second<<endl;
  return;
}

void Time::nextSecond()
{
  m_second++;
  if(m_second == 60 && m_minute == 59 && m_hour != 23)
  {
    m_second = 0;
    m_minute = 0;
    m_hour++;
  }
  else if(m_second == 60 && m_minute == 59 && m_hour == 23)
  {
    m_second = 0;
    m_minute = 0;
    m_hour = 0;
  }
  else if(m_second == 60)
  {
    m_second = 0;
    m_minute++;
  }
  
  if(m_hour > 9)
    cout<<"The new time is "<<m_hour<<":";
  else
    cout<<"The new time is 0"<<m_hour<<":";
           
  if(m_minute > 9)
    cout<<m_minute<<":";
  else
    cout<<"0"<<m_minute<<":";
                        
  if(m_second > 9)
    cout<<m_second<<endl;
  else
    cout<<"0"<<m_second<<endl;  

  return;
}
