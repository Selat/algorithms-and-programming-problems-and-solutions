#include <iostream>

using namespace std;

/*
 * 1.1.9. The Fibonacci sequence is defined as follows: a[0] = 0, a[1] = 1, a[k] =
 * a[k-1] + a[k-2] for k >= 2. For a given n, compute an .
 */

typedef unsigned long long ull;

ull fib(int n)
{
	ull a = 1, b = 0;
	for(int i = 0; i < n; ++i) {
		b = a + b;
		a = b - a;
	}
	return b;
}

int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}
