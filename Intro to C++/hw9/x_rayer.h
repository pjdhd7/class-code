//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: x_rayer.h           Description: Header for the x_rayer class
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "patient_class.h"
using namespace std;

#ifndef X_RAYER_H
#define X_RAYER_H

const float COST_DEFAULT = 550;
const short ZERO_USES = 0;
const short HALF_MOD1 = 13;
const short HALF_MOD2 = 56;
const short HALF_CHANCE = 11;
const short HALF_CHANCE_TRUE = 10;

//Description: Establishes a default x_rayer object
//Pre-conditions: N/A
//Post-condition: Sets the defaults for the x_rayer class

//Description: Charges a patient for the scan
//Pre-conditions: A patient, preferably not dead
//Post-conditions: Alters the patient's monetary reserves

//Description: Alters a patient's health
//Pre-conditions: A patient, preferably not dead
//Post-conditions: Alters the patient's condition status

//Description: Allows the class to be outputted
//Pre-conditions: A valid ostream object
//Post-conditions: Inserts data into the ostream

class x_rayer
{
  public:
    x_rayer();
    void charge_patient(patient& p);
    void apply(patient& p);
    friend ostream& operator <<(ostream& o, const x_rayer x); 
  private:
    float x_cost_per_use;
    short x_num_uses;
};

#endif