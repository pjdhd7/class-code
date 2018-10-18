//LLSTACK TESTER
#include "abstractstack.h"
#include "llstack.h"
#include <iostream>
using namespace std;

int main()
{
  LLStack<int> tester;
  tester.isEmpty();
  tester.pop();
  tester.top();
  cout << "Pre-fill" << tester <<endl;
  for(int i = 0; i < 10; i++)
    tester.push(i);
  cout <<"Post-fill"<< tester<<endl;
  tester.pop();
  tester.pop();
  cout << tester <<endl;
  tester.clear();
  return 0;
}