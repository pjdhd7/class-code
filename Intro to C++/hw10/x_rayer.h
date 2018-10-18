//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The declaration for the simulation of the usage of a X-Rayer
// machine for use in the program that simulates a doctor and patient
// entering a room and using the machine in a hospital room
#ifndef XRAYER_H
#define XRAYER_H

#include <iostream>
#include "patient.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const int CHANCE_XRAY_AFFECTS = 10;
const float CHARGE_PER_USE = 550;

//-----------------------------Documentation---------------------------------//
// X_Rayer() is the default constructor for X_Rayer
// Preconditions: None
// Postconditions: m_cost_per_use set to CHARGE_PER_USE, m_num_uses set to 0

// charge_patient charges a patient for using this machine
// Preconditions: None
// Postconditions: Patient p's amount of money will be modified via call to
// pay_out, returns a bool

// apply will modify the patient's health
// Preconditions: None
// Postconditions: Patient p's condition will be modified via call to
// modify_health a certain percentage of the time
// (i.e., CHANCE_XRAY_AFFECTS)

// getCost simply returns the value of the machine's cost
// Pre=conditions: None
// Post-conditions: returns the machine's m_cost_per_use variable

// Overloaded operator for << (as friend function)
// Preconditions: None
// Postconditions: Machine's member variable values will be output to o
// (thereby modifying ostream o)

//--------------------------Class Definition---------------------------------//
class X_Rayer
{
  public:
    X_Rayer() : m_cost_per_use(CHARGE_PER_USE),
                m_num_uses(0) {}
    bool charge_patient(Patient& p) const;
    void apply(Patient& p);
    float getCost() const { return m_cost_per_use; }
    friend ostream& operator << (ostream& o,
                                 const X_Rayer& x);

  private:
    float m_cost_per_use; // how much patient charged
    short m_num_uses;     // how often machine gets used
};

#endif
