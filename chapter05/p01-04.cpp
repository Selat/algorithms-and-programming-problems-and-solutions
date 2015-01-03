#include <iostream>

using namespace std;

/*
 * 5.1.4. Pascal programs also contain quoted strings. If a curly brace appears in-
 * side a string, it does not mean the start of a comment. Similarly, a quote symbol
 * inside a comment does not signify a string. How do we modify the above program to
 * take this into account?
 */


enum State {BASIC, COMMENT, STRING};

void nextChar(char c, State &s, string &res)
{
	if(s == COMMENT) {
		if(c == '}') {
			s = BASIC;
			res.push_back(' ');
		}
	} else if(s == STRING) {
		if(c == '"'){
			s = BASIC;
		}
		res.push_back(c);
	} else {
		if(c == '{') {
			s = COMMENT;
		} else {
			if(c == '"') {
				s = STRING;
			}
			res.push_back(c);
		}
	}
}

void finishInput(State &s, string &res)
{
	if(s == COMMENT) {
		cerr << "Unclosed comment!" << endl;
	} else if(s == STRING) {
		cerr << "Unclosed string!" << endl;
	}
}

int main()
{
	string s;
	string res;
	getline(cin, s);
	State state = BASIC;
	for(int i = 0; i < s.length(); ++i) {
		nextChar(s[i], state, res);
	}
	finishInput(state, res);
	cout << res << endl;
	return 0;
}
