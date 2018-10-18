#include <iostream>
#include "realbox.h"

using namespace std;

int main () 
{
	cout << "RealBox Tester" << endl;
	
	cout << "#1" << endl;
	RealBox a(6,2.2);
	cout << a << endl;

	cout << "#2" << endl;
	RealBox b(4,3.14);
	cout << b << endl;
	
	cout << "#3" << endl;
	RealBox c(5,5.55);
	c.set( 1, 7.7 );
	cout << c << endl;
	
	cout << "#4" << endl;
	RealBox d(8,8.123);
	d.set( 2, 1.11 );
	cout << d << endl;

	cout << "#5 : Operator=" << endl;
	c = d;
	cout << d << endl;
	cout << c << endl;
	c.set( 5, 42.42 );
	cout << d << endl;
	cout << c << endl;
	
	cout << "#6 : Copy Constructor" << endl;
	RealBox e(a);
	cout << a << endl;
	cout << e << endl;
	e.set( 3, 88.123 );
	cout << a << endl;
	cout << e << endl;
	
  return 0;
}
