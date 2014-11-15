#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.17. Two arrays x: array[1..k] of integer and y: array[1..l] of
 * integer are sorted (x[1] < . . . < x[k], y[1] < . . . < y[l]). Find the num-
 * ber of common elements in both arrays; that is, the number of integers t such that
 * t = x[i] = y[j] for some i and j. (The number of operations should be of order
 * k + l.)
 */

int findNumberOfCommon(const vector <int> &a, const vector <int> &b)
{
	int k = a.size();
	int l = b.size();
	int res = 0;
	for(int i = 0, j = 0; (i < k) && (j < l);) {
		if(a[i] < b[j]) {
			++i;
		} else if(a[i] > b[j]) {
			++j;
		} else if(a[i] == b[j]) {
			++res;
			++i;
			++j;
		}
	}
	return res;
}

int main()
{
	int n, m;
	vector <int> a, b;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	cout << findNumberOfCommon(a, b) << endl;
	return 0;
}
