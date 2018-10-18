//Name: Peter Dolan   ID: 12410657
//Instructor: Morales    Section: A    Date: 04/25/2015
//File: llqueue.h     Desc: Class definition of LLQueue

#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <iostream>
#include "abstractqueue.h"

class Ship
{
private:
	string m_name;
	int m_fuel;
	int m_time_arrived;
	int m_time_fueling;
	int m_wait;

public:
	void set_ship(int fuel, string name, int time)
	{
		m_wait = m_time fueling = 0;
		m_fuel = fuel;
		m_name = name;
		m_time_arrived = time;
	}

	//Purpose: returns the fuel level
	int getFuel() const { return m_fuel; }

	//Purpose: Gets the arrival time of the ship
	int getTime() const { return m_time_arrived; }

	//Purpose: Gets the wait time of the ship
	int getWait() const { return m_wait; }

	//Purpose: Returns the name of the ship
	string getName() const { return m_name; }

	//Purpose: Simulates fuel getting added to a ship
	//Post: m_fuel is incremented down by one
	void addFuel()
	{
		if (m_time_fueling % 3 == 0)
			m_fuel--;
		return;
	}

	//Purpose: simulates the pleasure of waiting
	//Post: m_wait is incremented up by one
	void addWait() { m_wait++; return; }

	Ship operator=(const Ship& s)
	{
		Ship ship;
		ship.m_name = s.m_name;
		ship.m_fuel = s.m_fuel;
		ship.m_time_arrived = s.m_time_arrived;
		ship.m_wait = s.m_wait;
		return ship;
	}
};

template < typename T >
class LLQueue:public AbstractQueue<T>
{
  public:
    LLQueue<T>* m_next;
    Ship m_data;
  
    LLQueue() : m_next(NULL) {}
  
    virtual ~LLQueue() {}
  
    // Purpose: Checks if a queue is empty
    // Returns: 'true' if the queue is empty
    //     'false' otherwise
    bool isEmpty() const
    {
      if(m_next == NULL)
        return true;
      return false;
    }
  
    // Purpose: looks at the front of the queue
    // Returns: a reference to the element currently in front of the queue
    // Exception: if the queue is empty, THROW a 'Oops' object with an error 
    //            message!!!
    const Ship& front() const throw (Oops);
    
    // Purpose: looks at the back of the queue
    // Returns: a reference to the element currently in the back of the queue
    // Exception: if the queue is empty, THROW a 'Oops' object with an error 
    //            message!!!
    const Ship& back() const throw (Oops);
  
    // Purpose: enqueue an element into the queue
    // Parameters: x is the item to add to the queue
    // Postconditions: x is now the element at the end of the queue,
    void enqueue(const Ship& x);

	// Purpose: enqueue an element into the queue
	// Parameters: x is the item to add to the queue
	// Postconditions: x is now the element at the end of the queue,
	void enqueue(int fuel, string name, int time);
  
    // Purpose: dequeues
    // Postconditions: the element formerly at the front of the queue has
    //     been removed.
    // Note: Dequeueing an empty queue results in an empty queue.
    void dequeue();
    
    //Purpose: counts the ship in the queue
    //Parameters: An LLQueue
    //Postconditions: returns an integer value for how many ships are 
    //                in the queue
    int count_ships() const;
    
    //Purpose: Adds wait time to all ships in the queue
    //Parameters: An LLQueue
    void waiting();
  
    // Purpose: clears the queue
    // Postconditions: the queue is now empty
    void clear()
    {
      while(m_next != NULL)
        dequeue();
      return;
    }
  
};

const int FUEL_TIME = 3;

#include "llqueue.hpp"

#endif