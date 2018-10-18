//Name: Peter Dolan      ID: 12410657
//Instructor: Morales   Section: A     Date: 02/28/2015
//File: arraylist.hpp      Desc: implementations for arraylist class
#include <iostream>
using namespace std;

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete []m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  T* temp = new T[rhs.m_max];
  delete []m_data;
  for(int i = 0; i < rhs.m_size; i++)
    temp[i] = rhs[i];
  m_data = temp;
  m_max = rhs.m_max;
  m_size = rhs.m_size;
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_data = new T[cpy.max()];
  *this = cpy;
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if (m_size == 0)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
    return m_errobj;
  }
	
  return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if (i >= m_size)
  {
	cout << "!-- ERROR : PANIC in ARRAYLIST.[]!!  (List is empty)" << endl;
	return m_errobj;
  }
  
  return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if (i >= m_size)
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST.[]!!  (List is empty)" << endl;
    return m_errobj;
  }
  
  return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  int found = -1;
  for(int i = 0; i < m_size && found < 0; i++)
  {
    if(x == m_data[i])
	  found = i;
  }
  return found;
}

template <typename T>
void ArrayList<T>::clear()
{
  delete []m_data;
  m_data = NULL;
  m_max = m_size = 0;
  return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if(m_max == 0)
  {
    m_data = new T[1];
	m_max = 1;
  }
  
  if(m_size >= m_max)
  {
    T* temp = new T[m_max * 2];
    for(int i = 0; i < m_size; i++)
	  temp[i] = m_data[i];
	delete []m_data;
	m_data = temp;
	m_max = m_max * 2;
  }
  
  m_data[m_size] = x;
  m_size++;
  return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if (i > m_size)
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"
		 << endl;
  else 
  {
    if(m_size == m_max)
    {
      T* temp = new T[m_max * 2];
      for(int k = 0; k < m_size; k++)
	    temp[k] = m_data[k];
	  delete []m_data;
	  m_data = temp;
	  m_max  = m_max * 2 + 1;
    }
  
    for(int k = m_size; k >= i; k--)
      m_data[k] = m_data[k - 1];
  
    m_data[i] = x;
    m_size++;
  }
  return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if (i > m_size)
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"
         << endl;
  else 
  {
    if(m_size == m_max / 4)
    {
      T* temp = new T[m_max / 2];
      for(int k = 0; k < m_size; k++)
	    temp[k] = m_data[k];
	  delete []m_data;
	  m_data = temp;
	  m_max /= 2;
    }
  
    for(int k = i; k < m_size; k++)
      m_data[k] = m_data[k+1];
  
    m_size--;
  }
  return;
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if(i > m_size || k > m_size)
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"
	    <<endl;
  else
  {
    T temp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = temp;
  }
  return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  //added 5 to give a little extra space and prevent seg faults
  T* temp = new T[m_max + alist.max() + 5];
  
  for(int i = 0; i < m_size; i++)
    temp[i] = m_data[i];
	
  for(int i = m_size; i < (m_size + alist.size()); i++)
    temp[i] = alist[i - m_size];
	
  delete []m_data;
  m_data = temp;
  m_max += alist.max();
  m_size += alist.size();
  
  return;
}

template <typename T>
void ArrayList<T>::purge()
{
  for(int i = 0; i < m_size; i++)
    for(int k = i + 1; k < m_size; k++)
	  if(m_data[i] == m_data[k])
	    remove(k);
		
  return;
}