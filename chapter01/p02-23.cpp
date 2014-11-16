#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.23. (from D. Gries’ book [7]) There is a number that is present in all three
 * non-decreasing arrays x[1] 6 . . . 6 x[p], y[1] 6 . . . 6 y[q], z[1] 6 . . . 6
 * z[r]. Find this number (or one of them, if there is more than one). The number of
 * operations should be of order p + q + r.
 */

int findCommon(const vector <int> &a, const vector <int> &b, const vector <int> &c)
{
	for(int i = 0, j = 0, k = 0; (i < a.size()) && (j < b.size()) && (k < c.size());) {
		if(a[i] < b[j]) {
			++i;
		} else if(b[j] < c[k]) {
			++j;
		} else if(c[k] < a[i]) {
			++k;
		} else {
			return a[i];
		}
	}
}

int main()
{
	int n, m, l;
	vector <int> a, b, c;
	cin >> n >> m >> l;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	c.resize(l);
	for(int i = 0; i < l; ++i) {
		cin >> c[i];
	}

	cout << findCommon(a, b, c) << endl;
	return 0;


}
