#include <iostream>
#include <vector>

using namespace std;

/*
 * 8.1.8. An array x 1 , . . . , x n of n positive integers and an integer N are given.
 * Check if N is equal to the sum of some subset of {x 1 , . . . , x n }. The number of oper-
 * ations should be of order N n.
 */

bool solve(vector <int> &a, int n)
{
	vector <bool> used(n + 1, false);
	used[0] = true;
	for(int i = 0; i < a.size(); ++i) {
		for(int j = used.size() - 1; j >= 0; --j) {
			int next_id = j + a[i];
			if(used[j] && (next_id <= n)) {
				used[next_id] = true;
			}
		}
	}

	return used[n];
}

int main()
{
	int n, m;
	cin >> m >> n;
	vector <int> a(m);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	if(solve(a, n)) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}
