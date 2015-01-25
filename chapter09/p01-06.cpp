#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/*
 * 9.1.6. A table of cross rates for n currencies is given: rate[i][j] tells how
 * many units of ith currency one get in exchange for one unit of jth currency. (Note
 * that rate[i][j] could differ from 1/rate[j][i] due to transaction costs.) Check
 * in O(n 3 ) time whether an arbitrage deal is possible, i.e., you can make money by
 * currency exchange alone.
 *
 * This is Floyd algorithm.
 */

const int MAXN = 100;

int n;
double a[MAXN][MAXN];
double d[MAXN][MAXN];;

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
			// Here we use log function to come to additive function from multiplicative.
			a[i][j] = -log(a[i][j]);
		}
	}
	if(hasCycle()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
