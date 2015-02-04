#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 10.4.2. How do we fill the table L[1]..L[n]?
 *
 * L[i] is the length of the maximal prefix of x[1]..x[i] that is
 * simultaneously a suffix of x[1]..x[i].
 */

void prefixFunction(const string &s, vector <int> &pi)
{
	int n = s.length();
	pi.resize(n);
	pi[0] = 0;
	for(int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while((j > 0) && (s[i] != s[j])) {
			j = pi[j - 1];
		}
		if(s[i] == s[j]) ++j;
		pi[i] = j;
	}
}

int main()
{
	string s;
	vector <int> pi;
	cin >> s;
	prefixFunction(s, pi);
	for(int i = 0; i < pi.size(); ++i) {
		cout << pi[i] << " ";
	}
	cout << endl;
	return 0;
}
