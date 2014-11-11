#include <iostream>

using namespace std;

/*
 * 1.1.15. Nonnegative integers a and b are given, at least one of which is not zero.
 * Find d = GCD(a,b) and integers x and y such that d = a*x + b*y.
 */

int gcd(int a, int b, int &x, int &y)
{
	// invariant relation:
	// a = a_0 * xa + b_0 * ya,
	// b = a_0 * xb + b_0 * yb
	int xa = 1, ya = 0;
	int xb = 0, yb = 1;
	while((a > 0) && (b > 0)) {
		if(a >= b) {
			a -= b;
			xa -= xb;
			ya -= yb;
		} else {
			b -= a;
			xb -= xa;
			yb -= ya;
		}
	}
	if(a > 0) {
		x = xa;
		y = ya;
	} else {
		x = xb;
		y = yb;
	}
	return a + b;
}

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	cout << gcd(a, b, x, y) << endl;
	cout << x << " " << y << endl;
	return 0;
}

