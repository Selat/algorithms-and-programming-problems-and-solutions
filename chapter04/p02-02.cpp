#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.2.1. Find a sorting algorithm that requires only O(n log n) operations. (In
 * other words, the number of operations should not exceed Cn log n for some constant
 * C that does not depend on n.)
 * This solution implements heap sort.
 */

void restore(vector <int> &a, int s, int k)
{
	int t = s;
	while(((2 * t + 1 <= k) && (a[2 * t + 1] > a[t]))
	      || ((2 * t <= k) && (a[2 * t] > a[t]))) {
		if((2 * t + 1 <= k) && (a[2 * t + 1] >= a[2 * t])) {
			swap(a[t], a[2 * t + 1]);
			t = 2 * t + 1;
		} else {
			swap(a[t], a[2 * t]);
			t = 2 * t;
		}
	}
}

void sort(vector <int> &a)
{
	int n = a.size() - 1;
	for(int i = n; i > 0; --i) {
		restore(a, i, n);
	}
	for(int i = n; i > 1;) {
		swap(a[1], a[i]);
		--i;
		restore(a, 1, i);
	}
}

int main()
{
	int n;
	vector <int> a;
	cin >> n;
	a.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a);
	for(int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
