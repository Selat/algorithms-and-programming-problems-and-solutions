#include <iostream>

using namespace std;

/*
 * 1.1.17. Find GCD(a, b) and LCM(a, b)
 */

int lcm(int a, int b)
{
	// invariant relation
	// GCD(a, b) = GCD(n ,m),
	// n * u + m * v = 2 * a * b
	int n = a, m = b;
	int u = b, v = a, z;
	while((n > 0) && (m > 0)) {
		if(n >= m) {
			n -= m;
			v += u;
		} else {
			m -= n;
			u += v;
		}
	}
	if(n > 0) {
		z = u;
	} else {
		z = v;
	}
	return z >> 1;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
	return 0;
}
