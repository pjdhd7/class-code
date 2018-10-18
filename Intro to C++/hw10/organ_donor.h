//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.h             Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the class definition for the class that simulates an organ
// donor machine within the program that simulates a patient and a doctor
// visiting hospital rooms.

#ifndef ORGAN_DONOR_H
#define ORGAN_DONOR_H

#include <iostream>
#include "patient.h"

using namespace std;

//----------------------------Global Constants-------------------------------//
const short OD_INIT_USES = 0;                     //Used in default constructor
const float OD_COST_PER_USE = 100;               //Used in default constructor
const short INCREMENT_MENTAL_HEALTH = 10;
const short INCREMENT_WEIGHT = -10;
const short KILL_CHANCE = 2;
const short MAX_PHYS_CHANGE = 2;
const short OD_PERCENTAGE = 100;
const short OD_MIN_PERCENT = 1;

//-----------------------------Documentation---------------------------------//
// Organ_donor() is the default constructor for this class. This default
//  constructor initializes the member vars for the cost per use and the number
//  of uses
// Pre: None.
// Post: Initializes member vars for the cost per use and the number of uses.

// charge_patient() calls a member function of the patient class to subtract the
//  cost per use from the patient's money.
// Pre: None.
// Post: Calls member function of the patient class to subtract the cost per
//  use from the patient's money.

// apply() increases patient's mental health by 10, decreases physical health
//  by random value from (and inclusive of) 0 to 20, dcreases weight by 10 lbs,
//  and has a 2% chance of killing patient.
// Pre: Rand() must be seeded.
// Post: Increases patient's mental health by 10 and physical health by 3.
//  Possibly turned patient into a vegetable or altered patient's name.

// Accessor for cost per use returns the cost per use.
// Pre: None.
// Post: Returns the cost per use.

// Overloaded insertion operator as friend of Organ_donor class
// Pre: None.
// Post: Organ_donor member vars passed to the ostream parameter.

//--------------------------Class Definition---------------------------------//
class Organ_donor
{
  public:
    Organ_donor(): m_cost_per_use(OD_COST_PER_USE), m_num_uses(OD_INIT_USES) {}
    bool charge_patient(Patient & p) const;
    void apply(Patient & p);
    float getCost() const {return m_cost_per_use;}
    friend ostream & operator << (ostream & o, const Organ_donor & organ);
  private:
    float m_cost_per_use;
    short m_num_uses;
};

#endif
