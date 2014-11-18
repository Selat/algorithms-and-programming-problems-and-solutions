#include <iostream>

using namespace std;

/*
 * 1.1.35. Two nonnegative integers a and b are given, with b > 0. Find a mod b
 * and a div b using only integer variables and avoiding explicit div and mod oper-
 * ations (the only exception: an even number may be divided by 2). The number of
 * operations should not exceed C 1 log(a/b) + C 2 for some constants C 1 and C 2 .
 */

pair <int, int> divide(int a, int b)
{
	int b1 = b;
	while(b1 <= a) {
		b1 <<= 1;
	}
	int q = 0, r = a;
	// invariant:
	// a / b = q
	// a % b = r
	// b * q + r = a
	while(b1 != b) {
		b1 = b1 / 2;
		q *= 2;
		if(r > b1) {
			++q;
			r -= b1;
		}
	}
	return make_pair(q, r);
}

int main()
{
	int a, b;
	cin >> a >> b;
	pair <int, int> p = divide(a, b);
	cout << p.first << " " << p.second << endl;
	return 0;
}
