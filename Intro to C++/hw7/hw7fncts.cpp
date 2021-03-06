//Programmer: Peter Dolan     ID: 12410657
//Instructor: Price     Section: A      Date: 10/23/2014
//File: hw7fncts.cpp      Description: Zombism functions
#include "hw7.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void greeting()
{
  cout <<"=======  Welcome to Dr. Eloe's research study on Zombism!  ======="
       <<endl;
  return;
}

void read_in(int & people)
{
  do
  {
    cout <<"Enter the number of people in the test (1-5000):  ";
    cin >> people;
    if(people <= 0 || people >= 5001)
      cout <<"ERROR, that's not a valid entry"<<endl;
  }while(people <= 0 || people >= 5001);
  return;
}

void brains_research(person data_set[], float & brains, const int & people)
{
  short tally = 0;
  for(int i = 0; i < people; i++)
  {
    do
    {
      data_set[i].m_brains = ((RAND_MOD1 * rand() + RAND_MOD2) % RAND_BRAINS);
    }while(data_set[i].m_brains != 1 && data_set[i].m_brains != 0);
    if(data_set[i].m_brains == 1)
      tally++;
  }
  brains = (static_cast<float>(tally) / people) * 100;
  return;
}

void odor_research(person data_set[], float & odor, const int & people)
{
  short tally = 0;
  for(int i = 0; i < people; i++)
  {
    do
    {
      data_set[i].m_odor = ((RAND_MOD1 * rand() + RAND_MOD2) % RAND_ODOR);
    }while(data_set[i].m_odor != 1 && data_set[i].m_odor != 0 
    && data_set[i].m_odor != 2 && data_set[i].m_odor != 3);
    if(data_set[i].m_odor == 2 || data_set[i].m_odor == 3)
      tally++;
  }
  odor = (static_cast<float>(tally) / people) * 100;
  return;
}

void gait_research(person data_set[], float & gait, const int & people)
{
  short tally = 0;
  for(int i = 0; i < people; i++)
  {
    do
    {
      data_set[i].m_gait = ((RAND_MOD1 * rand() + RAND_MOD2) % RAND_GAIT);
    }while(data_set[i].m_gait != 1 && data_set[i].m_gait != 0 
    && data_set[i].m_gait != 2);
    if(data_set[i].m_gait == 1 || data_set[i].m_gait == 2)
      tally++;
  }
  gait = (static_cast<float>(tally) / people) * 100;
  return;
}

void gene_research(person data_set[], const int & people)
{
  short temp;
  for(int i = 0; i < people; i++)
  {
    for(int j = 0; j < GENE_LENGTH; j++)
    {
      temp = ((RAND_MOD1 * rand() + RAND_MOD2) % RAND_GENES);
      if(temp < 0)
        temp = temp * -1;

      if(temp >= GENE1_MIN && temp <= GENE1_MAX)
        data_set[i].m_genes[j] = GENE1;
      else if(temp >= GENE2_MIN && temp <= GENE2_MAX)
        data_set[i].m_genes[j] = GENE2;
      else if(temp >= GENE3_MIN && temp <= GENE3_MAX)
        data_set[i].m_genes[j] = GENE3;
      else if(temp >= GENE4_MIN && temp <= GENE4_MAX)
        data_set[i].m_genes[j] = GENE4;
    }
  }
  return;
}

void isZombie(person data_set[], float & physical, float & genetic, 
              float & zombie, const int & people)
{
  short physical_tally = 0;
  short genetic_tally = 0;
  short zombie_tally = 0;
  short is_zombie;
  short j;
  bool gene_test = false;
  
  for(int i = 0; i < people; i++)	//each person in array
  {
    is_zombie = 0;
    gene_test = false;
    j = -1;
    //testing for zombieism via physical stuff
    if(data_set[i].m_brains == 1)
      if(data_set[i].m_odor == 2 || data_set[i].m_odor == 3)
        if(data_set[i].m_gait == 1 || data_set[i].m_gait == 2)
          is_zombie++;			//tally one
    
    do				//testing for zomb via genes
    {
      j++;		//start at j=0
      if(data_set[i].m_genes[j] == GENE1)
        if(data_set[i].m_genes[j + 1] == GENE2)
          if(data_set[i].m_genes[j + 2] == GENE3)
            if(data_set[i].m_genes[j + 3] == GENE4)
            {
              is_zombie += 2;
              gene_test = true;
            }
    } while(j < (GENE_LENGTH - 4) && gene_test == false);
    switch (is_zombie)
    {
      case 1:
        physical_tally++;
        break;
      case 2:
        genetic_tally++;
        break;
      case 3:
        zombie_tally++;
        break;
     }
  }
  
  physical = (static_cast<float>(physical_tally) / people) * 100;
  genetic = (static_cast<float>(genetic_tally) / people) * 100;
  zombie = (static_cast<float>(zombie_tally) / people) * 100;
  return;
}
void results(const float & gait, const float & odor, const float & brains, 
             const float & physical, const float & genetic, const float & zombie, 
             const int & people)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint); 
  cout.precision(2);
  cout <<"Out of a total of "<<people<<" tested:"<<endl
       <<"     "<<brains<<"% want to eat brains."<<endl
       <<"     "<<odor<<"% have a slightly ripe or rotting stench smell."<<endl
       <<"     "<<gait<<"% do not walk normally."<<endl
       <<"     "<<physical<<"% qualify as zombies only by physical"
       <<" characteristics"<<endl
       <<"     "<<genetic<<"% qualify as zombies only by genetic"
       <<" characteristics"<<endl
       <<"     "<<zombie<<"% qualify by both the genetic tests and by"
       <<" physical characteristics."<<endl;
  return;
}

void signoff()
{
  cout <<"We hope you found this research study interesting."<<endl;
  return;
}
