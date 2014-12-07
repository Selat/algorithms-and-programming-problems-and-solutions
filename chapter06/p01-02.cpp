#include <iostream>

using namespace std;

/*
 * 6.1.2. The program can be simplified if the sequence contains only parentheses
 * and no brackets. How?
 */

int main()
{
	string s;
	cin >> s;
	int open_parentheses = 0;
	int close_parentheses = 0;
	bool ok = true;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == '(') {
			++open_parentheses;
		} else {
			++close_parentheses;
		}
		if(close_parentheses > open_parentheses) {
			ok = false;
			break;
		}
	}
	if(ok) {
		cout << "CORRECT" << endl;
	} else {
		cout << "INCORRECT" << endl;
	}
	return 0;
}
