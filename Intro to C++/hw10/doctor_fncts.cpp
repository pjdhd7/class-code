//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: hw10.cpp                  Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the implementation for the class that simulates
// a doctor within the program that simulates a patient and a doctor
// visiting hospital rooms.bool puke()

#include "doctor.h"

using namespace std;

//----------------------------Class constants-------------------------------//
short PUKE_LVL = 25;        //Oz of Schraut that warrants puking
short POST_PUKE_LVL = 0;    //Oz of Schraut in doctor's stomach after puking
short MIN_SCHRAUT = 3;      //Range of Schraut consumed
short MAX_SCHRAUT = 1;
// The constants were moved to this .cpp file due to compiler errors that
// resulted from doctor.h getting included in more than one file

bool Doctor::puke()
{
  bool puked = false;
  if(m_schraut >= PUKE_LVL)
  {
    m_schraut = POST_PUKE_LVL;
    puked = true;
    cout << "The good doctor has vomited." << endl;
  }
  return puked;
}

bool Doctor::consume_schraut(float & room_schraut)
{
  bool consumed = false;
  if(room_schraut > 0)
  {
    consumed = true;
    short schraut_consumed = (rand() % MAX_SCHRAUT) + MIN_SCHRAUT;

    if(schraut_consumed <= room_schraut)
    {
      room_schraut -= schraut_consumed;
    }

    else if(schraut_consumed > room_schraut)
    {
      schraut_consumed = room_schraut;
      room_schraut = 0;
    }
    puke();
  }
  return consumed;
}

ostream & operator <<(ostream & o, const Doctor & d)
{
  o << "Dr. " << d.m_name << " has $" << d.m_money << " and "
    << "eaten " << d.m_schraut << " oz of Schraut.";
  return o;
}
