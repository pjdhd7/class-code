//Programmer: Peter Dolan      Date: 10/11/2014
//Instructor: Price       Section: A        Date: 10/11/2014
//File: hw6.h       Description: Header File for the Program
#ifndef HW6_H
#define HW6_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const short P1_RANGE = 101;
const float P2_RANGE = 101.0;
const short P3_RANGE = 11;
const short P4_RANGE = 41;
const short P5_RANGE = 11;
const short CHANCE = 101;
struct proteins
{
  short m_p1;
  float m_p2;
  short m_p3;
  short m_p4;
  short m_p5;
};

//Description: Gets the patients name
//Pre-condition: A string variable
//Post-condition: Alters the 'name' variable
void getName(string & name);

//Description: Measures the values of p1, p2, and p3
//Pre-condition: A proteins struct
//Post-condition: Either the values of p1, p2, or p3, or a message indicating
//                test failure
void tone1(proteins & levels);

//Description: Measures the values of p2 and p4
//Pre-condition: A proteins struct
//Post-condition: Either the values of p2 and p4, or a message indicating
//                test failure
void tone2(proteins & levels);

//Description: Measures the values of p1, p4, and p5
//Pre-condition: A proteins struct
//Post-condition: Either the values of p1, p4, and p5, or a message indicating
//                test failure
void tone3(proteins & levels);

//Description: Determines the presence of JHS
//Pre-condition: A proteins struct that has been assigned values
//Post-condition: Outputs whether or not the patient has JHS
void prognosis(const proteins & levels, string name);

//Description: Asks if Dr. Eloe would like to test another patient
//Pre-condition: A bool variable
//Post-condition: Outputs message to screen, Alters bool variable
void WantToQuit(bool & quit);

//Description: Resets the values of the protein levels, so that the prognosis
//             is based on information gathered ONLY from the current patient
//Pre-condition: A proteins struct
//Post-condition: Sets the values of a proteins struct to 0
void reset(proteins & levels);

#endif
