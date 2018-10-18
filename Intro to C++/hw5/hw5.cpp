//Programmer: Peter Dolan    Student ID: 12410657
//Instructor: Price     Section: A      Date: 10/02/2014      
//File hw5.cpp       Description: Health Calculator
#include <iostream>
using namespace std;

//Description: Outputs a greeting when the program is initially run
//Pre-Condition: None
//Post-Condition: Outputs a greeting
void greeting();

//Description: Calculates BMI
//Pre-condition: Two positive whole numbers
//Post-condition: Returns the BMI
float bodyMassIndex(int wt, int ht);

//Description: Calculates the Creatinine Clearance
//Pre-condition: Three Positive numbers
//Post-condition: Returns the value of the Creatinine Clearance
float creatinineClearance(int age, int wt, float creatineValue);

//Description: Calculates the Coronary Risk
//Pre-condition: Two positive numbers and a true or false response
//Post-condition: Returns the Coronary Risk
short coronaryRisk(float BMI, bool heartDisease, short baconPounds);

//Description: Calculates the Totter Index
//Pre-condition: Two positive numbers
//Post-condition: Returns the Totter Index
float totterIndex(float leftLeg, float rightLeg);

//Description: Outputs a sign-off message
//Pre-condition: None
//Post-condition: Outputs a sign-off message
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
  
  //Greeting
  greeting();
  
  //The main menu
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
    
    //Switch case to the provided options
    switch (menuChoice)
    {
      case 1:
        do
	{
	  cout <<"Type the Patient's mass (in pounds):  ";
          cin >> wt;
	  if(wt < 0)
	    cout <<"That's not valid, try again"<<endl;
        }while(wt < 0);
	do
	{
	  cout <<"Type the Pateint's height (in inches):  ";
          cin >> ht;
	  if(ht < 0)
	    cout <<"That's not valid, try again"<<endl;
	}while(ht < 0);  
          cout <<"The Body Mass Index is "<< bodyMassIndex(wt, ht)<<endl<<endl;
          break;
      case 2:
        do
	{
	  cout <<"What is the patient's age:  ";
          cin >> age;
	  if(age < 0)
	    cout <<"That's not valid, try again"<<endl;
	}while(age < 0);
	do
	{
          cout <<"What is the patient's weight (in kilograms):  ";
          cin >> wt;
	  if(wt < 0)
	    cout <<"That's not valid, try again"<<endl;
        }while(ht < 0);
	do
	{
          cout <<"What is the patient's Serum Creatine value:  ";
          cin >> creatineValue;
	  if(creatineValue < 0)
	    cout <<"That's not valid, try again"<<endl;
        }while(creatineValue < 0);
        cout <<"The Creatinine Clearance is ";
        cout << creatinineClearance(age, wt, creatineValue)<<endl<<endl;
        break;
      case 3:
        do
        {
          cout <<"What is the patient's BMI:  ";
          cin >> BMI;
          if(BMI < 0)
            cout <<"That's not valid, try again"<<endl;
        }while(BMI < 0);
        do
        {
          cout <<"Does either of the patient's parents have"; 
          cout <<" heart disease (y/n):  ";
          cin >> yesOrNo;
          if(yesOrNo != 'y' && yesOrNo != 'n')
            cout <<"That's not valid, try again"<<endl;
        }while(yesOrNo != 'y' && yesOrNo != 'n');
        if (yesOrNo == 'y' )
          heartDisease = true;
        else if (yesOrNo == 'n' )
          heartDisease = false;
        do
        {  
          cout <<"How many pounds of bacon did the patient have";
          cout <<" for breakfast:  ";
          cin >> baconPounds;
          if(baconPounds < 0)
            cout <<"That's not valid, try again"<<endl;
        }while(baconPounds < 0);
        cout <<"The patient's Coronary Risk is ";
        cout << coronaryRisk(BMI, heartDisease, baconPounds)<<endl<<endl;
        break;
      case 4:
        do
        {
          cout <<"What is the length of the patient's left leg:  ";
          cin >> leftLeg;
          if(leftLeg < 0)
            cout <<"That's not valid, try again"<<endl;
        }while(leftLeg < 0);
        do
        {
          cout <<"What is the length of the patient's right leg:  ";
          cin >> rightLeg;
          if(rightLeg < 0)
            cout <<"That's not valid, try again"<<endl;
        }while(rightLeg < 0);
        cout <<"The patient's Totter Index is ";
        cout << totterIndex(leftLeg, rightLeg)<<endl<<endl;
        break;
      case 5:
        goodbye();
        quit = true;
        break;
      default:
        cout <<"That is not a valid option, please try again"<<endl<<endl;
        break;
    }
  }while(!quit);
  return 0;
}

//the Greeting function
void greeting()
{
  cout <<"---------WELCOME---------"<<endl;
  cout <<"Let's see how healthy your patient is!"<<endl;
  return;
}

//The BMI function
float bodyMassIndex(const int wt, const int ht)
{
  return (static_cast<float>(wt) / (ht * ht)) * 703;
}

//The CC function
float creatinineClearance(const int age, const int wt, const float creatineValue)
{
  return (140 - age) * static_cast<float>(wt) / 72 * creatineValue;
}

//The Cornary Risk function
short coronaryRisk(const float BMI, const bool heartDisease, const short baconPounds)
{
  short BMIandParentRisk = 0;
  
  if(BMI > 30)
    BMIandParentRisk = BMIandParentRisk + 2;
  if(heartDisease == true )
    BMIandParentRisk++;
  
  return BMIandParentRisk + baconPounds;
}

//The Totter Index function
float totterIndex(const float leftLeg, const float rightLeg)
{
  float Index = 0;
  if (leftLeg == 0 || rightLeg == 0)
    Index = 0;
  else  
    Index = leftLeg / rightLeg;
  return Index;
}

//The goodbye function
void goodbye()
{
  cout <<"You have chosen to quit. Good bye!"<<endl;
  return;
}
