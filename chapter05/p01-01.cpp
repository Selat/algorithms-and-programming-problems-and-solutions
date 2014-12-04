#include <iostream>
#include <string>

using namespace std;

/*
 * 5.1.1. Throughout a program text the operation x y was denoted by x**y. It was
 * decided that notation should be changed to x^y. How do we do that? The input text is
 * read character-by-character; the output text should be produced in the same manner.
 */

struct State
{
	State() :
		after_asterisk(false)
	{
	}
	bool after_asterisk;
};

void nextChar(char c, State &s, string &res)
{
	if(s.after_asterisk) {
		if(c == '*') {
			res.push_back('^');
		} else {
			res.push_back('*');
			res.push_back(c);
		}
		s.after_asterisk = false;
	} else {
		if(c == '*') {
			s.after_asterisk = true;
		} else {
			res.push_back(c);
		}
	}
}

void finishInput(State &s, string &res)
{
	if(s.after_asterisk) {
		res.push_back('*');
	}
}

int main()
{
	string s;
	string res;
	cin >> s;
	State state;
	for(int i = 0; i < s.length(); ++i) {
		nextChar(s[i], state, res);
	}
	finishInput(state, res);
	cout << res << endl;
	return 0;
}
