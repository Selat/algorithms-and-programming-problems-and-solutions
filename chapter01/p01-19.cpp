#include <iostream>

using namespace std;

/*
 * 1.1.19. Modify the solution of the preceding problem to find x and y such that
 * ax + by = GCD(a, b).
 */

void divideByTwo(int &a, int &b, int &x, int &y)
{
	if(!(a & 1) && !(b & 1)) {
		a >>= 1;
		b >>= 1;
	} else {
		if((x & 1) || (y & 1)) {
			x += b;
			y -= a;
		}
		x >>= 1;
		y >>= 1;
	}
}

int gcd(int a, int b, int &x, int &y)
{
	// invariant relation
	// GCD(a, b) = d * GCD(n ,m),
	// n = a * xa + b * ya,
	// m = a * xb + b * yb
	int n = a, m = b, d = 1;
	int xa = 1, ya = 0;
	int xb = 0, yb = 1;
	while((n > 0) && (m > 0)) {
		if((n & 1) && (m & 1)) {
			if(n >= m) {
				n -= m;
				xa -= xb;
				ya -= yb;
			} else {
				m -= n;
				xb -= xa;
				yb -= ya;
			}
		} else if(n & 1) {
			m >>= 1;
			divideByTwo(a, b, xb, yb);
		} else if(m & 1) {
			n >>= 1;
			divideByTwo(a, b, xa, ya);
		} else {
			d <<= 1;
			n >>= 1;
			m >>= 1;
			int ta = a, tb = b;
			divideByTwo(ta, tb, xa, ya);
			divideByTwo(a, b, xa, ya);
		}
	}
	if(n > 0) {
		x = xa;
		y = ya;
	} else {
		x = xb;
		y = yb;
	}
	return d * (n + m);
}

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	cout << gcd(a, b, x, y) << endl;
	cout << x << " " << y << endl;
	return 0;
}
