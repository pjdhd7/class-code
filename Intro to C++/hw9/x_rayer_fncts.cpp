//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: x_rayer_fncts.cpp     Description: Functions for the x_rayer class
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "x_rayer.h"
#include "patient_class.h"
#include "hospital_room.h"
using namespace std;

x_rayer::x_rayer()
{
  x_num_uses = ZERO_USES;
  x_cost_per_use = COST_DEFAULT;
}

void x_rayer::charge_patient(patient& p)
{
  p.pay_out(x_cost_per_use);
  x_num_uses++;
  return;
}

void x_rayer::apply(patient& p)
{
  short chance = 0;
  bool half_health = false;
  do
  {
    chance = ((HALF_MOD1 * rand()) + HALF_MOD2) % HALF_CHANCE;
  }while(chance < 1 || chance > 10); 
  
  if(chance == HALF_CHANCE_TRUE)
    half_health = true;
  
  p.modify_health(half_health);
  return;
}

ostream& operator<<(ostream& o, const x_rayer x)
{
  o<<"The X_Ray machine has been used "<<x.x_num_uses<<" times at $"
   <<x.x_cost_per_use<<" per use."<<endl;
  return o;
}