//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: hospital_room.h      Description: Header for the hospital_room class
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "patient_class.h"
#include "x_rayer.h"
using namespace std;

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

const float SCHRAUT_DEFAULT = 10.0;

class hospital_room
{
  public:
    //Description: Establishes a default hospital room
    //Pre-conditions: N/A
    //Post-conditions: Establishes a default hospital room
    hospital_room();
    
    //Description: Simulates a patient going through the hospital room
    //Pre-conditions: A patient, preferably not dead
    //Post-conditions: Alters the patient's health and wealth
    void admit(patient& p);
    
    //Description: Allows the class to be outputted
    //Pre-conditions: A valid ostream object
    //Post-conditions: Inserts data into the ostream
    friend ostream& operator <<(ostream& o, const hospital_room h);
  private:
    x_rayer the_machine;
    float schraut_stash;
};

#endif