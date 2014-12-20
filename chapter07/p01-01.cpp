#include <iostream>

using namespace std;

/*
 * 7.1.1. Write a recursive program that computes the factorial of a positive integer
 * n (i.e., the product n! = 1 · 2 · · · n).
 */

long long fact(int n)
{
	if(n > 1) {
		return n * fact(n - 1);
	} else {
		return 1ull;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}
