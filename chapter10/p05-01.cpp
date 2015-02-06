#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 10.5.1. How do we fill the array pos?
 */

void fillPos(const string &s, const string &pattern, vector <int> &pos)
{
	pos.assign('z' - 'a' + 1, 0);
	for(int i = 0; i < pattern.length(); ++i) {
		pos[pattern[i]] = i;
	}
}

int main()
{
	string s, pattern;
	vector <int> pos;
	cin >> s >> pattern;
	fillPos(s, pattern, pos);
	for(int i = 0; i < pos.size(); ++i) {
		cout << pos[i] << " ";
	}
	cout << endl;
	return 0;
}
