#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 5.2.3. Repeat the previous problem if the number may be optionally preceded
 * by - or +.
 */

struct State
{
	State() : type(INITIAL), res(0.0), fmul(0.1), is_positive(true) {}
	enum Type {ACCEPT, ERROR, INITIAL, SIGN_PART, INTEGER_PART, DECIMAL_POINT, FRACTION_PART} type;
	double res, fmul;
	bool is_positive;
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
		} else if((c == '-') || (c == '+')) {
			s.type = State::SIGN_PART;
			s.is_positive = (c == '+');
		} else {
			cerr << "Expected digit at the beginning of the string." << endl;
			s.type = State::ERROR;
		}
		break;
	case State::SIGN_PART:
		if(isdigit(c)) {
			s.type = State::INTEGER_PART;
			s.res = s.res * 10 + (c - '0');
		} else {
			cerr << "Expected digit after the sign." << endl;
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
			if(!s.is_positive) {
				s.res = -s.res;
			}
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
