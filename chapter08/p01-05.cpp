#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

/*
 * 8.1.5. An m × n matrix is a rectangular table with m rows and n columns filled
 * with numbers. An m×n matrix may be multiplied by an n×k matrix (the width of the
 * left factor must be equal to the height of the matrix on the right) giving m × k matrix
 * as the result. The cost of such a multiplication is defined as mnk (this is the number
 * of multiplications required by the standard multiplication algorithm, but this is not
 * important). Matrix multiplication is associative, therefore the product of s matrices
 * may be computed in any order. For each ordering, consider the total cost of all matrix
 * multiplications. Find the minimal cost when the sizes of the matrices are given. The
 * running time of the algorithm should be bounded by a polynomial over the number
 * of factors (s).
 *
 * The solution uses the following relation
 * a(i, j) = min{a(i, k) + a(k, j) + d[i] * d[k] * d[j]},
 * where a(i, j) - the minimal cost of computation the product of all matricies in the
 * interval [i, j].
 */

const int MAXN = 100;
const int INF = INT_MAX;

int a[MAXN][MAXN];

int solve(vector <int> &d)
{
	for(int i = 0; i < d.size(); ++i) {
		for(int j = 0; j < d.size(); ++j) {
			a[i][j] = INF;
		}
		a[i][i + 1] = 0;
	}
	stack <pair <int, int> > s;
	s.push(make_pair(0, d.size() - 1));
	while(!s.empty()) {
		int l = s.top().first;
		int r = s.top().second;
		if(a[l][r] == INF) {
			bool can_compute = true;
			int val = INF;
			for(int k = l + 1; k < r; ++k) {
				if(a[l][k] == INF) {
					can_compute = false;
					s.push(make_pair(l, k));
				}
				if(a[k][r] == INF) {
					can_compute = false;
					s.push(make_pair(k, r));
				}
				val = min(val, a[l][k] + a[k][r] + d[l] * d[k] * d[r]);
			}
			if(can_compute) {
				a[l][r] = val;
			}
		} else {
			s.pop();
		}
	}
	return a[0][d.size() - 1];
}

int main()
{
	int n;
	cin >> n;
	vector <int> d(n + 1);
	for(int i = 0; i <= n; ++i) {
		cin >> d[i];
	}
	cout << solve(d) << endl;
	return 0;
}
