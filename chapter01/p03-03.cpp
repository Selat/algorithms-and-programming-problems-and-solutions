#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.3.3. Two sequences x[1]..x[n] and y[1]..y[k] of integers are given. Find
 * the maximal length of a sequence that is a subsequence of both given sequences. The
 * number of operations should be of order n · k.
 */

int f[100][100];

int solve(const vector <int> &a, const vector <int> &b)
{
	// f[i][j] - maximal length of a subsequence of a[0] .. a[i] and b[0] .. b[j].
	int n = a.size(), m = b.size();
	int l = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[0]) {
			l = 1;
		}
		f[i][0] = l;
	}
	l = 0;
	for(int i = 0; i < m; ++i) {
		if(b[i] == a[0]) {
			l = 1;
		}
		f[0][i] = l;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i] == b[j]) {
				f[i + 1][j + 1] = f[i][j] + 1;
			} else {
				f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
			}
		}
	}
	return f[a.size() - 1][b.size() - 1];
}

int main()
{
	vector <int> a, b;
	int n, m;
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	cout << solve(a, b) << endl;
	return 0;
}
