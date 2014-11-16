#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.18. Solve the preceding problem with the assumption that x[1] 6 . . . 6
 * x[k] and y[1] 6 . . . 6 y[l] (arrays are non-decreasing but not necessarily in-
 * creasing).
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
