#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.29. (Moscow programming contest) A non-decreasing integer array a[1] <=
 * a[2] <= ... <= a[n] contains positive numbers only. Find the minimal positive integer
 * that cannot be represented as a sum of several elements of this array (no element
 * may be used more than once). The number of operations should be of order n.
 */

int getMinSuitableNum(const vector <int> &a)
{
	int s = 0;
	for(int i = 0; (i < a.size()) && (s + 1 >= a[i]); ++i) {
		s += a[i];
	}
	return s + 1;
}

int main()
{
	vector <int> a;
	int n;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cout << getMinSuitableNum(a) << endl;
	return 0;
}
