#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/*
 * 9.1.8. There are n airports. For every i and j we know the baggage allowance
 * on the flights from ith to jth airport. For a given starting point a and for all other
 * airports x find the maximal weight that can be transported from a to x (using as many
 * intermediate stops as necessary). The total time (for a given a and all x) should be
 * O(n^2 ).
 *
 * This is modified Dijkstra algorithm.
 */

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int d[MAXN];
bool used[MAXN];

void dijkstra(int id)
{
	for(int i = 0; i < n; ++i) {
		d[i] = a[id][i];
	}
	for(int i = 0; i < n; ++i) {
		used[i] = false;
	}
	d[id] = 0;
	used[id] = true;
	for(int i = 1; i < n; ++i) {
		int min_id = -1;
		for(int j = 0; j < n; ++j) {
			if(!used[j] && ((min_id == -1) || (d[min_id] > d[j]))) {
				min_id = j;
			}
		}
		used[min_id] = true;
		for(int j = 0; j < n; ++j) {
			d[j] = max(d[j], min(d[min_id], a[min_id][j]));
		}
	}
}

int main()
{
	int id;
	cin >> n >> id;
	--id;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	dijkstra(id);
	for(int i = 0; i < n; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
	return 0;
}
