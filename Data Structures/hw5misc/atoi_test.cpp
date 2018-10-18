#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
int main ()
{
  string s1, s2;
  int x, y;  
  
  cin >> s1 >> s2;
  x = atoi( s1.c_str() );
  y = atoi( s2.c_str() );
  cout << s1 << " * " << s2 << " = " << x*y << endl;
  return 0;  
}