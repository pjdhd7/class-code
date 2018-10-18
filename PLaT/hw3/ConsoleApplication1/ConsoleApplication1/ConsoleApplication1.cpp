// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
using namespace std;

int string_size = 200;

int main()
{
	istringstream ss;
	string temp;
	char input[200];
	int lines = 0;
	cin.getline(input, string_size, '\n');
	ss.clear();
	ss.str(input);
	while (ss >> temp) {
		if (temp == "\n") {
			cout << lines << " counted!" << endl;
			cin >> input;
			ss.clear();
			ss.str(input);
		}
	}

	return 0;
}

