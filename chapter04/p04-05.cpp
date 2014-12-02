#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.4.5. Assume that an array of n elements and a function f defined on those
 * elements are given. Assume that the possible values of f are 1, ... , m. Rearrange
 * the array in such a way that the values of f are in non-decreasing order and the
 * elements with equal values of f are in the same order as before. The number of
 * operations should be of order m + n.
 */

void sort(vector <int> &a, const vector <int> &f, int m)
{
	// c[i] - number of elements in a such that f[a[j]] = i
	vector <int> c(m + 1, 0);
	vector <int> tmp_a(a.size());
	for(int i = 0; i < a.size(); ++i) {
		++c[f[a[i]]];
	}

	// c[i] - 1 >= -1 - is maximal integer such that d[c[i]] <= i
	// where d - already sorted array.
	for(int i = 1; i < c.size(); ++i) {
		c[i] += c[i - 1];
	}
	// c[i] - is minimal non-negative integer such that d[c[i]] >= i
	// where d - already sorted array.
	for(int i = c.size() - 1; i > 0; --i) {
		c[i] = c[i - 1];
	}

	for(int i = 0; i < a.size(); ++i) {
		tmp_a[c[f[a[i]]]++] = a[i];
	}
	a = tmp_a;
}

int main()
{
	int n, m;
	vector <int> a, f;
	cin >> n >> m;
	a.resize(n);
	f.resize(m + 1);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> f[i];
	}
	sort(a, f, m);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
