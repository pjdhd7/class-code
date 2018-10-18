#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
  string temp;
  ifstream fin;
  fin.open("Leg.dat");
  
  while(fin >> temp)
    cout <<temp<<endl;
  return 0;
}