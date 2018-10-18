//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: The declaration for the simulation of the usage of a Placaeboizer
// machine for use in the program that simulates a doctor and patient
// entering a room and using the machine in a hospital room
#ifndef PLACAEBOIZER_H
#define PLACAEBOIZER_H

#include <iostream>
#include "patient.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const short PLACAE_CHARGE_AMOUNT = 500;
const short PLACAE_WEIGHT_GAIN = 50;
const short PLACAE_MENTAL_MAX = 67;
const float PLACAE_DIVISOR = 0.5;

//-----------------------------Documentation---------------------------------//
// Placaeboizer() is the initializer for the placaeboizer object
// Pre-conditions: N/A
// Post-conditions: Creates a placaeboizer object

// charge_patient charges the patient for the use of the machine
// Pre-conditions: A patient class object
// Post-conditions: Returns false, or returns true and alters the patient's
// money member variable

// apply simulates the application of the placaeboizer machine
// Pre-conditions: A patient class object
// Post-conditions: Alters the patient's weight and mental health variables

// getCost simply returns the value of the machine's cost
// Pre=conditions: None
// Post-conditions: returns the machine's m_cost_per_use variable

// Allows the placaeboizer object to be outputted
// Pre-conditions: An ostream object
// Post-conditions: Outputs a message to the stream

//--------------------------Class Definition---------------------------------//
class Placaeboizer
{
  public:
    Placaeboizer() : m_cost_per_use(PLACAE_CHARGE_AMOUNT) , m_num_uses(0) {}
    bool charge_patient(Patient& p) const;
    void apply(Patient& p);
    float getCost() const { return m_cost_per_use; }
    friend ostream& operator << (ostream& o, const Placaeboizer& p);

  private:
    float m_cost_per_use;     //The cost of the machine
    short m_num_uses;         //Counts the number of uses
};

#endif
