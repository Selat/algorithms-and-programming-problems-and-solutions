#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.21. Two arrays x[1] 6 . . . 6 x[k] and y[1] 6 . . . 6 y[l] are given. Find
 * their “intersection”, i.e., an array z[1] 6 . . . 6 z[m] that contains their common
 * elements. The multiplicity of each element in z should be equal to the smaller of its
 * multiplicities in x and y. The number of operations should be of order k + l.
 */

void merge(const vector <int> &a, const vector <int> &b, vector <int> &c)
{
	int k = a.size();
	int l = b.size();
	c.clear();
	for(int i = 0, j = 0; (i < k) && (j < l);) {
		if(a[i] < b[j]) {
			++i;
		} else if(a[i] > b[j]){
			++j;
		} else {
			c.push_back(a[i]);
			++i;
			++j;
		}
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
