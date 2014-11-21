#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.28. (From D. Gries’ book [7]) An array
 * x: array[1..n] of array[1..m] of integer
 * is sorted both row-wise and column-wise:
 * x[i][j] <= x[i][j+1],
 * x[i][j] <= x[i+1][j].
 * Determine if a given number a is present among the array elements x[i][j].
 */

bool isPresent(vector <vector <int> > &a, int x)
{
	int n = a.size();
	int m = a[0].size();
	int l = n - 1, k = 0;
	while((l >= 0) && (k < m) && (a[l][k] != x)) {
		if(a[l][k] < x) {
			// All elements a[i][k], where 0 <= i <= l are smaller than x.
			++k;
		} else {
			// All elements a[l][i], where 0 <= i <= k are bigger than x.
			--l;
		}
	}
	if((l >= 0) && (k < m)) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	vector <vector <int> > a;
	int n, m, x;
	cin >> n >> m >> x;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(n);
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	if(isPresent(a, x)) {
		cout << "Present" << endl;
	} else {
		cout << "Not present" << endl;
	}
}
