#include <iostream>

using namespace std;

/*
 * 5.1.5. One more feature that exists in many Pascal implementations is a com-
 * ment of the type
 * i := i+1; (* here i is increased by 1 *)
 * A closing comment symbol must be paired with an opening comment symbol of
 * the same type (e.g., {. . . *) is not permitted). How do we deal with these types of
 * comments?
 */


enum State {BASIC, COMMENT1, COMMENT2_BEGIN, COMMENT2_END, COMMENT2, STRING};

void nextChar(char c, State &s, string &res)
{
	switch(s) {
	case COMMENT1:
		if(c == '}') {
			s = BASIC;
			res.push_back(' ');
		}
		break;
	case COMMENT2_BEGIN:
		if(c == '*') {
			s = COMMENT2;
		} else {
			s = BASIC;
			res.push_back('(');
			res.push_back(c);
		}
		break;
	case COMMENT2_END:
		if(c == ')') {
			s = BASIC;
			res.push_back(' ');
		} else {
			s = COMMENT2;
		}
		break;
	case COMMENT2:
		if(c == '*') {
			s = COMMENT2_END;
		}
		break;
	case STRING:
		if(c == '"'){
			s = BASIC;
		}
		res.push_back(c);
		break;
	default:
		if(c == '{') {
			s = COMMENT1;
		} else if(c == '(') {
			s = COMMENT2_BEGIN;
		} else if(c == '"') {
			s = STRING;
			res.push_back(c);
		} else {
			res.push_back(c);
		}
	}
}

void finishInput(State &s)
{
	if((s == COMMENT1) || (s == COMMENT2) || (s == COMMENT2_END)) {
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
	finishInput(state);
	cout << res << endl;
	return 0;
}
