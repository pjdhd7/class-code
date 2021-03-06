//Programmer: Peter Dolan       ID: 12410657
//Instructor: Armita     Section: C     Date: 10/21/2014
//File: lab9fncts.cpp        Description: Grade sorting
#include "lab9.h"
#include <iostream>
#include <string>
using namespace std;

void read_in(student students[], const int size)
{
  for(int i = 0; i < size; i++)
  {
    cout<<"Enter a name:  ";
    cin>>students[i].name;
    for(int j = 0; j < 3; j++)
    {
      cout<<"Enter the grade for course #"<<j + 1<<":  ";
      cin>>students[i].grades[j];
    }
    cout<<endl;
  }
  return;
}

int max_index(student students[], const int size, const int course_number)
{
  short return_value, temp_max = 0;
   for(int i = 0; i < size; i++)
     if(students[i].grades[course_number] > temp_max)
     {
       temp_max = students[i].grades[course_number];
       return_value = i;
     }
    
  return return_value;
}

int min_index(student students[], const int size, const int course_number)
{
  short return_value, temp_max = 101;
  for(int i = 0; i < size; i++)
    if(students[i].grades[course_number] < temp_max)
    {
      temp_max = students[i].grades[course_number];
      return_value = i;
    }
  return return_value;
}
