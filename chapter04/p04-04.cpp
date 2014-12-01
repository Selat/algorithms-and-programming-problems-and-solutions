#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.4.4. An array of n integers in the range 0, ... , 2^{k − 1} is given. Each integer is
 * written as a binary string of length k. Using the tests “i-th bit is 0” and “i-th bit is 1”
 * instead of comparisons, sort all the integers. The number of operations should be of
 * order n * k.
 */

void _sort(vector <int> &a, int l, int r, vector <int> &b, int k)
{
	int id = l;
	int mask = (1 << k);
	for(int i = l; i < r; ++i) {
		if((a[i] & mask) == 0) {
			b[id++] = a[i];
		}
	}
	int m = id;
		
	for(int i = l; i < r; ++i) {
		if((a[i] & mask) != 0) {
			b[id++] = a[i];
		}
	}
	for(int i = l; i < r; ++i) {
		a[i] = b[i];
	}
	if(k > 0) {
		_sort(a, l, m, b, k - 1);
		_sort(a, m, r, b, k - 1);
	}
}

void sort(vector <int> &a, int k)
{
	vector <int> b(a.size());
	_sort(a, 0, a.size(), b, k);
}

int main()
{
	int n, k = 0;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		while(a[i] >= (1 << k)) {
			++k;
		}
	}
	sort(a, k);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
