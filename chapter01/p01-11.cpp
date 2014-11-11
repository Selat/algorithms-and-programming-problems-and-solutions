#include <iostream>

using namespace std;

/*
 * 1.1.11. For a nonnegative integer n, compute
 * 1 / 0! + 1 / 1! + ... + 1 / n!
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

long double sum(int n)
{
	long double ans = 0.0l;
	for(int i = 0; i <= n; ++i) {
		ans += 1.0l / fact(i);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << sum(n) << endl;
	return 0;
}
