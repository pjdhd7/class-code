//Programmer: Peter Dolan     ID: 12410657
//Instructor: Price     Section: A      Date: 10/23/2014
//File: hw7.h      Description: Zombism header
#ifndef HW7_H
#define HW7_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//struct that will be used for the people in the study
struct person
{
  char m_genes[128];
  short m_odor;
  bool m_brains;
  short m_gait;
};

//Constants, whether for random number generation or ensuring that the gene
//distribution is accurate
const short RAND_BRAINS = 2;
const short RAND_ODOR = 4;
const short RAND_GAIT = 3;
const short RAND_GENES = 101;
const short RAND_MOD1 = 27;
const short RAND_MOD2 = 62;
const short GENE_LENGTH = 128;
const short GENE1 = 'G';
const short GENE2 = 'T';
const short GENE3 = 'A';
const short GENE4 = 'C';
const short GENE1_MIN = 1;
const short GENE1_MAX = 30;
const short GENE2_MIN = 31;
const short GENE2_MAX = 53;
const short GENE3_MIN = 54;
const short GENE3_MAX = 80;
const short GENE4_MIN = 81;
const short GENE4_MAX = 100;

//Description: Outputs a greeting
//Pre-condition: N/A
//Post-condition: Outputs a greeting to the screen
void greeting();

//Description: Asks how many people are to be generated
//Pre-condition: A integer variable
//Post-condition: Alters an integer variable
void read_in(int & people);

//Description: Generates the desire for brains data for research
//Pre-condition: A person struct array, a float variable, and the number 
//               of people
//Post-condition: Alters an float variable
void brains_research(person data_set[], float & brains, const int & people);

//Description: Generates the body odor data for research
//Pre-condition: A person struct array, a float variable, and the number 
//               of people
//Post-condition: Alters an float variable
void odor_research(person data_set[], float & odor, const int & people);

//Description: Generates the gait data for research
//Pre-condition: A person struct array, a float variable, and the number 
//               of people
//Post-condition: Alters an float variable
void gait_research(person data_set[], float & gait, const int & people);

//Description: Generates the Genetic sequence data for research
//Pre-condition: A person struct array, a float variable, the gene length,
//                the number of people, and parameters for each gene
//Post-condition: Alters the character arrays in each struct and alters a float
//                variable
void gene_research(person data_set[], const int & people);

//Description: Determines which people have physical, genetic, or both 
//             indicators of zombism
//Pre-condition: A person struct array, number of people, and three float 
//               variables
//Post-condition: Alters three float variables
void isZombie(person data_set[], float & physical, float & genetic, 
float & zombie, const int & people);

//Description: Displays the research results 
//Pre-condition: Seven float variables and one integer variable
//Post-condition: Outputs a message to the screen
void results(const float & gait, const float & odor, const float & brains, 
const float & physical, const float & genetic, const float & zombie, 
const int & people);

//Description: Outputs a signoff
//Pre-condition: N/A
//Post-condition: Displays a signoff message on the screen
void signoff();

#endif
