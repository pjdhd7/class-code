//Programmer: Peter Dolan    Student ID: 12410657
//Instructor: Clayton Price   Section: A    Date: 09/13/2014
//File: hw3.cpp     Description: Dr. Eloe's ER priorities
#include <iostream>
#include <string>
using namespace std;

int main ()
{
  const short CEREB_CONT = 9;
  const short DISK_RUPT = 7;
  const short BROK_RAD = 3;
  const short INTE_DIST = 2;
  const short BROK_NECK = 6;
  const short BURN_TOE = 1;
  const short PERM_SMIL = 3;
  const short FLAIL_CHEST = 4;
  const short EARLOBE = 5;
  const short ALCO_POIS = 2;
  const short FRAC_FEMR = 3;
  const short NAIL_FUNG = 0;
  const short ALTER_EGO = 4;
  const short ALIEN_IMPLANT = 8;
  const short BBQ_RIBS = 7;
  const short PLAST_SURG = 1;
  const short HEALTHY = -1;
  short REGION1;
  short SUBREGION1;
  short INJURY1_INPUT;
  short INJURY1;
  short REGION2;
  short SUBREGION2;
  short INJURY2_INPUT;
  short INJURY2;
  string patient1;
  string patient2;
  
  cout << "/----------------GREETINGS----------------/" <<endl;
  cout << "Enter the first patient's name:  ";
  cin >> patient1;
  cout << "Enter the second patient's name:  ";
  cin >> patient2;
  while (REGION1 != 1 && REGION1 != 2 && REGION1 != 3 && REGION1 != 4)
  {
  cout << endl;
  cout << "Let's Begin with " << patient1 <<endl;
  cout << "             Region Menu" <<endl;
  cout << "         -------------------" <<endl;
  cout << "         1. Head and Neck" <<endl;
  cout << "         2. Torso" <<endl;
  cout << "         3. Extremity" <<endl;
  cout << "         4. Not Listed" <<endl;
  cout << "Which region is the injury located (type an integer):   ";
  cin >> REGION1;
  }
  if (REGION1 == 1)
  {
   while (SUBREGION1 != 1 && SUBREGION1 != 2 && SUBREGION1 != 3)
   {
   cout <<endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Head" <<endl;
   cout << "         2. Face" <<endl;
   cout << "         3. Neck" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION1;
   }
   if (SUBREGION1 == 1)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2 && INJURY1_INPUT != 3)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Cerebral Contusion" <<endl;
    cout << "         2. Earlobe gastrophilology" <<endl;
    cout << "         3. Altered Ego" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = CEREB_CONT;
    else if (INJURY1_INPUT == 2)
     INJURY1 = EARLOBE;
    else
     INJURY1 = ALTER_EGO;
    }
   }
   else if (SUBREGION1 == 2)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Permanent Smiley Face" <<endl;
    cout << "         2. Deformed Plastic Surgery" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = PERM_SMIL;
    else
     INJURY1 = PLAST_SURG;
    }
   }
   else if (SUBREGION1 == 3)
   {
    while (INJURY1_INPUT != 1)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Broken Neck" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = BROK_NECK;
    }
   }
  }
  else if (REGION1 == 2)
  {
   while (SUBREGION1 != 1 && SUBREGION1 != 2 && SUBREGION1 != 3)
   {
   cout <<endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Back" <<endl;
   cout << "         2. Chest" <<endl;
   cout << "         3. Abdomen" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION1;
   }
   if (SUBREGION1 == 1)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. BBQd Ribs" <<endl;
    cout << "         2. Disk Rupture" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = BBQ_RIBS;
    else
     INJURY1 = DISK_RUPT;
    }	
   }
   else if (SUBREGION1 == 2)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Alien Implantation" <<endl;
    cout << "         2. Flail Chest" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = ALIEN_IMPLANT;
    else
     INJURY1 = FLAIL_CHEST;
    }
   }
   else
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Alcohol Poisoning" <<endl;
    cout << "         2. Intestinal Distress" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = ALCO_POIS;
    else if (INJURY1_INPUT == 2)
     INJURY1 = INTE_DIST;
    }
   }
  }
  else if (REGION1 == 3)
  {
   while (SUBREGION1 != 1 && SUBREGION1 != 2)
   {
   cout <<endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Arm" <<endl;
   cout << "         2. Leg" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION1;
   }
   if (SUBREGION1 == 1)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Broken Radius" <<endl;
    cout << "         2. Nail Fungus" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = BROK_RAD;
    else
     INJURY1 = NAIL_FUNG;
    }
   }
   else if (SUBREGION1 == 2)
   {
    while (INJURY1_INPUT != 1 && INJURY1_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Fractured Femur" <<endl;
    cout << "         2. Burned Toe Hair" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY1_INPUT;
    if (INJURY1_INPUT == 1)
     INJURY1 = FRAC_FEMR;
    else
     INJURY1 = BURN_TOE;
    }
   }
  }
  else if (REGION1 == 4)
  {
   INJURY1 = HEALTHY;
   cout << endl;
   cout << "You're Fine. Go Home.";
   cout << endl;
  }
  
  cout << endl;
  cout << "Now let's look at " << patient2 <<endl;
  while (REGION2 != 1 && REGION2 != 2 && REGION2 != 3 && REGION2 != 4)
  {
  cout << "             Region Menu" <<endl;
  cout << "         -------------------" <<endl;
  cout << "         1. Head and Neck" <<endl;
  cout << "         2. Torso" <<endl;
  cout << "         3. Extremity" <<endl;
  cout << "         4. Not Listed" <<endl;
  cout << "Which region is the injury located (type an integer):   ";
  cin >> REGION2;
  }
  if (REGION2 == 1)
  {
   while (SUBREGION2 != 1 && SUBREGION2 != 2 && SUBREGION2 != 3)
   {
   cout <<endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Head" <<endl;
   cout << "         2. Face" <<endl;
   cout << "         3. Neck" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION2;
   }
   if (SUBREGION2 == 1)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2 && INJURY2_INPUT != 3)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Cerebral Contusion" <<endl;
    cout << "         2. Earlobe gastrophilology" <<endl;
    cout << "         3. Altered Ego" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = CEREB_CONT;
    else if (INJURY2_INPUT == 2)
     INJURY2 = EARLOBE;
    else
     INJURY2 = ALTER_EGO;
    }
   }
   else if (SUBREGION2 == 2)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Permanent Smiley Face" <<endl;
    cout << "         2. Deformed Plastic Surgery" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = PERM_SMIL;
    else
     INJURY2 = PLAST_SURG;
    }
   }
   else if (SUBREGION2 == 3)
   {
    while (INJURY2_INPUT != 1)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Broken Neck" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = BROK_NECK;
    }
   }
  }
  else if (REGION2 == 2)
  {
   while (SUBREGION2 != 1 && SUBREGION2 != 2 && SUBREGION2 != 3)
   {
   cout << endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Back" <<endl;
   cout << "         2. Chest" <<endl;
   cout << "         3. Abdomen" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION2;
   }
   if (SUBREGION2 == 1)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. BBQd Ribs" <<endl;
    cout << "         2. Disk Rupture" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = BBQ_RIBS;
    else if (INJURY2_INPUT == 2)
     INJURY2 = DISK_RUPT;
    }
   }
   else if (SUBREGION2 == 2)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Alien Implantation" <<endl;
    cout << "         2. Flail Chest" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = ALIEN_IMPLANT;
    else
     INJURY2 = FLAIL_CHEST;
    }
   }
   else
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Alcohol Poisoning" <<endl;
    cout << "         2. Intestinal Distress" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = ALCO_POIS;
    else
     INJURY2 = INTE_DIST;
    }
   }
  }
  else if (REGION2 == 3)
  {
   while (SUBREGION2 != 1 && SUBREGION2 != 2)
   {
   cout <<endl;
   cout << "          Sub-Region Menu" <<endl;
   cout << "         -----------------" <<endl;
   cout << "         1. Arm" <<endl;
   cout << "         2. Leg" <<endl;
   cout << "Which sub-region is the injury located (type an integer):  ";
   cin >> SUBREGION2;
   }
   if (SUBREGION2 == 1)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Broken Radius" <<endl;
    cout << "         2. Nail Fungus" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = BROK_RAD;
    else
     INJURY2 = NAIL_FUNG;
    }
   }
   else if (SUBREGION2 == 2)
   {
    while (INJURY2_INPUT != 1 && INJURY2_INPUT != 2)
    {
    cout <<endl;
    cout << "             Injury Menu" <<endl;
    cout << "         -------------------" <<endl;
    cout << "         1. Fractured Femur" <<endl;
    cout << "         2. Burned Toe Hair" <<endl;
    cout << "Which injury does the patient have (type an integer):  ";
    cin >> INJURY2_INPUT;
    if (INJURY2_INPUT == 1)
     INJURY2 = FRAC_FEMR;
    else
     INJURY2 = BURN_TOE;
    }
   }
  }
  else if (REGION2 == 4)
  {
   INJURY2 = HEALTHY;
   cout << endl;
   cout << "You're fine. Go Home.";
   cout << endl;
  }
  
  if (INJURY1 > INJURY2)
  {
   cout << patient1 << " has an ISS value of " << INJURY1 <<endl;
   cout << "Please admit them immediately." <<endl;
   cout << "Thank you and have a good day!";
  }
  else if (INJURY1 < INJURY2)
  {
   cout << patient2 << " has an ISS value of " << INJURY2 <<endl;
   cout << "Please admit them immediately." <<endl;
   cout << "Thank you and have a good day!";
  }
  else if (patient1 < patient2)
  {
   cout << patient1 << " has an ISS value of " << INJURY1 <<endl;
   cout << "Please admit them immediately." <<endl;
   cout << "Thank you and have a good day!";
  }
  else if (patient1 > patient2)
  {
   cout << patient2 << " has an ISS value of " << INJURY2 <<endl;
   cout << "Please admit them immediately." <<endl;
   cout << "Thank you and have a good day!";
  }
  else
  {
   cout << patient1 << " has an ISS value of " << INJURY1 <<endl;
   cout << "Please admit them immediately." <<endl;
   cout << "Thank you and have a good day!";
  }
  cout << endl;
  return 0;
}
  
  
