//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: patient_fncts.cpp        Description: Functions for the patient class
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "x_rayer.h"
#include "patient_class.h"
#include "hospital_room.h"
using namespace std;

ostream& operator<<(ostream& o, const patient& p)
{
  o<<"Name: "<<p.p_name<<endl<<"Money available: "<<p.p_money<<endl
   <<"Their Condition: "<<p.p_condition<<endl;
  if(p.p_is_alive == true)
    o<<"The patient is alive"<<endl;
  else
    o<<"The patient is dead"<<endl;
  return o;
}

patient::patient()
{
  short count = 0;
  ifstream fin;
  fin.open("names.dat");
  do
  {
    p_money = ((MONEY_MOD1 * rand()) + MONEY_MOD2) % MONEY_MAX;
  }while(p_money < 0 || p_money > 4000);
  
  do
  {
    count = ((NAME_MOD1 * rand()) + NAME_MOD2) % NAME_MAX;
  }while(count < 1 || count > 23);
  
  for(int i = 1; i <= count; i++)
  {
    fin >> p_name;
    if(i != count)
      for(int j = 0; j < NAME_LENGTH; j++)
        p_name[j] = '\0';
  }
  
  do
  {
    p_condition = ((CONDITION_MOD1 * rand()) + CONDITION_MOD2) % CONDITION_MAX;
  }while(p_condition < 0 || p_condition > 100);
  
  if(p_condition == 0)
    p_is_alive = false;
  else
    p_is_alive = true;
  
  fin.close();
}

void patient::pay_out(const float bill)
{
  p_money -= bill;
  return;
}
 
void patient::modify_health(const bool half_health)
{
  if(half_health == true)
    p_condition /= 2;
  
  if(p_condition <= 0)
    kill();
  
  return;
}