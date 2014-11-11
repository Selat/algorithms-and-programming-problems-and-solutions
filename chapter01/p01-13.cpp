#include <iostream>

using namespace std;

/*
 * 1.1.13. Two nonnegative integers a and b are not both zero. Compute GCD(a,b),
 * the greatest common divisor of a and b.
 */

int gcd(int a, int b)
{
	while((a -= b) && (b > 0)) {
		if(a >= b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	return a + b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
