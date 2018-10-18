//Programmer: Peter Dolan         ID: 12410657
//Instructor: Armita     Section: C      Date: 11/04//2014
//File: lab11.cpp       Description: Username generator
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
  int i = 0;
  char firstname[10];
  char lastname[10];
  char User_ID[20];
  ifstream fin;
  ofstream fout;
  fin.open("input.txt");
  fout.open("output.txt");

  while(fin>>firstname)
  {
    //Sends off the first and last name so I may alter them without issues
    fin>>lastname;
    fout<<firstname<<" "<<lastname;

    //this segment scans for any e's and replaces them
    i = 0;
    while(firstname[i] != '\0' && i < 10)
    {
      if(firstname[i] == 'e')
        firstname[i] = 'X';
      i++;
    }
    firstname[0] = (toupper(firstname[0]));
    
    //This segment assigns firstname to User_ID, then adds an underscore
    for(int j = 0; j < i; j++)
      User_ID[j] = firstname[j];
    User_ID[i] = '_';

    //This segment checks lastname for e's and capital letters
    i = 0;
    while(lastname[i] != '\0' && i < 10)
    {
      if(lastname[i] == 'e')
        lastname[i] = 'X';
      i++;
    }
    lastname[0] = (toupper(lastname[0]));
    strcat(User_ID, lastname);
    fout<<" "<<User_ID<<"  "<<endl;
    for(int j = 0; j < 20; j++)
      User_ID[j] = '\0';
  }
  
  fin.close();
  fout.close();
    
  return 0;
}
