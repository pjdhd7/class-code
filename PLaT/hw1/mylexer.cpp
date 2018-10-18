#include "mylexer.h"

int main()
{
	int T;
	char s[100];

	cin >> T;
	for (int i = 0; i<T; i++) {
		for (int k = 0; k < 100; k++)
			s[k] = NULL;
		cin >> s;
		if (is_integer(s)) {
			cout << i + 1 << ": Integer." << endl;
		}
		else if (is_decimal(s)) {
			cout << i + 1 << ": Decimal." << endl;
		}
		else if (is_scientific(s)) {
			cout << i + 1 << ": Scientific." << endl;
		}
		else if (is_hex(s)) {
			cout << i + 1 << ": Hexadecimal." << endl;
		}
		else if (is_keyword(s)) {
			cout << i + 1 << ": Keyword." << endl;
		}
		else if (is_identifier(s)) {
			cout << i + 1 << ": Identifier." << endl;
		}
		else if (is_email(s)) {
			cout << i + 1 << ": Email." << endl;
		}
		else
			cout << i + 1 << ": INVALID!" << endl;
	}
	return 0;
}
