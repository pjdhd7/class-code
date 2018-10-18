//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: pharmacy.cpp              Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the implementation for the class that
// simulates a pharmacy within the program that simulates a patient
// and a doctor visiting hospital rooms.

#include "pharmacy.h"

using namespace std;

bool Pharmacy::charge_patient(Patient & p) const
{
  return p.pay_out(PHARM_COST_PER_USE);       //Returns true if Patient able to pay
}

void Pharmacy::apply(Patient & p)
{
  m_num_uses++;
  if(m_num_pills > 0)
  {
    switch((rand() % P4) + P1)
    {
      case 1:
        p.modify_health(P1_CHANGE_PHYS);
        p.modify_mental(P1_CHANGE_MENTAL);
        break;
      case 2:
        p.modify_health(P2_CHANGE_PHYS);
        p.set_mental(P2_SET_MENTAL);
        break;
      case 3:
        p.set_physical(P3_SET_PHYS);
        break;
      case 4:
        p.set_mental(P4_SET_MENTAL);
        p.modify_weight(P4_CHANGE_WT);
        break;
      default:
        cout << "Check your code, bud." << endl;
        break;
    }
  }
  else
  {
    p.modify_mental(CB_CHANGE_MENTAL);
    p.modify_weight(CB_WT_CHANGE);
  }
  return;
}

ostream & operator << (ostream & o, const Pharmacy & ph)
{
  o << "Pharmacy cost per use: " << ph.m_cost_per_use 
    << " Num Uses: "<< ph.m_num_uses  
	<< " Pills remaining: "<< ph.m_num_pills;
  return o;
}
