//Programmer: Peter Dolan     ID: 12410657
//Instructor: Price     Section: A      Date: 10/23/2014
//File: hw7.cpp      Description: Zombism calculator
#include "hw7.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  srand(time(NULL));
  person data_set[5000];
  int people;
  float brains, odor, gait, physical, genetic, zombie;
  greeting();
  read_in(people);
  brains_research(data_set, brains, people);
  odor_research(data_set, odor, people);
  gait_research(data_set, gait, people);
  gene_research(data_set, people);
  isZombie(data_set, physical, genetic, zombie, people);
  results(gait, odor, brains, physical, genetic, zombie, people);
  signoff();
  return 0;
}
