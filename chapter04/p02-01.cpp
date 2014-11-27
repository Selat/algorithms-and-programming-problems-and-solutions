#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.2.1. Find a sorting algorithm that requires only O(n log n) operations. (In
 * other words, the number of operations should not exceed Cn log n for some constant
 * C that does not depend on n.)
 * This solution implements merge sort.
 */

void merge(int p, int q, int r, vector <int> &a, vector <int> &b)
{
	int p0 = p, q0 = q, s = p;
	while((p0 < q) && (q0 < r)) {
		if(a[p0] < a[q0]) {
			b[s++] = a[p0++];
		} else {
			b[s++] = a[q0++];
		}
	}
	while(p0 < q) {
		b[s++] = a[p0++];
	}
	while(q0 < r) {
		b[s++] = a[q0++];
	}

	for(int i = p; i < r; ++i) {
		a[i] = b[i];
	}
}

void mergeTransform(int k, vector <int> &a, vector <int> &b)
{
	int n = a.size();
	for(int i = 0; i < n; i += 2 * k) {
		int p = i;
		int q = min(i + k, n);
		int r = min(i + 2 * k, n);
		merge(p, q, r, a, b);
	}
}

void mergeSort(vector <int> &a)
{
	vector <int> b(a.size());
	int k = 1;
	while(k < a.size()) {
		mergeTransform(k, a, b);
		k *= 2;
	}
}

int main()
{
	int n;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	mergeSort(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
