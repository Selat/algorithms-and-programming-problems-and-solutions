#include <iostream>
#include <string>

using namespace std;

/*
 * 10.2.2. Construct such an automaton. Show all its states and the transition table
 * (which determines a new state as a function of an old state and an input character).
 */


bool contains(const string &s, const string &pattern)
{
	int state = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == pattern[state]) {
			++state;
			if(state == pattern.length()) {
				return true;
			}
		} else {
			for(int j = state; j >= 1; --j) {
				bool ok = true;
				for(int k = 0; k < j; ++k) {
					if(pattern[k] != s[i - j + k + 1]) {
						ok = false;
					}
				}
				if(ok) {
					state = j;
					break;
				}
			}
		}
	}
	return false;
}

int main()
{
	string s, pattern;
	cin >> s >> pattern;
	if(contains(s, pattern)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
