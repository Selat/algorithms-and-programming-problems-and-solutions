#include <iostream>

using namespace std;

/*
 * 1.1.18. Write a version of Euclid’s algorithm using the identities
 * GCD(2a, 2b) = 2 * GCD(a, b);
 * GCD(2a, b) = GCD(a, b)
 * for odd b
 * The algorithm should avoid division (div and mod operations); only division by 2
 * and the test “to be even” are allowed. (The number of operations should be of order
 * log k if both numbers do not exceed k.)
 */

int gcd(int a, int b)
{
	// invariant relation
	// GCD(a, b) = d * GCD(n ,m),
	int n = a, m = b, d = 1;
	while((n > 0) && (m > 0)) {
		if((n & 1) && (m & 1)) {
			if(n >= m) {
				n -= m;
			} else {
				m -= n;
			}
		} else if(n & 1) {
			m >>= 1;
		} else if(m & 1) {
			n >>= 1;
		} else {
			d <<= 1;
			n >>= 1;
			m >>= 1;
		}
	}
	return d * (n + m);
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
