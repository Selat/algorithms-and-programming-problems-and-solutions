#include <iostream>
#include <vector>

using namespace std;

/*
 * 4.4.2. An integer array a[1]..a[n] is given; all the integers are nonnegative
 * and do not exceed m. Sort this array using no more than C(m + n) operations (C is a
 * constant that does not depend on m and n).
 */

void sort(vector <int> &a, int m)
{
	vector <int> b(m + 1, 0);
	for(int i = 0; i < a.size(); ++i) {
		++b[a[i]];
	}
	int id = 0;
	for(int i = 0; i < b.size(); ++i) {
		for(int j = 0; j < b[i]; ++j) {
			a[id++] = i;
		}
	}
}

int main()
{
	int n, m = 0;
	vector <int> a;
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	sort(a, m);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
