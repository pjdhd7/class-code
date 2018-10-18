//Name: Peter Dolan     ID: 12410657
//Instructor: Morales      Section: A      Date: 03/16/2015
//File: linkedlist.hpp      Desc: Implementation for linkedlist.h
#include <iostream>
using namespace std;

template <typename T>
const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  if(this != &rhs)
  {
    clear();
    if(rhs.isEmpty() == true)
      return *this;
    else
    {
	  int max = rhs.size();
      LinkedList<T> const* temp2 = &rhs;
      for(int i = 0; i < max; i++)
	  {
	    insert((temp2->m_data), getAtPtr(i));
		temp2=temp2->m_next;
	  }
    }
  }
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	m_next = NULL;
	*this = rhs;
}

template <typename T>
int LinkedList<T>::size() const
{
  const LinkedList<T>* r = this;
  int counter = 0;
  while(r -> m_next != NULL)
  {
    r = r -> m_next;
    counter++;
  }
  return counter;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(m_next == NULL)
    return true;
  else
    return false;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(isEmpty() == true)
  {
    cout <<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<<endl;
	return NULL;
  }
  else
  {
    LinkedList<T>* r = this;
    return r;
  }
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
	if (m_next == NULL)
	{
		cout << "!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list" << endl;
		return NULL;
	}
	else
	{
		if (m_next != NULL && m_next->m_next == NULL)
			return this;
		else
		{
			LinkedList<T>* temp = this;
			while (temp -> m_next != NULL && temp -> m_next -> m_next != NULL)
			{
				temp = temp->m_next;
			}
			return temp;
		}
	}
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  LinkedList<T>* r = this;
  int counter = 0;
  while(r -> m_next != NULL && counter < i)
  {
    r = r -> m_next;
    counter++;
  }
  if(counter == i)
    return r;
  else 
  {
   cout <<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index"<<endl;   
   return NULL;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
	/*if (m_next != NULL)
	{
		LinkedList<T>* r = this->m_next;
		LinkedList<T>* temp = NULL;

		this->m_next = NULL;
		this->m_data = '\0';

		while (r->m_next != NULL)
		{
			temp = r->m_next;
			delete r;
			r = temp;
		}
	}*/
	while(isEmpty() == false)
	{
	  remove(getAtPtr(0));
	}
	  return;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  /*if(isEmpty() == true)
  {
    m_data = x;
	m_next = new LinkedList<T>;
  }
  else
  {
    LinkedList<T>* r = new LinkedList<T>;
	r -> m_next = this -> m_next;
	r -> m_data = this -> m_data;
	this -> m_next = r;
	this -> m_data = x;
  }*/
	insert(x, this);
  return;
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList<T>* temp = new LinkedList<T>;
  temp -> m_data = pos -> m_data;
  temp -> m_next = pos -> m_next;
  pos -> m_next = temp;
  pos -> m_data = x;
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList<T>* temp = pos -> m_next;
  pos -> m_data = temp -> m_data;
  pos -> m_next = temp -> m_next;
  delete temp;
  return;
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  LinkedList<T> const* temp_left = this;
  LinkedList<T> const* temp_right = &rhs;
  while(temp_left -> m_data == temp_right -> m_data)
  {
    if((temp_left -> m_next == NULL && temp_right -> m_next != NULL) ||
       (temp_left -> m_next != NULL && temp_right -> m_next == NULL))
       return false;
    else if(temp_left -> m_next == NULL && temp_right -> m_next == NULL)
	  return true;
	else
	{
      temp_left = temp_left -> m_next;
      temp_right = temp_right -> m_next;
    }
  }
  temp_right = NULL;
  temp_left = NULL;
  return false;
}

template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList<T>* temp = this;
  while(temp -> m_next != NULL)
  {
    if(temp -> m_data == x)
	  return temp;
	else
	  temp = temp -> m_next;
  }
  return NULL;
}

template <typename T>
void LinkedList<T>::reverse()
{
 
	LinkedList<T>* temp1= this;
	LinkedList<T>* temp2=new LinkedList<T>;
	while (temp1->m_next != NULL)
	{
		temp2->insert_front(temp1->m_data);
		temp1 = temp1->m_next;
	}
	*this = *temp2;
	temp2->clear();
	delete temp2;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  int size_xlist = xlist.size();
  int size_this = size();
  const LinkedList<T>* p = &xlist;
  for(int i = 0; i < size_xlist; i++)
  {
    insert(p -> m_data, getAtPtr(size_this));
	p=p->m_next;
	size_this++;
  }
  return;
}