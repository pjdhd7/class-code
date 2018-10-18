//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The declaration for the simulation of the usage of a
// Liposuctionizer machine for use in the program that simulates a doctor
// and patient entering a room and using the machine in a hospital room
#ifndef LIPOSUCTIONIZER_H
#define LIPOSUCTIONIZER_H

#include <iostream>
#include "patient.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const short LIPO_CHARGE_AMOUNT = 750;
const short LIPO_WEIGHT_REDUCTION = -10;
const short LIPO_MENTAL_BOOST = -20;
const short LIPO_KILL_CHANCE = 61;

//-----------------------------Documentation---------------------------------//
// Liposuctionizer() is the default constructor for the Liposuctionizer class
// Pre-conditions: N/A
// Post-conditions: Set m_cost_per_use to CHARGE_AMOUNT and m_num_uses to zero

// charge_patient charges a patient for the machine
// Pre-conditions: A patient, preferably with enough money
// Post-conditions: Returns true and the patient gets charged or false

// apply simulates the machine being used on the patient
// Pre-conditions: A patient, preferably alive
// Post-conditions: Alters the patient and may kill them

// getCost() simply returns the value of the machine's cost
// Pre=conditions: None
// Post-conditions: returns the machine's m_cost_per_use variable

// Overloaded the << operator (as a friend function)
// Pre-conditions: None
// Post-conditions: Member variables will be passed to the ostream passed to
// the function

//--------------------------Class Definition---------------------------------//
class Liposuctionizer
{
  public:
    Liposuctionizer() : m_cost_per_use(LIPO_CHARGE_AMOUNT) , m_num_uses(0) {}
    bool charge_patient(Patient& p) const;
    void apply(Patient& p);
    float getCost() const { return m_cost_per_use; } 
    friend ostream& operator << (ostream& o, const Liposuctionizer& L);

  private:
    float m_cost_per_use;    // A float to charge patients
    short m_num_uses;        // Count for the number of uses
};

#endif
