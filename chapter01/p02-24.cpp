#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.24. Repeat the previous problem assuming that we do not know in advance
 * if such a common element exist. Determine whether or not it exists and locate it if it
 * does.
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
	return -1;
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
