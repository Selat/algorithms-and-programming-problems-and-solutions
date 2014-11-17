#include <iostream>

using namespace std;

/*
 * 1.1.34. The same problem for f(0) = 13, f(1) = 17, f(2) = 20, f(3) = 30,
 * f(2n) = 43 f(n) + 57 f(n + 1) and f(2n + 1) = 91 f(n) + 179 f(n + 1) for n > 2.
 */

int getF(int n)
{
	int f[] = {13, 17, 20, 30, 2550, 7190};
	int a = 1, b = 0, c = 0;
	if(n == 0) {
		return 13;
	}
	// invariant relation: 0 <= k, f(n) = a * f(k) + b * f(k + 1) + c * f(k + 2)
	int k;
	for(k = n; k > 3;) {
		int l = k / 2;
		int a2, b2, c2;
		if(k & 1) {
			// k = 2l + 1
			a2 = 91 * a;
			b2 = 179 * a + 43 * b + 91 * c;
			c2 = 57 * b + 179 * c;
		} else {
			// k = 2l
			a2 = 42 * a + 91 * b;
			b2 = 57 * a + 179 * b + 43 * c;
			c2 = 57 * c;
		}
		a = a2;
		b = b2;
		c = c2;
		k = l;
	}
	return f[k] * a + f[k + 1] * b + f[k + 2] * c;
}

int main()
{
	int n;
	cin >> n;
	cout << getF(n) << endl;
	return 0;
}
