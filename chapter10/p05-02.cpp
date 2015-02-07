#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 10.5.2. What modifications in the program are necessary?
 */

bool substring(const string &s, const string &pattern)
{
	vector <int> pos('z' - 'a' + 1, 0);
	for(int i = 0; i < pattern.length(); ++i) {
		pos[pattern[i] - 'a'] = i;
	}
	int n = pattern.length();
	int m = s.length();
	int last = n - 1;
	while(last < m) {
		if(pattern[n - 1] == s[last]) {
			bool equal = true;
			for(int i = 0; i < n; ++i) {
				if(pattern[i] != s[last - n + 1 + i]) {
					equal = false;
					break;
				}
			}
			if(equal) {
				return true;
			}
		}
		last = last + (n - pos[pattern[last]]);
	}
	return false;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if(substring(s1, s2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
