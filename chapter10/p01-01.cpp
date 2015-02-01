#include <iostream>
#include <string>

using namespace std;

/*
 * 10.1.1. The character string x[1]..x[n] is given. Check if it contains the sub-
 * string abcd.
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
		} else if(s[i] == pattern[0]) {
			state = 1;
		} else {
			state = 0;
		}
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	if(contains(s, "abcd")) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
