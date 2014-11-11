#include <iostream>

using namespace std;

/*
 * 1.1.8. For a given nonnegative integer n, compute n! (n! is the product 1 · 2 ·
 * 3 · ... · n; we assume that 0! = 1).
 */

typedef unsigned long long ull;

ull fact(int n)
{
	ull res = 1;
	for(int i = 2; i <= n; ++i) {
		res *= i;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}
