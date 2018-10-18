//Programmer: Peter Dolan        ID: 12410657
//Instructor: Price    Section: A       Date: 11/07/2014
//File: hw8.h        Description: Header for Health-o-matic
#ifndef HW8_H
#define HW8_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>
using namespace std;

const int DIAGNOSIS_ARRAY = 251;
const int LARGE_ARRAY = 21001;
const int PILL_ARRAY = 101;
const int MAX_SYLLABLES = 5;
const int MOD_1 = 27;
const int MOD_2 = 59;

//Description: Counts the number of a words in a character array
//Pre-conditions: A character array that has at least one word, if not 
//                multiple words
//Post-Conditions: Alters the value of an integer variable
void countWords(const char complaint[], int &wordCount);

//Description: Pulls out random words to parrot back at the patient
//Pre-conditions: The number of words in complaint must be known
//Post-conditions: Alters a null-terminated character array
void repeat(const char complaint[], const int &wordCount);

//Description: Makes a diagnosis that points out which area is affected
//Pre-condition: A character array and an integer with the number of words
//Post-condition: Alters an integer variable
void prognosis(const char complaint[], int &case_diagnosis);

//Description: Makes a diagnosis based around the Leg area
//Pre-conditions: Needs an array size, and the "Leg.dat" file
//Post-conditions: Alters a character array
void legs_diagnosis(char diagnosis[]);

//Description: Makes a diagnosis based around the head area
//Pre-conditions: Needs an array size, and the "Head.dat" file
//Post-conditions: Alters a character array
void head_diagnosis(char diagnosis[]);

//Description: Makes a diagnosis based around the Hands area
//Pre-conditions: Needs an array size, and the "Hands.dat" file
//Post-conditions: Alters a character array
void hands_diagnosis(char diagnosis[]);

//Description: Makes a diagnosis based around the Torso area
//Pre-conditions: Needs an array size, and the "Torso.dat" file
//Post-conditions: Alters a character array
void torso_diagnosis(char diagnosis[]);

//Description: Makes a diagnosis based around the Nose area
//Pre-conditions: Needs an array size, and the "Nose.dat" file
//Post-conditions: Alters a character array
void nose_diagnosis(char diagnosis[]);

//Description: Prescribes medicine and, if necessary, surgery
//Pre-conditions: The files "Scripts.dat" and "Surgeries.dat"
//Post-conditions: Alters two character arrays
void prescription(char pill[], char surgery[], bool &needs_surgery);

#endif