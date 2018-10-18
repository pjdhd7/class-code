//Programmer: Peter Dolan        ID: 12410657
//Instructor: Price    Section: A       Date: 11/07/2014
//File: hw8fncts.cpp        Description: Functions for Health-o-matic
#include "hw8.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>
using namespace std;

void countWords(const char complaint[], int &wordCount)
{
  string temp;
  istringstream iss(complaint);
  while(iss >> temp)
    wordCount++;
  return;
}

//repeats words at the patient, expecting them to believe we know what we're
//doing and that they can put their lives in our clueless hands
void repeat(const char complaint[], const int &wordCount)
{
  const int PROBABILITY = 4;
  int chance, count = 0;
  char temp[31];
  istringstream iss(complaint);
  cout <<endl<<" So, ";
  while(iss >> temp)
  {
    count++;
    do
    {
      chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
    }while(chance < 1 || chance > 3);
    
    if(chance == 1)
	{
      cout <<temp;
      if(count < wordCount)
        cout <<", ";
    }
	if(count == wordCount)
	  cout <<"? ";
    for(int i = 0; i < 31; i++)
	  temp[i] = '\0';
  }
  return;
}

//Using a switch-case statement in main, this generates an int to be used in
//main for calling particular individual functions
void prognosis(const char complaint[], int &case_diagnosis)
{
  string temp;
  int keyword_count = 0;
  istringstream iss(complaint);
  while(iss >> temp)
  {
    if(temp == "leg" || temp == "Leg" || temp == "Leg." || temp == "leg."
       || temp == "leg?" || temp == "Leg?" || temp == "legs" || 
       temp == "Legs" || temp == "Legs." || temp == "legs." || 
       temp == "legs?" || temp == "Legs?")
    {
      case_diagnosis = 1;
      keyword_count++;
    }
    else if(temp == "head" || temp == "Head" || temp == "head."  || temp ==
    "Head." || temp == "head?" || temp == "Head?")
    {
      case_diagnosis = 2;
      keyword_count++;
    }
    else if(temp == "hand" || temp == "Hand" || temp == "hand."  || temp ==
            "Hand." || temp == "hand?" || temp == "Hand?" ||temp == "hands" 
            || temp == "Hands" || temp == "hands."  || temp == "Hands." || 
            temp == "hands?" || temp == "Hands?")
    {
      case_diagnosis = 3;
      keyword_count++;
    }
    else if(temp == "torso" || temp == "Torso" || temp == "torso." 
            || temp == "Torso." || temp == "torso?" || 
            temp == "Torso?")
    {
      case_diagnosis = 4;
      keyword_count++;
    }
    else if(temp == "nose" || temp == "Nose" || temp == "nose."  ||
            temp == "Nose." || temp == "nose?" || temp == "Nose?")
    {
      case_diagnosis = 5;
      keyword_count++;
    }
  }
    
  if(keyword_count != 1)
    case_diagnosis = 0;
  return;
}

//The next few functions individually connect and disconnect to files
//To grab random diagnoses
void legs_diagnosis(char diagnosis[])
{
  const int PROBABILITY = 11;
  int chance;
  ifstream leg;
  leg.open("Leg.dat");
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
  }while(chance < 1 || chance > 10);
  
  for(int i = 0; i <= chance; i++)
  {
    leg.getline(diagnosis, DIAGNOSIS_ARRAY, '\n');
    if(i < chance)
      for(int j = 0; j < DIAGNOSIS_ARRAY; j++)
        diagnosis[j] = '\0';
  }
  leg.close();
  return;
}

void head_diagnosis(char diagnosis[])
{
  const int PROBABILITY = 11;
  int chance;
  ifstream head;
  head.open("Head.dat");
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
  }while(chance < 1 || chance > 10);
  
  for(int i = 0; i <= chance; i++)
  {
    head.getline(diagnosis, DIAGNOSIS_ARRAY, '\n');
    if(i < chance)
      for(int j = 0; j < DIAGNOSIS_ARRAY; j++)
        diagnosis[j] = '\0';
  }
  head.close();
  return;
}

void hands_diagnosis(char diagnosis[])
{
  const int PROBABILITY = 11;
  int chance;
  ifstream hands;
  hands.open("Hands.dat");
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
  }while(chance < 1 || chance > 10);
  
  for(int i = 0; i <= chance; i++)
  {
    hands.getline(diagnosis, DIAGNOSIS_ARRAY, '\n');
    if(i < chance)
      for(int j = 0; j < DIAGNOSIS_ARRAY; j++)
        diagnosis[j] = '\0';
  }
  hands.close();
  return;
}

void torso_diagnosis(char diagnosis[])
{
  const int PROBABILITY = 11;
  int chance;
  ifstream torso;
  torso.open("Torso.dat");
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
  }while(chance < 1 || chance > 10);
  
  for(int i = 0; i <= chance; i++)
  {
    torso.getline(diagnosis, DIAGNOSIS_ARRAY, '\n');
    if(i < chance)
      for(int j = 0; j < DIAGNOSIS_ARRAY; j++)
        diagnosis[j] = '\0';
  }
  torso.close();
  return;
}

void nose_diagnosis(char diagnosis[])
{
  const int PROBABILITY = 9;
  int chance;
  ifstream nose;
  nose.open("Nose.dat");
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % PROBABILITY;
  }while(chance < 1 || chance > 8);
  
  for(int i = 0; i <= chance; i++)
  {
    nose.getline(diagnosis, DIAGNOSIS_ARRAY, '\n');
    if(i < chance)
      for(int j = 0; j < DIAGNOSIS_ARRAY; j++)
        diagnosis[j] = '\0';
  }
  nose.close();
  return;
}

//Connects to scripts and surgeries so the patient can waste their money
void prescription(char pill[], char surgery[], bool &needs_surgery)
{
  int count = 0;
  int chance = 0;
  char temp[15];
  const int PROBABILITY_PILLS = 38;
  const int PROBABILITY_SURGERY = 16;
  ifstream pill_stream, surgery_stream;
  pill_stream.open("Scripts.dat");
  surgery_stream.open("Surgeries.dat");
  
  while(count <= MAX_SYLLABLES)
  {
    do
    {
      chance = (MOD_1 * rand() + MOD_2) % PROBABILITY_PILLS;
    }while(chance < 1 || chance > 37);
    
    for(int i = 0; i <= chance; i++)
    {
      pill_stream >> temp;
      if(i < chance)
        for(int j = 0; j < 15; j++)
          temp[j] = '\0';
    }
	strcat(pill, temp);
	pill_stream.clear();
	pill_stream.seekg(0);
	count++;
  }
  do
  {
    chance = (MOD_1 * rand() + MOD_2) % 5;
  }while(chance < 1 || chance > 4);
  
  switch (chance)
  {
    case 1:
      needs_surgery = false;
      break;
    default:
      needs_surgery = true;
      break;
  }
  if(needs_surgery == true)
  {
    do
    {
      chance = (MOD_1 * rand() + MOD_2) % PROBABILITY_SURGERY;
    }while(chance < 1 || chance > 15);
  
    for(int i = 0; i <= chance; i++)
    {
      surgery_stream.getline(surgery, PILL_ARRAY, '\n');
      if(i < chance)
        for(int j = 0; j < PILL_ARRAY; j++)
          surgery[j] = '\0';
    }
  }
  pill_stream.close();
  surgery_stream.close();
  return;
}