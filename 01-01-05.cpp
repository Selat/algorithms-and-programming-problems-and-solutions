#include <iostream>

using namespace std;

/*
 * 1.1.5. Two nonnegative integers a and b are given. Compute the product a*b
 * (only +, -, =, <> are allowed).
 */

int mult(int a, int b)
{
	int res = 0;
	for(int i = 0; i < b; ++i) {
		res += a;
	}
	return res;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << mult(a, b) << endl;
	return 0;
}
