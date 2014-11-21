#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.35. A square matrix a[1..n][1..n] and a number m <= n are given. For
 * any m×m-subsquare, compute the sum of its elements. The total number of operations
 * should be of order n^2 .
 */

void compute(const vector <vector <int> > &a, vector <vector <int> > &b, int m)
{
	vector <vector <int> > tmp;
	b.clear();
	if(m > a.size()) {
		return;
	}
	tmp.resize(a.size());
	// Compute sum of rectangles 1×m
	for(int i = 0; i < a.size(); ++i) {
		tmp[i].resize(a.size() - m + 1);
		int s = 0;
		for(int j = 0; j < m; ++j) {
			s += a[i][j];
		}
		tmp[i][0] = s;
		for(int j = m; j < a.size(); ++j) {
			s -= a[i][j - m];
			s += a[i][j];
			tmp[i][j - m + 1] = s;
		}
	}

	b.resize(a.size() - m + 1);
	for(int i = 0; i < b.size(); ++i) {
		b[i].assign(a.size() - m + 1, 0);
	}

	// Compute sum of squares m×m
	for(int i = 0; i < b.size(); ++i) {
		int s = 0;
		for(int j = 0; j < m; ++j) {
			s += tmp[j][i];
		}
		b[0][i] = s;
		for(int j = m; j < a.size(); ++j) {
			s -= tmp[j - m][i];
			s += tmp[j][i];
			b[j - m + 1][i] = s;
		}
	}
}

int main()
{
	vector <vector <int> > a;
	vector <vector <int> > b;
	int n, m;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(n);
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	compute(a, b, m);
	for(int i = 0; i < b.size(); ++i) {
		for(int j = 0; j < b.size(); ++j) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
