#include <iostream>
#include <string>

using namespace std;

/*
 * 10.7.2. Construct a finite automaton that checks if the input string contains the
 * pattern ab*cd (in the sense just described).
 */

bool present(const string &s)
{
	/*
	 * pattern - "a?b"
	 * 0 - no symbols are matched,
	 * 1 - "a",
	 * 2 - "ab",
	 * 3 - "abc".
	 */
	int state = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(state == 0) {
			if(s[i] == 'a') {
				state = 1;
			}
		} else if(state == 1) {
			if(s[i] == 'b') {
				state = 2;
			} else if(s[i] == 'a') {
				state = 1;
			} else {
				state = 0;
			}
		} else if(state == 2) {
			if(s[i] == 'c') {
				state = 3;
			}
		} else {
			if(s[i] == 'd') {
				return true;
			} else if(s[i] != 'c') {
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
