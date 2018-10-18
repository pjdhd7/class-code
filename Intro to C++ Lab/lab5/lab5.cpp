//Programmer: Peter Dolan      ID: 12410657
//Instructor Name: Armita    Section: C     Date 09/23/2014
//File: lab5.cpp      Description: E-voting 
#include <iostream>
using namespace std;
int main ()
{
  const short TOTAL_VOTES = 10;
  short Apple_Vote = 0;
  short Lenovo_Vote = 0;
  short Dell_Vote = 0;
  short HP_Vote = 0;
  short Wasted_Vote = 0;
  short Votes_Cast = 0;
  float Apple_Percent;
  float Lenovo_Percent;
  float Dell_Percent;
  float HP_Percent;
  float Wasted_Percent;
  char Vote;
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);                                                        
  cout.precision(2); 
  
  cout << "---Welcome to the E-Voting system---" <<endl <<endl;
  cout << "Here are Laptop brands:" <<endl;
  cout << "A: Apple" <<endl;
  cout << "B: Lenovo" <<endl;
  cout << "C: Dell" <<endl;
  cout << "D: HP" <<endl <<endl;
  do
  {
    cout << "What Brand of Laptop do you vote for:  ";
    cin >> Vote;
    
    ++Votes_Cast;
    
    switch (Vote)
    {
      case 'a':
      case 'A':
        ++Apple_Vote;
        cout << "You voted for Apple"<<endl;
        break;
      case 'b':
      case 'B':
        ++Lenovo_Vote;
        cout <<"You voted for Lenovo"<<endl;
        break;
      case 'c':
      case 'C':
        ++Dell_Vote;
        cout <<"You voted for Dell"<<endl;
        break;
      case 'd':
      case 'D':
        ++HP_Vote;
        cout <<"You voted for HP"<<endl;
        break;
      default:
        ++Wasted_Vote;
        cout <<"You wasted your vote"<<endl;
        break;
    }
  }while (Votes_Cast < TOTAL_VOTES); 
  
  Apple_Percent = static_cast<float>(Apple_Vote) / TOTAL_VOTES;
  Lenovo_Percent = static_cast<float>(Lenovo_Vote) / TOTAL_VOTES;
  Dell_Percent = static_cast<float>(Dell_Vote) / TOTAL_VOTES;
  HP_Percent = static_cast<float>(HP_Vote) / TOTAL_VOTES;
  Wasted_Percent = static_cast<float>(Wasted_Vote) / TOTAL_VOTES;
  
  cout << "~-~Here's the voting summary~-~"<<endl<<endl;
  cout << "Laptops         Votes    Percentage (%)"<<endl;
  cout << "Apple             "<<Apple_Vote<<"      "<<Apple_Percent<<endl;
  cout << "Lenovo            "<<Lenovo_Vote<<"      "<<Lenovo_Percent<<endl;
  cout << "Dell              "<<Dell_Vote<<"      "<<Dell_Percent<<endl;
  cout << "HP                "<<HP_Vote<<"      "<<HP_Percent<<endl;
  cout << "Wasted Votes      "<<Wasted_Vote<<"      "<<Wasted_Percent<<endl<<endl;
  cout << "Thank you for using th E-voting system"<<endl;
  cout << "Have a Nice Day!";
  
  return 0;
}
