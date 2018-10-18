#include "progparser.h"

bool is_correct;

int main() {
	string temp;
	char input[limit];
	is_correct = true;
	cin.getline(input, limit, '\n');
	istringstream ss(input);
	FunctionSequence(ss, input, temp);
	if (is_correct == true)
		cout << "CORRECT" << endl;
	else
		cout << "INVALID!" << endl;
	return 0;
}