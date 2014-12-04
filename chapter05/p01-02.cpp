#include <iostream>

using namespace std;

/*
 * 5.1.2. Write a program that deletes all occurrences of the substring "abc".
 */

struct State
{
	State() :
		match_id(0)
	{
	}
	int match_id;
};

void nextChar(char c, State &s, string &res, const string &pattern)
{
	// invariant relation: substrings a[i .. i + match_id - 1] and
	// pattern[0 .. match_id - 1] are matching.
	if(c == pattern[s.match_id]) {
		++s.match_id;
		if(s.match_id == pattern.size()) {
			s.match_id = 0;
		}
	} else {
		if(s.match_id > 0) {
			res += pattern.substr(0, s.match_id);
		}
		s.match_id = 0;
		res.push_back(c);
	}
}

void finishInput(State &s, string &res, const string &pattern)
{
	if(s.match_id > 0) {
		res += pattern.substr(0, s.match_id);
		s.match_id = 0;
	}
}

int main()
{
	string s;
	string res;
	const string pattern = "abc";
	cin >> s;
	State state;
	for(int i = 0; i < s.length(); ++i) {
		nextChar(s[i], state, res, pattern);
	}
	finishInput(state, res, pattern);
	cout << res << endl;
	return 0;
}
