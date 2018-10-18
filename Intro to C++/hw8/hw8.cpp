//Programmer: Peter Dolan        ID: 12410657
//Instructor: Price    Section: A       Date: 11/07/2014
//File: hw8.cpp        Description: Main function for Health-o-matic
#include "hw8.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
  srand(time(NULL));
  int wordCount = 0;
  int case_diagnosis = 0;
  bool quit = false;
  bool needs_surgery = false;
  char yes_or_no;
  char complaint[LARGE_ARRAY];
  char diagnosis[DIAGNOSIS_ARRAY];
  char pill[PILL_ARRAY];
  char surgery[PILL_ARRAY];
  
  cout <<"---------WELCOME TO DR. ELOE'S HEALTH-O-MATIC---------"<<endl;
  while(!quit)
  {
    needs_surgery = false;
    //This do-while is essentially an anti-stupid loop, assuming someone
    //just hit enter without actually typing anything
    do
    {
      cout <<"What brings you to my world-class facility today?  "<<endl;
      cin.getline(complaint, 21000, '\n');
      countWords(complaint, wordCount);
      if(wordCount <= 0)
      {
        cout <<" You know, you need to tell me what's wrong with you, so I "
             <<"can tell you what's wrong with you. Let's try again."<<endl;
      }  
    }while(wordCount <= 0);

    repeat(complaint, wordCount);
    prognosis(complaint, case_diagnosis);
	
//This switch case receives the 'case_diagnosis' variable, then redirects
//The program to a specific function, depending on the identified region
//For unknown reasons, the cout statements here will output a period instead
//Of the first character in the line. I just put a space in front to avoid
//missing characters
    switch (case_diagnosis)
    {
      case 1:
        legs_diagnosis(diagnosis);
		cout <<"It is clear that you have "<<diagnosis<<"."<<endl;
        break;
      case 2:
        head_diagnosis(diagnosis);
		cout <<"It is clear that you have "<<diagnosis<<"."<<endl;
        break;
      case 3:
        hands_diagnosis(diagnosis);
		cout <<"It is clear that you have "<<diagnosis<<"."<<endl;
        break;
      case 4:
        torso_diagnosis(diagnosis);
		cout <<"It is clear that you have "<<diagnosis<<"."<<endl;
        break;
      case 5:
        nose_diagnosis(diagnosis);
		cout <<"It is clear that you have "<<diagnosis<<"."<<endl;
        break;
      default:
        cout<<"There is clearly nothing wrong with you. Take two "
            <<"aspirin and get some sleep."<<endl;
    }
    
    prescription(pill, surgery, needs_surgery);
	
//For unknown reasons, the cout statement here will output a period instead
//Of the first character in the line. I just put a space in front to avoid 
//missing characters
	cout <<" I am going to prescribe that you take "<<wordCount<<" pills per"
	     <<" day of 20 mg "<<pill<<"."<<endl;
    if(needs_surgery == true)
    {
      cout <<" I would also recommend that you undergo a "<<surgery<<"."<<endl
	       <<endl;
    }
    
//Do-while for resetting the program or exiting the program
	do
    {
      cout<<"Would you like to quit?(y/n)  ";
      cin>> yes_or_no;
      if(yes_or_no == 'y')
        quit = true;
	  else if(yes_or_no == 'n')
	  {
	    quit = false;
		for(int i = 0; i < LARGE_ARRAY; i++)
		  complaint[i] = '\0';
		for(int i = 0; i < DIAGNOSIS_ARRAY; i++)
		  diagnosis[i] = '\0';
		for(int i = 0; i < PILL_ARRAY; i++)
		{
		  pill[i] = '\0';
		  surgery[i] = '\0';
		}
		wordCount = 0;
		cout <<endl;
	  }
      else
        cout<<" INVALID ENTRY"<<endl;
	  cin.ignore(15, '\n');
    }while(yes_or_no != 'y' && yes_or_no != 'n');
  }
  
  cout<<endl<<"Thank you and have a good day!"<<endl;
  return 0;
}