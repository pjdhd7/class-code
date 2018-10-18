//-----------------------------------------------------------------------
// Name: ALEX SHAW, PETER DOLAN 	 Date: 11-25-14
// File: organ_donor.cpp           Class: CS 1570, Sections B and A
//------------------------------------------------------------------------
// Purpose: Defines the patient-class object for our simulation and all
// member functions and variables for the simulation of a doctor and patient
// entering a hospital room and using the machine in that room
#include "patient.h"
using namespace std;

Patient::Patient()
{
  m_money = rand() % (MAX_INITIAL_FUNDS+1);
  m_condition = rand() % (PERFECT_HEALTH+1);
  if(m_condition > 0)
    m_isAlive = true;
  else
    m_isAlive = false;
  m_mental_health = rand() % (PERFECT_HEALTH+1);
  m_weight = (rand() % (PERFECT_HEALTH+1)) + WEIGHT_MIN;
  kill();
  m_name = randomlyChooseName();
  return;
}

bool Patient::pay_out(const float amount)
{
  bool got_charged = false;
  if(m_money >= amount)
  {
    m_money -= amount;
    got_charged = true;
  }
  return got_charged;
}

void Patient::modify_health(const int conditionModifier)
{
  m_condition += conditionModifier;
  kill();
  return;
}

void Patient::modify_weight(const int conditionModifier)
{
  m_weight += conditionModifier;
  kill();
  return;
}

void Patient::modify_mental(const int conditionModifier)
{
  m_mental_health += conditionModifier;
  return;
}

void Patient::kill()
{
  if (m_condition == DEAD || m_weight == DEAD)
    m_isAlive = false;
  return;
}

string Patient::randomlyChooseName()
{
  ifstream fin;
  int numEntriesInFile;
  int randomLineNum;
  string name;

  fin.clear();  // reset connection
  fin.open(PATIENT_NAME_FILE);
  if (!fin)
    cout << "Cannot open " << PATIENT_NAME_FILE << "!\n";
  else
  {
    numEntriesInFile = count_el(fin);

	//resets file connection by closing and reopening the file
    fin.close();

    // Choose random number for a line # in file
    randomLineNum = (rand() % numEntriesInFile) + 1;

    // Re-open the file so we can go read that entry
    fin.clear();  // reset connection
    fin.open(PATIENT_NAME_FILE);
    if (!fin)
      cout << "Cannot open " << PATIENT_NAME_FILE << "!\n";
    else
    {
      name = rand_name(randomLineNum, fin);
      fin.close();
    }
  }
  return name;
}

void Patient::forgot_name()
{
  ifstream fin;
  int numEntriesInFile;
  int randomLineNum;
  string name;

  fin.clear();  // reset connection
  fin.open(PATIENT_NAME_FILE);
  if (!fin)
    cout << "Cannot open " << PATIENT_NAME_FILE << "!\n";
  else
  {
    numEntriesInFile = count_el(fin);

	//resets file connection by closing and reopening the file
    fin.close();

    // Choose random number for a line # in file
    randomLineNum = (rand() % numEntriesInFile) + 1;

    // Re-open the file so we can go read that entry
    fin.clear();  // reset connection
    fin.open(PATIENT_NAME_FILE);
    if (!fin)
      cout << "Cannot open " << PATIENT_NAME_FILE << "!\n";
    else
    {
      name = rand_name(randomLineNum, fin);
      fin.close();
    }
    m_name += name;
  }
  return;
}

ostream& operator << (ostream& o, const Patient& p)
{
  o << "Name: " << p.m_name << ", "
       << "Status: "
       << (p.m_isAlive? "alive" : "dead") << ", "
       << "Condition: " << p.m_condition << ", "
       << "Assets: $"<<p.m_money<<endl;
  return(o);
}

//----------------Non-member functions used with Patient class--------------//
string rand_name(const short num_names, ifstream& fin)
{
  string name;
  short counter = 1;      //Set to 1 because 1 name read before loop
  fin >> name;
  while(!fin.eof() && counter < num_names)   //Stops at end of file, at number
  {
    fin >> name;
    counter ++;
  }
  return name;
}

short count_el(ifstream& fin)
{
  short num_el = 0;
  string next;
  while(fin >> next)
  {
    num_el++;
  }
  return num_el;
}
