//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: pharmacy.h                Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains global constants and the definition for the class that
// simulates a pharmacy within the program that simulates a patient
// and a doctor visiting hospital rooms.

#ifndef PHARMACY_H
#define PHARMACY_H

#include <iostream>
#include "patient.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const short PHARM_INIT_USES = 0;                 //Used in default constructor
const float PHARM_COST_PER_USE = 150;            //Used in default constructor
const short MIN_PILLS = 50;
const short P1 = 1;                   //Used when randomly generating pills
const short P4 = 4;
const short P1_CHANGE_PHYS = 10;          //Effects of pills
const short P1_CHANGE_MENTAL = -10;
const short P2_CHANGE_PHYS = 20;
const short P2_SET_MENTAL = 0;
const short P3_SET_PHYS = 50;
const short P4_SET_MENTAL = 100;
const short P4_CHANGE_WT = 100;
const short CB_CHANGE_MENTAL = -23;
const short CB_WT_CHANGE = 44;

//-----------------------------Documentation---------------------------------//
// Pharmacy() is the default constructor for this class. This default
//  constructor initializes the member vars for the cost per use, the number
//  of uses, and the number of pills in the pharmacy.
// Pre: Rand must be seeded.
// Post: Initializes member vars for the cost per use, number of uses, and
//  number of pills.

// charge_patient() calls a member function of the Patient class to subtract the
//  cost per use from the patient's money.
// Pre: None.
// Post: Calls member function of the Patient class to subtract the cost per
//  use from the patient's money.

// apply() decrements number of pills, randomly selects 1 of 4 pills to give
//  to patient, and applies the effects of that pill to patient.
// Pre: Rand must be seeded.
// Post: Applies effects of chosen pill to patient.

// Accessor for cost per use returns the cost per use.
// Pre: None.
// Post: Returns the cost per use.

// Overloaded insertion operator as friend of Pharmacy class
// Pre: None.
// Post: Pharmacy member vars passed to the ostream parameter.

//--------------------------Class Definition---------------------------------//
class Pharmacy
{
  public:
    Pharmacy(): m_cost_per_use(PHARM_COST_PER_USE), m_num_uses(PHARM_INIT_USES),
                m_num_pills((rand() % MIN_PILLS) + MIN_PILLS) {}
    bool charge_patient(Patient & p) const;
    void apply(Patient & p);
    float getCost() const {return m_cost_per_use;}
    friend ostream & operator << (ostream & o, const Pharmacy & pharm);
  private:
    float m_cost_per_use;
    short m_num_uses;
    short m_num_pills;
};

#endif
