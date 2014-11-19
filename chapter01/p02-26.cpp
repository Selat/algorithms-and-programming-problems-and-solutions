#include <iostream>
#include <vector>

using namespace std;

/*
 * 1.2.26. Our solution of the preceding problem requires mn 2 operations. Find an
 * algorithm that needs only O(mn) operations (i.e., not more than Cmn operations for
 * some C).
 */

int findCommon(vector <vector <int> > &a)
{
	vector <int> b(a.size(), 0);
	bool equal = true;
	// If such element doesn't exist there will be a runtime error.
	for(int i = 1; i < a.size(); ++i) {
		while(a[i][b[i]] < a[0][b[0]]) ++b[i];
	}
	for(int i = 1; i < a.size(); ++i) {
		equal = equal && (a[i][b[i]] == a[0][b[0]]);
	}
	while(!equal) {
		++b[0];
		for(int i = 1; i < a.size(); ++i) {
			while(a[i][b[i]] < a[0][b[0]]) ++b[i];
		}
		equal = true;
		for(int i = 1; i < a.size(); ++i) {
			equal = equal && (a[i][b[i]] == a[0][b[0]]);
		}
	}
	return a[0][b[0]];
}

int main()
{
	int n, m;
	vector <vector <int> > a;
	cin >> n >> m;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		a[i].resize(m);
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	cout << findCommon(a) << endl;
	return 0;
}
