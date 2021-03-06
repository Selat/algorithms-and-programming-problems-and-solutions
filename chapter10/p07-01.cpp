#include <iostream>
#include <string>

using namespace std;

/*
 * 10.7.1. Construct a finite automaton that checks if the pattern a?b is present in
 * the input string.
 */

bool present(const string &s)
{
	/*
	 * pattern - "a?b"
	 * 0 - no symbols are matched,
	 * 1 - "?a",
	 * 2 - "a?",
	 * 3 - "aa".
	 */
	int state = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(state == 0) {
			if(s[i] == 'a') {
				state = 1;
			}
		} else if(state == 1) {
			if(s[i] == 'a') {
				state = 3;
			} else {
				state = 2;
			}
		} else if(state == 2) {
			if(s[i] == 'b') {
				return true;
			} else if(s[i] == 'a') {
				state = 1;
			} else {
				state = 0;
			}
		} else {
			if(s[i] == 'b') {
				return true;
			} else if(s[i] == 'a') {
				state = 3;
			} else {
				state = 2;
			}
		}
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	if(present(s)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
