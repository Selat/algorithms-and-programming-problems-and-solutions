#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.20. Two arrays x[1] 6 . . . 6 x[k] and y[1] 6 . . . 6 y[l] are given.
 * Merge them into one array z[1] 6 . . . 6 z[m] (m = k + l). Any element should
 * appear is z as many times as it appears in x and y together. The number of operations
 * should be of order m.
 */

void merge(const vector <int> &a, const vector <int> &b, vector <int> &c)
{
	int k = a.size();
	int l = b.size();
	int i = 0, j = 0, id = 0;
	c.resize(k + l);
	while((i < k) && (j < l)) {
		if(a[i] < b[j]) {
			c[id++] = a[i];
			++i;
		} else {
			c[id++] = b[j];
			++j;
		}
	}
	while(i < k) {
		c[id++] = a[i];
		++i;
	}
	while(j < l) {
		c[id++] = b[j];
		++j;
	}
}

int main()
{
	int n, m;
	vector <int> a, b, c;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	merge(a, b, c);
	for(int i = 0; i < c.size(); ++i) {
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}
