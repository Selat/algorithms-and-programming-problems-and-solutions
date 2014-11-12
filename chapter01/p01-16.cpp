#include <iostream>

using namespace std;

/*
 * 1.1.16. Solve the preceding problem using the mod operator.
 */

int gcd(int a, int b, int &x, int &y)
{
	// invariant relation
	// n = a * xa + b * ya,
	// m = a * xb + b * yb
	int xa = 1, ya = 0;
	int xb = 0, yb = 1;
	int n = a, m = b;
	while((n > 0) && (m > 0)) {
		if(n >= m) {
			int k = n / m;
			n %= m;
			xa -= k * xb;
			ya -= k * yb;
		} else {
			int k = m / n;
			m %= n;
			xb -= k * xa;
			yb -= k * ya;
		}
	}
	if(n > 0) {
		x = xa;
		y = ya;
	} else {
		x = xb;
		y = yb;
	}
	return n + m;
}

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	cout << gcd(a, b, x, y) << endl;
	cout << x << " " << y << endl;
	return 0;
}
