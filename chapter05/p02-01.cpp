#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 5.2.1. Read the maximal prefix of the input string that may be a prefix of a
 * decimal number. Determine whether this prefix is a decimal number or not.
 */

enum State {ACCEPT, ERROR, INITIAL, INTEGER_PART, DECIMAL_POINT, FRACTION_PART} state;

void nextChar(char c, State &s)
{
	switch(s) {
	case INITIAL:
		if(isspace(c)) {
			s = INITIAL;
		} else if(isdigit(c)) {
			s = INTEGER_PART;
		} else {
			cerr << "Expected digit at the beginning of the string." << endl;
			s = ERROR;
		}
		break;
	case INTEGER_PART:
		if(isdigit(c)) {
			s = INTEGER_PART;
		} else if(c == '.') {
			s = DECIMAL_POINT;
		} else {
			cerr << "Expected digit or '.' in the integer of the number." << endl;
			s = ERROR;
		}
		break;
	case DECIMAL_POINT:
		if(isdigit(c)) {
			s = FRACTION_PART;
		} else {
			cerr << "Expected digit after the decimal point." << endl;
			s = ERROR;
		}
		break;
	case FRACTION_PART:
		if(isdigit(c)) {
			s = FRACTION_PART;
		} else {
			s = ACCEPT;
		}
		break;
	default:
		s = ERROR;
	}
}

void finishInput(State &s)
{
	switch(s) {
	case ACCEPT:
		cerr << "Input accepted" << endl;
		break;
	default:
		cerr << "Invalid input" << endl;
	}
}

int main()
{
	string s;
	getline(cin, s);
	State state = INITIAL;
	int i = 0;
	int power = 1;
	while((state != ACCEPT) && (state != ERROR)) {
		nextChar(s[i++], state);
	}
	finishInput(state);

	return 0;
}
