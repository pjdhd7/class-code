//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: hospital.h                Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include "patient.h"
#include "doctor.h"
using namespace std;

//----------------------------Global Constants-------------------------------//
const float INITIAL_SCHRAUT_AMT = 10;
const float PAYOUT_PORTION = 0.5;         //Percentage of cost given to doctor
short DRUNK_APPS = -5;      //Total Schraut consumed+DRUNK_APPS=# applications
short ANGRY_APPS = 2;       //Used if no Schraut is consumed
//-----------------------------Documentation---------------------------------//

// Hospital() is the default constructor for Hospital
// Preconditions: None
// Postconditions: m_schraut set to INITIAL_SCHRAUT_AMT

// Admit a patient to the hospital
// Preconditions: None
// Postconditions: Patient p will be modified via calls
// to charge_patient and apply

// Overloaded operator for << (as friend function)
// Preconditions: None
// Postconditions: Hospital's member variable values will
// be output to o (thereby modifying ostream o)
template <class T_machine>
class Hospital
{
  public:
    Hospital();
    bool admit(Patient& p, Doctor& d);

    template <typename u>
    friend ostream& operator << (ostream& o, const Hospital<u>& h);

  private:
    T_machine m_the_machine;   // template machine
    float m_schraut;           // ounces of Schraut!
    float m_doctor_payout;      // The amount of money the doctor gets
};

#include "hospital_room_fncts.hpp"
#endif
