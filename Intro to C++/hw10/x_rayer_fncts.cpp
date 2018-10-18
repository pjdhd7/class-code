//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The implementation for the simulation of the usage of a X-Rayer
// machine for use in the program that simulates a doctor and patient
// entering a room and using the machine in a hospital room

#include "x_rayer.h"
using namespace std;

bool X_Rayer::charge_patient(Patient& p) const
{
  bool got_charged = false;
  if(p.getMoney() >= m_cost_per_use)
  {
    p.pay_out(m_cost_per_use);
    got_charged = true;
  }
  return got_charged;
}

void X_Rayer::apply(Patient& p)
{
  if ((rand() % 100) <= CHANCE_XRAY_AFFECTS)
    p.modify_health(p.getCondition()/2);
  m_num_uses++;
  return;
}

ostream& operator << (ostream& o, const X_Rayer& x)
{
  o << "X-Rayer cost per use: $" << x.m_cost_per_use
       << ", Num uses: " << x.m_num_uses;
  return(o);
}
