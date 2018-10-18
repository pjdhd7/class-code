//Name: Peter Dolan   ID: 12410657
//Instructor: Morales    Section: A    Date: 04/16/2015
//File: llstack.h     Desc: Class definition of LLStack

#ifndef LLSTACK_H
#define LLSTACK_H

#include <iostream>
#include "abstractstack.h"
using namespace std;

template <typename T>
class LLStack:public AbstractStack<T>
{
  public:
    LLStack<T>* m_next;
    T m_data;
    
    LLStack() : m_next(NULL) {}
    
    virtual ~LLStack()
    {
    }  
    
    //Desc: Checks if stack is empty
    //Pre: A valid LLStack
    //Post: returns 'true' for true, 'false' for false
	bool isEmpty() const;
    
    //Desc: Gets top of the stack
    //Pre: a valid stack
    // Exception: If empty, throws an Oops
    //Post: Returns the top of the stack
	const T& top() const throw(Oops);
    
    //Desc: Places data at the top of the stack
    //Pre: a valid stack and a T data element
    //Post: the data is at the top of the stack, other elements pushed back
	void push(const T& x);
    
    //Desc: Removes the top element
    //Pre: a valid stack
    //Post: top element is removed, all elements shifted forward, does nothing
    //      if stack is empty
	void pop();
    
    //Desc: Empties the stack
    //Pre: A valid stack
    //Post: stack will be emptied, does nothing if stack is empty
	void clear();
	
	//Desc: Adds the top two elements and places the sum at the top
	//Pre: A valid stack
	//Post: top two elements will be removed and their sum will be pushed onto
	//      the stack. Does nothing if stack is empty
	void add2();
	
	//Desc: Subtracts the top two elements and places the difference at the top
	//Pre: A valid stack
	//Post: top two elements will be removed and their difference will be 
	//      pushed onto the stack. Does nothing if stack is empty
	void minus();
	
	//Desc: Multiplies the top two elements and places the product at the top
	//Pre: A valid stack
	//Post: top two elements will be removed and their product will be pushed
	//      onto the stack. Does nothing if stack is empty
	void times();
	
	//Desc: Divides the top two elements and places the quotient at the top
	//Pre: A valid stack
	//Post: top two elements will be removed and their quotient will be pushed
	//      onto the stack. Does nothing if stack is empty
	void divide();
	
	//Desc: Divides the top two elements and places the remainder at the top
	//Pre: A valid stack
	//Post: top two elements will be removed and their remainder will be pushed
	//      onto the stack. Does nothing if stack is empty
	void mod();
	
	//Desc: Multiplies the top element by -1
	//Pre: a valid stack
	//Post: Multiplies the top element by -1. Does nothing if stack is empty
	void negate();
	
	//Desc: Sums entire stack together
	//Pre: A valid stack
	//Post: Removes all elements of the stack and places their sum at the top
	//      Does nothing if stack is empty
	void sum();
	
	//Desc: Reverses the order of the elements of the stack
	//Pre: A valid stack
	//Post: Reverses the order of the elements of the stack.  Does nothing if
	//      stack is empty
	void reverse();
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const LLStack<T>& xlist)
{
	out << "[ ";
	const LLStack<T>* p = &xlist;
	while (p->m_next != NULL){
		out << p->m_data;
		p = p->m_next;
		if(p->m_next != NULL)
		  cout <<", ";
	}
	out << " ]";

	return out;
}


#include "llstack.hpp"
#endif