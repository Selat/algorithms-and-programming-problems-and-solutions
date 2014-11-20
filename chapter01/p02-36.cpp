#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.36. An array a[1]..a[n] contains all integers in [0..n] except one. Find
 * this omitted integer with fixed additional memory. Number of operations should be
 * proportional to n.
 */

int getOmittedElement(vector <int> &a)
{
	int s = 0;
	int n = a.size();
	for(int i = 0; i < n; ++i) {
		s += a[i];
	}
	return n * (n + 1) / 2 - s;
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

	cout << getOmittedElement(a) << endl;
	return 0;
}
