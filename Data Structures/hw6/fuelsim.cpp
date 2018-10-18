//Name: Peter Dolan   ID: 12410657
//Instructor: Morales    Section: A    Date: 04/25/2015
//File: fuelsim.cpp    Desc: Main File for gas station sim

#include "llqueue.h"
#include <sstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
	LLQueue<Ship>* A = new LLQueue<Ship>;
	LLQueue<Ship>* B = new LLQueue<Ship>;
	LLQueue<Ship>* C = new LLQueue<Ship>;
	LLQueue<Ship>* Order = new LLQueue<Ship>;
	LLQueue<Ship>* Filled = new LLQueue<Ship>;
	int time_elapsed = 0;
	int ship_count = 0;
	int time_here;
	int fuel_needed;
	string input = "\0";
	string temp = "\0";

    //Getting the data for the ships to be used
	cin >> ship_count;
	for (int i = 0; i < ship_count; i++)
	{
		input = temp = "\0";
		cin >> input;
		istringstream iss(input.c_str());
		iss >> temp;
		time_here = atoi(temp.c_str());
		iss >> input;
		iss >> temp;
		fuel_needed = atoi(temp.c_str());
		Order->enqueue(fuel_needed, input, time_here);
	}
	
	//The Brute-Force method of simulating a gas station
	while(Filled -> count_ships() != ship_count)
	{
	   //the increment of time
	   time_elapsed++;
	   A -> waiting();
	   B -> waiting();
	   C -> waiting();
	   
	   
	   /*Adding fuel to each of the ships at the front of the queues by
	   checking if there is anyone there and then referencing off of a 
	   member variable to see if they have waited long enough to get a
	   fuel unit added*/
	   if(A -> m_next != NULL)
	     A ->m_next ->m_data.addFuel();
	   if (B->m_next != NULL)
	     B ->m_next ->m_data.addFuel();
	   if (C->m_next != NULL)
	     C ->m_next ->m_data.addFuel();
	   
	   /*checking if we should move a ship into any of the queues*/
	   while(time_elapsed == Order -> m_data.getTime())
	   {
	     if(A -> count_ships() <= B -> count_ships() &&
	        A -> count_ships() <= C -> count_ships())
	     {
			 cout << "At time "<<time_elapsed<<Order->m_next->m_data.getName()
	            <<" joins Port A."<<endl;
	       A -> enqueue(Order -> front());
	       Order -> dequeue();
	     }
	     else if(B -> count_ships() <= A -> count_ships() &&
	             B -> count_ships() <= C -> count_ships())
	     {
			 cout << "At time "<<time_elapsed<<Order->m_next->m_data.getName()
	            <<" joins Port B."<<endl;
	       B -> enqueue(Order -> front());
	       Order -> dequeue();
	     }
	     else if(C -> count_ships() <= A -> count_ships() &&
	             C -> count_ships() <= B -> count_ships())
	     {
			 cout << "At time "<<time_elapsed<<Order->m_next->m_data.getName()
	            <<" joins Port C."<<endl;
	       C -> enqueue(Order -> front());
	       Order -> dequeue();
	     }
	   }
	   
	   /*Checking if a ship is filled up in Line A*/
	   if(A -> m_next -> m_data.getFuel() == 0)
	   {
		   cout << "At time " << time_elapsed << A->m_next->m_data.getName()
	          <<" is done fueling."<<endl;
	     Filled -> enqueue(A->front());
	     A -> dequeue();
	   }
	   
	   /*Checking if a ship is filled up in Line B*/
	   if(B -> m_next -> m_data.getFuel() == 0)
	   {
		   cout << "At time " << time_elapsed << B->m_next->m_data.getName()
	          <<" is done fueling."<<endl;
	     Filled -> enqueue(A->front());
	     B -> dequeue();
	   }
	   
	   /*Checking if a ship is filled up in Line C*/
	   if(C -> m_next -> m_data.getFuel() == 0)
	   {
		   cout << "At time " << time_elapsed << C->m_next->m_data.getName()
	          <<" is done fueling."<<endl;
	     Filled -> enqueue(A->front());
	     C -> dequeue();
	   }
	}
	//Clears the Port queues so I can reuse them for the final task
	A-> clear();
	delete A;
    B-> clear();
	delete B;
    C-> clear();
	delete C;

    //Checking which ship waited the longest
    B = Filled -> m_next;
	A = Filled->m_next->m_next;
	while(A != Filled -> m_next)
	{
	  if(A -> m_data.getWait() > B -> m_data.getWait())
	    B = A;
	}
	
	//Checking which ship waited the shortest
	C = Filled -> m_next;
	A = Filled->m_next->m_next;
	while(A != Filled -> m_next)
	{
	  if(A -> m_data.getWait() < C -> m_data.getWait())
	    C = A;
	}
	
	//Outputting the results of the last 15 lines of code
	cout << endl <<"Longest wait: "<<B -> m_data.getName() <<", "
	     << B->m_data.getWait() <<" mins."<<endl;
	     
	cout << endl <<"Shortest wait: "<<C -> m_data.getName() <<", "
	     << C->m_data.getWait() <<" mins."<<endl;
	  
	
	//De-allocates the remaining LLQueues
    Order-> clear();
    Filled-> clear();
	return 0;
}