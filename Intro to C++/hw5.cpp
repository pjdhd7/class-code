//Programmer: Peter Dolan    Student ID: 12410657
//Instructor: Price     Section: A      Date: 10/02/2014      
//File hw5.cpp       Description: Health Calculator
#include <iostream>
using namespace std;

//prototype of the functions
void greeting();
float bodyMassIndex(int wt, int ht);
float creatinineClearance(int age, int wt, float creatineValue);
short coronaryRisk(float BMI, bool heartDisease, short baconPounds);
float totterIndex(float leftLeg, float rightLeg);
void goodbye();

int main()
{
  //Declaring the variables
  int wt;
  int ht;
  int age;
  short baconPounds;
  short menuChoice;
  float creatineValue;
  float BMI;
  float leftLeg;
  float rightLeg;
  char yesOrNo;
  bool heartDisease;
  bool quit = false;
  
  greeting();
  do
  {
    cout <<"    Eloe's Health-o-Matic"<<endl<<endl;
    cout <<"  1. Body Mass Index (BMI)"<<endl;
    cout <<"  2. Creatinine Clearance (CC)"<<endl;
    cout <<"  3. Coronary Risk (CR)"<<endl;
    cout <<"  4. Totter Index (TI)"<<endl;
    cout <<"  5. Quit"<<endl;
    cout <<"What would you like to do, Dr. Eloe? (type an integer):  ";
    cin >> menuChoice;
    cout <<endl<<endl;
    
    switch (menuChoice)
    {
      case 1:
        cout <<"Type the Patient's mass (in pounds):  "
        cin >> wt;
        cout <<"Type the Pateint's height (in inches):  "
        cin >> ht;
        cout <<"The Body Mass Index is "<< bodyMassIndex(wt, ht)<<endl<<endl;
        break;
      case 2:
        cout <<"What is the patient's age:  ";
        cin >> age;
        cout <<"What is the patient's weight (in kilograms):  ";
        cin >> wt;
        cout <<"What is the patient's Serum Creatine value:  ";
        cin >> creatineValue;
        cout <<"The Creatinine Clearance is ";
        cout << creatinineClearance(age, wt, creatineValue)<<endl<<endl;
        break;
      case 3:
        cout <<"What is the patient's BMI:  ";
        cin >> BMI;
        cout <<"Does either of the patient's parents have"; 
        cout <<" heart disease (y/n):  ";
        cin >> yesOrNo;
        if (yesOrNo = y)
          heartDisease = true;
        else if (yesOrNo = n)
          heartDisease = false;
        cout <<"How many pounds of bacon did the patient have";
        cout <<" for breakfast:  ";
        cin >> baconPounds;
        cout <<"The patient's Coronary Risk is ";
        cout << coronaryRisk(BMI, heartDisease, baconPounds)<<endl<<endl;
        break;
      case 4:
        cout <<"What is the length of the patient's left leg:  ";
        cin >> leftLeg;
        cout <<"What is the length of the patient's right leg:  ";
        cin >> rightLeg;
        cout <<"The patient's Totter Index is ";
        cout << totterIndex(leftLeg, rightLeg)<<endl<<endl;
        break;
      case 5:
        goodbye();
        break;
      default:
        cout <<"That is not a valid option, please try again"<<endl<<endl;
        break;
    }
  }while(!quit)
  return 0;
}

float bodyMassIndex(int wt, int ht)
{
  float BMI;
  BMI = (wt / (ht * ht)) * 703;
  return BMI;
}

float creatinineClearance(int age, int wt, float creatineValue)
{
  float Creatinine;
  Creatinine = (140 - age) * wt / 72 * creatineValue;
  return Creatinine;
}

short coronaryRisk(float BMI, bool heartDisease, short baconPounds)
{
  short BMI_parent_risk = 0;
  short coronaryRisk;
  
  if(BMI > 30)
    BMI_parent_risk = BMI_parent_risk + 2;
  if(heartDisease = true)
    BMI_parent_risk++;
  
  coronaryRisk = BMI_parent_risk + baconPounds;
  return coronaryRisk;
}

float totterIndex(float leftLeg, float rightLeg)
{
  float Index;
  Index = leftLeg / rightLeg;
  return Index;
}

void goodbye()
{
  cout <<"You have chosen to quit. Good bye!"<<endl;
  return;
}