#include <iostream>
#include <climits>
#include <stack>

using namespace std;

/*
 * 8.1.6. A one-way railway has n stops. We know the price of tickets from the i-th
 * stop to the j-th stop (for i < j, since there is no traffic in the other direction). Find
 * the minimal travel cost from stop 1 to stop n (taking into account possible savings
 * due to intermediate stops).
 *
 * The solution uses the following relation: d[i] = min{d[j] + a[j][i]}, forall j < i. Where
 * d[i] - minimal travel cost from stop 0 to stop i. Also this solution uses "memorization"
 * technique, which reduces working time to O(n ^ 2).
 */

const int MAXN = 100;
const int INF = INT_MAX;
int a[MAXN][MAXN];
int d[MAXN];

int solve(int n)
{
	stack <int> s;
	d[0] = 0;
	for(int i = 1; i < n; ++i) {
		d[i] = INF;
	}
	s.push(n - 1);
	while(!s.empty()) {
		int id = s.top();
		bool can_compute = true;
		int min_dist = INF;
		for(int i = 0; i < id; ++i) {
			if(d[i] == INF) {
				s.push(i);
				can_compute = false;
			} else {
				min_dist = min(min_dist, d[i] + a[i][id]);
			}
		}
		if(can_compute) {
			d[id] = min_dist;
			s.pop();
		}
	}
	return d[n - 1];
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	cout << solve(n) << endl;
	return 0;
}
