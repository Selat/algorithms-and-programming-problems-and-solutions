#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 5.2.5. What changes in the above program above are necessary to allow empty
 * integer or fractional parts like in 1., .1 or even . (the latter number is considered to
 * be equal to zero)?
 */

struct State
{
	State() : type(INITIAL), res(0.0), fmul(0.1), is_positive(true), exponent(0),
	          is_exp_positive(true) {}
	enum Type {ACCEPT, ERROR, INITIAL, SIGN_PART, INTEGER_PART, DECIMAL_POINT, FRACTION_PART,
	           EXPONENT_SYMBOL, EXPONENT_SIGN, EXPONENT_NUMBER} type;
	double res, fmul;
	int exponent;
	bool is_positive;
	bool is_exp_positive;
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
		} else if(c == '.') {
			s.type = State::DECIMAL_POINT;
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
		} else if(c == 'E') {
			s.type = State::EXPONENT_SYMBOL;
		} else {
			s.type = State::ACCEPT;
			if(!s.is_positive) {
				s.res = -s.res;
			}
		}
		break;
	case State::FRACTION_PART:
		if(isdigit(c)) {
			s.type = State::FRACTION_PART;
			s.res += (c - '0') * s.fmul;
			s.fmul /= 10.0;
		} else if(c == 'E') {
			s.type = State::EXPONENT_SYMBOL;
			if(!s.is_positive) {
				s.res = -s.res;
			}
		} else {
			s.type = State::ACCEPT;
			if(!s.is_positive) {
				s.res = -s.res;
			}
		}
		break;
	case State::EXPONENT_SYMBOL:
		if(isdigit(c)) {
			s.type = State::EXPONENT_NUMBER;
			s.exponent = c - '0';
		} else if((c == '+') || (c == '-')) {
			s.type = State::EXPONENT_SIGN;
			s.is_exp_positive = (c == '+');
		} else {
			s.type = State::ERROR;
			cerr << "Expected digit or sign after the exponent symbol." << endl;
		}
		break;
	case State::EXPONENT_SIGN:
		if(isdigit(c)) {
			s.type = State::EXPONENT_NUMBER;
			s.exponent = c - '0';
		} else {
			s.type = State::ERROR;
			cerr << "Expected digit after the sign." << endl;
		}
		break;
	case State::EXPONENT_NUMBER:
		if(isdigit(c)) {
			s.type = State::EXPONENT_NUMBER;
			s.exponent = s.exponent * 10 + (c - '0');
		} else {
			s.type = State::ACCEPT;
			if(s.is_exp_positive) {
				for(int i = 0; i < s.exponent; ++i) {
					s.res *= 10.0;
				}
			} else {
				for(int i = 0; i < s.exponent; ++i) {
					s.res /= 10.0;
				}
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
