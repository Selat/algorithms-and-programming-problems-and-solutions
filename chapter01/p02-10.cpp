#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.10. An array x[1]..x[n] is given. Without using other arrays, put its ele-
 * ments in reverse order.
 */

void reverse(vector <int> &a)
{
	int n = a.size();
	int n_2 = n / 2;
	// just swap all pairs of elements (a[i], a[n - i - 1]), i in [0, n / 2]
	for(int i = 0; i < n_2; ++i) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
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

	reverse(a);
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
