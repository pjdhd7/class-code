//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: placaeboizer.cpp          Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The implementation for the simulation of the usage of a
// Placaeboizer machine for use in the program that simulates a doctor and
// patient entering a room and using the machine in a hospital room
#include "placaeboizer.h"

using namespace std;

bool Placaeboizer::charge_patient(Patient& p) const
{
  bool got_charged = false;
  if(p.getMoney() >= m_cost_per_use)
  {
    p.pay_out(m_cost_per_use);
    got_charged = true;
  }
  return got_charged;
}

void Placaeboizer::apply(Patient& p)
{
  //This if-else statement prevents the mental health value from exceeding 100
  if(p.getMental() <= PLACAE_MENTAL_MAX)
    p.modify_mental((100 - p.getMental()) * PLACAE_DIVISOR);
  else
    p.modify_mental(100 - p.getMental());

  p.modify_weight(PLACAE_WEIGHT_GAIN);
  m_num_uses++;
  return;
}

ostream& operator << (ostream& o, const Placaeboizer& p)
{
  o << "Placaeboizer cost per use: $" << p.m_cost_per_use
       << ", Num uses: " << p.m_num_uses;
  return o;
}
