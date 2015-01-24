#include <iostream>
#include <climits>

using namespace std;

/*
 * 9.1.5. Find in O(n 3 ) time whether a cyclic travel plan with negative total cost
 * exists.
 *
 * This is Floyd algorithm.
 */

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int d[MAXN][MAXN];;

bool hasCycle()
{
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			d[i][j] = a[i][j];
		}
	}
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if(d[i][i] < 0) {
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	if(hasCycle()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
