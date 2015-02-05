#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 10.4.5. Write the program discussed in the last paragraph: It checks whether a
 * string X = x[1]..x[n] is a substring of a string Y = y[1]..y[m].
 */

bool substring(const string &s, const string &pattern)
{
	int n = pattern.length();
	int m = s.length();
	vector <int> pi(n);
	for(int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while((j > 0) && (s[i] != s[j])) {
			j = pi[j - 1];
		}
		if(s[i] == s[j]) ++j;
		pi[i] = j;
	}
	int j = 0, len = 0;
	while((len != n) && (j != m)) {
		while((pattern[len + 1] != s[j + 1]) && (len > 0)) {
			len = pi[len];
		}
		if(pattern[len + 1] == s[j + 1]) {
			++len;
		} else {
			len = 0;
		}
		++j;
	}
	return (len == n);
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
