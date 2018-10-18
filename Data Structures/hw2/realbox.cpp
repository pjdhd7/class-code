//Name: Peter Dolan     ID: 12410657
//Instructor: Morales      Section: A      Date: 02/22/2015
//File: realbox.cpp      Desc: Implementation for real.h
#include "realbox.h"
#include <iostream>
using namespace std;

RealBox::RealBox(int s, float a)
{
  m_boxsize = s;
  m_reals = new float[m_boxsize];
  for(int i = 0; i < m_boxsize; i++)
    m_reals[i] = a;
}

RealBox::~RealBox()
{
  delete []m_reals;
}

const RealBox& RealBox::operator=(const RealBox& rhs)
{
  delete []m_reals;
  m_reals = new float [rhs.m_boxsize];
  for(int i = 0; i < rhs.m_boxsize; i++)
    m_reals[i] = rhs.m_reals[i];
  
  m_boxsize = rhs.m_boxsize;
  
  return *this;
}

RealBox::RealBox(const RealBox& rhs)
{
  m_reals = new float[rhs.m_boxsize];
  *this = rhs;
}

void RealBox::set( int i, float x)
{
  if(i < m_boxsize)
    m_reals[i] = x;
  return;
}

std::ostream& operator<< (std::ostream& out, 
                          const RealBox& box)
{
  out <<"[ ";
  for(int i = 0; i < box.m_boxsize; i++)
    out<<box.m_reals[i]<<", ";
  out <<" ]";
  return out;
}