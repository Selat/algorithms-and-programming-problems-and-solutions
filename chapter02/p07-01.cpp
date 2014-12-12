#include <iostream>

using namespace std;

/*
 * 2.7.1. (Number of partitions) Let P(n) be the number of representations of a
 * nonnegative integer n as a sum of positive integer summands (order is insignificant;
 * that is, the representations 1 + 2 and 2 + 1 are identical). We assume that P(0) = 1
 * (the only representation has no summands at all). Write a program that finds P(n)
 * for a given n.
 */

int f[100001];

int getF(int n)
{
	/*
	 * P(n) = P(n - 1) + P(n - 2) - P(n - 5) - P(n - 7) + ...
	 */
	if(f[n] != -1) {
		return f[n];
	} else {
		int sign = 1;
		f[n] = 0;
		for(int i = 1; n - (3 * i * i - i) / 2 >= 0; ++i) {
			int id1 = n - (3 * i * i - i) / 2;
			int id2 = n - (3 * i * i + i) / 2;
			f[n] += sign * getF(id1);
			if(id2 >= 0) {
				f[n] += sign * getF(id2);
			}
			sign = -sign;
		}
		return f[n];
	}
}

int main()
{
	int n;
	f[0] = 1;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		f[i] = -1;
	}
	cout << getF(n) << endl;
	return 0;
}
