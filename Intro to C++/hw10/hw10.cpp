//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: hw10.cpp                  Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Contains the program that simulates a patient and a doctor visiting
// hospital rooms.

class Patient;

#include "patient.h"
#include "doctor.h"
#include "hospital.h"
#include "lobotomizer.h"
#include "organ_donor.h"
#include "pharmacy.h"
#include "placaeboizer.h"
#include "liposuctionizer.h"
#include "x_rayer.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  srand(time(NULL));                       //Seed rand()
  const short NUM_PATIENTS = 10;         
  Hospital<X_Rayer> xr_room;               //Objects of each room
  Hospital<Lobotomizer> lob_room;
  Hospital<Organ_donor> od_room;
  Hospital<Pharmacy> pharm_room;
  Hospital<Placaeboizer> placae_room;
  Hospital<Liposuctionizer> lipo_room;
  Patient patients[NUM_PATIENTS];               //Array to hold patients
  Doctor dr("Price");                 //Make object of Doctor type

  cout << "\n--------------------Initial Statuses------------------" << endl;
  cout << dr <<endl;
  cout << xr_room <<endl;
  cout << lob_room <<endl;
  cout << od_room <<endl;
  cout << pharm_room <<endl;
  cout << placae_room <<endl;
  cout << lipo_room <<endl;
  for(int i = 0; i < NUM_PATIENTS; i++)
  {
    cout << patients[i];
  }

  cout << "\n-------------------Commencing Testing-----------------" << endl;

  for(int i = 0; i < NUM_PATIENTS; i++)         //Loop through patients
  {
    cout << "\n--------------------Patient #" << i + 1 << " is now being"
         << " tested------------------------" << endl;

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << " the x-ray room. ------------" << endl;

    if(xr_room.admit(patients[i], dr))
    {
      cout << patients[i];
      cout << endl;
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "is unable to enter the x_ray room"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];
      cout << endl;        //Check if patient entered room
      cout << dr;
    }

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << " the lobotomizer room. ------------" << endl;

    if(lob_room.admit(patients[i], dr))
    {
      cout << patients[i];
      cout << endl;
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "is unable to enter lobotomizer room"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];        //Check if patient entered room
      cout << endl;
      cout << dr;
    }

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << " the organ donor room. ------------" << endl;

    if(od_room.admit(patients[i], dr))
    {
      cout << patients[i];
      cout << endl;
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "is unable to enter organ donor room"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];
      cout << endl;        //Check if patient entered room
      cout << dr;
    }

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << "the pharmacy. ------------" << endl;

    if(pharm_room.admit(patients[i], dr))
    {
      cout << patients[i];
      cout << endl;
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "is unable to enter the pharmacy"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];
      cout << endl;        //Check if patient entered room
      cout << dr;
    }

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << " the placaeboizer room. ------------" << endl;

    if(placae_room.admit(patients[i], dr))
    {
      cout << patients[i];
      cout << endl;
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "is unable to enter placaeboizer room"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];
      cout << endl;        //Check if patient entered room
      cout << dr;
    }

    cout << "\n----------Patient #" << i + 1 << " is attempting to enter"
         << " the liposuctionizer room. ------------" << endl;

    if(lipo_room.admit(patients[i], dr))
    {
      cout << patients[i];
      //Still needs to display how many times machine was applied on patient
      cout << dr;
    }

    else            //Explain reason for not entering
    {
      cout << "\nPatient #" << i + 1 << "can't enter the liposuctionizer room"
           << " because he/she is "
           << ((patients[i].getCondition() == 0) ? "dead." : "unable to pay.")
           << endl;
      cout << patients[i];
      cout << endl;        //Check if patient entered room
      cout << dr;
    }
  }
  cout << "\n----------------------Final Statuses--------------------" << endl;
  cout << dr;
  cout << xr_room;
  cout << lob_room;
  cout << od_room;
  cout << pharm_room;
  cout << placae_room;
  cout << lipo_room;
  for(int j = 0; j < NUM_PATIENTS; j++)
  {
    cout << patients[j];
  }
  return 0;
}
