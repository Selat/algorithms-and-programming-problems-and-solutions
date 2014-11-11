#include <iostream>

using namespace std;

/*
 * 1.1.7. A nonnegative integer a and positive integer d are given. Compute the
 * quotient q and the remainder r when a is divided by d. Do not use the operations
 * div or mod.
 */

pair <int, int> divide(int a, int d)
{
	int q = 0, r = a;
	while(r >= d) {
		r -= d;
		++q;
	}
	return make_pair(q, r);
}

int main()
{
	int a, b;
	cin >> a >> b;
	pair <int, int> res = divide(a, b);
	cout << res.first << " " << res.second << endl;
	return 0;
}
