#include <iostream>

using namespace std;

/*
 * 1.1.28. A nonnegative integer n is given. Count all the solutions of the inequality
 * x^2 + y^2 < n where x and y are nonnegative integers. The program should not use
 * operations with real numbers (square roots, etc.).
 */

int solve(int n)
{
	// invariant relation: s = the number of all pairs
	// <x,y> such that (x*x + y*y < n and x < a)}
	int a = 0, s = 0;
	while(a * a < n) {
		int t = 0;
		while(a * a + t * t < n) ++t;
		++a;
		s += t;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
