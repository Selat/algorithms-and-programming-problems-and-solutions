#include <iostream>

using namespace std;

/*
 * 1.1.31. A natural number n > 1 is given. Find the length of the period of the
 * decimal number 1/n.
 */

int getPeriod(int n)
{
	int r = 1;
	// The length of initial non-periodic sequence doesn't exceed n.
	for(int i = 0; i < n + 1; ++i) {
		r = (r * 10) % n;
	}
	int c = r;
	r = (r * 10) % n;
	int k = 1;
	// All elements of the period are distinct, therefore we can just search
	// for first occurrence of (n + 1)-th element.
	while(c != r) {
		r = (r * 10) % n;
		++k;
	}
	return k;
}

int main()
{
	int n, k;
	cin >> n;
	cout << getPeriod(n) << endl;
	return 0;
}
