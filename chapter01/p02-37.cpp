#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.37. An array a[1]..a[n] contains some integers, and every element ap-
 * pears twice except for one element that appears only once. Find this element with
 * fixed additional memory. Number of operations should be proportional to n.
 */

int getAbsentElement(const vector <int> &a)
{
	int n = a.size();
	int x = 0;
	for(int i = 0; i < n; ++i) {
		x ^= a[i];
	}
	return x;
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

	cout << getAbsentElement(a) << endl;

	return 0;
}
