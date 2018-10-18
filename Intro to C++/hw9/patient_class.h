//Programmer: Peter Dolan      ID: 12410657
//Instructor: Price     Section: A    Date: 11/17/2014
//File: patient_class.h        Description: header for the patient class
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef PATIENT_CLASS_H
#define PATIENT_CLASS_H

const short MONEY_MOD1 = 203;
const short MONEY_MOD2 = 402;
const short MONEY_MAX = 4001;
const short NAME_MOD1 = 25;
const short NAME_MOD2 = 42;
const short NAME_MAX = 24;
const short NAME_LENGTH = 25;
const short CONDITION_MOD1 = 51;
const short CONDITION_MOD2 = 76;
const short CONDITION_MAX = 101;

//Description: Allows for the patient class to be outputted
//Pre-conditions: An ostream and a patient type object
//Post-conditions: Outputs something to the screen

//Description: Constructor for the patient class
//Pre-conditions: N/A
//Post-conditions: Creates a randomized patient-class object
    
//Description: Slaps the patient with a bill
//Pre-conditions: A positive numerical value
//Post-conditions: Deducts the specified amount from the patient's wallet
    
//Description: Updates the patient's health
//Pre-Conditions: Requires the kill function
//Post-conditions: Updates the patient's health

//Description: Updates the patient's 'is_alive' status
//Pre-conditons: N/A
//Post-conditions: Alters a bool value in the patient class
class patient
{
  public:
    friend ostream& operator<<(ostream& o, const patient& p);
    patient();
    void pay_out(const float bill);
    void modify_health(const bool half_health);
  private:
    float p_money;
    char p_name[NAME_LENGTH];
    bool p_is_alive;
    int p_condition;
    void kill()
	{
      p_is_alive = false;
      return;
    };
};

#endif