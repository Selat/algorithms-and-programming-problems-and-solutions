#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.32. Repeat the previous problem with the additional restriction that the elements
 * smaller than b should precede elements equal to b which themselves should
 * precede elements greater than b.
 */

void rearrange(vector <int> &a, int b)
{
	// invariant relation:
	// a[0 .. l] < b
	// a[l+1 .. m] == b
	// a[r+1 .. n] > b
	int l = 0, m = 0, r = a.size() - 1;
	while(m != r) {
		if(a[m] == b) {
			++m;
		} else if(a[m] > b) {
			swap(a[m], a[r]);
			--r;
		} else {
			// a[m] < b
			swap(a[m], a[l]);
			++l;
			++m;
		}
	}
}

int main()
{
	int n, b;
	vector <int> a;
	cin >> n >> b;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	rearrange(a, b);

	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}
