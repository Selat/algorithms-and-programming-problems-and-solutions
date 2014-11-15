#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.11. (From D. Gries’ book [7]) An array x[1]..x[m+n] is considered as
 * a concatenation of two segments: a prefix x[1]..x[m] of length m and a suffix
 * x[m+1]..x[m+n] of length n. Without using other arrays, exchange these prefix
 * and suffix segments. (The number of operations should be of order m + n.)
 */

int a[1000];

void reverse(int *a, int n)
{
	int n_2 = n / 2;
	// just swap all pairs of elements (a[i], a[n - i - 1]), i in [0, n / 2]
	for(int i = 0; i < n_2; ++i) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

int swapSegment(int *a, int m, int n)
{
	reverse(a, m);
	reverse(a + m, n);
	reverse(a, n + m);
}

int main()
{
	int len, m, n;
	cin >> len >> m >> n;
	for(int i = 0; i < len; ++i) {
		cin >> a[i];
	}

	swapSegment(a, m, n);
	for(int i = 0; i < len; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
