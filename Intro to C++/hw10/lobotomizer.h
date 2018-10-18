//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: lobotomizer.h             Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the class definition for the class that simulates
// a Lobotomizer within the program that simulates a patient and a doctor
// visiting hospital rooms.

#ifndef LOBOTOMIZER_H
#define LOBOTOMIZER_H

#include <iostream>
#include "patient.h"

using namespace std;

//----------------------------Global Constants-------------------------------//
const short LOB_INIT_USES = 0;                        //Used in default constructor
const float LOB_COST_PER_USE = 200;                 //Used in default constructor
const short INCREMEMENT_MENTAL_HEALTH = 10;       //Amt apply() changes patient
const short INCREMENT_PHYSICAL_HEALTH = 3;
const short LB_PERCENTAGE = 100;             //Percentage calculation constant
const short LB_MIN_PERCENT = 1;               //Minimum percentage 
const short VEG_CHANCE = 3;              //Percent chance of turning vegetable
const short VEG_STATUS = 0;             //Mental health qualifying as vegetable
const short NAME_ALTER_CHANCE = 10;           //Percent chance of altering name

//-----------------------------Documentation---------------------------------//
// Lobotomizer() is the default constructor for this class. This default
//  constructor initializes the member vars for the cost per use and the number
//  of uses
// Pre: None.
// Post: Initializes member vars for the cost per use and the number of uses.

// charge_patient() calls a member function of the patient class to subtract the
//  cost per use from the patient's money.
// Pre: None.
// Post: Calls member function of the patient class to subtract the cost per
//  use from the patient's money.

// apply() increases patient's mental health by 10 and physical health by 3 and
//  has a chance of turning the patient into a vegetable or altering the
//  patient's name.
// Pre: Rand() must be seeded.
// Post: Increases patient's mental health by 10 and physical health by 3.
//  Possibly turned patient into a vegetable or altered patient's name.

// Accessor for cost per use returns the cost per use.
// Pre: None.
// Post: Returns the cost per use.

// Overloaded insertion operator as friend of Lobotomizer class
// Pre: None.
// Post: Lobotomizer member vars passed to the ostream parameter.
//--------------------------Class Definition---------------------------------//
class Lobotomizer
{
  public:
    Lobotomizer(): m_cost_per_use(LOB_COST_PER_USE), m_num_uses(LOB_INIT_USES) {};
    bool charge_patient(Patient & p) const;
    void apply(Patient & p);
    float getCost() const {return m_cost_per_use;} 
    friend ostream & operator << (ostream & o, const Lobotomizer & l);
  private:
    float m_cost_per_use;
    short m_num_uses;
};

#endif
