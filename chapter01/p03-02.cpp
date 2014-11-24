#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.3.2. (Communicated by D.V. Varsonofiev) Two sequences x[1]..x[n] and
 * y[1]..y[k] of integers are given. Determine if the second sequence is a
 * subsequence of the first one; that is, if it is possible to delete some terms of the first
 * sequence to obtain the second one. The number of operations should be of order
 * n + k.
 */

bool isSubsequence(const vector <int> &a,
                   const vector <int> &b)
{
	int i = 0, j = 0;
	while((i < a.size()) && (j < b.size())) {
		if(a[i] == b[j]) {
			++i;
			++j;
		} else {
			++i;
		}
	}
	return j == b.size();
}

int main()
{
	vector <int> a, b, c;
	int n, m;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	b.resize(m);
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	if(isSubsequence(a, b)) {
		cout << "Subsequence!" << endl;
	} else {
		cout << "Not a subsequence!" << endl;
	}
	return 0;
}
