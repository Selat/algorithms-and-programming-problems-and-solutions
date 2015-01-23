#include <iostream>
#include <climits>

using namespace std;

/*
 * 9.1.4. Find the minimal travel costs i → j for all i,j in time O(n 3 ).
 *
 * This is Floyd algorithm.
 */

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int d[MAXN][MAXN];;

void findPaths()
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
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	findPaths();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
