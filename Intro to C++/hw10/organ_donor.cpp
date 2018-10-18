//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the implementaion for the class that simulates an organ
// donor machine within the program that simulates a patient and a doctor
// visiting hospital rooms.

#include "organ_donor.h"

using namespace std;

bool Organ_donor::charge_patient(Patient & p) const
{
  return p.pay_out(OD_COST_PER_USE);      //Returns true if patient able to pay
}

void Organ_donor::apply(Patient & p)
{
  m_num_uses++;
  p.modify_mental(INCREMENT_MENTAL_HEALTH);
  p.modify_weight(INCREMENT_WEIGHT);
  p.modify_health(-(rand() % MAX_PHYS_CHANGE));
  if((rand() % OD_PERCENTAGE) + OD_MIN_PERCENT <= KILL_CHANCE)
  {
    p.modify_health(-(p.getCondition()));
  }
  return;
}

ostream & operator << (ostream & o, const Organ_donor & od)
{
  o << "Organ Donator cost per use: " << od.m_cost_per_use
    << " Num uses: "<< od.m_num_uses ;
  return o;
}
