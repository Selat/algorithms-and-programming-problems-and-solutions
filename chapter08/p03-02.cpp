#include <iostream>
#include <map>
#include <stack>

using namespace std;

/*
 * 8.3.2. Write a non-recursive program to compute f.
 * f(0) = a,
 * f(x) = h(x, f(l(x)), f(r(x))), x > 0,
 * here a is some number, while h, l and r are known functions. We assume that
 * for any x the sequences x, l(x), l(l(x)), ... and x, r(x), r(r(x)), ... reache 0.
 */

const int a = 0;

enum Type {FUNCL, FUNCR, FUNCF, FUNCH, NUMBER};

int l(int x)
{
	return x - 1;
}

int r(int x)
{
	return x - 1;
}

int h(int x, int y, int z)
{
	return x + y + z;
}

int f(int x)
{
	stack <int> s;
	stack <pair <Type, int> > seq;
	map <int, int> vals;
	s.push(x);
	seq.push(make_pair(FUNCF, 0));
	vals[0] = a;
	while(!seq.empty()) {
		int type = seq.top().first;
		int arg = seq.top().second;
		seq.pop();
		int val;
		switch(type) {
		case FUNCL:
			val = s.top();
			s.pop();
			s.push(l(val));
			break;
		case FUNCR:
			val = s.top();
			s.pop();
			s.push(r(val));
			break;
		case FUNCF: {
			val = s.top();
			s.pop();
			auto i = vals.find(val);
			if(i != vals.end()) {
				s.push(i->second);
			} else {
				// Function r itself
				seq.push(make_pair(FUNCH, 0));
				// Third arg for h
				seq.push(make_pair(FUNCF, 0));
				seq.push(make_pair(FUNCR, 0));
				seq.push(make_pair(NUMBER, val));
				// Second arg for h
				seq.push(make_pair(FUNCF, 0));
				seq.push(make_pair(FUNCL, 0));
				seq.push(make_pair(NUMBER, val));
				// First arg for h
				seq.push(make_pair(NUMBER, val));
			}
			break;
		}
		case FUNCH: {
			int val1, val2, val3;
			val3 = s.top();
			s.pop();
			val2 = s.top();
			s.pop();
			val1 = s.top();
			s.pop();
			int func_value = h(val1, val2, val3);
			vals[val1] = func_value;
			s.push(func_value);
			break;
		}
		case NUMBER:
			s.push(arg);
			break;
		}
	}
	return s.top();
}

int main()
{
	int x;
	cin >> x;
	cout << f(x) << endl;
	return 0;
}
