#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 5.2.2. Add the following requirement to the preceding program: If a processed
 * part is a decimal number, its value should be placed into the variable val: real.
 */

struct State
{
	State() : type(INITIAL), res(0.0), fmul(0.1) {}
	enum Type {ACCEPT, ERROR, INITIAL, INTEGER_PART, DECIMAL_POINT, FRACTION_PART} type;
	double res, fmul;
};

void nextChar(char c, State &s)
{
	switch(s.type) {
	case State::INITIAL:
		if(isspace(c)) {
			s.type = State::INITIAL;
		} else if(isdigit(c)) {
			s.type = State::INTEGER_PART;
			s.res = s.res * 10 + (c - '0');
		} else {
			cerr << "Expected digit at the beginning of the string." << endl;
			s.type = State::ERROR;
		}
		break;
	case State::INTEGER_PART:
		if(isdigit(c)) {
			s.type = State::INTEGER_PART;
			s.res = s.res * 10 + (c - '0');
		} else if(c == '.') {
			s.type = State::DECIMAL_POINT;
		} else {
			cerr << "Expected digit or '.' in the integer of the number." << endl;
			s.type = State::ERROR;
		}
		break;
	case State::DECIMAL_POINT:
		if(isdigit(c)) {
			s.type = State::FRACTION_PART;
			s.res += (c - '0') * s.fmul;
			s.fmul /= 10.0;
		} else {
			cerr << "Expected digit after the decimal point." << endl;
			s.type = State::ERROR;
		}
		break;
	case State::FRACTION_PART:
		if(isdigit(c)) {
			s.type = State::FRACTION_PART;
			s.res += (c - '0') * s.fmul;
			s.fmul /= 10.0;
		} else {
			s.type = State::ACCEPT;
		}
		break;
	default:
		s.type = State::ERROR;
	}
}

void finishInput(State &s)
{
	if(s.type == State::ERROR) {
		cerr << "Invalid input!" << endl;
	}
}

int main()
{
	string s;
	getline(cin, s);
	State state;
	int i = 0;
	int power = 1;
	while((state.type != State::ACCEPT) && (state.type != State::ERROR)) {
		nextChar(s[i++], state);
	}
	finishInput(state);
	cout << setprecision(10) << fixed << state.res << endl;

	return 0;
}
