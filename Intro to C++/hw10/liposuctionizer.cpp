//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The implementation for the simulation of the usage of a
// Liposuctionizer machine for use in the program that simulates a doctor
// and patient entering a room and using the machine in a hospital room
#include "liposuctionizer.h"
using namespace std;

bool Liposuctionizer::charge_patient(Patient& p) const
{
  bool got_charged = false;
  if (p.getMoney() >= m_cost_per_use)
  {
    p.pay_out(m_cost_per_use);
    got_charged = true;
  }
  return got_charged;
}

void Liposuctionizer::apply(Patient& p)
{
  p.modify_weight(LIPO_WEIGHT_REDUCTION);
  p.modify_mental(LIPO_MENTAL_BOOST);
  if((m_num_uses % LIPO_KILL_CHANCE) == 0)
    p.modify_health(-(p.getCondition()));
  m_num_uses++;
  return;
}

ostream& operator << (ostream& o, const Liposuctionizer& L)
{
  o << "Liposuctionizer cost per use: $" << L.m_cost_per_use
       << ", Num uses: " << L.m_num_uses;
  return o;
}
