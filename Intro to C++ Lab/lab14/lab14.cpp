//Name: Peter Dolan         ID: 12410657
//Instructor: Armita     Seciton: C    Date: 12/02/2014
//File: lab14.cpp       Desc: Template class lab
#include <iostream>
using namespace std;

const short SIZE = 4;

template <class T>
class Array_Class
{
  private:
    T m[SIZE];
    
  public:
    Array_Class(T m_0, T m_1, T m_2, T m_3);
    Array_Class(T _m[]);
    Array_Class(){m[0]=m[1]=m[2]=m[3]=0;}
    T GetMem(const short mem){return m[mem];};
    Array_Class operator *=(const Array_Class T_1);
    
    template <class u>
    friend Array_Class<u> operator+(const Array_Class<u> T_1, const Array_Class<u> T_2);
    template <class u>
    friend ostream &operator<<(ostream &o, const Array_Class<u> &arr);
};

template<class T>
Array_Class<T>::Array_Class(T m_0, T m_1, T m_2, T m_3)
{
  m[0] = m_0;
  m[1] = m_1;
  m[2] = m_2;
  m[3] = m_3;
}

template<class T>
Array_Class<T>::Array_Class(T _m[])
{
  for(int i = 0; i < SIZE; i++)
    m[i] = _m[i];
}

template<class T>
Array_Class<T> Array_Class<T>::operator *=(const Array_Class<T> T_1)
{
  for(int i = 0; i < SIZE; i++)
    m[i] *= T_1.m[i];
  return *this;
}

template<class T>
Array_Class<T> operator+(const Array_Class<T> T_1, const Array_Class<T> T_2)
{
  Array_Class<T> T_temp;
  
  for(int i = 0; i < SIZE; i++)
    T_temp.m[i] = T_1.m[i] + T_2.m[i];
   
  return T_temp;
}

template<class T>
ostream & operator <<(ostream &o, const Array_Class<T> &arr)
{
  o <<"|"<<arr.m[0]<<", "<<arr.m[1]<<", "<<arr.m[2]<<", "<<arr.m[3]<<"|"<<endl;
  return o;
}
int main()
{
  int arr[4] = {3,2,3,5};
  Array_Class<int> A(1,2,3,4);
  Array_Class<int> B(arr);
  Array_Class<int> C;
  cout <<"A: "<<A<<"B: "<<B<<"C: "<<C;
  B *= A;
  C = A + B;
  cout <<"A: "<<A<<"B: "<<B<<"C: "<<C;
                                
  return 0;
}
                  
