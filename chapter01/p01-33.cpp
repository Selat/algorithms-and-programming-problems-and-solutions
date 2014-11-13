#include <iostream>

using namespace std;

/*
 * 1.1.33. (E. Dijkstra). A function f whose arguments and values are nonnegative
 * integers is defined as follows: f(0) = 0, f(1) = 1, f(2n) = f(n), f(2n + 1) =
 * f(n) + f(n + 1). Write a program that computes f(n) for a given n; the number of
 * operations should be of order log n.
 */

int getF(int n)
{
	int a = 1, b = 0;
	// invariant relation: 0 <= k, f(n) = a * f(k) + b * f(k + 1)
	for(int k = n; k > 0;) {
		int l = k / 2;
		if(k & 1) {
			// k = 2l + 1
			b += a;
		} else {
			// k = 2l
			a += b;
		}
		k = l;
	}
	return b;
}

int main()
{
	int n;
	cin >> n;
	cout << getF(n) << endl;
	return 0;
}
