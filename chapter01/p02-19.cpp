#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.19. Two arrays x: array[1..k] of integer and y: array[1..l] of
 * integer satisfying x[1] 6 . . . 6 x[k], y[1] 6 . . . 6 y[l] are given. Find the
 * number of different elements among x[1], . . . , x[k], y[1], . . . , y[l]. (The num-
 * ber of operations should be of order k + l.)
 */

int findDiffNum(const vector <int> &a, const vector <int> &b)
{
	int k = a.size();
	int l = b.size();
	int res = 0;
	int i = 0, j = 0;
	while((i < k) && (j < l)) {
		if(a[i] < b[j]) {
			++i;
			while((i < k) && (a[i] == a[i - 1])) ++i;
		} else if(a[i] > b[j]) {
			++j;
			while((j < l) && (b[j] == b[j - 1])) ++j;
		} else if(a[i] == b[j]) {
			++i;
			while((i < k) && (a[i] == a[i - 1])) ++i;
			++j;
			while((j < l) && (b[j] == b[j - 1])) ++j;
		}
		++res;
	}
	res += (k - i) + (l - j);
	return res;
}

int main()
{
	int n, m;
	vector <int> a, b;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	cout << findDiffNum(a, b) << endl;
	return 0;
}
