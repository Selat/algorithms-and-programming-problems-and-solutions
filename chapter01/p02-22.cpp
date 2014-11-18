#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

/*
 * 1.2.22. Two arrays x[1] 6 . . . 6 x[k] and y[1] 6 . . . 6 y[l] and a number
 * q are given. Find i and j such that x[i] + y[j] is as close to q as possible.
 * (The number of operations should be of order k+l. You may use a fixed number of
 * auxiliary integer variables; the arrays x and y are read-only.)
 */

pair <int, int> getNearest(vector <int> &a, vector <int> &b, int q)
{
	int i = 0, j = b.size() - 1;
	int besti = 0, bestj = 0;
	int best_val = INT_MAX;
	bool prev_a_set = false;
	bool prev_b_set = false;
	int prev_a = 0;
	int prev_b = 0;
	int prev_a_i = 0;
	int prev_a_j = 0;
	while((i < a.size()) && (j >= 0)) {
		if((i > 0) && (j < b.size() - 1) && (fabs(a[i - 1] + b[j + 1] - q) < best_val)) {
			besti = i - 1;
			bestj = j + 1;
			best_val = fabs(a[i - 1] + b[j + 1] - q);
		}

		if(a[i] < q - b[j]) {
			++i;
		} else {
			--j;
		}
	}

	while(i < a.size()) {
		if((i > 0) && (j < b.size() - 1) && (fabs(a[i - 1] + b[j + 1] - q) < best_val)) {
			besti = i - 1;
			bestj = j + 1;
			best_val = fabs(a[i - 1] + b[j + 1] - q);
		}
		++i;
	}

	while(j >= 0) {
		if((i > 0) && (j < b.size() - 1) && (fabs(a[i - 1] + b[j + 1] - q) < best_val)) {
			besti = i - 1;
			bestj = j + 1;
			best_val = fabs(a[i - 1] + b[j + 1] - q);
		}
		--j;
	}

	if((i > 0) && (j < (int)b.size() - 1) && (fabs(a[i - 1] + b[j + 1] - q) < best_val)) {
		besti = i - 1;
		bestj = j + 1;
		best_val = fabs(a[i - 1] + b[j + 1] - q);
	}

	return make_pair(besti, bestj);
}

int main()
{
	int n, m, q;
	vector <int> a, b;
	cin >> n >> m >> q;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	pair <int, int> p = getNearest(a, b, q);
	cout << p.first << " " << p.second << endl;
	return 0;
}
