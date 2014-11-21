#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.34. An array a[1..n] and a number m 6 n are given. For any segment
 * formed by m adjacent elements (there are n − m + 1 segments of this type) compute
 * its sum. The total number of operations should be of order n.
 */

void compute(const vector <int> &a, vector <int> &b, int m)
{
	int s = 0;
	b.resize(a.size() - m + 1);
	for(int i = 0; i < m; ++i) {
		s += a[i];
	}
	b[0] = s;
	for(int i = m; i < a.size(); ++i) {
		s -= a[i - m];
		s += a[i];
		b[i - m + 1] = s;
	}
}

int main()
{
	vector <int> a, b;
	int n, m;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	compute(a, b, m);
	for(int i = 0; i < b.size(); ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}
