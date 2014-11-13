#include <iostream>

using namespace std;

/*
 * 1.1.32. (R.W. Floyd, communicated by Yu.V. Matijasevich) A function f that
 * maps {1..N} to {1..N} is given. The sequence 1, f(1), f(f(1)), . . . is periodic.
 * Find its period. The number of operations should be proportional to the length of the
 * smallest initial segment that includes the period (this length may be significantly less
 * than N).
 */

const int period = 13;
const int preperiod_prefix = 30;

int f(int x)
{
	if(x < preperiod_prefix) {
		return x + 1;
	}
	return (x % 13) + 2 * preperiod_prefix;
}

int getPeriod()
{
	int k = 1;
	int a = f(1);
	int b = f(f(1));
	// a = f[k, 1]; b = f[2 * k, 1]
	while(a != b) {
		++k;
		a = f(a);
		b = f(f(b));
	}
	int m = 1;
	b = f(a);
	while(a != b) {
		b = f(b);
		++m;
	}
	return m;
}

int main()
{
	// should print value of variable period
	cout << getPeriod() << endl;
	return 0;
}
