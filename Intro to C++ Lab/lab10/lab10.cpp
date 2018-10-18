//Programmer: Peter Dolan      ID: 12410657
//Instructor: Armita      Section: C      Date: 10/28/2014
//File: lab10.cpp      Description: email signup
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct account
{
  char m_first_name[16];
  char m_last_name[16];
  char m_username[16];
  char m_password[16];
};

//Description: Outputs a greeting message
//Pre-condition: N/A
//Post-condition: Displays a message on the screen
void greeting();

//Description: Gets information for an account struct
//Pre-condition: An account struct
//Post-condition: Alters the values of the account struct
void read_in(account & user);

//Description: Prints the information for a user's account 
//Pre-condition: An account struct that has been assigned values
//Post-condition: Outputs a message to the screen
void print_out(account & user);

//Description: Prints asterisks (*) as if they were a password
//Pre-condition: A character array with assigned values
//Post-condition: Outputs a message to the screen
void printPassword(char password[]);

//Description: Outputs a farewell message to the screen
//Pre-condition: N/A
//Post-condition: Outputs a message to the screen
void signoff();

int main()
{
  account user;
  
  greeting();
  read_in(user);
  print_out(user);
  printPassword(user.m_password);
  signoff();
  return 0;
}

void greeting()
{
  cout <<"Welcome! Please enter your information to sign up"<<endl;
  return;
}

void read_in(account & user)
{
  char temp[15];
  short count = 0;
  int exit = 5;
  short length = 0;
  cout <<"Enter your First Name:  ";
  cin.getline(user.m_first_name, 15, '\n');
  
  cout <<"Enter your Last Name:  ";
  cin.getline(user.m_last_name, 15,'\n');
  
  count = strlen(user.m_last_name);
  for(int i = 0; i < count + 1; i++)
    user.m_username[i] = user.m_last_name[i];
    
  strcat(user.m_username, user.m_first_name);

  while(exit != 0)
  {
    cout<<"Enter your Password:  ";
    cin.getline(user.m_password, 15, '\n');
    length = strlen(user.m_password);
    if(length >= 7)
    {
      cout <<"Confirm your Password:  ";
      cin.getline(temp, 15, '\n');
      exit = strcmp(temp, user.m_password);
    }
  }  
  return;
}

void print_out(account & user)
{
  cout <<"*********************************************"<<endl
       <<"Account Information Summary:"<<endl<<endl
       <<"First Name:   "<<user.m_first_name<<endl
       <<"Last Name:    "<<user.m_last_name<<endl
       <<"Username:     "<<user.m_username<<endl;
  return;
}

void printPassword(char password[])
{
  short count = 0;
  cout <<"Password:     ";
  while(password[count] != '\0')
  {
    cout <<"*";
    count++;
  }
  cout <<endl;
  return;
}

void signoff()
{
  cout <<"Thanks!"<<endl;
  return;
}
