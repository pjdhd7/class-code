//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: hospital_room_fncts.cpp    Description: Functions for the hospital_room
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "x_rayer.h"
#include "patient_class.h"
#include "hospital_room.h"
using namespace std;

hospital_room::hospital_room()
{
  schraut_stash = SCHRAUT_DEFAULT;
}

void hospital_room::admit(patient& p)
{
  the_machine.charge_patient(p);
  the_machine.apply(p);
  return;
}

ostream& operator <<(ostream& o, const hospital_room h)
{
  o<<"There are "<<h.schraut_stash<<" ounces of Schraut in the room"<<endl;
  o<<h.the_machine;
  return o;
}