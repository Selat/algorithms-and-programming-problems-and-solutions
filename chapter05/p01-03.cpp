#include <iostream>

using namespace std;

/*
 * 5.1.3. In Pascal, comments are surrounded by curly braces like this:
 * begin {here a block begins}
 * i := i + 1; {increase i by one}
 * Write a program that removes all comments and puts a space character in the place
 * of a removed comment. (According to Pascal rules, 1{one}2 is equivalent to 1 2,
 * not 12).
 */

struct State
{
	State() :
		inside_comment(false)
	{
	}
	bool inside_comment;
};

void nextChar(char c, State &s, string &res, const string &pattern)
{
	if(s.inside_comment) {
		if(c == '}') {
			s.inside_comment = false;
			res.push_back(' ');
		}
	} else {
		if(c == '{') {
			s.inside_comment = true;
		} else {
			res.push_back(c);
		}
	}
}

void finishInput(State &s, string &res, const string &pattern)
{
	if(s.inside_comment) {
		cerr << "Unclosed comment!" << endl;
	}
}

int main()
{
	string s;
	string res;
	const string pattern = "abc";
	getline(cin, s);
	State state;
	for(int i = 0; i < s.length(); ++i) {
		nextChar(s[i], state, res, pattern);
	}
	finishInput(state, res, pattern);
	cout << res << endl;
	return 0;
}
